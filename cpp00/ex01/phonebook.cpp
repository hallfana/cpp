#include "phonebook.hpp"

contact::contact(void) {
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->secret = "";
}

contact::~contact(void) {}

std::string contact::set(std::string key, std::string value) {
	if (key == "first_name")
		return this->first_name = value, "success";
	else if (key == "last_name")
		return this->last_name = value, "success";
	else if (key == "nickname")
		return this->nickname = value, "success";
	else if (key == "phone_number")
		return this->phone_number = value, "success";
	else if (key == "secret")
		return this->secret = value, "success";
	else
		return "failure, key not found";
}

std::string contact::get(std::string key) {
	if (key == "first_name")
		return this->first_name;
	else if (key == "last_name")
		return this->last_name;
	else if (key == "nickname")
		return this->nickname;
	else if (key == "phone_number")
		return this->phone_number;
	else if (key == "secret")
		return this->secret;
	else
		return "failure, key not found";
}

phonebook::phonebook() {}
phonebook::~phonebook() {}

void phonebook::add(void) {
	static int current_index = 0;
	std::string fn, ln, nm, pn, s;
	
	std::cout << std::endl << "[NEW CONTACT]\nFIRST NAME: ";
	std::cin >> fn;
	if (fn == "")
		std::cout<<"please provide a valide value [FIRST NAME]";
	std::cout << "LAST NAME: ";
	std::cin >> ln;
	if (ln == "")
		std::cout<<"please provide a valide value [LAST NAME]";
	std::cout << "NICKNAME: ";
	std::cin >> nm;
	if (nm == "")
		std::cout<<"please provide a valide value [NICKNAME]";
	std::cout << "PHONE NUMBER: ";
	std::cin >> pn;
	if (pn == "")
		std::cout<<"please provide a valide value [PHONE NUMBER]";
	std::cout << "SECRET: ";
	std::cin >> s;
	if (s == "")
		std::cout<<"please provide a valide value [SECRET]";

	if (current_index > 7) {
		current_index = 0;
	}

	this->contact_list[current_index].set("first_name", fn);
	this->contact_list[current_index].set("last_name", ln);
	this->contact_list[current_index].set("nickname", nm);
	this->contact_list[current_index].set("phone_number", pn);
	this->contact_list[current_index].set("secret", s);
	current_index++;
}

void phonebook::search(void) {
	int c = 0;
	for (int i = 0; i < 8; i++) {
		if (this->contact_list[i].get("first_name").length() > 0)
			c++;
	}
	if (c == 0) {
		std::cout << std::endl << "[!]Please enter at least one contact to search inside your phonebook." << std::endl << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << "index|first name|last name |nickname  " << std::endl;
	for (int i = 0; i < 8; i++) {
		if (this->contact_list[i].get("first_name").length() > 0) {
			std::string fn, ln, nm;
			std::string gfn, gln, gnm;
			gfn = this->contact_list[i].get("first_name");
			gln = this->contact_list[i].get("last_name");
			gnm = this->contact_list[i].get("nickname");
			fn = "          ";
			ln = "          ";
			nm = "          ";
			if (gfn.length() > 10) {
				fn = gfn.substr(0, 9);
				fn.append(".");
			} else {
				fn = gfn;
				for (int j = 0; j < (int)(10 - gfn.length()); j++) 
					fn.append(" ");
			}
			if (gln.length() > 10) {
				ln = gln.substr(0, 9);
				ln.append(".");
			} else {
				ln = gln;
				for (int j = 0; j < (int)(10 - gln.length()); j++) 
					ln.append(" ");
			}
			if (gnm.length() > 10) {
				nm = gnm.substr(0, 9);
				nm.append(".");
			} else {
				nm = gnm;
				for (int j = 0; j < (int)(10 - gnm.length()); j++) 
					nm.append(" ");
			}
			std::cout << "    " << i << "|" << fn << "|" << ln << "|" << nm << std::endl;
		}
	}
	std::cout << std::endl << "Enter the index of contact: ";
	std::string input;
	std::cin >> input;
	if (input == "") {
		std::cout << std::endl << "[!]You need to provide a valid index[0-7]" << std::endl;
		return;
	}

	c = atoi(input.c_str());
	if ((c == 0 && input[0] != '0') || (c > 7 || c < 0)) {
		std::cout << "[!]You need to provide a valid index[0-7]" << std::endl;
		return;
	}

	std::string i1, i2, i3, i4, i5;
	i1 = this->contact_list[c].get("first_name");
	i2 = this->contact_list[c].get("last_name");
	i3 = this->contact_list[c].get("nickname");
	i4 = this->contact_list[c].get("phone_number");
	i5 = this->contact_list[c].get("secret");
	std::cout << "\nFIRST NAME: " << i1 << "\nLAST NAME: " << i2 << "\nNICKNAME: " << i3 << "\nPHONE NUMBER: " << i4 << "\nDARKEST SECRET: " << i5 << std::endl << std::endl;
	return;
}

int main(void) {
	phonebook pb;

	std::string command;
	while (true) {
		std::cout << "[PHONEBOOK TERMINAL]>> ";
		std::cin >> command;
		if (command.compare("ADD") == 0) {
			pb.add();
		} else if (command.compare("SEARCH") == 0) {
			pb.search();
		} else if (command.compare("EXIT") == 0) {
			break;
		}
	}
}