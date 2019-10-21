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

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_RICONS
#include "raygui.h"

typedef struct {
    Rectangle rect;
} Panel;

typedef struct {
    Rectangle rect;
    char* text;
    int value;
    int minValue;
    int maxValue;
    bool editMode;
} Spinner;

typedef struct {
    Rectangle rect;
    char* text;
} Button;

typedef struct {
    Rectangle rect;
    char* text;
    bool active;
} ToggleButton;

typedef struct {
    Rectangle rect;
    char* text;
    int activeIndex;
} ToggleGroup;

typedef struct {
    Rectangle rect;
    char* text;
} Label;

typedef struct {
    Panel menuPanel;
    Button newButton;
    Button openButton;
    Button saveButton;

    Label brushesLabel;
    ToggleGroup brushToggles;

    Spinner tileBrushSize;
    Spinner lineBrushThickness;
} GuiState;

GuiState* NewGuiState() {
    return (GuiState*)malloc(sizeof(GuiState));
}

void FreeState(GuiState* state) {
    if (state == NULL) return;
    free(state);
}

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

    GuiState* guiState = NewGuiState();
    guiState->menuPanel = (Panel) {
        (Rectangle){ 0.0, 0.0, screenWidth, 33.0 }
    };
    guiState->newButton = (Button) {
        (Rectangle){ 3.0, 3.0, 27.0, 27.0 },
        "#8#"
    };
    guiState->openButton = (Button) {
        (Rectangle){ 33.0, 3.0, 27.0, 27.0 },
        "#5#"
    };
    guiState->saveButton = (Button) {
        (Rectangle){ 63.0, 3.0, 27.0, 27.0 },
        "#6#"
    };
    guiState->brushesLabel = (Label) {
        (Rectangle){ 93.0, 13.0, 64.0, 3.0 },
        "Brushes:"
    };
    guiState->brushToggles = (ToggleGroup) {
        (Rectangle){ 157.0, 3.0, 27.0, 27.0 },
        "#24#;#192#;#63#",
        0
    };
    guiState->tileBrushSize = (Spinner) {
            (Rectangle){ 290.0, 3.0, 100.0, 27.0 },
            "Size:",
            1.0f,
            1.0f,
            32.0f,
            false
    };

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        GuiPanel(guiState->menuPanel.rect);
        if (GuiButton(guiState->newButton.rect, guiState->newButton.text)) {
            // clicked
        }
        if (GuiButton(guiState->openButton.rect, guiState->openButton.text)) {
            // clicked
        }
        if (GuiButton(guiState->saveButton.rect, guiState->saveButton.text)) {
            // clicked
        }

        GuiLabel(guiState->brushesLabel.rect, guiState->brushesLabel.text);

        guiState->brushToggles.activeIndex = GuiToggleGroup(guiState->brushToggles.rect, guiState->brushToggles.text, guiState->brushToggles.activeIndex);
        switch (guiState->brushToggles.activeIndex) {
            case 0:
                if (GuiSpinner(guiState->tileBrushSize.rect, guiState->tileBrushSize.text, &guiState->tileBrushSize.value, guiState->tileBrushSize.minValue, guiState->tileBrushSize.maxValue, guiState->tileBrushSize.editMode))
                    guiState->tileBrushSize.editMode = !guiState->tileBrushSize.editMode;
                break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
