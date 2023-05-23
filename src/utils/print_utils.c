//
// Created by Idir on 21/04/2023.
//
// Utilitaires d'affichage. La plupart des fonctions sont inutilisées

#include <stdio.h>
#include "print_utils.h"
#include "../shapes.h"

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
    printf("\n\n\tVoici la liste des formes :");
    for (int i = 0; i < area->nb_shapes; i++) {
        printf("\n\t\tID %d : ", area->shapes[i]->id);
        print_shape(area->shapes[i]);
    }
    newline();
    newline();
    newline();
}


// ##########################################################

void print_canvas() {
    for (int y = 0; y < area->size_y; y++) {
        for (int x = 0; x < area->size_x; x++) {
            if (area->mat[y][x] == 1) {
                printf(" X");
            } else {
                printf(" .");
            }
        }
        newline();
    }
}

void print_prompt() {
    newline();
    printf(">> ");
}

void print_help() {
    newline();
    printf("Voici la liste des commandes disponibles :");
    newline();
    printf("\n\t- point x y : ajoute un point");
    printf("\n\t- line x1 y1 x2 y2 : ajoute un segment reliant deux points (x1, y1) et (x2, y2)");
    printf("\n\t- circle x y radius : ajoute un cercle de centre (x, y) et de rayon radius");
    printf("\n\t- square x y length : ajoute un carre dont le coin superieur gauche est (x, y) et de cote length.");
    printf("\n\t- rectangle x y width height : ajoute un rectangle dont le coin superieur gauche est (x, y), de largeur width et de longueur height");
    printf("\n\t- polygon x1 y1 x2 y2 x3 y3 ... ... : ajoute un polygone avec la liste des points donnes");
    printf("\n\t- plot : affiche le dessin");
    printf("\n\t- list : liste les formes du dessin");
    printf("\n\t- delete id : supprime une forme d'identifiant (id) si elle existe");
    printf("\n\t- clear : efface l'ecran");
    printf("\n\t- erase : supprime toutes les formes du dessin");
    newline();
    printf("\n\t- help : affiche la liste des commandes disponibles");
    newline();
    printf("\n\t- quit : quitte le programme");
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

void error_msg() {
    printf("\nSyntaxe incorrecte. Utilisez la commande \"help\" pour plus d'informations.");
}