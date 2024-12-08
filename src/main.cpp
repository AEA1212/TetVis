#include <raylib.h>
#include "game.h"
#include "custom.h"
#include "colors.h"
#include <iostream>
#include <string.h>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    /*
    Step1: blank screen & Game Loop
    Defintions : variables +  objects
    Game Loop : updateing the positions and checking for collisions
    */

    // create window of size 300* 500 and with name "raylib Teteris" (Note: origin in computer graphics is top left corner)

    InitWindow(500, 620, "raylib Tetris");
    SetTargetFPS(60); // Set the frame rate to 60 frames per second (withouth this the game will run as fast as the computer can run it)

    Font font = LoadFontEx("Font/Tetris.ttf", 64, 0, 0);

    Game game = Game();
    int width = 20;
    int height = 23;
    Custom custom = Custom(width, height);
    custom.LoadControlPanel();

    enum Mode
    {
        Menu,
        Play,
        Custom
    };
    Mode currentMode = Menu;

    while (WindowShouldClose() == false) // This function returns true if the close button or esc key is pressed
    {
        if (currentMode == Menu)
        {
            BeginDrawing();
            ClearBackground(darkBlue);

            DrawRectangleRounded({40, 10, 440, 60}, 0.2, 0, lightBlue);
            DrawTextEx(font, "Custom Build Mode", Vector2{45, 20}, 38, 2, WHITE);

            DrawRectangleRounded({115, 310, 250, 60}, 0.2, 0, lightBlue);
            DrawTextEx(font, "Play Mode", Vector2{125, 320}, 38, 2, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousePosition = GetMousePosition();
                if (CheckCollisionPointRec(mousePosition, {40, 10, 440, 60}))
                {
                    currentMode = Custom;
                    std::cout << "Custom Build Mode is not implemented yet" << std::endl;
                }
                else if (CheckCollisionPointRec(mousePosition, {115, 310, 250, 60}))
                {
                    currentMode = Play;
                }
            }

            EndDrawing();
        }
        else if (currentMode == Play)
        {
            game.HandleInput();
            if (EventTriggered(0.2))
            {
                game.MoveBlockDown();
            }

            BeginDrawing();
            ClearBackground(darkBlue);

            // score board
            DrawTextEx(font, "SCORE", Vector2{330, 15}, 38, 2, WHITE);
            DrawRectangleRounded({320, 55, 170, 60}, 0.2, 0, lightBlue);
            char scoreText[10];
            sprintf(scoreText, "%d", game.score);
            Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
            DrawTextEx(font, scoreText, Vector2{320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

            // next block board
            DrawTextEx(font, "NEXT", Vector2{347, 140}, 38, 2, WHITE);
            DrawRectangleRounded({320, 180, 170, 180}, 0.2, 0, lightBlue);
            // Draw the next will be called in the game.Draw() function

            // Game
            game.Draw();

            // game over board
            if (game.gameOver)
            {
                DrawRectangleRounded({30, 240, 260, 60}, 0.2, 0, lightBlue);
                DrawTextEx(font, "GAME OVER", Vector2{40, 250}, 36, 2, WHITE);
            }

            EndDrawing();
        }
        else if (currentMode == Custom)
        {

            // Custom mode
            SetWindowSize(30 * width + 400, 30 * height + 20);

            BeginDrawing();
            ClearBackground(darkBlue);
            custom.DrawControlPanel();

            custom.chooseBlock();
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousePosition = GetMousePosition(); // relative to the window and the the width is 30 of every grid cell
                std::cout << "Mouse Position: " << mousePosition.x << " " << mousePosition.y << std::endl;
                custom.placeBlock((mousePosition.y - 10) / 30, (mousePosition.x - 10) / 30);
            }
            custom.grid.Draw();
            EndDrawing();
        }
    }

    CloseWindow();
}
