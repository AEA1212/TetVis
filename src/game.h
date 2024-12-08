#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    bool gameOver;
    int score;

    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();

private:
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int rowsCleared, int moveDown);
};
