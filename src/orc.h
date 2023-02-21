#pragma once
#include "unit.h"

struct Orc : IUnit {
    //  Orcs receive reduced damage
	void GetDamage(const float damage) override {
		IUnit::GetDamage(damage - 1.0);
	}

	float AtackPower() const override {
		return 10.0;
	}

	const char* const Name() const override {
		return "Orc";
	}
};