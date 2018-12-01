#include <iostream>
#include <cstring>

#include "../include/canvas.h"

using namespace canvas;

int main(void)
{
    // Cria um objeto canvas de 800 por 600 pixels de dimensão.
    Canvas c(800, 600);

    // Definie a cor de fundo da imagem.
    c.clear(LIGHT_GREY);

    c.pixel(0, 0, RED);
    c.pixel(0, 1, RED);

    // Vamos desenhar um retângulo cujo canto superior esquerdo está em (100,100).
    coord_type orig_x{100}, orig_y{100};
    // Vamos utilizar uma linha com 3 pixels de largura.
    c.thickness(3);
    // Um retângulo pode ser formado através do desenho de 4 linhas.
    c.hline(orig_x, orig_x, 300, RED);
    c.vline(orig_x, orig_y, 200, STEEL_BLUE);
    c.hline(orig_x, orig_y + 200, 300, GREEN);
    c.vline(orig_x + 300, orig_y, 200, YELLOW);
    // Preencher o interior do retângulo com um quadrado de 50 x 50 pixels.
    c.box(orig_x + 125, orig_y + 75, 50, 50, DEEP_SKY_BLUE);

    // Recuperar as informações do Canvas (imagem) para poder gravar um arquivo PNG.
    auto width = c.width();
    auto height = c.height();
    auto pixels = c.buffer(); // Ponteiro para o vetor de bytes representando a imagem.
}
