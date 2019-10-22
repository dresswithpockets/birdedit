//
// Created by Ashley on 10/21/2019.
//

#include "stdlib.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_RICONS
#include "gui.h"

GuiState* BirdNewGuiState() {
    return (GuiState*)malloc(sizeof(GuiState));
}

void BirdFreeGuiState(GuiState* guiState) {
    if (guiState == NULL) return;
    free(guiState);
}

void BirdSetDefaultGuiState(GuiState* guiState, AppState* appState) {
    guiState->menuPanel = (Panel) {
        (Rectangle){ 0.0f, 0.0f, appState->screenSize.x - 250.0f, 33.0f }
    };
    guiState->newButton = (Button) {
        (Rectangle){ 3.0f, 3.0f, 27.0f, 27.0f },
        "#8#"
    };
    guiState->openButton = (Button) {
        (Rectangle){ 33.0f, 3.0f, 27.0f, 27.0f },
        "#5#"
    };
    guiState->saveButton = (Button) {
        (Rectangle){ 63.0f, 3.0f, 27.0f, 27.0f },
        "#6#"
    };
    guiState->brushesLabel = (Label) {
        (Rectangle){ 105.0f, 15.0f, 64.0f, 3.0f },
        "Brushes:"
    };
    guiState->brushToggles = (ToggleGroup) {
        (Rectangle){ 157.0f, 3.0f, 27.0f, 27.0f },
        "#24#;#192#;#63#",
        0
    };
    guiState->tileBrushSize = (Spinner) {
        (Rectangle){ 290.0f, 3.0f, 100.0f, 27.0f },
        "Size:",
        1,
        1,
        32,
        false
    };
    guiState->lineBrushThickness = (Spinner) {
        (Rectangle){ 310.0f, 3.0f, 100.0f, 27.0f },
        "Thickness:",
        1,
        1,
        32,
        false
    };

    guiState->palettePanel = (Panel) {
        (Rectangle){ appState->screenSize.x - 250.0f, 0.0f, 250.0f, appState->screenSize.y / 2.0f }
    };
    guiState->paletteLabel = (Label) {
        (Rectangle){ guiState->palettePanel.rect.x + 3.0f, guiState->palettePanel.rect.y + 3.0f, 247.0f, 27.0f },
        "Palettes"
    };

    guiState->hierarchyPanel = (Panel) {
        (Rectangle){ appState->screenSize.x - 250.0f, appState->screenSize.y / 2.0f, 250.0f, appState->screenSize.y / 4.0f }
    };
    guiState->hierarchyLabel = (Label) {
        (Rectangle){ guiState->hierarchyPanel.rect.x + 3.0f, guiState->hierarchyPanel.rect.y + 3.0f, 247.0f, 27.0f },
        "Hierarchy"
    };

    guiState->propertiesPanel = (Panel) {
        (Rectangle){ appState->screenSize.x - 250.0f, 3.0f * appState->screenSize.y / 4.0f, 250.0f, appState->screenSize.y / 4.0f }
    };
    guiState->propertiesLabel = (Label) {
        (Rectangle){ guiState->propertiesPanel.rect.x + 3.0f, guiState->propertiesPanel.rect.y + 3.0f, 247.0f, 27.0f },
        "Properties"
    };
}

void BirdUpdateGuiState(GuiState* guiState, AppState* appState) {
    guiState->menuPanel.rect.width = appState->screenSize.x - 250.0f;

    guiState->palettePanel.rect.x = appState->screenSize.x - 250.0f;
    guiState->palettePanel.rect.height = appState->screenSize.y / 2.0f;

    guiState->paletteLabel.rect.x = guiState->palettePanel.rect.x + 3.0f;
    guiState->paletteLabel.rect.y = guiState->palettePanel.rect.y + 3.0f;

    guiState->hierarchyPanel.rect.x = appState->screenSize.x - 250.0f;
    guiState->hierarchyPanel.rect.y = appState->screenSize.y / 2.0f;
    guiState->hierarchyPanel.rect.height = appState->screenSize.y / 4.0f;

    guiState->hierarchyLabel.rect.x = guiState->hierarchyPanel.rect.x + 3.0f;
    guiState->hierarchyLabel.rect.y = guiState->hierarchyPanel.rect.y + 3.0f;

    guiState->propertiesPanel.rect.x = appState->screenSize.x - 250.0f;
    guiState->propertiesPanel.rect.y = 3.0f * appState->screenSize.y / 4.0f;
    guiState->propertiesPanel.rect.height = appState->screenSize.y / 4.0f;

    guiState->propertiesLabel.rect.x = guiState->propertiesPanel.rect.x + 3.0f;
    guiState->propertiesLabel.rect.y = guiState->propertiesPanel.rect.y + 3.0f;
}

void BirdDrawGuiButton(Button* button) {
    button->clicked = GuiButton(button->rect, button->text);
}

void BirdDrawGuiToggleGroup(ToggleGroup* toggleGroup) {
    toggleGroup->activeIndex = GuiToggleGroup(toggleGroup->rect, toggleGroup->text, toggleGroup->activeIndex);
}

void BirdDrawGuiSpinner(Spinner* spinner) {
    if (GuiSpinner(spinner->rect, spinner->text, &spinner->value, spinner->minValue, spinner->maxValue, spinner->editMode)) {
        spinner->editMode = !spinner->editMode;
    }
}

void BirdDrawLabelStyle(Label* label, GuiControlProperty property, int value)
{
    int prevStyle = GuiGetStyle(LABEL, property);
    GuiSetStyle(LABEL, property, value);
    GuiLabel(label->rect, label->text);
    GuiSetStyle(LABEL, property, prevStyle);
}

void BirdDrawGuiState(GuiState* guiState, AppState* appState) {
    GuiPanel(guiState->menuPanel.rect);
    BirdDrawGuiButton(&guiState->newButton);
    BirdDrawGuiButton(&guiState->openButton);
    BirdDrawGuiButton(&guiState->saveButton);

    GuiLabel(guiState->brushesLabel.rect, guiState->brushesLabel.text);

    BirdDrawGuiToggleGroup(&guiState->brushToggles);
    switch (guiState->brushToggles.activeIndex) {
        case 0:
            BirdDrawGuiSpinner(&guiState->tileBrushSize);
            break;
        case 1:
            BirdDrawGuiSpinner(&guiState->lineBrushThickness);
            break;
    }

    GuiPanel(guiState->palettePanel.rect);
    BirdDrawLabelStyle(&guiState->paletteLabel, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);

    GuiPanel(guiState->hierarchyPanel.rect);
    BirdDrawLabelStyle(&guiState->hierarchyLabel, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);

    GuiPanel(guiState->propertiesPanel.rect);
    BirdDrawLabelStyle(&guiState->propertiesLabel, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
}