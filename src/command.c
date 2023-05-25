//
// Created by Niilyx on 19/05/2023.
//
// Ici sont gérées les commandes utilisateurs, donc leur interprétation et leur exécution.

#include <stdlib.h>
#include <stdio.h>

#include "command.h"
#include "Common.h"
#include "utils/strings.h"
#include "utils/print_utils.h"

/**
 * Vérifie sur la commande donnée a le bon nombre d'arguments
 * @param substrings_number nombre d'arguments passés à la commande
 * @param type type de la commande
 * @return 1 pour vrai, 0 pour faux
 */
int check_args_number(int substrings_number, COMMAND_TYPE type) {
    substrings_number--;
    switch (type) {
        case point: {
            return substrings_number == 2;
        }
        case line:
        case rectangle: {
            return substrings_number == 4;
        }
        case circle:
        case square: {
            return substrings_number == 3;
        }
        case polygon: {
            return substrings_number >= 2 && substrings_number % 2 == 0;
        }
        case delete: {
            return substrings_number == 1;
        }
        default: {
            return 1;
        }
    }
}

/**
 * Petite fonction de nettoyage de la mémoire
 * @param array liste à libérer
 */
void cleanup_scanning(char ***array, int size) {
    for (int i = 0; i < size; ++i) {
        free((*array)[i]);
    }
    free(*array);
    free(array);
}

void cleanup_scanning_original(char ***array) {
    free(*array);
    free(array);
}

/**
 * Crée une commande
 * @return la commande créée
 */
Command* create_cmd() {
    Command* cmd = malloc(sizeof(Command));
    cmd->type = undefined;
    cmd->int_size = 0;
    cmd->str_size = 0;
    return cmd;
}

/**
 * Inutilisé
 */
void add_str_param(Command* cmd, char* p) {
    cmd->str_params[cmd->str_size++] = p;
}

/**
 * Ajoute un paramètre de type entier à la commande
 * @param cmd la commande
 * @param p entier à ajouter
 */
void add_int_param(Command* cmd, int p) {
    cmd->int_params[(cmd->int_size)++] = p;
}

/**
 * Libère la mémoire allouée à la commande
 * @param cmd la commande
 */
void free_cmd(Command* cmd) {
//    for (int i = 0; i < cmd->str_size; ++i) {
//        free(cmd->str_params[i]);
//    }
    free(cmd);
}

/**
 * Exécute la commande donnée. À ce stade, les arguments devraient être vérifiés.
 * @param cmd la commande
 * @return une valeur de succès inutilisée
 */
