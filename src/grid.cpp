#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    grid = new int* [20];
    for (int i = 0; i < 20; ++i) {
        grid[i] = new int[10];
    }
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

Grid::Grid(int width, int height)
{
    numRows = height;
    numCols = width;
        grid = new int* [height];
    for (int i = 0; i < height; ++i) {
        grid[i] = new int[width];
    }
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}


void Grid::Initialize()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::Print()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize + 11, i * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int col)
{
    if (row < 0 || row >= numRows || col < 0 || col >= numCols)
    {
        return true;
    }
    return false;
}

bool Grid::IsCellEmpty(int row, int col)
{
    if (grid[row][col] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;

}

bool Grid::IsRowFull(int row)
{
    for (int j = 0; j < numCols; j++)
    {
        if (grid[row][j] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int j = 0; j < numCols; j++)
    {
        grid[row][j] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int j = 0; j < numCols; j++)
    {
        grid[row + numRows][j] = grid[row][j];
        grid[row][j] = 0;
    }
}