//
// Created by Idir on 21/04/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "print_utils.h"
#include "../shapes.h"
#include "../states.h"

#include "../Common.h"
#include "scan_utils.h"
#include "../id.h"

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
    printf("\n\tQ- Quitter");
    newline();
}

void listen_canvas_menu() {
    char choice;

    while (1) {
        fflush(stdin);
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
            case 'a': {
                if (drawing->nb_shapes < 256)
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
                printf("\n\tC- Supprimer une forme");
                printf("\n\tD- Tracer le dessin (non fait pour l'instant !)");
                newline();
                printf("\n\tQ- Quitter");
                newline();
                break;
            }
        }
    }
}

void print_add_shape_menu() {
    printf("\nVeuillez choisir une forme a ajouter :");
    printf("\n\tA- Point");
    printf("\n\tB- Ligne");
    printf("\n\tC- Carre");
    printf("\n\tD- Rectangle");
    printf("\n\tE- Cercle");
    printf("\n\tF- Polygone");
    newline();
    printf("\n\tQ- Annuler");
    newline();
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
                point_shape->id = get_next_id();
                point_shape->shape_type = POINT;

                drawing->nb_shapes++;
                drawing->shapes[drawing->nb_shapes - 1] = point_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'B':
            case 'b': { // Ajouter une ligne
                int x1, y1, x2, y2;
                scan_point(&x1, &y1, 1);
                scan_point(&x2, &y2, 2);

                Shape* line_shape = create_line_shape(x1, y1, x2, y2);
                line_shape->id = get_next_id();
                line_shape->shape_type = LINE;

                drawing->nb_shapes++;
                drawing->shapes[drawing->nb_shapes - 1] = line_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'C':
            case 'c': { // Ajouter un carré
                int x, y, len;
                scan_point(&x, &y, 1);
                scan_length(&len, 1);

                Shape* square_shape = create_square_shape(x, y, len);
                square_shape->id = get_next_id();
                square_shape->shape_type = SQUARE;

                drawing->nb_shapes++;
                drawing->shapes[drawing->nb_shapes - 1] = square_shape;

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
                rectangle_shape->id = get_next_id();
                rectangle_shape->shape_type = RECTANGLE;

                drawing->nb_shapes++;
                drawing->shapes[drawing->nb_shapes - 1] = rectangle_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'E':
            case 'e': { // Ajouter un cercle
                int x, y, radius;
                scan_point(&x, &y, 1);
                scan_length(&radius, 1);

                Shape* circle_shape = create_circle_shape(x, y, radius);
                circle_shape->id = get_next_id();
                circle_shape->shape_type = CIRCLE;

                drawing->nb_shapes++;
                drawing->shapes[drawing->nb_shapes - 1] = circle_shape;

                current_state = ON_CANVAS;
                return;
            }
            case 'F':
            case 'f': { // Ajouter un polygone
                int nb_pts;
                scan_points_number(&nb_pts);

                int* coord_tab = (int *) malloc(nb_pts * 2 * sizeof(int));

                for (int i = 0; i < nb_pts; i++) {
                    scan_point(&coord_tab[i], &coord_tab[i+1], i + 1);
                }

                Shape* polygon_shape = create_polygon_shape(coord_tab, nb_pts);
                polygon_shape->id = get_next_id();
                polygon_shape->shape_type = POLYGON;

                drawing->nb_shapes++;
                drawing->shapes[drawing->nb_shapes - 1] = polygon_shape;

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