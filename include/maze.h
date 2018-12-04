#ifndef MAZE_H
#define MAZE_H
	namespace mzr{
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

				Maze(int=8, int=6);
				void knock_down(int row, int col, cell_e wall);
			private:

		};
	}	
#endif