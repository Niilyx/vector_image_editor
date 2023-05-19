//
// Created by Niilyx on 19/05/2023.
//

#ifndef VECTOR_IMAGE_EDITOR_COMMAND_H
#define VECTOR_IMAGE_EDITOR_COMMAND_H
typedef enum { undefined, quit, clear, point, line, circle, square, rectangle, polygon, plot, list, delete, erase, help } COMMAND_TYPE;

typedef struct {
    COMMAND_TYPE type;
    int int_params[10];
    int int_size;

    char* str_params[10];
    int str_size;
} Command;


Command* create_cmd();
void add_str_param(Command* cmd, char* p);
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
int exec_command(Command* cmd);
void read_from_stdin(Command* cmd);


#endif //VECTOR_IMAGE_EDITOR_COMMAND_H
