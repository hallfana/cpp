#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		typedef void (Harl::*ComplaintFunction)(void);
		struct ComplaintLevel {
			std::string level;
			ComplaintFunction function;
		};
		static const ComplaintLevel levels[4];
	public:
		void complaint(std::string level);
};

#endif