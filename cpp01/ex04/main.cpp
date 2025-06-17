#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void replaceStrings(std::ofstream &fileOut, std::string s1, std::string s2, std::string input) {
	size_t pos = input.find(s1);
	if (pos == std::string::npos) {
		fileOut << input;
		return ;
	} else {
		fileOut << input.substr(0, pos);
		fileOut << s2;
		size_t toSkip = pos + s1.length();
		replaceStrings(fileOut, s1, s2, input.substr(toSkip));
	}
}

int main(int argc, char **argv) {
	if (argc != 4){
		std::cerr << "wrong number of args, ./replace file s1 s2" << std::endl; return 1;}
	std::string string_to_replace = argv[2];
	std::string string_replacement = argv[3];
	std::string file = argv[1];
	std::string buffer;
	std::ifstream fileIN;
	std::ofstream fileOUT;
	fileIN.open(file.c_str());
	if (fileIN.good() == false){
		std::cerr << "input file error" << std::endl; return 1;}
	fileOUT.open(file.append(".replace").c_str());
	if (fileOUT.good() == false){
		std::cerr << "outptu file error" << std::endl; return 1;}
	while (getline(fileIN, buffer))
		replaceStrings(fileOUT, string_to_replace, string_replacement, buffer + '\n');
	fileIN.close();
	fileOUT.close();
	return 0;
}