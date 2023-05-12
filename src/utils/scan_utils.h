//
// Created by Niilyx on 23/04/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_SCAN_UTILS_H
#define VECTOR_IMAGE_EDITOR_SCAN_UTILS_H

#include "print_utils.h"

void listen_main_menu();
void listen_choose_size();
void listen_canvas_menu();
void listen_add_shape_menu();

void scan_point(int* a, int* b, int n);
void scan_length(int* a, int n);
void scan_points_number(int* a);

#endif //VECTOR_IMAGE_EDITOR_SCAN_UTILS_H
