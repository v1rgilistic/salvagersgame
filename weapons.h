#pragma once
#include "includes.h"
class Weapon {
public:
	string type;
	int damage;
	int thedamage();
	string findtype();
	Weapon(const std::string& type, int damage);
};