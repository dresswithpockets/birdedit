//
// Created by Ashley on 10/21/2019.
//

#include <stdlib.h>
#include "app.h"

AppState* BirdNewAppState() {
    return (AppState*)malloc(sizeof(AppState));
}

void BirdUpdateAppState(AppState* appState) {
    appState->screenSize = (Vector2){ GetScreenWidth(), GetScreenHeight() };
}

void BirdFreeAppState(AppState* appState) {
    if (appState == NULL) return;
    free(appState);
}