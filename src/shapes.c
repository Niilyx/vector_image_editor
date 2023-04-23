//
// Created by Idir on 21/04/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "shapes.h"

// ==================== POINT ====================
Point* create_point(int x, int y) {
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

void delete_point(Point *point) {
    free(point);
}

void print_point(Point *p) {
    printf("POINT %d %d", p->x, p->y);
}

// ==================== LINE ====================
Line* create_line(Point *start, Point *end) {
    Line *l = malloc(sizeof(Line));
    l->p1 = start;
    l->p2 = end;
    return l;
}

void delete_line(Line *line) {
    free(line);
}

void print_line(Line *l) {
    printf("LINE %d %d %d %d", l->p1->x, l->p1->y, l->p2->x, l->p2->y);
}

// ==================== CIRCLE ====================

Circle* create_circle(Point *start, int radius) {
    Circle *c = malloc(sizeof(Circle));
    c->center = start;
    c->radius = radius;
    return c;
}

void delete_circle(Circle *circle) {
    free(circle);
}

void print_circle(Circle *c) {
    printf("CIRCLE %d %d %d", c->center->x, c->center->y, c->radius);
}

// ==================== SQUARE ====================

Square* create_square(Point *start, int size) {
    Square *s = malloc(sizeof(Square));
    s->start = start;
    s->size = size;
    return s;
}

void delete_square(Square *square) {
    free(square);
}

void print_square(Square *s) {
    printf("SQUARE %d %d %d", s->start->x, s->start->y, s->size);
}

// ==================== RECTANGLE ====================

Rectangle* create_rectangle(Point *start, int length, int height) {
    Rectangle *r = malloc(sizeof(Rectangle));
    r->start = start;
    r->length = length;
    r->height = height;
    return r;
}

void delete_rectangle(Rectangle *rectangle) {
    free(rectangle);
}

void print_rectangle(Rectangle *r) {
    printf("RECTANGLE %d %d %d %d", r->start->x, r->start->y, r->length, r->height);
}

// ==================== POLYGON ====================

Polygon* create_polygon(Point *points[], int nb_points) {
    Polygon *p = malloc(sizeof(Polygon));
    p->points = points;
    p->nb_points = nb_points;
    return p;
}

void delete_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->nb_points; ++i) {
        free(polygon->points[i]);
    }
    free(polygon);
}

void print_polygon(Polygon *p) {
    printf("POLYGON");
    for (int i = 0; i < p->nb_points; i++) {
        printf(" %d %d", p->points[i]->x, p->points[i]->y);
    }
}

// ==================== POLYGON ====================

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->id = 1;
    shp->shape_type = shape_type;
    shp->ptrShape = NULL;
    return shp;
}

Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2) {
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *l = create_line(p1, p2);
    shp->ptrShape = l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square *s = create_square(p, length);
    shp->ptrShape = s;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height) {
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *r = create_rectangle(p, width, height);
    shp->ptrShape = r;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius) {
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle *c = create_circle(p, radius);
    shp->ptrShape = c;
    return shp;
}

/*Shape *create_polygon_shape(int lst[], int n) {
    Shape *shp = create_empty_shape(POLYGON);
    Point *points = lst;
    Circle *p = create_polygon(points, n);
    shp->ptrShape = c;
    return shp;
}*/

void delete_shape(Shape * shape) {
    free(shape)
}

void print_shape(Shape * shape) {

}
