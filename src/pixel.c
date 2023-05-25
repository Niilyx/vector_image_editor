//
// Created by Idir on 12/05/2023.
//
// Tout ce qui touche à la conversion des Shapes du dessin en vrais pixels affichables sur la console

#include <stdlib.h>

#include "pixel.h"
#include "shapes.h"
#include "utils/math.h"

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

// Algorithme de Nicolas Flasque
void pixel_line(Shape * shape, Pixel*** pixels, int* size) {
    Line* line = shape->ptr_shape;

    int dx, dy;
    int x, y;

    int k=0;

    if (line->p2->x >= line->p1->x){
        dx = line->p2->x - line->p1->x;
        dy = line->p2->y - line->p1->y;
        x = line->p1->x;
        y = line->p1->y;
    } else {
        dx = line->p1->x - line->p2->x;
        dy = line->p1->y - line->p2->y;
        x = line->p2->x;
        y = line->p2->y;
    }

    int dmin = min(dx,abs(dy));
    int dmax = max(dx,abs(dy));
    int nb_segs = dmin + 1;
    int* segments = malloc(nb_segs * sizeof(int));

    for (int i = 0; i < nb_segs; i++){
        segments[i] = (dmax + 1) / nb_segs;
    }

    int restants = (dmax + 1) % nb_segs;
    int* cumuls = malloc(nb_segs * sizeof(int));
    cumuls[0] = 0;

    for (int i = 1; i < nb_segs; i++){
        cumuls[i] = ((i * restants) % nb_segs > ((i + 1) * restants) % nb_segs);
        segments[i] = segments[i] + cumuls[i];
    }


    if (dy < 0){ // On trace vers le bas
        if (dx > abs(dy)){ // Les segments sont horizontaux
            for (int i = 0; i < nb_segs; i++) {
                for (int j = 0; j < segments[i]; j++) {
                    *pixels = realloc(*pixels, ((*size) + 1) * sizeof(Pixel*));
                    (*pixels)[(*size)++] = create_pixel(x + k++, y - i);
                }
            }
        } else { // Les segments sont verticaux
            for (int i = 0; i < nb_segs; i++){
                for (int j = 0; j < segments[i]; j++){
                    *pixels = realloc(*pixels, ((*size) + 1) * sizeof(Pixel*));
                    (*pixels)[(*size)++] = create_pixel(x + i, y - k++);
                }
            }
        }
    } else { // On trace vers le haut
        if (dx > dy) { // Les segments sont horizontaux
            for(int i = 0; i < nb_segs; i++){
                for(int j = 0; j < segments[i]; j++){
                    *pixels = realloc(*pixels, ((*size) + 1) * sizeof(Pixel*));
                    (*pixels)[(*size)++] = create_pixel(x + k++, y + i);
                }
            }
        }
        else{ // Les segments sont verticaux
            for (int i = 0; i < nb_segs; i++){
                for (int j = 0; j < segments[i]; j++){
                    *pixels = realloc(*pixels, ((*size) + 1) * sizeof(Pixel*));
                    (*pixels)[(*size)++] = create_pixel(x + i, y + k++);
                }
            }
        }
    }
}

void pixel_square(Shape* shape, Pixel*** pixels, int* size) {
    Square* square = shape->ptr_shape;

    int nb_pix_to_draw = 4*(square->size - 1); // on fait - 1 car sinon on compte 2 fois les coins
    *pixels = (Pixel**) realloc(*pixels, (*size + nb_pix_to_draw) * sizeof(Pixel*));

    for (int i = 0; i < square->size; ++i) {
        (*pixels)[(*size)++] = create_pixel(square->origin->x + i, square->origin->y);
        (*pixels)[(*size)++] = create_pixel(square->origin->x + i, square->origin->y + square->size - 1);
    }
    for (int i = 1; i < square->size -1; ++i) {
        (*pixels)[(*size)++] = create_pixel(square->origin->x, square->origin->y + i);
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
        (*pixels)[(*size)++] = create_pixel(rectangle->origin->x, rectangle->origin->y + i);
        (*pixels)[(*size)++] = create_pixel(rectangle->origin->x + rectangle->length - 1, rectangle->origin->y + i);
    }
}

// Algorithme de Bresenham pour tracer un cercle
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

    for (int i = 0; i < polygon->nb_points; ++i) {
        Point* start = polygon->points[i];
        Point* end;
        if (i != polygon->nb_points - 1)
            end = polygon->points[i + 1];
        else
            end = polygon->points[0];
        Shape * line = create_line_shape(start->x, start->y, end->x, end->y);
        pixel_line(line, pixels, size);
        free(line);
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
        case SQUARE:
            pixel_square(shape, &pixels, final_size);
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