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

void pixel_point(Shape* shape, Pixel*** pixels, int* size) {
    Point* point = shape->ptr_shape;
    (*size)++;
    *pixels = realloc(*pixels, sizeof(Pixel*) * (*size));
    *pixels[*size - 1] = create_pixel(point->x, point->y);
}

void pixel_line(Shape* shape, Pixel*** pixels, int* nb_pixels) {
    Line* line = shape->ptr_shape;

    int x, y, dx, dy;
    float e, e_10, e_01;
    dy = line->p2->y - line->p1->y;
    dx = line->p2->x - line->p1->x;
    y = line->p1->y;
    e = 0.f;
    e_10 = (float) dy / (float) dx;
    e_01 = -1.f;

    for (x = line->p1->x; x <= line->p2->x; ++x) {
        *pixels = realloc(*pixels, sizeof(Pixel*) * (*nb_pixels + 1));
        (*pixels)[(*nb_pixels)++] = create_pixel(x, y);
        e += e_10;
        if ((e = e+e_10) >= 0.5f) {
            y++;
            e += e_01;
        }
    }
}

void pixel_square(Shape* shape, Pixel*** pixels, int* size) {
    Square* square = shape->ptr_shape;

    int nb_pix_to_draw = 4*(square->size - 1);
    *pixels = (Pixel**) realloc(*pixels, (*size + nb_pix_to_draw) * sizeof(Pixel*));

    for (int i = 0; i < square->size; ++i) {
        (*pixels)[(*size)++] = create_pixel(square->origin->x + i, square->origin->y);
        (*pixels)[(*size)++] = create_pixel(square->origin->x + i, square->origin->y + square->size - 1);
    }
    for (int i = 1; i < square->size -1; ++i) {
        (*pixels)[(*size)++] = create_pixel(square->origin->x, square->origin->y);
        (*pixels)[(*size)++] = create_pixel(square->origin->x + square->size - 1, square->origin->y + i);
    }
}

void pixel_rectangle(Shape* shape, Pixel*** pixels, int* size) {
    Rectangle* rectangle = shape->ptr_shape;

    int nb_pix_to_draw = 2 * (rectangle->length + rectangle->height) - 4;
    *pixels = (Pixel**) realloc(*pixels, (*size + nb_pix_to_draw) * sizeof(Pixel*));

    for (int i = 0; i < rectangle->length; ++i) {
        (*pixels)[(*size)++] = create_pixel(rectangle->origin->x + i, rectangle->origin->y);
        (*pixels)[(*size)++] = create_pixel(rectangle->origin->x + i, rectangle->origin->y + rectangle->height - 1);
    }

    for (int i = 1; i < rectangle->height -1; ++i) {
        (*pixels)[(*size)++] = create_pixel(rectangle->origin->x, rectangle->origin->y);
        (*pixels)[(*size)++] = create_pixel(rectangle->origin->x + rectangle->length - 1, rectangle->origin->y + i);
    }
}

void pixel_circle(Shape* shape, Pixel*** pixels, int* size) {
    Circle* circle = shape->ptr_shape;
    int x = 0, y = circle->radius;
    int delta = circle->radius - 1;

    while (y >= x) {
        *pixels = (Pixel**) realloc(*pixels, (*size + 8) * sizeof(Pixel*));
        (*pixels)[(*size)++] = create_pixel(circle->center->x + x, circle->center->y + y);
        (*pixels)[(*size)++] = create_pixel(circle->center->x + y, circle->center->y + x);
        (*pixels)[(*size)++] = create_pixel(circle->center->x - x, circle->center->y + y);
        (*pixels)[(*size)++] = create_pixel(circle->center->x - y, circle->center->y + x);

        (*pixels)[(*size)++] = create_pixel(circle->center->x + x, circle->center->y - y);
        (*pixels)[(*size)++] = create_pixel(circle->center->x + y, circle->center->y - x);
        (*pixels)[(*size)++] = create_pixel(circle->center->x - x, circle->center->y - y);
        (*pixels)[(*size)++] = create_pixel(circle->center->x - y, circle->center->y - x);

        if (delta >= 2 * x) {
            delta -= 2 * x + 1;
            x++;
        } else if (delta < 2 * (circle->radius - y)) {
            delta += 2 * y - 1;
            y--;
        } else {
            delta += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

void pixel_polygon(Shape* shape, Pixel*** pixels, int* size) {
    Polygon *polygon = shape->ptr_shape;

    for (int i = 0; i < polygon->nb_points - 1; ++i) {
        pixel_line(create_line_shape(polygon->points[i]->x, polygon->points[i]->y, polygon->points[i+1]->x, polygon->points[i+1]->y), pixels, size);
    }
}

void delete_pixel_shape(Pixel*** pixels, int nb_pixels) {
    for (int i = 0; i < nb_pixels; ++i) {
        free((*pixels)[i]);
    }
    free(*pixels);
    free(pixels);
}

Pixel** create_shape_to_pixel(Shape* shape, int* final_size) {
    Pixel** pixels = malloc(sizeof(Pixel*));
    *final_size = 0;
    switch (shape->shape_type) {
        case POINT:
            pixel_point(shape, &pixels, final_size);
            break;
        case LINE:
            pixel_line(shape, &pixels, final_size);
            break;
        case RECTANGLE:
            pixel_rectangle(shape, &pixels, final_size);
            break;
        case CIRCLE:
            pixel_circle(shape, &pixels, final_size);
            break;
        case POLYGON:
            pixel_polygon(shape, &pixels, final_size);
            break;
        default:
            break;
    }
    return pixels;
}