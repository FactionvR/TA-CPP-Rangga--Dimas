#include "Item.h"
#include "Assets.h"

Item::Item(float x, float y, float width, float height, float speed, int scoreValue, ItemType type, Texture2D* texture)
    : rect{ x, y, width, height },  speed(speed), scoreValue(scoreValue),  texture(texture) {}


void Item::Update() {
    rect.y += speed;
}

void Item::Draw() const {
    if (texture) {
        DrawTexture(*texture, rect.x, rect.y, WHITE);
        DrawTexturePro(
            *texture,
            { 0, 0, static_cast<float>(texture->width), static_cast<float>(texture->height) },
            rect,
            {0, }, // origin
            0.0f,
            WHITE
        );
    }
}


bool Item::CheckCollision(Rectangle playerRect) const {
    return CheckCollisionRecs(rect, playerRect);
}

int Item::GetScoreValue() const {
    return scoreValue;
}

bool Item::IsOffScreen() const {
    return rect.y > 1000;
}


