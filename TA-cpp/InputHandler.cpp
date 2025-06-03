#include "InputHandler.h"
#include "Player.h"
#include "raylib.h"

using namespace std;

InputHandler::InputHandler() {
    leftCommand = make_unique<MoveLeftCommand>();
    rightCommand = make_unique<MoveRightCommand>();
}

Command* InputHandler::HandleInput() {
    if (IsKeyDown(KEY_LEFT)) return leftCommand.get();
    if (IsKeyDown(KEY_RIGHT)) return rightCommand.get();
    return nullptr;
}
