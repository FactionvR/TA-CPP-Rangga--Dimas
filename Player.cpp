#include "Player.h"

Player::Player(float x, float y, float width, float height, float speed, Texture2D* texture)
    : rect{ x, y, width, height }, speed(speed), texture(texture) {}

void Player::SetSpeed(float newSpeed) {
    speed = newSpeed;
}

void Player::MoveLeft() {
    rect.x -= speed;
    if (rect.x < 0) rect.x = 0;
}

void Player::MoveRight() {
    rect.x += speed;
    if (rect.x + rect.width > 1070) rect.x = 1070 - rect.width;
}

void Player::Draw() const {
    if (texture) {
        DrawTexturePro(
            *texture,
            { 0, 0, static_cast<float>(texture->width), static_cast<float>(texture->height) },
            rect,
            { 0, 0 },
            0.0f,
            WHITE
        );
    }
}
    
Rectangle Player::GetRect() const {
    return rect;
}
