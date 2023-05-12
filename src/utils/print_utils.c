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
#include "../area.h"

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

void print_choose_size() {
    printf("\nChoisissez la taille de votre dessin (entre 10,10 et 50,50) : ");
}

void print_about() {
    printf("\nPour dessiner des images vectorielles, allons donc.\n");
}

void print_shapes() {
    if (area->nb_shapes == 0) {
        printf("\n\tIl n'y a pas de formes dans le dessin.\n");
        return;
    }
    printf("\n\n\n\n\tVoici la liste des formes :");
    for (int i = 0; i < area->nb_shapes; i++) {
        printf("\n\t\t%d : ", i + 1);
        switch (area->shapes[i]->shape_type) {
            case POINT: {
                Point *point = (Point *) area->shapes[i]->ptr_shape;
                print_point(point);
                break;
            }
            case LINE: {
                Line *line = (Line *) area->shapes[i]->ptr_shape;
                print_line(line);
                break;
            }
            case SQUARE: {
                Square *square = (Square *) area->shapes[i]->ptr_shape;
                print_square(square);
                break;
            }
            case RECTANGLE: {
                Rectangle *rectangle = (Rectangle *) area->shapes[i]->ptr_shape;
                print_rectangle(rectangle);
                break;
            }
            case CIRCLE: {
                Circle *circle = (Circle *) area->shapes[i]->ptr_shape;
                print_circle(circle);
                break;
            }
            case POLYGON: {
                Polygon *polygon = (Polygon *) area->shapes[i]->ptr_shape;
                print_polygon(polygon);
                break;
            }
        }
    }
    newline();
    newline();
    newline();
}


// ##########################################################

void print_canvas() {

}

void print_canvas_menu() {
    printf("\nVeuillez choisir une action :");
    printf("\n\tA- Ajouter une forme");
    printf("\n\tB- Afficher la liste des formes");
    printf("\n\tC- Supprimer une forme (non fait pour l'instant !)");
    printf("\n\tD- Tracer le dessin (non fait pour l'instant !)");
    newline();
    printf("\n\tQ- Quitter");
    newline();
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

