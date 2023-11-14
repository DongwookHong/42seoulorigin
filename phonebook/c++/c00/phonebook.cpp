#include <iostream>
#include <string.h>
#include "phonebook.hpp"
#include "contact.hpp"
#include "iomanip"


void print_form(std::string str);
void base_print();
std::string over_len(std::string str);
void check_len(std::string str);

Phonebook::Phonebook() {
	this->i = 0;
	this->CountContact = 0;
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

	std::string index;
	index = (i)+'0';
	NewContact.setIndex(index);
	this->CountContact++;
	std::cout<<"You have been successfully added to your phonebook." <<std::endl;
	i++;
}

void Phonebook::Search()
{
	int i = 0;


	base_print();
	while(this->contact[i].getFname() != "")
	{
		check_len(this->contact[i].getIndex());
		check_len(this->contact[i].getFname());
		check_len(this->contact[i].getLname());
		check_len(this->contact[i].getNname());
		std::cout<<std::endl;
		i++;
	}

	std::string search;
	int num = 0;
	
	std::cout << "Choose Index you want!!!"<<std::endl;
	std::getline(std::cin, search); 
	num = search[0]-'0';
	if (num >=8  || num <0){
		std::cout<<"Please check index!!"<<std::endl;
		// break;
	}
	if (this->contact[num].getFname() == "" || this->contact[num].getLname() == "" || this->contact[num].getIndex()== ""|| \
		this->contact[num].getNname() == "" )
	{
		std::cout<<"Please check index!!"<<std::endl;
		// break;
	}
	else
	{
		base_print();
		check_len(this->contact[num].getIndex());
		check_len(this->contact[num].getFname());
		check_len(this->contact[num].getLname());
		check_len(this->contact[num].getNname());
		std::cout<<std::endl;
	}
	
}

void check_len(std::string str)
{
	int namecount;
	namecount =str.length();
	if (namecount <= 10 && namecount >= 0){
		print_form(str);
		std::cout << "|";
	}
	else{
		print_form(over_len(str));
		std::cout << "|";
	}
}


void print_form(std::string str)
{
	std::cout << std::setw(10) << str;
}

std::string over_len(std::string str)
{
	std::string Change;

	Change = str.substr(0,10);
	Change[9] = '.';
	return Change;
}

void base_print()
{
	std::cout <<"  Index   "<< "|";
	std::cout <<"First Name"<< "|";
	std::cout <<"Last  Name"<< "|";
	std::cout <<"Nick  Name"<< "|"<< std::endl;
}