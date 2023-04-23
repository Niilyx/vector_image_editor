//
// Created by Idir on 21/04/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_SHAPES_H
#define VECTOR_IMAGE_EDITOR_SHAPES_H

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
    Point *center;
    int radius;
} Circle;

typedef struct {
    Point *start;
    int size;
    // float angle;
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
    void *ptr_shape;
} Shape;


typedef struct {
    int size_x;
    int size_y;

    Shape **shapes;
    int nb_shapes;
} Drawing;

// all functions
Point* create_point(int x, int y);
void delete_point(Point *point);
void print_point(Point *p);

Line* create_line(Point *p1, Point *p2);
void delete_line(Line *line);
void print_line(Line *l);

Circle* create_circle(Point *start, int radius);
void delete_circle(Circle *circle);
void print_circle(Circle *c);

Square* create_square(Point *start, int size);
void delete_square(Square *square);
void print_square(Square *s);

Rectangle* create_rectangle(Point *start, int length, int height);
void delete_rectangle(Rectangle *rectangle);
void print_rectangle(Rectangle *r);

Polygon* create_polygon(Point *points[], int nb_points);
void delete_polygon(Polygon *polygon);
void print_polygon(Polygon *p);

extern Drawing *drawing;

#endif //VECTOR_IMAGE_EDITOR_SHAPES_H
