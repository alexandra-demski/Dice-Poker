/*
Fichier contenant les signatures des fonctions liées à une partie de dice poker
*/

#ifndef GAME_H
#define GAME_H

int manche(int nb); // Génère une manche
int *identifie(int hand[]); // Identifie le type d'un jet de dés
int sequence(int hand[]); // Identifie une séquence
int score(int poly[], int hand[]); // Calcul le score du jet
int departage(int ordi[], int joueur[]); // Départage les types de jet
int relance(int hand[], char choix[]); // Relance des dés du joueur
void affiche(char *name, int hand[], int poly[]); // Affiche un jet de dés et ses informations

#endif