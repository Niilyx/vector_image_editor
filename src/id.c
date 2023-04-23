//
// Created by Niilyx on 23/04/2023.
//

#include "id.h"

unsigned int global_id = 0;

int get_next_id() {
    return global_id++;
}