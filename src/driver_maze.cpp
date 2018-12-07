#include <iostream>
#include "../include/maze.h"
//#include "../include/render.h"
#include "../include/common.h" // class Coord.

//using namespace mzr;

int main(void)
{
    // Cria um labirinto 5 x 7.
    mzr::Maze m(5, 7);

    // Construtor do render e passando o maze (no render recebemos com Maze *).
    //Render render( &m, 800, 600 );
    // vamos derrubar a parede direita da celulua (1,2)
    m.knock_down(1, 2, mzr::Maze::cell_e::RightWall);
    // vamos derrubar a parede de baixo da mesma célula.
    m.knock_down(1, 2, mzr::Maze::cell_e::BottomWall);
    // Tentando derrubar uma parede "ilegal", ou seja que não pode ser derrubada.
    m.knock_down(0, 2, mzr::Maze::cell_e::LeftWall);

    // render.draw( "img1"); // Grava a imagem resultante.

    render.draw("img1"); // Grava a imagem resultante.

    return 0;
}
