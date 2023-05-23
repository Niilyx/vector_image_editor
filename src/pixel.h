//
// Created by Idir on 12/05/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_PIXEL_H
#define VECTOR_IMAGE_EDITOR_PIXEL_H

#include "shapes.h"

typedef struct {
    int px;
    int py;
}Pixel;

Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);

void pixel_point(Shape* shape, Pixel*** pixels, int* size);
void pixel_line(Shape* shape, Pixel*** pixels, int* size);
void pixel_square(Shape* shape, Pixel*** pixels, int* size);
void pixel_rectangle(Shape* shape, Pixel*** pixels, int* size);
void pixel_circle(Shape* shape, Pixel*** pixels, int* size);
void pixel_polygon(Shape* shape, Pixel*** pixels, int* size);

void delete_pixel_shape(Pixel*** pixels, int nb_pixels);
Pixel** create_shape_to_pixel(Shape* shape, int* final_size);


#endif //VECTOR_IMAGE_EDITOR_PIXEL_H
