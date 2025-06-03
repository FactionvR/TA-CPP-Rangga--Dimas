#ifndef COMMAND_H
#define COMMAND_H

class Player;

class Command {
public:
    virtual ~Command() {}
    virtual void Execute(Player& player) = 0;
};

class MoveLeftCommand : public Command {
public:
    void Execute(Player& player) override;
};

class MoveRightCommand : public Command {
public:
    void Execute(Player& player) override;
};

#endif
