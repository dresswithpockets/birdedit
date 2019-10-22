//
// Created by Ashley on 10/21/2019.
//

#ifndef BIRDEDIT_APP_H
#define BIRDEDIT_APP_H

#include <raylib.h>

typedef struct {
    Vector2 screenSize;
} AppState;

AppState* BirdNewAppState();
void BirdFreeAppState(AppState* appState);
void BirdUpdateAppState(AppState* appState);

#endif //BIRDEDIT_APP_H
