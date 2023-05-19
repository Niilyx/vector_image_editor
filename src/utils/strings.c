//
// Created by Niilyx on 19/05/2023.
//

#include <stdlib.h>

#include "strings.h"

int contains(const int* lst, int size, int x) {
    if (lst == NULL) return 0;

    for (int i = 0; i < size; i++) {
        if (lst[i] == x) return 1;
    }

    return 0;
}

/**
 * Découpe une chaîne de caractères en fonction d'un délimiteur.
 * @param string un pointeur vers la chaîne de caractères à découper
 * @param str_size la taille de la chaîne
 * @param delimiter le caractère délimitant
 * @return un pointeur vers un tableau de chaines de caractères
 */
char*** split(const char* string, int str_size, char delimiter, int* substrings_number) {
    if (string == NULL) return NULL;
    if (str_size == 0) {
        *substrings_number = 0;
        return NULL;
    }

    int counter = 0;
    int* delimiter_indexes = malloc(sizeof(int) * str_size);
    for (int i = 0; i < str_size; i++) {
        if (string[i] == delimiter) {
            delimiter_indexes[counter++] = i;
        }
    }

    int number_of_substrings = counter + 1;

    char*** result = malloc(sizeof(char**));
    *result = malloc(sizeof(char*) * number_of_substrings);
    for (int i = 0; i < number_of_substrings; ++i) {
        (*result)[i] = malloc(sizeof(char));
    }

    int substring_index = 0;
    int substring_cursor = 0;
    for (int i = 0; i < str_size; ++i) {
        if (contains(delimiter_indexes, number_of_substrings - 1, i)) {
            (*result)[substring_index][substring_cursor] = '\0';
            // Si on n'a pas avancé (si substring_cursor = 0), ça veut dire qu'il y a deux délimiteurs à la suite.
            // Dans ce cas, inutile d'avancer substring_index.
            if (substring_cursor)
                substring_index++;
            substring_cursor = 0;
        } else {
            realloc((*result)[substring_index], sizeof(char) * (substring_cursor + 1));
            (*result)[substring_index][substring_cursor++] = string[i];
        }
    }
    realloc((*result)[substring_index], sizeof(char) * (substring_cursor + 1));
    (*result)[substring_index][substring_cursor++] = '\0';

    *substrings_number = number_of_substrings;
    return result;
}

int length(char** string) {
    int i = 0;
    while (string[i++] != NULL);
    return i;
}

int to_lower(char** c, int size) {
    if (c == NULL || *c == NULL) return 0;

    for (int i = 0; i < size; ++i) {
        if ((*c)[i] < 'A' || 'Z' < (*c)[i]) {
            continue;
        }
        if ('A' <= (*c)[i] && (*c)[i] <= 'Z') {
            (*c)[i] += 32;
        }
    }
    return 1;
}

int equals(const char* a, const char* b) {
    if (a == NULL || b == NULL) return 0;

    int i = 0;
    while (a[i] && b[i] && a[i] == b[i]) {
        i++;
    }
    return !a[i] && !b[i] && a[i] == b[i];
}

int parse_int(const char* str) {
    if (str == NULL) return 0;

    int result = 0;
    int i = 0;
    int neg;
    if (str[0] == '-') {
        if (str[1] == '\0') return -1;
        i = 1;
        neg = -1;
    }
    else neg = 1;
    while (str[i]) {
        if ('0' <= str[i] && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
            i++;
        } else {
            return -1;
        }
    }
    result *= neg;
    return result;
}