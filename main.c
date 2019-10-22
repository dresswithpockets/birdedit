/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>
#include "app.h"
#define RAYGUI_STATIC
#define RAYGUI_SUPPORT_RICONS
#include "gui.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1200;
    int screenHeight = 1000;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "birdedit");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    AppState* appState = BirdNewAppState();
    GuiState* guiState = BirdNewGuiState();
    BirdSetDefaultGuiState(guiState, appState);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        BirdUpdateAppState(appState);
        BirdUpdateGuiState(guiState, appState);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        BirdDrawGuiState(guiState, appState);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    BirdFreeGuiState(guiState);
    BirdFreeAppState(appState);

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
