/*!
 *  This is the program entry, that  manages the game loop (programming pattern).
 *
 *  @author Selan R. dos Santos
 *
 */

#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // cerr

#include "../include/magos.h"

int main(int argc, char *argv[])
{
    if (argc > 5)
    {
        std::cout << "Too many arguments" << std::endl;
        return 0;
    }

    std::cout << "rodando o programa " << std::endl;
    mzr::MagosGame mg;

    mg.welcome();

    auto result = mg.initialize(argc, argv);
    if (result.type == mzr::MagosGame::game_state_e::ERROR)
    {
        std::cerr << result.msg << "\n";
        return EXIT_FAILURE;
    }

    // The Game Loop.
    while (not mg.game_over())
    {
        mg.process_events();
        mg.update();
        mg.render();
    }

    return EXIT_SUCCESS;
}