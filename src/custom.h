#pragma once
#include <vector>
#include "block.h"
#include "grid.h"
#include "blocks.cpp"



class Custom{
public:
    Custom(int width, int height);
    int width;
    int height;
    Grid grid;
    Block currentBlock;
    Texture2D controlPanel;
    void DrawBlock(Block block);
    void chooseBlock();
    void RotateBlock();
    void placeBlock(int row, int col);
    void Reset();
    void LoadControlPanel();
    void DrawControlPanel();
    void ScreenShot();


private:
    std::vector<Block> blocks;
    


};
