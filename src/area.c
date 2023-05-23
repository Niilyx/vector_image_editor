//
// Created by Idir on 12/05/2023.
//

#include <stdlib.h>
#include <stdio.h>

#include "shapes.h"
#include "area.h"
#include "pixel.h"

Area* create_area(unsigned int width, unsigned int height) {
    Area *a = malloc(sizeof(Area));
    a->size_x = width;
    a->size_y = height;
    a->mat = malloc(sizeof(int*) * width);
    for (int i = 0; i < width; ++i) {
        a->mat[i] = malloc(sizeof(int) * height);
        for (int j = 0; j < height; ++j) {
            a->mat[i][j] = 0;
        }
    }
    a->nb_shapes = 0;
    return a;
}

void add_shape_to_area(Area* area, Shape* shape) {
    if (area->nb_shapes >= SHAPE_MAX) {
        printf("\nErreur : il y a trop de formes sur le dessin");
        return;
    }
    area->shapes[(area->nb_shapes)++] = shape;
}

void clear_area(Area* area) {
    for (int i = 0; i < area->size_x; ++i) {
        for(int j = 0; j < area->size_y; ++j) {
            area->mat[i][j] = 0;
        }
    }
}

void erase_area(Area* area) {
    for (int i = 0; i < area->nb_shapes; ++i) {
        delete_shape(area->shapes[i]);
    }
    area->nb_shapes = 0;
}

void delete_area(Area* area) {
    erase_area(area);
    for (int i = 0; i < area->size_y; ++i) {
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);
}

void draw_area(Area* area) {
    for (int i = 0; i < area->nb_shapes; ++i) {
        Pixel** pixels;
        int n;
        pixels = create_shape_to_pixel(area->shapes[i], &n);

        for (int j = 0; j < n; ++j) {
            area->mat[pixels[j]->py][pixels[j]->px] = 1;
        }
    }
}

void print_area(Area* area) {
    for (int i = 0; i < area->size_y; i++) {
        for (int j = 0; j < area->size_x; j++) {
            if (area->mat[i][j]) printf("#");
            else printf(".");
            printf(" ");
        }
        printf("\n");
    }
}

Shape* get_shape(Area* area, int id, int* index) {
    for (int i = 0; i < area->nb_shapes; ++i) {
        if (area->shapes[i]->id == id) {
            *index = i;
            return area->shapes[i];
        }
    }
    return NULL;
}