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
    free(polygon);
}

void print_polygon(Polygon *p) {
    printf("POLYGON");
    for (int i = 0; i < p->nb_points; i++) {
        printf(" %d %d", p->points[i]->x, p->points[i]->y);
    }
}