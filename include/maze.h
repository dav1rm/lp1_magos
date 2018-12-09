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
					RightWall, 
					BottomWall, 
					UpperWall, 
					LeftWall
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
				int get_hash(int element);
				bool is_border_wall(cell element, cell_e wall);
				void add_neighbor(int hash, int element, cell_e wall);
				void create_maze();
				void create_hash();
				void knock_down(int row, int col, cell_e wall);
				void print_hash();
			private:

    private:
  };
} // namespace mzr
#endif
