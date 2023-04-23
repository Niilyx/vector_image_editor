#include "states.h"
#include "utils/print_utils.h"
#include "shapes.h"

int main() {
    static STATE current_state = MAIN_MENU;
    static int running = 1;
    static Drawing *drawing;

    while (running) {

        switch (current_state) {
            case MAIN_MENU: {
                print_main_menu();
                listen_main_menu();
            }
            case CHOOSE_SIZE: {
                print_choose_size();
                listen_choose_size();
            }
            case ON_CANVAS: {
                print_canvas();

                print_canvas_menu();
                listen_canvas_menu();
            }
            case ADD_SHAPE: {
                break;
            }
        }

    }

    return 0;
}
