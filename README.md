# Dice Poker

February 2022

Alexandra Demski

**[Github Deposit of the project](https://github.com/alexandra-demski/Dice-Poker/)**

## Introduction

The dice poker is a variation of the poker game that uses dices instead of cards. The goal is to implement the game allowing the user to play against the computer. The game includes multiple rounds where the player and the computer will roll a certain number of dices, a number choosed by the player beforehand, and will try to make combinations by rolling again some of the dices or none.

## Organization

The project breaks down into three packages : `bin`, `include` and `src`.

`src`: source code
`bin`: executable files
`include` : headers managing dependencies



In order to simplify the compilation and execution of the program, a `Makefile` was draft, synthesizing complex command lines.
`make` or `make all`: create executable files
`make run`: launch the program
`make clean`: delete all executable files

It is important to note that these commands are only valid at the root of the project and on Linux machines only (or Windows machines with the necessary tools).



The project is divided into several files.
`main.c`: is the main menu of the game, the user can either set parameters, launch a game or quit the program.
`game.c`: is responsible of a game, it includes all the functions needed for a round of dice poker.
`bubble.c`: is a complementary library, implementing a bubble sort.

In order to get a quick overview of all the functions in a file, you can view the header files.



## Functionnalities

The project implements several functionnalities

### The main menu

The main menu is implemented in the `main.c` file. It starts with a welcoming message and the initialization of several variables, including a timer used to get random values : `srand(time(NULL));`. Before the beggining of a round, the player can choose the number of dice to play with, thanks to the `parametre` function. Then, a round is automatically launched. When the number of rounds reaches the maximum, the game ends and the player can either play again, change the parameters or quit the program by tapping 1, 2 or 3. If an incorrect answer is given, the program will ask the question again.

### A round of dice poker

A game of dice poker is divided into several rounds. Each round begins with a random dice roll for each participant (the player and the computer). In order to enhance the lisibility, each dice roll is arranged in ascending order before being analyzed by the program. When all the nedded information about a dice roll is displayed (its owner, composition and pattern), the player has the possibility to roll some dices again. In order to do so, the player has to type a serie of 0 (leave be) and 1 (roll again) to define the dices to reroll, in the same ordre as they were put in the command line console. If the player doesn't want to change its roll dice, they can simply type 0. If they want to reroll all the dices, they can simply type 1. After changing the dices, the winner is selected and the next round starts.

### The bubble sort

In order to enhance the efficiency of the project, the arrays are sorted with a bubble sort. The concept is pretty simple : while the array is not sorted, neighboring cells are swapped if they aren't in the correct order. It reduces the number of operations needed to sort an array.
