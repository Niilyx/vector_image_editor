//
// Created by Niilyx on 19/05/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_STRINGS_H
#define VECTOR_IMAGE_EDITOR_STRINGS_H

char*** split(const char* string, int str_size, char delimiter, int* number_of_substrings);
int length(char** string);
int to_lower(char** c, int size);
int equals(const char* a, const char* b);
int parse_int(const char* str);

#endif //VECTOR_IMAGE_EDITOR_STRINGS_H
