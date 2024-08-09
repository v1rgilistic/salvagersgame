#pragma once
#include "includes.h"
#include <SFML/Graphics.hpp>
#include "player.h"
using namespace sf;
class Item {
protected:
    std::string name;
    std::string type;

public:
    Item(const std::string& itemName, const std::string& itemType);
    virtual void use(player& player) = 0;  // Pure virtual function
    virtual std::string getName() const;
};

class HpRestoreItem : public Item {
    int hpRestorePercentage;

public:
    HpRestoreItem(const std::string& itemName, int hpRestorePercentage);
    void use(player& player) override;
};

class InventoryExtendingItem : public Item {
    int extraSpaces;

public:
    InventoryExtendingItem(const std::string& itemName, int extraSpaces);
    void use(player& player) override;
};

class ImmunityItem : public Item {
    int extraDefense;
    int duration;

public:
    ImmunityItem(const std::string& itemName, int extraDefense, int duration);
    void use(player& player) override;
};