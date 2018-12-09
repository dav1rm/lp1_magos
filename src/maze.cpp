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
	void Maze::knock_down(int x, int y, Maze::cell_e wall)
	{
		maze[xy_to_vet(x, y)].wall[wall] = '0';
	}
	void Maze::create_hash()
	{	
		for(unsigned int element = 0; element < maze.size(); element ++)
		{
			
			int actual_hash = get_hash(element);
			if(maze[element].wall[0] != '1') 	// check if left wall is down
				if(!is_border_wall(maze[element], Maze::cell_e::LeftWall))
					add_neighbor(actual_hash, element, Maze::cell_e::LeftWall);
			if(maze[element].wall[1] != '1') 	// check if upper wall is down
				if(!is_border_wall(maze[element], Maze::cell_e::UpperWall))
					add_neighbor(actual_hash, element, Maze::cell_e::UpperWall);
			if(maze[element].wall[2] != '1') 	// check if right wall is down
				if(!is_border_wall(maze[element], Maze::cell_e::RightWall))
					add_neighbor(actual_hash, element, RightWall);
			if(maze[element].wall[3] != '1'){ 	// check if bottom wall is down
				if(!is_border_wall(maze[element], BottomWall)){
					add_neighbor(actual_hash, element, BottomWall);
				}
			}	
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
		if(wall == Maze::cell_e::LeftWall)
		{
			std::cout << element << wall;
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element - 1) != hashs[hash].end()))
			hashs[hash].push_back(element - 1);
		}

		if(wall == Maze::cell_e::UpperWall)
		{
			std::cout << element << wall;
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element - rows) != hashs[hash].end())) 
			hashs[hash].push_back(element - rows);
		}
			
		if(wall == Maze::cell_e::RightWall)
		{	
			std::cout << element << wall;
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element + 1) != hashs[hash].end())) 
				hashs[hash].push_back(element + 1);
		}
		if(wall == Maze::cell_e::BottomWall){
			std::cout << element << wall;
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element + rows) != hashs[hash].end())) 
				hashs[hash].push_back(element + rows);
			
		}
		std::cout << std::endl;
	}
	void Maze::create_maze()
	{
		for (int x = 0; x < rows; x ++)
		{
			for(int y = 0; y < cols; y ++)
			{
				cell element = {x,y,"0001"};
				maze.push_back(element);
			}
		}
		fix_collisions();
	}
	int Maze::xy_to_vet(int x, int y)
		{return ((rows * x) + y);}
	
	void Maze::fix_collisions()
	{
		for(Maze::cell &element : maze) {
			if (!is_border_wall(element, Maze::LeftWall))
			{
				auto left_neighbor = maze[xy_to_vet(element.x, element.y) - 1];
				if( left_neighbor.wall[2] != element.wall[0])
				{
					knock_down(left_neighbor.x, left_neighbor.y, Maze::RightWall);
					knock_down(element.x, element.y, Maze::LeftWall);
				}
			}
			if (!is_border_wall(element, Maze::UpperWall))
			{
				auto upper_neighbor = maze[xy_to_vet(element.x, element.y) - cols];
				if( upper_neighbor.wall[3] != element.wall[1])
				{
					knock_down(upper_neighbor.x, upper_neighbor.y, Maze::BottomWall);
					knock_down(element.x, element.y, Maze::UpperWall);
				}
			}
			if (!is_border_wall(element, Maze::RightWall))
			{
				auto right_neighbor = maze[xy_to_vet(element.x, element.y) + 1];
				if( right_neighbor.wall[0] != element.wall[2])
				{
					knock_down(right_neighbor.x, right_neighbor.y, Maze::LeftWall);
					knock_down(element.x, element.y, Maze::RightWall);
				}
			}
			if (!is_border_wall(element, Maze::BottomWall))
			{
				auto bottom_neighbor = maze[xy_to_vet(element.x, element.y) - cols];
				if( bottom_neighbor.wall[1] != element.wall[3])
				{
					knock_down(bottom_neighbor.x, bottom_neighbor.y, Maze::UpperWall);
					knock_down(element.x, element.y, Maze::BottomWall);
				}
			}
			
		}
		
	}
}