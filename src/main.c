#include "states.h"
#include "utils/print_utils.h"
#include "area.h"
#include "utils/scan_utils.h"
#include "command.h"

#include <stdio.h>

STATE current_state = MAIN_MENU; // On commence sur le menu principal
int running = 1;
Area *area; // Zone de dessin

int main() {
    // À décommenter si rien ne s'affiche dans la console
    // Décommenté.
    setvbuf(stdout, NULL, _IONBF, 0);
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
                Command* cmd = create_cmd();

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
            // Inutilisé depuis l'ajout de commandes
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
