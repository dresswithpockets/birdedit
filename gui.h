//
// Created by Ashley on 10/21/2019.
//

#ifndef BIRDEDIT_GUI_H
#define BIRDEDIT_GUI_H

#include "raygui.h"
#include "app.h"

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
    bool clicked;
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
    Rectangle rect;
    char* text;
    int value;
    int minValue;
    int maxValue;
    bool editMode;
} ValueBox;

typedef struct {
    Rectangle rect;
    Rectangle content;
    Vector2 scroll;
} ScrollPanel;

typedef struct {
    Panel menuPanel;
    Button newButton;
    Button openButton;
    Button saveButton;

    Label brushesLabel;
    ToggleGroup brushToggles;

    Spinner tileBrushSize;
    Spinner lineBrushThickness;

    Panel palettePanel;
    Label paletteLabel;

    Panel hierarchyPanel;
    Label hierarchyLabel;
    ScrollPanel hierarchyScrollPanel;

    Panel propertiesPanel;
    Label propertiesLabel;
    Label nodePositionLabel;
    ValueBox nodeXValue;
    ValueBox nodeYValue;
    Label nodeSizeLabel;
    ValueBox nodeWidthValue;
    ValueBox nodeHeightValue;
} GuiState;

GuiState* BirdNewGuiState();
void BirdFreeGuiState(GuiState* guiState);
void BirdSetDefaultGuiState(GuiState* guiState, AppState* appState);
void BirdUpdateGuiState(GuiState* guiState, AppState* appState);
void BirdDrawGuiState(GuiState* guiState, AppState* appState);

#endif //BIRDEDIT_GUI_H
