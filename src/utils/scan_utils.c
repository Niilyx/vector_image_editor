//
// Created by Niilyx on 23/04/2023.
//

#include <stdio.h>
#include "scan_utils.h"

void scan_point(int* a, int* b, int n) {
    printf("Entrez x%d y%d : ", n, n);
    fflush(stdin);
    scanf("%d %d", a, b);
}

void scan_length(int* a, int n) {
    int choice = -1;
    while (choice < 0) {
        fflush(stdin);
        printf("Entrez la longueur de la ligne %d : ", n);
        scanf("%d", &choice);
    }
    *a = choice;
}

void scan_points_number(int* a) {
    int choice = -1;
    while (choice < 3) {
        fflush(stdin);
        printf("Entrez le nombre de points (entre 3 et environ 37000) : ");
        scanf("%d", &choice);
    }
    *a = choice;
}