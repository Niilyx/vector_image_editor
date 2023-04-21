//
// Created by Idir on 21/04/2023.
//

#include <stdio.h>
#include "print_utils.h"

void newline() {
    printf("\n");
}

void print_main_menu() {
    printf("\n###################################");
    printf("\n##                               ##");
    printf("\n##    LE TITRE DU PROJET !!!!!!  ##");
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

void print_about() {
    printf("\nPour dessiner des images vectorielles, allons donc.");
}