# Dice Poker
Projet réalisé par Alexandra Demski

## Introduction

Le dice poker est une variation du poker qui utilise des dés au lieu de cartes. L'objectif du projet est d'implémenter un programme permettant de joueur contre l'ordinateur. Le jeu comporte plusieurs manches, le joueur et l'ordinateur lanceront un nombre de dés préalablement configuré et tenteront d'établir des combinaisons, en relançant ou non des dés, pour gagner.

## Organisation

Le projet se décompose en plusieurs packages : `bin`, `include` et `src`.
`src`: comporte le code source
`bin`: stocke les exécutables
`include` : gère les dépendances grâce aux headers



Afin de faciliter la mise en place et l'exécution du programme, un fichier `Makefile` a été rédigé, qui permet de synthétiser des commandes compliquées. 
`make` ou `make all`: les exécutables sont crées
`make run`: le programme est lancé
`make clean`: les exécutables sont supprimés

Il est important à noter que ces commandes ne sont valides qu'à la source du projet sur une machine Linux (ou Windows avec les outils nécessaires installés).



Le programme est divisé en plusieurs fichiers, permettant de diviser le code source de façon logique.
`main.c`: est le cœur du programme, il met en place l'interface permettant de gérer les paramètres, jouer une partie ou quitter le jeu
`game.c`: est le responsable d'une partie, il comporte toutes les fonctions nécessaires à son bon déroulement
`bubble.c`: est une bibliothèque annexe, elle implémente un tri de tableau de type bubble sort

Pour avoir un rapide aperçu des utilités de leurs fonctions, il est posible de consulter le header de chaque fichier (hors le main)



## Fonctionnalités

Le projet implémente différentes fonctionnalités répartie en fonctions.

### Le menu principal

Le menu principal, stocké dans le fichier `main.c` débute par un message d'accueil et l'initialisation des différentes valeurs, notamment le timeur permettant d'obtenir des valeurs aléatoires : `srand(time(NULL));`. C'est lors de cette étape que la fonction `paramètre` demande au joueur de saisir le nombre de dés qui seront jouer lors de la partie lancée automatiquement après. A la fin de la partie, le joueur a la possibilité de quitter le programme, rejouer une partie ou modifier les paramètres. Il fait savoir au programme son choix à l'aide d'un chiffre de 1 à 3. Une réponse non conforme renverra le choix des option à l'utilisateur.

### Une partie de dice poker

Une partie de dice poker est composée d'un certain nombre de manche. Lorsqu'une manche est lancée, celle-ci commence par attribuer un jet aléatoire à chaque participant (le joueur et l'ordinateur). Pour améliorer la lisibilité, chaque jet est trié avant d'être analysé. Lorsque les informations sur chaque jet sont affichées (le propriétaire, sa composante et les différents pattern qui le compose), le joueur a la possibilité de rejouer des dés. Pour cela, il indique une série de 0 (laisser) et 1 (relancer) pour définir les dés à relancer, dans l'ordre qu'ils apparaissent à la console. Si le joueur ne souhaite pas rejouer ses dés, il peut simplement taper 0. Si le joueur souhaite relancer tous ses dés, il peut simplement taper 1. Une fois satisfait (ou le nombre de relance épuisé) le gagnant est élu et la manche suivante débute.

### Le tri bubble sort

Afin de rendre le programme plus efficace, la fonctionnalité de tri a été améliorée en implémentant le bubble sort. Le concept est très simple : tant que le tableau n'est pas trié, on échange de places deux voisins qui ne sont pas dans l'ordre croissant. Cela permet de diminuer les opérations à réaliser sur le tableau.