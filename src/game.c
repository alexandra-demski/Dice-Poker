/*
Fichier contenant les fonctions liées à une partie de dice poker
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/game.h"
#include "../include/bubble.h"
#include "../include/enums.h"
#include "../include/globals.h"

int nb_des = 0;

int manche(int nb){
    /*
    * Génère une manche
    * @param nombre de dés
    * @return WIN, EQUAL ou LOOSE (1,0,-1)
    */
    nb_des = nb;
    int *poly_o, *poly_j, *ordi, *joueur;
    int count, res_o, res_j, res;
    char choix[nb_des];
    
    ordi = (int*) calloc(nb_des,sizeof(int)); // Lancer de l'ordi
    joueur = (int*) calloc(nb_des,sizeof(int)); // Lancer du joueur
    
    for(int i=0; i<nb_des; i++){ // Remplir les lancers
        ordi[i] = rand()%6+1; // Nombre aléatoire
        joueur[i] = rand()%6+1;
    }

    sort(ordi,nb_des); // Trier par ordre croissant
    sort(joueur,nb_des);

    // Identifier type de jet
    poly_o = identifie(ordi); // Polynôme de l'ordi
    poly_j = identifie(joueur); // Polynôme du joueur

    affiche("Ordinateur",ordi,poly_o); // Affichage des résultats
    affiche("Joueur",joueur,poly_j);
    printf("\n");

    count = 0; // Relancer des dés
    while(count < nb_rel){
        printf("Que voulez vous faire ? ");
        scanf("\n%s",choix);
        printf("\n");
        count++;

        if(relance(joueur,choix)){ // Si on a relancé des dés
            poly_o = identifie(ordi); // Identifier type de jet
            poly_j = identifie(joueur);
            affiche("Ordinateur",ordi,poly_o); // Affichage des résultats
            affiche("Joueur",joueur,poly_j);
            printf("\n");
        } else { // Si on a rien changé
            count = nb_rel; // On quitte la boucle
        }
    }

    res_o = score(poly_o,ordi); // Calcul de score
    res_j = score(poly_j,joueur);
   
    if(res_j > res_o){ // Choix vainqueur
        printf("Vous avez gagné.");
        res = WIN;
    } else if(res_j == res_o){
        if(res_j != 0){
            res = departage(poly_o,poly_j);
        } else {
            printf("Manche nulle.");
            res = EQUAL;
        }
    } else {
        printf("Vous avez perdu.");
        res = LOOSE;
    }

    free(ordi);
    free(joueur);
    free(poly_o);
    free(poly_j);
    return res;
}

int *identifie(int hand[nb_des]){
    /*
    * Identifie le type d'un jet de dés
    * @param le jet à analyser
    * @return polynome qui décrit le jet (tableau de fréquences des fréquences)
    */
    int val[7]; //Tableau des fréquences
    static int *freq; // Tableau des fréquences de fréquences
    freq = calloc(nb_des+1,sizeof(int)); // Lancer de l'ordi

    for(int i=1; i<=6; i++){ // Remplissage du tableau de fréquences
        val[i] = 0;
        for(int j=0; j<nb_des; j++){
            if(hand[j] == i){
                val[i]++;
            }
        }
    }

    for(int i=0; i<=nb_des; i++){ // Remplissage du tableau des fréquences de fréquences
        freq[i] = 0;
        for(int j=1; j<=6; j++){
            if(val[j] == i){
                freq[i]++;
            }
        }
    }
    return freq;
}

int sequence(int hand[]){
    /*
    * Identifie une séquence (straight)
    * @param le jet de dés
    * @return 1 si séquence sinon 0
    */
    for(int i=0; i<nb_des-1; i++){
        int val1 = hand[i];
        int val2 = hand[i+1];
        if(val2-val1 != 1){
            return 0;
        }
    }
    return 1;
}

int score(int poly[], int hand[]){
    /*
    * Calcul le score du jet
    * @param le polynome et le jet
    * @return le score
    */
    int res = 0;

    // Vérifier si série
    if(sequence(hand)){// si straight
        res = nb_des; // Score arbitraire pour straight
    } else { // sinon
        int x = 2;
        int y = 0;
        for(int i=2; i<=nb_des; i++){
            y = (int) pow((double)x,(double)i);
            res = res + (poly[i] * y); // calcul de score avec polynome
        }
    }
    return res;
}

int departage(int ordi[], int joueur[]){
    /*
    * Départage les types de jet
    * @param les deux jets (ordi et joueur)
    * @return WIN, EQUAL ou LOOSE (1,0,-1)
    */
    int max_o = ordi[nb_des-1]; // Prendre max
    int max_j = joueur[nb_des-1];

    if(max_j > max_o){ // Départage avec max
        printf("Vous avez gagné.\n");
        return WIN;
    } else if(max_j == max_o){
        printf("Manche nulle.\n");
        return EQUAL;
    } else {
        printf("Vous avez perdu.\n");
        return LOOSE;
    }
}

int relance(int hand[], char choix[]){
    /*
    * Relance des dés du joueur
    * @param le jet du joueur ainsi que son choix pour relancer
    * @return 1 si relance 0 sinon
    */
    int boolean = 0;
    if(choix[0] == '1' && choix[1] == 0){ // On change tous les dés
        for(int i=0; i<nb_des; i++){
            hand[i] = rand()%6+1;
            boolean = 1;
        } 
    } else if(choix[0] == '0' && choix[1] == 0){ // On change aucun dés
        return 0;
    } else {// On change une série de dés
        for(int i=0; i<nb_des; i++){
            if(choix[i] == '1'){
                boolean = 1;
                hand[i] = rand()%6+1;
            } else if(choix[i] == 0){ // On peut éviter de continuer si on a plus rien dans les choix
                break;
            }
        }
    }

    sort(hand,nb_des);
    if(boolean)
        return 1;
    return 0;
}

void affiche(char *name, int hand[], int poly[]){
    /*
    * Affiche un jet de dés et ses informations
    * @param le nom du joueur, son jet et le polynome qui le décrit
    * @return void
    */
    printf("%s : ",name); // Affichage du nom

    for(int i=0; i<nb_des; i++){ // Affichage des dés
        printf("%d ",hand[i]);
    }
    printf("(");
    int first = 1; // Facilite l'affichage
    for(int i=2; i<=nb_des; i++){// Affichage polynôme
        if(poly[i] > 0){
            if(first){ // Si premier élement
                printf("%d %s",poly[i], appellation[i]);
                first = 0;
            } else { // Sinon
                printf(", %d %s",poly[i], appellation[i]);
            }
        }
    }
    if(first){ // On a rien trouvé
        if(sequence(hand)){
            printf("straight");
        } else {
            printf("rien");
        }
    }
    printf(")");

    printf("\n");
}
