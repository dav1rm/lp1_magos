#include <iostream>
#include <vector>
#include <cstring>
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
				//std::string ** hash_table;
				Maze(int=8, int=6);
				void create_maze();
				void knock_down(int row, int col, cell_e wall);
			private:

    private:
  };
} // namespace mzr
#endif
