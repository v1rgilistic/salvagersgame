#include "weapons.h"
#include "includes.h"

Weapon::Weapon(const std::string& type, int damage)
	: type(type), damage(damage) {}
string Weapon::findtype() {
	return type;
}
int Weapon::thedamage() {
	return damage;
}