int exec_command(Command* cmd) {
    switch (cmd->type) {
        case quit: {
            running = 0;
            break;
        }
        case clear: {
            for (int i = 0; i < 64; ++i) {
                newline();
            }
            break;
        }
        case point: {
            int x = cmd->int_params[0];
            int y = cmd->int_params[1];
            if (x >= area->size_x || y >= area->size_y) {
                printf("\nLes coordonnees du point sont en dehors de la zone de dessin.");
                break;
            }

            add_shape_to_area(area, create_point_shape(x, y));
            break;
        }
        case line: {
            int x1 = cmd->int_params[0];
            int y1 = cmd->int_params[1];
            int x2 = cmd->int_params[2];
            int y2 = cmd->int_params[3];
            if (x1 >= area->size_x || y1 >= area->size_y || x2 >= area->size_x || y2 >= area->size_y) {
                printf("\nLes coordonnees de la ligne sont en dehors de la zone de dessin.");
                break;
            }

            add_shape_to_area(area, create_line_shape(x1, y1, x2, y2));
            break;
        }
        case circle: {
            int x = cmd->int_params[0];
            int y = cmd->int_params[1];
            int r = cmd->int_params[2];
            if (x >= area->size_x || y >= area->size_y) {
                printf("\nLes coordonnees du cercle sont en dehors de la zone de dessin.");
                break;
            }

            add_shape_to_area(area, create_circle_shape(x, y, r));
            break;
        }
        case square: {
            int x = cmd->int_params[0];
            int y = cmd->int_params[1];
            int l = cmd->int_params[2];
            if (x >= area->size_x || y >= area->size_y || x + l >= area->size_x || y + l >= area->size_y) {
                printf("\nLes coordonnees de la ligne sont en dehors de la zone de dessin.");
                break;
            }

            add_shape_to_area(area, create_square_shape(x, y, l));
            break;
        }
        case rectangle: {
            int x = cmd->int_params[0];
            int y = cmd->int_params[1];
            int l = cmd->int_params[2];
            int h = cmd->int_params[3];
            if (x >= area->size_x || y >= area->size_y || x + l >= area->size_x || y + h >= area->size_y) {
                printf("\nLes coordonnees du rectangle sont en dehors de la zone de dessin.");
                break;
            }

            add_shape_to_area(area, create_rectangle_shape(x, y, l, h));
            break;
        }
        case polygon: {
            int* x = malloc((sizeof(int) * cmd->int_size) / 2);
            int* y = malloc((sizeof(int) * cmd->int_size) / 2);
            for (int i = 0; i < cmd->int_size; i += 2) {
                x[i / 2] = cmd->int_params[i];
                y[i / 2] = cmd->int_params[i + 1];
                if (x[i / 2] >= area->size_x || y[i / 2] >= area->size_y) {
                    printf("\nLes coordonnees d'un point du polygone sont en dehors de la zone de dessin.");
                    free(x);
                    free(y);
                    free_cmd(cmd);
                    return 1;
                }
            }

            int* lst = malloc(sizeof(int) * cmd->int_size);
            for (int i = 0; i < cmd->int_size; i += 2) {
                lst[i] = x[i / 2];
                lst[i + 1] = y[i / 2];
            }
            add_shape_to_area(area, create_polygon_shape(lst, cmd->int_size));
            break;
        }
        case plot: {
            draw_area(area);
            print_area(area);
            break;
        }
        case list:
            print_shapes();
            break;
        case delete: {
            int id = cmd->int_params[0];
            int index;
            Shape* shape = get_shape(area, id, &index);
            if (shape == NULL) {
                printf("\nAucune forme ne correspond a cet identifiant.");
                break;
            }
            delete_shape(shape);
            for (int i = index; i < area->nb_shapes - 1; ++i) {
                area->shapes[i] = area->shapes[i + 1];
            }
            area->nb_shapes--;
            break;
        }
        case erase: {
            erase_area(area);
            break;
        }
        case help: {
            print_help();
            break;
        }
        default:
            break;
    }
    free_cmd(cmd);
    return 0;
}

/**
 * Lit une commande depuis l'entrée standard, et la rejette si elle a le mauvais nombre d'arguments
 * @param cmd la commande
 */
