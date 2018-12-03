#include <iostream>

#include "../include/magos.h"

namespace mzr
{
    
    void MagosGame::welcome()
    {
        std::cout << "We are now preparing the maze" << std::endl;
    }

    MagosGame::ResultType MagosGame::initialize(int argc, char ** argv)
    {
        MagosGame::ResultType * ans = new MagosGame::ResultType;
        
        if(argc > 5)        /// First we have to check if there are more arguments than we need
        {
            ans->type = MagosGame::game_state_e::ERROR;
            ans->msg = MagosGame::messages::TOO_MANY_ARGUMENTS;
        }
        else if(argc == 5)  /// If we have exactly 5, there is no need to use default values
        {
            ans->type = MagosGame::game_state_e::RUNNING;
            ans->msg = MagosGame::messages::OK;
        }else
        {
            ans->type = MagosGame::game_state_e::RUNNING;
            ans->msg = MagosGame::messages::USING_DEFAULT_VALUES;
        }
        return *ans;
    }

    void MagosGame::process_events(){}
    void MagosGame::update(){}
    void MagosGame::render(){}

    bool MagosGame::game_over()
    {return true;}
}