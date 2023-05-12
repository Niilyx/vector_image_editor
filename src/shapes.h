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
    Point *origin;
    int size;
    // float angle;
} Square;

typedef struct {
    Point *origin;
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

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(const int lst[], int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#endif //VECTOR_IMAGE_EDITOR_SHAPES_H
