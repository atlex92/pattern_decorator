#pragma once
#include "atack_decorator.h"
#include "stdio.h"
#include <cstdlib>

struct AssasinAtackDecorator : virtual IAtackDecorator {
	explicit AssasinAtackDecorator(IUnit* const wrappee) : IAtackDecorator{ wrappee } {}

    //  Assassins have chance to atack twice
	void Atack(IUnit* unit) override {
		IAtackDecorator::Atack(unit);
		const bool is_critical_strike{ kCriticalStrikeChance_ * 100 >= std::rand() % 100 };
		printf("Assasin's atack effect: critical strike: %s\r\n", (is_critical_strike ? "YES" : "NO"));
		if (is_critical_strike) {
			printf("Assasin's SECOND ATACK\r\n");
			IAtackDecorator::Atack(unit);
		}
	}
private:
	static constexpr float kCriticalStrikeChance_{0.2f};
};