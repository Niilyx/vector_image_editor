#include <stdio.h>
#include "utils/print_utils.h"
#include "states.c"

int running = 1;

int main() {

    while (running) {

        switch (current_state) {
            case MAIN_MENU: {
                print_main_menu();
            }
            case CHOOSE_SIZE: {
                break;
            }
        }

    }

    return 0;
}
