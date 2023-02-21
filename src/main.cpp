#include <iostream>
#include <memory>
#include "unit.h"
#include "orc.h"
#include "elf.h"
#include "assassin_atack_decorator.h"
#include "lifestealer_atack_decorator.h"

using namespace std;

/**
 * @brief Helper function to implement step-by-step fight between two units
 * 
 * @param first first unit to fight
 * @param second second unit to fight
 * @return IUnit* first/second unit, who lost the fight
 */
IUnit* makeFight(IUnit* const first, IUnit* const second);

int main() {

    srand(time(nullptr));
	std::unique_ptr<IUnit> orc{ new Orc };
	std::unique_ptr<IUnit> elf{ new Elf };

	IUnit* first_round_looser = makeFight(orc.get(), elf.get());
	IUnit* first_round_winner = (first_round_looser == elf.get()) ? orc.get() : elf.get();

	system("pause");
	system("cls");

	printf("now %s will get life steal effect!\r\n\r\n", first_round_looser->Name());

	system("pause");
	system("cls");

	std::unique_ptr<IUnit> unit_with_life_stealing{ new LifeStealerAtackDecorator{first_round_looser} };

	IUnit* second_round_looser = makeFight(unit_with_life_stealing.get(), first_round_winner);
	IUnit* second_round_winner = (second_round_looser == unit_with_life_stealing.get()) ? first_round_winner : unit_with_life_stealing.get();

	printf("now %s will get critical strike effect!\r\n\r\n", second_round_looser->Name());

	std::unique_ptr<IUnit> unit_with_critical_strike{ new AssasinAtackDecorator{second_round_looser} };

	makeFight(unit_with_critical_strike.get(), second_round_winner);
    return 0;
}

IUnit* makeFight(IUnit* const first, IUnit* const second) {

	first->ResetHp();
	second->ResetHp();

	printf("%s vs %s fight begins!\r\n\r\n", first->Name(), second->Name());
	system("pause");
	system("cls");
	size_t round{};

	while ((first->Hp() > 0.0) && (second->Hp() > 0.0)) {
		printf("Round #%u\r\n", ++round);;
		printf("%s attacks...\r\n", first->Name());
		first->Atack(second);
		printf("%s attacks...\r\n", second->Name());
		second->Atack(first);
		printf("%s's hp: %.2f, %s's hp: %.2f\r\n\r\n", first->Name(), first->Hp(), second->Name(), second->Hp());
		system("pause");
		system("cls");
	}

	bool is_first_winner{ first->Hp() > 0.0};
	printf("%s wins!\r\n\r\n", is_first_winner ? first->Name() : second->Name());

	return is_first_winner ? second : first;
}