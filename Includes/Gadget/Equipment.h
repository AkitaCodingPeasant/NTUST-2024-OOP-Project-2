#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <cstdint>
#include <vector>
#include <set>
#include "Accessory.h"
#include "Armor.h"
#include "Weapon.h"
#include "Attribute.h"
#include "Skill.h"

class Equipment {
private:
    Weapon weapon;
    Armor armor;
    Accessory accessory;

public:
    Equipment();  // Default constructor

    void SetWeapon(const Weapon&);
    void SetArmor(const Armor&);
    void SetAccessory(const Accessory&);

    Weapon GetWeapon() const;
    Armor GetArmor() const;
    Accessory GetAccessory() const;

public:
    Attribute GetTotalAttribute() const;
    Skill GetTotalSkills() const;
};

#endif
