//
// Created by Niilyx on 23/04/2023.
//
// Génère un identifiant unique

#include "id.h"

unsigned int global_id = 0;

unsigned int get_next_id() {
    return global_id++;
}