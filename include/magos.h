#ifndef MAGOS_H
#define MAGOS_H

namespace mzr
{
    class MagosGame
    {
        public:
        
        enum game_state_e {   
            ERROR
        };
        enum messages{
            MENSAGEM_TESTE
        };
        struct ResultType
        {   
            game_state_e type;
            messages msg;
        };
      
        
        void welcome();
        ResultType initialize(int argc, char ** argv);
        void process_events();
        void update();
        void render();
        bool game_over();

        private:
        
    };
} // namespace magos
#endif // MAGOS_H