//
// Created by Tristen.Horton on 10/22/2019.
//

#include <raylib.h>
#include <stdlib.h>
#include <math.h>
#include "editor.h"

typedef struct {
    int tileId;
    char patternMap;
} PaletteTile;

typedef struct {
    int tileCount;
    PaletteTile* tiles;
    Texture texture;
    int tileWidth;
    int tileHeight;
} Palette;

typedef struct {
    Palette palette;
    Vector2 pos;
    int width;
    int height;
    char* tileData;
} Editor;

Editor* BirdNewEditor(Vector2 pos, int width, int height) {
    Editor* editor = (Editor*)calloc(1, sizeof(Editor));
    size_t totalWidth = width * height;
    size_t paddedSize = (totalWidth + (totalWidth % sizeof(char))) / sizeof(char);
    editor->tileData = (char*)calloc(paddedSize, sizeof(char));
    editor->pos = pos;
    editor->width = width;
    editor->height = height;
    return editor;
}

void BirdFreeEditor(Editor* editor) {
    if (editor == NULL) return;
    if (editor->tileData != NULL) free(editor->tileData);
    free(editor);
}

