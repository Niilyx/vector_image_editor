//
// Created by Idir on 12/05/2023.
//
#include <stdlib.h>

#include "pixel.h"
#include "shapes.h"

Pixel *create_pixel(int px, int py) {
    Pixel *p = malloc(sizeof(Pixel));
    p->px = px;
    p->py = py;
    return p;
}

void delete_pixel(Pixel * pixel) {
    free(pixel);
}

Pixel** create_shape_to_pixel(Shape* shape, int* final_size) {

}

void delete_pixel_shape(Pixel** pixels, int size) {
    for (int i = 0; i < size; ++i) {
        free(pixels[i]);
    }
    free(pixels);
}

void pixel_point(Shape* shape, Pixel** pixels, int* size) {
    Point* point = shape->ptr_shape;
    (*size)++;
    pixels = realloc(pixels, sizeof(Pixel*) * (*size));
    pixels[*size - 1] = create_pixel(point->x, point->y);
}

void pixel_line(Shape* shape, Pixel** pixels, int* size) {
    Line* line = shape->ptr_shape;
}

void pixel_square(Shape* shape, Pixel** pixels, int* size) {
    Square* square = shape->ptr_shape;

}

void pixel_rectangle(Shape* shape, Pixel** pixels, int* size) {
    Rectangle* rectangle = shape->ptr_shape;
}

void pixel_circle(Shape* shape, Pixel** pixels, int* size) {
    Circle* circle = shape->ptr_shape;
}

