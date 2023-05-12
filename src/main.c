#include "states.h"
#include "utils/print_utils.h"
#include "shapes.h"

#include <stdio.h>

STATE current_state = MAIN_MENU;
int running = 1;
Area *drawing;

int main() {
    // À décommenter si rien ne s'affiche dans la console
//    setvbuf(stdout, NULL, _IONBF, 0);
    while (running) {

        switch (current_state) {
            case MAIN_MENU: {
                print_main_menu();
                listen_main_menu();
                break;
            }
            case CHOOSE_SIZE: {
                print_choose_size();
                listen_choose_size();
                break;
            }
            case ON_CANVAS: {
                print_canvas();

                print_canvas_menu();
                listen_canvas_menu();
                break;
            }
            case ADD_SHAPE: {
                print_add_shape_menu();
                listen_add_shape_menu();
                break;
            }
        }

    }

    return 0;
}
