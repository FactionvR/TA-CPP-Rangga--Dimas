#include "Command.h"
#include "Player.h"

void MoveLeftCommand::Execute(Player& player) {
    player.MoveLeft();
}

void MoveRightCommand::Execute(Player& player) {
    player.MoveRight();
}
