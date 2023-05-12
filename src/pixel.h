//
// Created by Idir on 12/05/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_PIXEL_H
#define VECTOR_IMAGE_EDITOR_PIXEL_H

typedef struct {
    int px;
    int py;
}Pixel;

Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);


#endif //VECTOR_IMAGE_EDITOR_PIXEL_H
