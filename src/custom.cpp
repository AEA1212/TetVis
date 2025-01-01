#include "custom.h"
#include <iostream>
#include "raylib.h"
#include "rlgl.h"
#include "stb_image_write.h" // Include a library for saving PNGs
#include <string>
#include <unistd.h>


Custom::Custom(int width, int height)
{
    this->width = width;
    this->height = height;
    grid = Grid(width, height);
    grid.Draw();
}

void Custom::chooseBlock()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePosition = GetMousePosition();
        if (mousePosition.x > width * 30 + 20 + 15 &&
            mousePosition.x < width * 30 + 20 + 85 &&
            mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 115 &&
            mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 185)
        {
            currentBlock = IBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 100 &&
                 mousePosition.x < width * 30 + 20 + 170 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 115 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 185)
        {
            currentBlock = IBlock(1);
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 185 &&
                 mousePosition.x < width * 30 + 20 + 255 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 115 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 185)
        {
            currentBlock = IBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 270 &&
                 mousePosition.x < width * 30 + 20 + 340 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 115 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 185)
        {
            currentBlock = IBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 15 &&
                 mousePosition.x < width * 30 + 20 + 75 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 190 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 245)
        {
            currentBlock = JBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 100 &&
                 mousePosition.x < width * 30 + 20 + 160 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 190 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 245)
        {
            currentBlock = JBlock(1);
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 175 &&
                 mousePosition.x < width * 30 + 20 + 235 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 190 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 245)
        {
            currentBlock = JBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 270 &&
                 mousePosition.x < width * 30 + 20 + 330 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 190 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 245)
        {
            currentBlock = JBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 15 &&
                 mousePosition.x < width * 30 + 20 + 75 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 250 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 305)
        {
            currentBlock = LBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 100 &&
                 mousePosition.x < width * 30 + 20 + 160 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 250 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 305)
        {
            currentBlock = LBlock(1);
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 175 &&
                 mousePosition.x < width * 30 + 20 + 235 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 250 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 305)
        {
            currentBlock = LBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 270 &&
                 mousePosition.x < width * 30 + 20 + 330 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 250 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 305)
        {
            currentBlock = LBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 15 &&
                 mousePosition.x < width * 30 + 20 + 85 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 310 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 385)
        {
            currentBlock = OBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 100 &&
                 mousePosition.x < width * 30 + 20 + 170 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 310 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 385)
        {
            currentBlock = OBlock(1);
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 185 &&
                 mousePosition.x < width * 30 + 20 + 255 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 310 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 385)
        {
            currentBlock = OBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 270 &&
                 mousePosition.x < width * 30 + 20 + 340 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 310 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 385)
        {
            currentBlock = OBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 15 &&
                 mousePosition.x < width * 30 + 20 + 75 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 390 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 445)
        {
            currentBlock = SBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 100 &&
                 mousePosition.x < width * 30 + 20 + 160 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 390 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 445)
        {
            currentBlock = SBlock(1);
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 185 &&
                 mousePosition.x < width * 30 + 20 + 245 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 390 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 445)
        {
            currentBlock = SBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 270 &&
                 mousePosition.x < width * 30 + 20 + 330 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 390 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 445)
        {
            currentBlock = SBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 15 &&
                 mousePosition.x < width * 30 + 20 + 75 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 450 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 505)
        {
            currentBlock = TBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 100 &&
                 mousePosition.x < width * 30 + 20 + 160 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 450 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 505)
        {
            currentBlock = TBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 185 &&
                 mousePosition.x < width * 30 + 20 + 245 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 450 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 505)
        {
            currentBlock = TBlock(1);
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 270 &&
                 mousePosition.x < width * 30 + 20 + 330 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 450 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 505)
        {
            currentBlock = TBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 15 &&
                 mousePosition.x < width * 30 + 20 + 75 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 510 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 570)
        {
            currentBlock = ZBlock(1);
        }
        else if (mousePosition.x > width * 30 + 20 + 100 &&
                 mousePosition.x < width * 30 + 20 + 160 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 510 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 570)
        {
            currentBlock = ZBlock(1);
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 185 &&
                 mousePosition.x < width * 30 + 20 + 245 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 510 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 570)
        {
            currentBlock = ZBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
        else if (mousePosition.x > width * 30 + 20 + 270 &&
                 mousePosition.x < width * 30 + 20 + 330 &&
                 mousePosition.y > height * 30 / 2 - controlPanel.height / 2 + 510 &&
                 mousePosition.y < height * 30 / 2 - controlPanel.height / 2 + 570)
        {
            currentBlock = ZBlock(1);
            currentBlock.Rotate();
            currentBlock.Rotate();
            currentBlock.Rotate();
        }
    }
}
void Custom::placeBlock(int row, int col)
{
    // place block
    if (true)
    {
        std::vector<Position> tiles = currentBlock.GetCellPositions();
        for (Position item : tiles)
        {
            if (row + item.row < height && col + item.column < width)
                grid.grid[row + item.row][col + item.column] = currentBlock.id;
        }
    }
    grid.Draw();
}

