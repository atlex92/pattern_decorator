#pragma once
#include "atack_decorator.h"
#include "stdio.h"

struct LifeStealerAtackDecorator : virtual IAtackDecorator {
	explicit LifeStealerAtackDecorator(IUnit* const wrappee) : IAtackDecorator{ wrappee } {}

    //  When atacks, lifestealer recover his HP
	void Atack(IUnit* unit) override {
		IAtackDecorator::Atack(unit);
		const auto life_steal_points{ AtackPower() * 0.5 };
		printf("Lifesteal atack effect: restoring %f HP\r\n", life_steal_points);
		wrappee_->SetHp(life_steal_points + wrappee_->Hp());
		if (wrappee_->Hp() > 100.0) {
			wrappee_->SetHp(100.0);
        }
	}
};