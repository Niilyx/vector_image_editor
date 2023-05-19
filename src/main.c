#include "states.h"
#include "utils/print_utils.h"
#include "area.h"
#include "utils/scan_utils.h"
#include "command.h"

#include <stdio.h>

STATE current_state = MAIN_MENU;
int running = 1;
Area *area;

int main() {
    // À décommenter si rien ne s'affiche dans la console
    setvbuf(stdout, NULL, _IONBF, 0);
    while (running) {
    /*TODO fix le delete (segfault)
    */
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
                Command* cmd = create_cmd();

                print_canvas();

                print_prompt();
                read_from_stdin(cmd);
                if (cmd->type != undefined) {
                    exec_command(cmd);
                } else {
                    error_msg();
                    print_help();
                }
                break;
            }
//            case ADD_SHAPE: {
//                print_add_shape_menu();
//                listen_add_shape_menu();
//                break;
//            }
            default:
                return 1;
        }

    }

    return 0;
}
