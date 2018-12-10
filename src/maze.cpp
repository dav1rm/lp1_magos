#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
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

	void Maze::build_wall(int x, int y, Maze::cell_e wall)
	{maze[xy_to_vet(y, x)].wall[wall] = '1';}

	void Maze::knock_down(int x, int y, Maze::cell_e wall)
	{
		// 	O vertor não reconhece
		//	00	01  mas sim
		//	10	11	 00	 10
		//			 01	 11
		maze[xy_to_vet(y, x)].wall[wall] = '0';
	}
	void Maze::create_hash()
	{	
		for(unsigned int element = 0; element < maze.size(); element ++)
		{
			int actual_hash = get_hash(element);
			if(maze[element].wall[0] != '1') 	// check if left wall is down
				if(!is_border_wall(maze[element], Maze::cell_e::LeftWall))
					add_neighbor(actual_hash, element, Maze::cell_e::LeftWall);
			if(maze[element].wall[Maze::cell_e::UpperWall] != '1') 	// check if upper wall is down
				if(!is_border_wall(maze[element], Maze::cell_e::UpperWall))
					add_neighbor(actual_hash, element, Maze::cell_e::UpperWall);
			if(maze[element].wall[Maze::cell_e::RightWall] != '1') 	// checMaze::cell_e::LeftWall if right wall is down
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
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element - 1) != hashs[hash].end()))
			hashs[hash].push_back(element - 1);
		}

		if(wall == Maze::cell_e::UpperWall)
		{
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element - rows) != hashs[hash].end())) 
			hashs[hash].push_back(element - rows);
		}
			
		if(wall == Maze::cell_e::RightWall)
		{	
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element + 1) != hashs[hash].end())) 
				hashs[hash].push_back(element + 1);
		}
		if(wall == Maze::cell_e::BottomWall)
		{
			if (!(std::find(hashs[hash].begin(), hashs[hash].end(), element + rows) != hashs[hash].end())) 
				hashs[hash].push_back(element + rows);	
		}
	}
	void Maze::create_maze()
	{
		srand (time(NULL));
		for (int x = 0; x < rows; x ++)
		{
			for(int y = 0; y < cols; y ++)
			{
				std::string wall_string = std::to_string(rand()%2) + std::to_string(rand()%2) + std::to_string(rand()%2) + std::to_string(rand()%2);
				cell element = {x,y,wall_string};
				maze.push_back(element);
			}
		}
		set_border();
		fix_collisions();
	}
	int Maze::xy_to_vet(int x, int y)
		{return ((rows * x) + y);}
	
	void Maze::fix(Maze::cell element, Maze::cell neighbor, Maze::cell_e wall_e, Maze::cell_e wall_n)
	{
		if( has_x_down_walls(element.wall, 2) && has_x_down_walls(neighbor.wall,2))
		{
			build_wall(neighbor.x, neighbor.y, wall_n);
			build_wall(element.x, element.y, wall_e);
			
		}else
		{
			knock_down(neighbor.x, neighbor.y, wall_n);
			knock_down(element.x, element.y, wall_e);
		}
	}
	bool Maze::has_x_down_walls(std::string wall_string, int x)
	{
		int qnt_down = 0;
		for (unsigned int i = 0; i < wall_string.length(); i++)
			if(wall_string[i] == '0') qnt_down ++;
		if(qnt_down >= x)return true;
		return false;
	}
	void Maze::fix_collisions()
	{
		for(Maze::cell &element : maze) {

			//std::cout << '('<< element.x << ", "<<element.y<< ") \n";
			if (!is_border_wall(element, Maze::cell_e::LeftWall))
			{	
				auto left_neighbor = maze[xy_to_vet(element.x, element.y) - 1];
				if( left_neighbor.wall[Maze::cell_e::RightWall] != element.wall[Maze::cell_e::LeftWall])
				{	
					fix(element, left_neighbor, Maze::cell_e::LeftWall, Maze::cell_e::RightWall);
					//knock_down(left_neighbor.x, left_neighbor.y, Maze::RightWall);
					//knock_down(element.x, element.y, Maze::LeftWall);
					
				}
			}
			if (!is_border_wall(element, Maze::cell_e::UpperWall))
			{
				auto upper_neighbor = maze[xy_to_vet(element.x, element.y) - cols];
				if( upper_neighbor.wall[Maze::cell_e::BottomWall] != element.wall[Maze::cell_e::UpperWall])
				{
					fix(element, upper_neighbor, Maze::cell_e::UpperWall, Maze::cell_e::BottomWall);
					//knock_down(upper_neighbor.x, upper_neighbor.y, Maze::BottomWall);
					//knock_down(element.x, element.y, Maze::UpperWall);
				}
			}
			if (!is_border_wall(element, Maze::cell_e::RightWall))
			{
				auto right_neighbor = maze[xy_to_vet(element.x, element.y) + 1];
				if( right_neighbor.wall[Maze::cell_e::LeftWall] != element.wall[Maze::cell_e::RightWall])
				{
					fix(element, right_neighbor, Maze::cell_e::RightWall, Maze::cell_e::LeftWall);
					//knock_down(right_neighbor.x, right_neighbor.y, Maze::LeftWall);
					//knock_down(element.x, element.y, Maze::RightWall);
				}
			}
			if (!is_border_wall(element, Maze::cell_e::BottomWall))
			{
				auto bottom_neighbor = maze[xy_to_vet(element.x, element.y) - cols];
				if( bottom_neighbor.wall[Maze::cell_e::UpperWall] != element.wall[Maze::cell_e::BottomWall])
				{
					fix(element, bottom_neighbor, Maze::cell_e::BottomWall, Maze::cell_e::UpperWall);
					//knock_down(bottom_neighbor.x, bottom_neighbor.y, Maze::UpperWall);
					//knock_down(element.x, element.y, Maze::BottomWall);
				}
			}
			
		}
		
	}
	void Maze::set_border()
	{
		for(Maze::cell &element : maze) {
			if(element.y == 0) build_wall(element.x, element.y, Maze::cell_e::LeftWall);	
			if(element.x == 0)  build_wall(element.x, element.y, Maze::cell_e::UpperWall);	
			if(element.y == cols-1) build_wall(element.x, element.y, Maze::cell_e::RightWall);
			if(element.x == rows-1)  build_wall(element.x, element.y, Maze::cell_e::BottomWall);
		}
	}
}