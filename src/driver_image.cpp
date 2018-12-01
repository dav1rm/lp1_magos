#include "image_writer.h"

struct Color{
	typedef unsigned char byte;
	byte channels[3]						//Keep rgb
	Color (byte r=0, byte g=0, byte b=0);
}

const Color BLACK(0, 0, 0);
const Color WHITE(1, 1, 1);

int main(void)
{
	// Canvas c(500, 300);

	// c.clear(WHITE);

	// c.draw_vertical_line (x,y, width, color);
	// c.draw_horizontal_line (x,y, height, color);

	size_t width = 800;
	size_t height = 600;
	byte * pixels = new byte[width * height * 3];

	std::memset( pixels, 125, width * height * 3 );

	// DRAWING A LINE
	int x = 100;
	int y = 300;
	int len = 50;
	for (auto col(0); col < len; col++)
	{
		x++;
		size_t idx = (y * width + x) * 3;
		pixels[idx + 0] = 255;		// R
		pixels[idx + 1] = 0;		// G
		pixels[idx + 2] = 0;		// B
	}


	stbi_write_png('teste123.png', width, height, 3, pixels, width*3);
}