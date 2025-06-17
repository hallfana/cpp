#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complaint(std::string level) {
	Harl::ComplaintLevel levels[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	int i = 0;
	for (; i < 4; i++) {
		if (level == levels[i].level) {
			break;
		}
	}
	switch (i)
	{
		case 0:
			(this->*levels[0].function)();
			(this->*levels[1].function)();
			(this->*levels[2].function)();
			(this->*levels[3].function)();
			break;
		case 1:
			(this->*levels[1].function)();
			(this->*levels[2].function)();
			(this->*levels[3].function)();
			break;
		case 2:
			(this->*levels[2].function)();
			(this->*levels[3].function)();
			break;
		case 3:
			(this->*levels[3].function)();
			break;
		default:
			break;
	}
}