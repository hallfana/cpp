#include <iostream>
#define LOG(x) std::cout << (char)std::toupper(x)

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		std::string str(argv[i]);
		for (int j = 0; j < (int)str.length(); j++) {
			LOG(str[j]);
		}
		if (i+1 < argc)
			std::cout << " ";
	}
	std::cout << std::endl;

	return 0;
}