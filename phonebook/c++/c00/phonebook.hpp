#pragma once

#include <iostream>
#include <string>
#include "contact.hpp"

class Phonebook
{
	private:
		Contact contact[8];
		int  i;
		int CountContact;
	public:
		Phonebook();
		~Phonebook();

		void Add();
		void Search();
		void Exit();

};

void base_print();
void check_len(std::string str);
std::string over_len(std::string str);
void print_form(std::string str);

