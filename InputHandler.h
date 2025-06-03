#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Command.h"
#include <memory>

using namespace std;

class InputHandler {
private:
    unique_ptr<Command> leftCommand;
    unique_ptr<Command> rightCommand;

public:
    InputHandler();

    Command* HandleInput();
};

#endif
