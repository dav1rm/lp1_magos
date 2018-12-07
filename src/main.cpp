/*!
 *  This is the program entry, that  manages the game loop (programming pattern).
 *
 *  @author Selan R. dos Santos
 *
 */

#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // cerr

#include "../include/magos.h"

/*!
     * Print result's message.
     * @param Initialization's result.
     */
void print_msg(const mzr::MagosGame::ResultType & result)
{
    switch ( result.msg )
    {
        case mzr::MagosGame::messages::OK:
            std::cout << ">>> Everything went smoothly \n";
            break;
        case mzr::MagosGame::messages::USING_DEFAULT_VALUES:
            std::cout << ">>> Using default values \n";
            break;
        case mzr::MagosGame::messages::TOO_MANY_ARGUMENTS:
            std::cout << ">>> Too many arguments \n";
            break;
    }
}


int main(int argc, char *argv[])
{
    mzr::MagosGame mg;

    /// Warm welcome
    mg.welcome();

    /// Ready to initialize game
    auto result = mg.initialize(argc, argv);

    /// Check if everything works
    if (result.type == mzr::MagosGame::game_state_e::ERROR)
    {
        print_msg(result);
        return EXIT_FAILURE;
    }else print_msg(result);

    // The Game Loop.
    while (not mg.game_over())
    {
        mg.process_events();
        mg.update();
        mg.render();
    }

    return EXIT_SUCCESS;
}