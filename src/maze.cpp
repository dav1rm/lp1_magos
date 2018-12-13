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
			if (element.x == 0) return true;
		if (wall == Maze::cell_e::UpperWall)
			if (element.y == 0) return true;
		if (wall == Maze::cell_e::RightWall)
			if (element.x == cols - 1) return true;
		if (wall == Maze::cell_e::BottomWall)
			if (element.y == rows - 1) return true;
		
		return false;
	}

	void Maze::build_wall(int x, int y, Maze::cell_e wall)
	{maze[xy_to_vet(x,y)].wall[wall] = '1';}

	void Maze::knock_down(int x, int y, Maze::cell_e wall)
	{
		// 	O vertor não reconhece
		//	00	01  mas sim
		//	10	11	 00	 10
		//			 01	 11
		maze[xy_to_vet(x,y)].wall[wall] = '0';
	}
	// void Maze::add_to_hash(int element, int hash)
	// {

	// }
	void Maze::create_hash()
	{
		// for (unsigned int element = 0; element < maze.size(); element ++)
		// {
			auto e_act = maze[0];
			//while(has_x_down_walls(e_act.wall, 1) ) // e parede aberta não for a mesma da parede anterior
			//{

				// existe vizinhos?
				// os vizinhos ja estao na minha hash table?
				// adiciona ele na minha hash table
				// chama recusivamente para o elemento adicionado

				if (!has_hash(xy_to_vet(e_act.x, e_act.y)))
					if(create_hash_vec(e_act)) 
					{	
						//if (!(std::find(hashs[hashs.size()-1].begin(), hashs[hashs.size()-1].end(), element)))
							add_element(hashs.size()-1, 0);
	
						
						
					}
					
				
			//}

		// }
		for(std::vector <int> &hash: hashs ) {
			std::cout << " { ";
			std::copy(hash.begin(),
				hash.end(),
				std::ostream_iterator<int>(std::cout, " "));
				std::cout << "} ";
		}

		std::cout << std::endl;
	}
	bool Maze::create_hash_vec(Maze::cell element)
	{
		std::vector <int> new_hash;
		// int el = xy_to_vet(element.x, element.y);
		// new_hash.push_back(el);
		hashs.push_back(new_hash);
		return true;
	}
	bool Maze::has_hash(int e)
	{
		for(unsigned int index = 0; index < hashs.size(); index++) {
			if (std::find(hashs[index].begin(), hashs[index].end(), e) != hashs[index].end()) return true;
		}
		return false;
	}
	int Maze::get_hash(int e)
	{
		int value = 0;
		for(unsigned int index = 0; index < hashs.size(); index++) {
			if (std::find(hashs[index].begin(), hashs[index].end(), e) != hashs[index].end()) 
			{
				value = index;
				break;
			}
		}
		return value;
	}
	void Maze::add_element(int hash, int element)
	{
		std::cout << "entrou: x=" << maze[element].x << " e y=" << maze[element].y << "\n";
		hashs[hash].push_back(element);

		if(maze[element].wall[Maze::cell_e::LeftWall] != '1')
			if(!is_border_wall(maze[element], Maze::cell_e::LeftWall)) 
				if (!(std::find(hashs[hashs.size()-1].begin(), hashs[hashs.size()-1].end(), element-1) != hashs[hashs.size()-1].end())) 
				{
					std::cout << "achou l " << element << "\n";
					add_element(hashs.size()-1, element - 1);
				}

		if(maze[element].wall[Maze::cell_e::UpperWall] != '1')
			if(!is_border_wall(maze[element], Maze::cell_e::UpperWall)) 
				if (!(std::find(hashs[hashs.size()-1].begin(), hashs[hashs.size()-1].end(), element-cols) != hashs[hashs.size()-1].end())) 
				{
					std::cout << "achou u " << element << "\n";
					add_element(hashs.size()-1, element - cols);
				}

		if(maze[element].wall[Maze::cell_e::RightWall] != '1')
			if(!is_border_wall(maze[element], Maze::cell_e::RightWall)) 
				if (!(std::find(hashs[hashs.size()-1].begin(), hashs[hashs.size()-1].end(), element+1) != hashs[hashs.size()-1].end())) 
				{
					std::cout << "achou r " << element << "\n";
					add_element(hashs.size()-1, element + 1);
				}

		if(maze[element].wall[Maze::cell_e::BottomWall] != '1')
			if(!is_border_wall(maze[element], Maze::cell_e::BottomWall)) 
				if (!(std::find(hashs[hashs.size()-1].begin(), hashs[hashs.size()-1].end(), element+cols) != hashs[hashs.size()-1].end())) 
				{
					std::cout << "achou b " << element << "\n";
					add_element(hashs.size()-1, element + cols);

				}

		std::cout << "sobrou: " << element << "\n";
	}
	void Maze::add_neighbors(int hash, int element)
	{
		if(maze[element].wall[Maze::cell_e::LeftWall] != '1' && !(is_border_wall(maze[element], Maze::cell_e::LeftWall)) )
		{
			hashs[hash].push_back(element - 1);
		}
		if(maze[element].wall[Maze::cell_e::UpperWall] != '1' && !(is_border_wall(maze[element], Maze::cell_e::UpperWall)))
		{
			hashs[hash].push_back(element - cols);
		}
		if(maze[element].wall[Maze::cell_e::RightWall] != '1' && !(is_border_wall(maze[element], Maze::cell_e::RightWall)))
		{	
			hashs[hash].push_back(element + 1);
		}
		if(maze[element].wall[Maze::cell_e::BottomWall] != '1' && !(is_border_wall(maze[element], Maze::cell_e::BottomWall)))
		{
			hashs[hash].push_back(element + cols);	
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
		{return ((rows * y) + x);}
	
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
				}
			}
			if (!is_border_wall(element, Maze::cell_e::UpperWall))
			{
				auto upper_neighbor = maze[xy_to_vet(element.x, element.y) - cols];
				if( upper_neighbor.wall[Maze::cell_e::BottomWall] != element.wall[Maze::cell_e::UpperWall])
				{
					fix(element, upper_neighbor, Maze::cell_e::UpperWall, Maze::cell_e::BottomWall);
				
				}
			}
			if (!is_border_wall(element, Maze::cell_e::RightWall))
			{
				auto right_neighbor = maze[xy_to_vet(element.x, element.y) + 1];
				if( right_neighbor.wall[Maze::cell_e::LeftWall] != element.wall[Maze::cell_e::RightWall])
				{
					fix(element, right_neighbor, Maze::cell_e::RightWall, Maze::cell_e::LeftWall);
					
				}
			}
			if (!is_border_wall(element, Maze::cell_e::BottomWall))
			{
				auto bottom_neighbor = maze[xy_to_vet(element.x, element.y) + cols];
				if( bottom_neighbor.wall[Maze::cell_e::UpperWall] != element.wall[Maze::cell_e::BottomWall])
				{
					fix(element, bottom_neighbor, Maze::cell_e::BottomWall, Maze::cell_e::UpperWall);
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