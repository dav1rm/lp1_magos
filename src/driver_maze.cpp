#include <iostream>
#include "../include/maze.h"
#include "../include/render.h"
#include "../include/common.h" // class Coord.

//using namespace mzr;

int main(void)
{
    // Cria um labirinto 5 x 7.
    mzr::Maze m( 2, 2 );
    m.create_maze();
    //m.create_hash();
        // for(std::vector <int> &hash: m.hashs ) {
        //    std::cout << " { ";
        //    std::copy(hash.begin(),
        //       hash.end(),
        //        std::ostream_iterator<int>(std::cout, " "));
        //     std::cout << "} ";
        // }

    // Construtor do render e passando o maze (no render recebemos com Maze *).
    mzr::Render render( &m, 200,200 );
    // vamos derrubar a parede direita da celulua (1,2)
    //m.knock_down( 1, 2, mzr::Maze::cell_e::RightWall );
	// vamos derrubar a parede de baixo da mesma célula.
    //m.knock_down( 1, 2, mzr::Maze::cell_e::BottomWall );
	// Tentando derrubar uma parede "ilegal", ou seja que não pode ser derrubada.
    //m.knock_down( 0, 2, mzr::Maze::cell_e::LeftWall );

    render.draw( "teste1.png"); // Grava a imagem resultante.

    //render.draw("img1"); // Grava a imagem resultante.

    return 0;
}
