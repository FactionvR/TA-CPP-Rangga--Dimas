#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include <string>

enum class ItemType {
    Apple,
    Bomb,
    Gold
};

class Item {
private:
    Rectangle rect;              // Untuk posisi dan ukuran (masih dipakai untuk collision)
    float speed;
    int scoreValue;
    ItemType type;
    Texture2D* texture;          // Texture untuk gambar

public:
    Item(float x, float y, float width, float height, float speed, int scoreValue, ItemType type, Texture2D* texture);
    virtual ~Item() {}

    virtual void Update();
    virtual void Draw() const;

    bool CheckCollision(Rectangle playerRect) const;
    int GetScoreValue() const;
    bool IsOffScreen() const;

    ItemType Getype() const;
    Rectangle GetRect() const;
};

#endif
