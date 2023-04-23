//
// Created by Idir on 21/04/2023.
//

#include <stdio.h>
#include "print_utils.h"
#include "../states.c"

void newline() {
    printf("\n");
}

void print_main_menu() {
    printf("\n###################################");
    printf("\n##                               ##");
    printf("\n##   LE TITRE DU PROJET !!!!!!   ##");
    printf("\n##                               ##");
    printf("\n##                               ##");
    printf("\n##                               ##");
    printf("\n###################################");
    printf("\nBonjour ! Que souhaiteriez-vous faire ?");
    printf("\n\t1. Nouveau dessin");
    newline();
    printf("\n\t2. À propos");
}

void listen_main_menu() {
    int choice;

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                fflush(stdin);
                current_state = CHOOSE_SIZE;
                return;
            }
            case 2: {
                printf("À propos");
                return;
            }
            default: {
                printf("\nQue souhaiteriez-vous faire ?");
                printf("\n\t1. Nouveau dessin");
                newline();
                printf("\n\t2. À propos");
                break;
            }
        }
    }
}

void print_choose_size() {
    printf("\nChoisissez la taille de votre dessin (entre 10 et 50) : ");
}

void listen_choose_size() {
    int size;

    while (1) {
        scanf("%d", &size);
        if (size >= 10 && size <= 50) {
            current_state = MAIN_MENU;
            return;
        } else {
            printf("\nChoisissez la taille de votre dessin (entre 10 et 50) : ");
        }
    }
}

void print_about() {
    printf("\nPour dessiner des images vectorielles, allons donc.");
}



// ##########################################################

void print_canvas() {

}

void print_canvas_menu() {
    printf("\nVeillez choisir une action :");
    printf("\n\tA- Ajouter une forme");
    printf("\n\tB- Afficher la liste des formes");
    printf("\n\tC- Suprrimer une forme");
    printf("\n\tD- Tracer le dessin (non fait pour l'instant !)");
    printf("\n\tE- Aide");
}

void listen_canvas_menu() {
    char choice;

    while (1) {
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
            case 'a': {
                current_state = ADD_SHAPE;
                return;
            }
            case 'B':
            case 'b': {
                current_state = SHOW_SHAPES;
                return;
            }
            case 'C':
            case 'c': {
                current_state = DELETE_SHAPE;
                return;
            }
            case 'D':
            case 'd': {
                current_state = DRAW;
                return;
            }
            case 'E':
            case 'e': {
                current_state = HELP;
                return;
            }
            default: {
                printf("\nVeillez choisir une action :");
                printf("\n\tA- Ajouter une forme");
                printf("\n\tB- Afficher la liste des formes");
                printf("\n\tC- Suprrimer une forme");
                printf("\n\tD- Tracer le dessin (non fait pour l'instant !)");
                printf("\n\tE- Aide");
                break;
            }
        }
    }
}