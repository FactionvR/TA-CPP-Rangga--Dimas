#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
private:
    Rectangle rect;
    float speed;
    Texture2D* texture;  // Tambahkan pointer ke texture

public:
    Player(float x, float y, float width, float height, float speed, Texture2D* texture);
    
    void SetSpeed(float newSpeed);
    void MoveLeft();
    void MoveRight();
    void Draw() const;
    Rectangle GetRect() const;
};

#endif
