//
// Created by Niilyx on 23/04/2023.
//

#include <stdio.h>
#include <stdlib.h>

#include "print_utils.h"
#include "scan_utils.h"

#include "../Common.h"

/*
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
*/
void listen_main_menu() {
    int choice = 0;

    fflush(stdin);
    scanf("%d", &choice);
    while (1) {
        switch (choice) {
            case 1: {
                fflush(stdout);
                current_state = CHOOSE_SIZE;
                area = (Area*) malloc(sizeof(Area));
                area->nb_shapes = 0;
                return;
            }
            case 2: {
                print_about();
                return;
            }
            case 99: {
                printf("Au revoir !");
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

void listen_choose_size() {
    int size_x = 0, size_y = 0;

    while (1) {
        fflush(stdin);
        scanf("%d,%d", &size_x, &size_y);
        if (10 <= size_x && size_x <= 50 && 10 <= size_y && size_y <= 50) {
            current_state = ON_CANVAS;

            area = create_area(size_x, size_y);
            return;
        } else {
            printf("\nChoisissez la taille de votre dessin (entre 10,10 et 50,50) : ");
        }
    }
}

/*
void listen_canvas_menu() {
    char choice;

    while (1) {
        fflush(stdin);
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
            case 'a': {
                if (area->nb_shapes < 256)
                    current_state = ADD_SHAPE;
                else
                    printf("\n\tVous avez atteint le nombre maximum de formes dans le dessin !");
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
            case 'Q':
            case 'q': {
                exit(0);
            }
            default: {
                printf("\nVeuillez choisir une action :");
                printf("\n\tA- Ajouter une forme");
                printf("\n\tB- Afficher la liste des formes");
                printf("\n\tC- Supprimer une forme (non fait pour l'instant !)");
                printf("\n\tD- Tracer le dessin (non fait pour l'instant !)");
                newline();
                printf("\n\tQ- Quitter");
                newline();
                break;
            }
        }
    }
}


void listen_add_shape_menu() {
    char choice;

    while (1) {
        fflush(stdin);
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
            case 'a': { // Ajouter un point
                int x, y;
                scan_point(&x, &y, 1);
                Shape* point_shape = create_point_shape(x, y);
                point_shape->shape_type = POINT;

                area->nb_shapes++;
                area->shapes[area->nb_shapes - 1] = point_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'B':
            case 'b': { // Ajouter une ligne
                int x1, y1, x2, y2;
                scan_point(&x1, &y1, 1);
                scan_point(&x2, &y2, 2);

                Shape* line_shape = create_line_shape(x1, y1, x2, y2);
                line_shape->shape_type = LINE;

                area->nb_shapes++;
                area->shapes[area->nb_shapes - 1] = line_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'C':
            case 'c': { // Ajouter un carré
                int x, y, len;
                scan_point(&x, &y, 1);
                scan_length(&len, 1);

                Shape* square_shape = create_square_shape(x, y, len);
                square_shape->shape_type = SQUARE;

                area->nb_shapes++;
                area->shapes[area->nb_shapes - 1] = square_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'D':
            case 'd': { // Ajouter un rectangle
                int x, y, length, height;
                scan_point(&x, &y, 1);
                scan_length(&length, 1);
                scan_length(&height, 2);

                Shape* rectangle_shape = create_rectangle_shape(x, y, length, height);
                rectangle_shape->shape_type = RECTANGLE;

                area->nb_shapes++;
                area->shapes[area->nb_shapes - 1] = rectangle_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'E':
            case 'e': { // Ajouter un cercle
                int x, y, radius;
                scan_point(&x, &y, 1);
                scan_length(&radius, 1);

                Shape* circle_shape = create_circle_shape(x, y, radius);
                circle_shape->shape_type = CIRCLE;

                area->nb_shapes++;
                area->shapes[area->nb_shapes - 1] = circle_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'F':
            case 'f': { // Ajouter un polygone
                int nb_pts;
                scan_points_number(&nb_pts);

                int* tab_x = (int *) malloc(nb_pts * sizeof(int));
                int* tab_y = (int *) malloc(nb_pts * sizeof(int));

                for (int i = 0; i < nb_pts; i++) {
                    scan_point(&tab_x[i], &tab_y[i], i + 1);
                }

                int* coord_tab = (int *) malloc(2 * nb_pts * sizeof(int));
                for (int i = 0; i < nb_pts; i++) {
                    coord_tab[2 * i] = tab_x[i];
                    coord_tab[2 * i + 1] = tab_y[i];
                }

                Shape* polygon_shape = create_polygon_shape(coord_tab, nb_pts);
                polygon_shape->shape_type = POLYGON;

                area->nb_shapes++;
                area->shapes[area->nb_shapes - 1] = polygon_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'Q':
            case 'q': {
                current_state = ON_CANVAS;
                return;
            }
            default: {
                printf("\nVeuillez choisir une forme à ajouter :");
                printf("\n\tA- Point");
                printf("\n\tB- Ligne");
                printf("\n\tC- Carre");
                printf("\n\tD- Rectangle");
                printf("\n\tE- Cercle");
                printf("\n\tF- Polygone");
                newline();
                printf("\n\tQ- Annuler");
                newline();
                break;
            }
        }
    }
}
 */