#ifndef MAGOS_H
#define MAGOS_H

namespace mzr
{
    class MagosGame
    {
        public:
        
        enum game_state_e {   
            ERROR,
            RUNNING
        };
        enum messages{
            OK,
            USING_DEFAULT_VALUES,
            TOO_MANY_ARGUMENTS
        };
        struct ResultType
        {   
            game_state_e type;
            messages msg;
        };
      
        
        void render();
        void update();
        void welcome();
        void process_events();
        bool game_over();
        ResultType initialize(int argc, char ** argv);

        private:
        
    };
} // namespace magos
#endif // MAGOS_H