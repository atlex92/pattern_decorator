#pragma once
#include "unit.h"
#include "stdio.h"
#include <cstdlib>

struct Elf : IUnit {
    //  Elfs can dodge a hit
	void GetDamage(const float damage) override {
		const bool evasion{ kEvasionChance * 100 >= std::rand() % 100 };
		if (!evasion) {
			IUnit::GetDamage(damage);
        }
		else {
			printf("Elf was managed to evade!\r\n");
        }
	}

	float AtackPower() const override {
		return 8.0;
	}

	const char* const Name() const override {
		return "Elf";
	}
private:
	static constexpr float kEvasionChance{0.2f};
};