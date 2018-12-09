#include <iostream>

#include "../include/maze.h"
namespace mzr{
	Maze::Maze(int rs, int cs) : rows(rs), cols(cs)
	{

	} 
	bool Maze::is_border_wall(Maze::cell element, Maze::cell_e wall)
	{
		if (wall == Maze::cell_e::LeftWall)
			if (element.y == 0) return true;
		if (wall == Maze::cell_e::UpperWall)
			if (element.x == 0) return true;
		if (wall == Maze::cell_e::RightWall)
			if (element.y == cols - 1) return true;
		if (wall == Maze::cell_e::BottomWall)
			if (element.x == rows - 1) return true;
		
		return false;
	}
	void Maze::knock_down(int row, int col, Maze::cell_e wall)
	{

	}
	void Maze::create_hash()
	{	
		for(unsigned int element = 0; element < maze.size(); element ++)
		{
			
			int actual_hash = get_hash(element);
			if(maze[element].wall[0] != '1') 	// check if left wall is down
				if(!is_border_wall(maze[element], LeftWall))
					add_neighbor(actual_hash, element, LeftWall);
			if(maze[element].wall[1] != '1') 	// check if upper wall is down
				if(!is_border_wall(maze[element], UpperWall))
					add_neighbor(actual_hash, element, UpperWall);
			if(maze[element].wall[2] != '1') 	// check if right wall is down
				if(!is_border_wall(maze[element], RightWall))
					add_neighbor(actual_hash, element, RightWall);
			if(maze[element].wall[3] != '1'){ 	// check if bottom wall is down
				if(!is_border_wall(maze[element], BottomWall)){
					add_neighbor(actual_hash, element, BottomWall);
				}
			}
			
			//for (char & w: maze[element].wall)
			//	if(w != '1') add_neighbor(actual_hash, element);		
		}
	}
	int Maze::get_hash(int element)
	{
		for(unsigned int index = 0; index < hashs.size(); index++) {
			if (std::find(hashs[index].begin(), hashs[index].end(), element) != hashs[index].end()) return index;
		}
		std::vector <int> new_vec;
		new_vec.push_back(element);
		hashs.push_back(new_vec);
		return hashs.size()-1;
	}
	void Maze::add_neighbor(int hash, int element, Maze::cell_e wall)
	{
		
		
		if(wall == LeftWall)
			//if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element) != hashs[hash].end()))
				hashs[hash].push_back(element - 1);
		if(wall == UpperWall)
			//if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element) != hashs[hash].end())) 
				hashs[hash].push_back(element - rows);
		if(wall == RightWall)
			//if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element) != hashs[hash].end())) 
				hashs[hash].push_back(element + 1);
		if(wall == BottomWall){
			//hashs[0].push_back(element + rows);
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element) != hashs[hash].end())) 
				hashs[hash].push_back(element + rows);
			
		}
	}
	void Maze::create_maze()
	{
		for (int x = 0; x < rows; x ++)
		{
			for(int y = 0; y < cols; y ++)
			{
				cell element = {x,y,"1010"};
				maze.push_back(element);
			}
		}
	}
}