void read_from_stdin(Command* cmd) {
    fflush(stdin);
    char input[100];
    input[0] = '\n';
    while (input[0] == '\n') {
        fgets(input, 100, stdin);
    }
    int i = 0;
    while (i < 100 && input[i++] != '\n');
    input[i - 1] = '\0';

    int substrings_number;
    char ***splitted = split(input, i, ' ', &substrings_number);
    if (substrings_number == 0) {
        printf("\nPas de commande entree.");
        return;
    }

    to_lower(*splitted, length(*splitted));
    char* command = (*splitted)[0]; // Nom de la commande
    if (equals(command, "exit") || equals(command, "quit")) {
        // On se moque d'eventuels arguments fournis, si et seulement la commande en exige 0
        cmd->type = quit;
    } else if (equals(command, "clear")) {
        cmd->type = clear;
    } else if (equals(command, "point")) {
        if (!check_args_number(substrings_number, point)) {
            cleanup_scanning(splitted, substrings_number);
            return;
        }

        int x = parse_int((*splitted)[1]);
        int y = parse_int((*splitted)[2]);
        if (x < 0 || y < 0) {
            cleanup_scanning(splitted, 0);
            return;
        }

        add_int_param(cmd, x);
        add_int_param(cmd, y);
        cmd->type = point;
    } else if (equals(command, "line")) {
        if (!check_args_number(substrings_number, line)) {
            cleanup_scanning(splitted, 0);
            return;
        }

        int x1 = parse_int((*splitted)[1]);
        int y1 = parse_int((*splitted)[2]);
        int x2 = parse_int((*splitted)[3]);
        int y2 = parse_int((*splitted)[4]);
        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
            cleanup_scanning(splitted, 0);
            return;
        }

        add_int_param(cmd, x1);
        add_int_param(cmd, y1);
        add_int_param(cmd, x2);
        add_int_param(cmd, y2);
        cmd->type = line;
    } else if (equals(command, "circle")) {
        if (!check_args_number(substrings_number, circle)) {
            cleanup_scanning(splitted, 0);
            return;
        }

        int x = parse_int((*splitted)[1]);
        int y = parse_int((*splitted)[2]);
        int r = parse_int((*splitted)[3]);
        if (x < 0 || y < 0 || r < 0) {
            cleanup_scanning(splitted, 0);
            return;
        }

        add_int_param(cmd, x);
        add_int_param(cmd, y);
        add_int_param(cmd, r);
        cmd->type = circle;
    } else if (equals(command, "square")) {
        if (!check_args_number(substrings_number, square)) {
            cleanup_scanning(splitted, 0);
            return;
        }

        int x = parse_int((*splitted)[1]);
        int y = parse_int((*splitted)[2]);
        int l = parse_int((*splitted)[3]);
        if (x < 0 || y < 0 || l < 0) {
            cleanup_scanning(splitted, 0);
            return;
        }

        add_int_param(cmd, x);
        add_int_param(cmd, y);
        add_int_param(cmd, l);
        cmd->type = square;
    } else if (equals(command, "rectangle")) {
        if (!check_args_number(substrings_number, rectangle)) {
            cleanup_scanning(splitted, 0);
            return;
        }

        int x = parse_int((*splitted)[1]);
        int y = parse_int((*splitted)[2]);
        int l = parse_int((*splitted)[3]);
        int h = parse_int((*splitted)[4]);
        if (x < 0 || y < 0 || l < 0 || h < 0) {
            cleanup_scanning(splitted, 0);
            return;
        }

        add_int_param(cmd, x);
        add_int_param(cmd, y);
        add_int_param(cmd, l);
        add_int_param(cmd, h);
        cmd->type = rectangle;
    } else if (equals(command, "polygon")) {
        if (!check_args_number(substrings_number, polygon)) {
            cleanup_scanning(splitted, 0);
            return;
        }

        for (int j = 1; j < substrings_number; j += 2) {
            int x = parse_int((*splitted)[j]);
            int y = parse_int((*splitted)[j + 1]);
            if (x >= 0 && y >= 0) {
                add_int_param(cmd, x);
                add_int_param(cmd, y);
            } else {
                cleanup_scanning(splitted, 0);
                return;
            }
        }
        cmd->type = polygon;
    } else if (equals(command, "plot")) {
        cmd->type = plot;
    } else if (equals(command, "delete") || equals(command, "del")) {
        if (!check_args_number(substrings_number, delete)) {
            cleanup_scanning(splitted, 0);
            return;
        }

        int id = parse_int((*splitted)[1]);
        if (id < 0) {
            cleanup_scanning(splitted, 0);
            return;
        }

        add_int_param(cmd, id);

        cmd->type = delete;
    } else if (equals(command, "list")) {
        cmd->type = list;
    } else if (equals(command, "help")) {
        cmd->type = help;
    } else if (equals(command, "erase")) {
        cmd->type = erase;
    } else {
        printf("\nCommande inconnue.\n");
        cmd->type = help;
    }


    // On nettoie
    cleanup_scanning(splitted, 0);
}
