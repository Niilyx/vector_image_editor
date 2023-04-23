//
// Created by Idir on 21/04/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "print_utils.h"
#include "../shapes.h"
#include "../states.h"

#include "../Common.h"

void newline() {
    printf("\n");
}

void print_main_menu() {
    printf("\n###################################");
    printf("\n##                               ##");
    printf("\n##          PEINTURE.COM         ##");
    printf("\n##                               ##");
    printf("\n##                               ##");
    printf("\n##                               ##");
    printf("\n###################################");
    printf("\nBonjour ! Que souhaiteriez-vous faire ?");
    printf("\n\t1. Nouveau dessin");
    newline();
    printf("\n\t2. A propos");
    newline();
    printf("\n\t99. Quitter");
    newline();
}

void listen_main_menu() {
    int choice = 0;

    fflush(stdin);
    scanf("%d", &choice);
    while (1) {
        switch (choice) {
            case 1: {
                fflush(stdout);
                current_state = CHOOSE_SIZE;
                drawing = (Drawing*) malloc(sizeof(Drawing));
                drawing->nb_shapes = 0;
                return;
            }
            case 2: {
                print_about();
                return;
            }
            case 99: {
                exit(0);
            }
            default: {
                printf("\nQue souhaiteriez-vous faire ?");
                printf("\n\t1. Nouveau dessin");
                newline();
                printf("\n\t2. A propos");
                newline();
                printf("\n\t99. Quitter");
                newline();
                return;
            }
        }
    }
}

void print_choose_size() {
    printf("\nChoisissez la taille de votre dessin (entre 10 et 50) : ");
}

void listen_choose_size() {
    int size = 0;

    while (1) {
        fflush(stdin);
        scanf("%d", &size);
        if (10 <= size && size <= 50) {
            current_state = ON_CANVAS;
            drawing->size_x = size;
            drawing->size_y = size;
            return;
        } else {
            printf("\nChoisissez la taille de votre dessin (entre 10 et 50) : ");
        }
    }
}

void print_about() {
    printf("\nPour dessiner des images vectorielles, allons donc.\n");
}

void print_shapes() {
    if (drawing->nb_shapes == 0) {
        printf("\n\tIl n'y a pas de formes dans le dessin.\n");
        return;
    }
    printf("\n\tVoici la liste des formes :");
    for (int i = 0; i < drawing->nb_shapes; i++) {
        printf("\n\t\t%d : ", i + 1);
        switch (drawing->shapes[i]->shape_type) {
            case POINT: {
                Point *point = (Point *) drawing->shapes[i]->ptr_shape;
                print_point(point);
                break;
            }
            case LINE: {
                Line *line = (Line *) drawing->shapes[i]->ptr_shape;
                print_line(line);
                break;
            }
            case SQUARE: {
                Square *square = (Square *) drawing->shapes[i]->ptr_shape;
                print_square(square);
                break;
            }
            case RECTANGLE: {
                Rectangle *rectangle = (Rectangle *) drawing->shapes[i]->ptr_shape;
                print_rectangle(rectangle);
                break;
            }
            case CIRCLE: {
                Circle *circle = (Circle *) drawing->shapes[i]->ptr_shape;
                print_circle(circle);
                break;
            }
            case POLYGON: {
                Polygon *polygon = (Polygon *) drawing->shapes[i]->ptr_shape;
                print_polygon(polygon);
                break;
            }
        }
    }
}


// ##########################################################

void print_canvas() {

}

void print_canvas_menu() {
    printf("\nVeuillez choisir une action :");
    printf("\n\tA- Ajouter une forme");
    printf("\n\tB- Afficher la liste des formes");
    printf("\n\tC- Supprimer une forme");
    printf("\n\tD- Tracer le dessin (non fait pour l'instant !)");
    newline();
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
                print_shapes();
                return;
            }
            case 'C':
            case 'c': {
                return;
            }
            case 'D':
            case 'd': {
                return;
            }
            default: {
                printf("\nVeuillez choisir une action :");
                printf("\n\tA- Ajouter une forme");
                printf("\n\tB- Afficher la liste des formes");
                printf("\n\tC- Supprimer une forme");
                printf("\n\tD- Tracer le dessin (non fait pour l'instant !)");
                break;
            }
        }
    }
}