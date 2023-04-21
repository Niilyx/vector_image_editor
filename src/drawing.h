//
// Created by Idir on 21/04/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_DRAWING_H
#define VECTOR_IMAGE_EDITOR_DRAWING_H

typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *p1;
    Point *p2;
} Line;

typedef struct {
    Point *start;
    int radius;
} Circle;

typedef struct {
    Point *start;
    int size_x;
    int size_y;
} Square;

typedef struct {
    Point *start;
    int length;
    int height;
} Rectangle;

typedef struct {
    Point **points;
    int nb_points;
} Polygon;

typedef struct {
    int id;
    SHAPE_TYPE shape_type;
    void *ptrShape;
} Shape;


typedef struct {
    int size_x;
    int size_y;
} Drawing;

#endif //VECTOR_IMAGE_EDITOR_DRAWING_H
