#include <iostream>

#include "../include/maze.h"
namespace mzr{
	Maze::Maze(int rs, int cs) : rows(rs), cols(cs)
	{

	} 
	void Maze::knock_down(int row, int col, Maze::cell_e wall)
	{

	}
	void Maze::create_maze()
	{
		for (int x = 0; x < rows; x ++)
		{
			for(int y = 0; y < cols; y ++)
			{
				cell element = {x,y,"1111"};
				maze.push_back(element);
			}
		}
	}
}