void Custom::LoadControlPanel()
{
    // draw pictures from local
    Image image = LoadImage("pics/SRS-pieces.png"); // Loaded in CPU memory (RAM)
    controlPanel = LoadTextureFromImage(image);     // Image converted to texture, GPU memory (VRAM)
    UnloadImage(image);
}

void Custom::DrawControlPanel()
{
    DrawTexture(controlPanel, width * 30 + 30, height * 30 / 2 - controlPanel.height / 2 + 100, WHITE);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            DrawRectangle(width * 30 + 129 + 10 + j * 30 + 11, 64 + i * 30 + 11, 30 - 1, 30 - 1, {255, 255, 255, 255});
        }
    }
    currentBlock.Draw(width * 30 + 150, height * 30 / 2 - controlPanel.height / 2 - 30);
}

void Custom::ScreenShot()
{
    // Calculate the cropped image dimensions
    int cropWidth = width * 30 + 20;
    int cropHeight = height * 30 + 20;

    // Get full screen pixel data
    int renderWidth = GetScreenWidth();
    int renderHeight = GetScreenHeight();
    unsigned char *imgData = rlReadScreenPixels(renderWidth, renderHeight);

    // Validate that the crop dimensions do not exceed screen dimensions
    if (cropWidth > renderWidth || cropHeight > renderHeight)
    {
        TraceLog(LOG_ERROR, "Crop dimensions exceed screen dimensions");
        delete[] imgData;
        return;
    }

    // Allocate memory for the cropped data
    unsigned char *croppedData = new unsigned char[cropWidth * cropHeight * 4]; // 4 bytes per pixel (RGBA)

    // Extract the cropped region starting at (0, 0)
    for (int y = 0; y < cropHeight; y++)
    {
        for (int x = 0; x < cropWidth; x++)
        {
            int srcIndex = 4 * (y * renderWidth + x); // Full image index
            int dstIndex = 4 * (y * cropWidth + x);   // Cropped image index

            // Copy RGBA values
            croppedData[dstIndex + 0] = imgData[srcIndex + 0]; // Red
            croppedData[dstIndex + 1] = imgData[srcIndex + 1]; // Green
            croppedData[dstIndex + 2] = imgData[srcIndex + 2]; // Blue
            croppedData[dstIndex + 3] = imgData[srcIndex + 3]; // Alpha
        }
    }

    // Save the cropped image to a file
    FILE *file = fopen("number", "r");
    int number;
    if (file == NULL)
    {
        number = 0;
    }
    else
    {
        fscanf(file, "%d", &number);
        fclose(file);
    }
    file = fopen("number", "w");
    fprintf(file, "%d", number + 1);
    fclose(file);

    std::string fileName = "screenshot" + std::to_string(number) + ".png";

    stbi_write_png(fileName.c_str(), cropWidth, cropHeight, 4, croppedData, cropWidth * 4);

    // Cleanup
    delete[] imgData;
    delete[] croppedData;
}