//
// Created by Idir on 12/05/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_AREA_H
#define VECTOR_IMAGE_EDITOR_AREA_H

#include "shapes.h"

#define SHAPE_MAX 100 // Nombre maximum de formes
#define BOOL int

typedef struct {
    unsigned int size_x;
    unsigned int size_y;
    BOOL** mat;
    Shape* shapes[SHAPE_MAX]; // arbitraire, et sera changé sur implémentation de la liste chainée
    int nb_shapes;
} Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

Shape* get_shape(Area* area, int id, int* index);
#endif //VECTOR_IMAGE_EDITOR_AREA_H
