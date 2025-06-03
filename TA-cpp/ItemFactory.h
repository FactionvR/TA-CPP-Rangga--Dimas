#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

#include "Item.h"
#include <vector>
#include <memory>

using namespace std;

class ItemFactory {
public:
    static unique_ptr<Item> CreateRandomItem();
};

#endif
