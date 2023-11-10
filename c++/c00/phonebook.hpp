#pragma once

#include <iostream>
#include <string>
#include "contact.hpp"

class Phonebook
{
	private:
		Contact contact[8];
		int  i;
	public:
		Phonebook();
		~Phonebook();

		void Add();
		void Search();
		void Exit();		
};

