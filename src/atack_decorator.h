#pragma once
#include "unit.h"

struct IAtackDecorator : virtual IUnit {
	explicit IAtackDecorator(IUnit* const wrappee) : wrappee_{ wrappee } {}

	void Atack(IUnit* unit) override {
		wrappee_->Atack(unit);
	}

	float AtackPower() const override {
		return wrappee_->AtackPower();
	}

	const char* const Name() const override {
		return wrappee_->Name();
	}

	void GetDamage(const float damage) override {
		wrappee_->GetDamage(damage);
	}

	float Hp() const override {
		return wrappee_->Hp();
	}

	void ResetHp() override{
		return wrappee_->ResetHp();
	}
	
protected:
	IUnit* wrappee_{nullptr};
};
