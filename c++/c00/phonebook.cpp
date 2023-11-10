#include <iostream>
#include "phonebook.hpp"
#include "contact.hpp"

Phonebook::Phonebook() {
	this->i = 0;
}
Phonebook::~Phonebook() {}

void Phonebook::Add()
{
	Contact& NewContact = this->contact[this->i % 8];

	std::string fname;
	while(1)
	{
		std::cout << "Type your First name"<<std::endl;
		std::getline(std::cin, fname); 
    	if (fname.empty())
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setFname(fname);
	
	std::string lname;
	while(1)
	{
		std::cout << "Type your Last name"<<std::endl;
		std::getline(std::cin, lname); 
    	if (lname.empty())
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setLname(lname);

	std::string nname;
	while(1)
	{
		std::cout << "Type your Nick name"<<std::endl;
		std::getline(std::cin, nname); 
    	if (nname.empty())
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setNname(nname);

	std::string num;
	while(1)
	{
		std::cout << "Type your Number"<<std::endl;
		std::getline(std::cin, num); 
    	if (num.empty())
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setNum(num);

	std::string secret;
	while(1)
	{
		std::cout << "Type your Secret"<<std::endl;
		std::getline(std::cin, secret); 
    	if (secret.empty())
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setSecret(secret);
	i++;
}