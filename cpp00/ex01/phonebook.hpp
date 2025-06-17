#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cstdlib>

class contact {
	public:
		contact();
		~contact();
		std::string get(std::string key);
		std::string set(std::string key, std::string value);
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
};

class phonebook {
	public:
		phonebook();
		~phonebook();
		void add(void);
		void search(void);
	private:
		::contact contact_list[8];
};

#endif