#include <iostream>

#include "../include/maze.h"
namespace mzr{
	Maze::Maze(int rs, int cs) : rows(rs), cols(cs)
	{

	} 
	void Maze::knock_down(int row, int col, Maze::cell_e wall)
	{

	}
	void Maze::create_hash()
	{	
		for(unsigned int element = 0; element < maze.size(); element ++)
		{
			std::vector <int> actual_hash = get_hash(element);
			for (char & w: maze[element].wall)
				if(w != '1') add_neig(actual_hash, element);		
		}
	}
	std::vector <int> Maze::get_hash(int element)
	{
		for(std::vector <int> &hash: hashs ) {
			if (std::find(hash.begin(), hash.end(), element) != hash.end()) return hash;
		}
		std::vector <int> new_vec;
		new_vec.push_back(element);
		hashs.push_back(new_vec);
		return hashs[hashs.size()-1];
	}
	void Maze::add_neig(std::vector <int> hash, int element)
	{
		if (!(std::find(hash.begin(), hash.end(), element) != hash.end())) hash.push_back(element);
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