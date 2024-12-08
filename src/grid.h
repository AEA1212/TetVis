#pragma once //check if this header file is already included
#include <vector> //vector is like list or array, but has some additional features, such that it can grow or shrink in size, add elements at the end, etc.
#include <raylib.h>


class Grid {    
    public:
        Grid();
        Grid(int width, int height);
        void Initialize();
        void Print();
        void Draw();
        bool IsCellOutside(int row, int col);
        bool IsCellEmpty(int row, int col);
        int ClearFullRows();
        int **grid;
  

    private:
        int numRows;
        int numCols;
        int cellSize;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        std::vector<Color> colors;
};