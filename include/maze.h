#include <iostream>
#include <iterator>
#include <vector>
#include <cstring>
#include <algorithm>
#ifndef MAZE_H
#define MAZE_H

	namespace mzr {
		class Maze
		{
			public:
				int rows;
				int cols;
				enum cell_e
				{
					LeftWall,
					UpperWall,
					RightWall, 					  
					BottomWall
				};
				struct cell
				{
					int x;
					int y;
					std::string wall;
				};
				std::vector <cell> maze;
				std::vector <std::vector <int>> hashs;
				//std::string ** hash_table;
				Maze(int=8, int=6);
				
				bool has_hash(int e);
				int get_hash(int e);
				int xy_to_vet(int x, int y);
				bool create_hash_vec(cell element);
				bool is_border_wall(cell element, cell_e wall);
				bool has_x_down_walls(std::string wall_string, int x);
				void fix(cell element, cell neighbor, cell_e wall_e, cell_e wall_n);
				void fix_collisions();
				void add_element(int hash, int element);
				void add_neighbors(int hash, int element);
				void create_maze();
				void create_hash();
				void set_border();
				void build_wall(int x, int y, cell_e wall);
				void knock_down(int x, int y, cell_e wall);
			private:

    private:
  };
} // namespace mzr
#endif
