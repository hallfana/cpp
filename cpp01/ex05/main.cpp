#include "Harl.hpp"

int main(void) {
	Harl h;

	std::cout << "[DEBUG] ";
	h.complaint("DEBUG");
	std::cout << "[INFO] ";
	h.complaint("INFO");
	std::cout << "[WARNING] ";
	h.complaint("WARNING");
	std::cout << "[ERROR] ";
	h.complaint("ERROR");

	return 0;
}