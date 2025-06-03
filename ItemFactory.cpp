#include "ItemFactory.h"
#include "Assets.h"  // Untuk akses texture

#include <cstdlib>
#include <memory>

using namespace std;

unique_ptr<Item> ItemFactory::CreateRandomItem() {
    
    int type = rand() % 3;
    float x = static_cast<float>(rand() % (1070 - 70)); // 800 - max width item
    float speed = 15 + rand() % 3;

    switch (type) {
        case 0: // Apple
            return make_unique<Item>(x, 0, 100, 100, speed, 10, ItemType::Apple, &Assets::appleTex);
        case 1: // Bomb
            return make_unique<Item>(x, 0, 120, 120, 20, -20, ItemType::Bomb, &Assets::bombTex);
        default: // Gold
            return make_unique<Item>(x, 0, 100, 100, speed, 20, ItemType::Gold, &Assets::goldTex);
    }
}
