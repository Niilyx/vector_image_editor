//
// Created by Niilyx on 23/04/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_COMMON_H
#define VECTOR_IMAGE_EDITOR_COMMON_H

#include "shapes.h"
#include "states.h"

// extern permet de ne pas réserver de mémoire, donc il n'y a jamais de conflits d'imports
extern STATE current_state;
extern Area *drawing;

extern unsigned int global_id;

#endif //VECTOR_IMAGE_EDITOR_COMMON_H
