#pragma once

struct IUnit {
	virtual ~IUnit() = default;
	virtual float AtackPower() const = 0;
	virtual const char* const Name() const = 0;

	virtual void GetDamage(const float damage) {
		printf("%s receives %.2f damage\r\n", Name(), damage);
		hp_ -= damage;
		if (hp_ < 0.0) {
			hp_ = 0.0;
        }
	}

	virtual void Atack(IUnit* unit) {
        unit->GetDamage(AtackPower());
    }

	virtual float Hp() const {
        return hp_;
    }

	virtual void ResetHp() {
        hp_ = 100.0;
    }

	void SetHp(const float value) {
        hp_ = value;
    }
protected:
	float hp_{100.0};
};
