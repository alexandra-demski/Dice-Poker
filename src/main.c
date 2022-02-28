/*
Fichier contenant les fonctions liées à l'interface du jeu en console
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/globals.h"

int nb_des; // Nombre de dés
void parametres();

int main() {
    /*
    * Fonction principale du programme
    * @return EXIT_SUCCESS
    */
    int score; // Score d'une partie
    int rep; // Etape après la partie
    char buffer[256];

    srand(time(NULL)); // Initialisation

    printf("Bienvenu au Dice Poker !\n");
    printf("Vous allez jouer %d manches contre l'ordinateur.\n\n",nb_mch);

    printf("---------- Règles ----------\n\n");
    printf("Manche gagnée\t=  1 point\nManche nulle\t=  0 point\nManche perdue\t= -1 point\n\n");
    
    parametres(); // Récupération nb_des

    printf("\n\n");

    while(1){ // Boucle sur une partie
        rep = -1;
        printf("---------- Début de partie ----------\n\n");

        for(int i=1; i<=nb_mch; i++){ // Boucle sur les manches
            printf("---------- Manche n°%d ----------\n\n",i);
            score += manche(nb_des);
            printf("\n\n");
        }
        printf("Votre score final est de %d.\n\n",score);

        printf("---------- Fin de partie ----------\n\n");

        while(rep < 0){ // Choix de l'étape suivante
            printf("Tapez 1 pour quitter.\n");
            printf("Tapez 2 pour rejouer.\n");
            printf("Tapez 3 pour changer les paramètres.\n\n");

            scanf("%s",buffer); // Récupération réponse
            printf("\n");

            rep = atoi(buffer);

            switch(rep){
                case 1: // Quitter le jeu
                    printf("Merci d'avoir jouer.\n\n");
                    return 0;
                case 2: // Rejouer (reboucler sur une partie)
                    break;
                case 3: // Changer les paramètres (puis reboucler sur la réponse)
                    parametres();
                    rep = -1;
                    break;
                default: // Mauvaise réponse (reboucler sur la réponse)
                    printf("Veuillez réessayer :\n");
                    rep = -1;
                    break;
            }
        }
    }
    return EXIT_SUCCESS;
}

void parametres(){
    /*
    * Change le nombre de dés
    * Amélioration possible : changer le nombre de manches
    * @return void
    */
    char buffer[256];
    printf("Indiquez le nombre de dés : ");
    
    while(1){
        scanf("%s",buffer);
        nb_des = atoi(buffer);
        if(nb_des > 0){
            break;
        } else {
            printf("Veuillez réessayer : ");
        }
    }
}