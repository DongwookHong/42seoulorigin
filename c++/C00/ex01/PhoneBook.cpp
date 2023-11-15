#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "iomanip"


void print_form(std::string str);
void base_print(int num);
std::string over_len(std::string str);
void check_len(std::string str);
void get_line(std::string &str);
bool empty_check(const std::string& str);

PhoneBook::PhoneBook() {
	this->i = 0;
	this->CountContact = 0;
}
PhoneBook::~PhoneBook() {}

void exe()
{
	PhoneBook pb;
	std::string choice;
	int num ;
	
	num =0;
	while(1)
	{
		std::cout<<"Choose option <[1].ADD> <[2].SEARCH> <[3].EXIT>"<<std::endl;
		get_line(choice);
		if (choice.length() != 1){
			std::cout<< "Please check Number!!!" << std::endl;
		}
		else {
			num = choice[0]-'0';
			if (num<=0 || num >=4){
				std::cout<< "Please check Number!!!" << std::endl;
			}
			switch(num)
			{
				case 1:
					pb.Add();
					break;
				case 2:
					pb.Search();
					break;
				case 3:
					exit(0);
					break;
				default:
					break;
			}
		}
	}
}

void PhoneBook::Add()
{
	Contact& NewContact = this->contact[this->i % 8];

	std::string fname;
	while(1)
	{
		std::cout << "Type your First name"<<std::endl;
		get_line(fname);
    	if (fname.empty() || empty_check(fname))
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setFname(fname);
	
	std::string lname;
	while(1)
	{
		std::cout << "Type your Last name"<<std::endl;
		get_line(lname); 
    	if (lname.empty() || empty_check(lname))
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setLname(lname);

	std::string nname;
	while(1)
	{
		std::cout << "Type your Nick name"<<std::endl;
		get_line(nname); 
    	if (nname.empty() || empty_check(nname))
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setNname(nname);

	std::string num;
	while(1)
	{
		std::cout << "Type your Number"<<std::endl;
		get_line(num); 
    	if (num.empty() || empty_check(num))
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setNum(num);

	std::string secret;
	while(1)
	{
		std::cout << "Type your Secret"<<std::endl;
		get_line(secret); 
    	if (secret.empty() || empty_check(secret))
        	std::cout << "Empty lines are not allowed" << std::endl;
    	else
        	break;
	}
	NewContact.setSecret(secret);

	std::string index;
	index = ((i%8)+'0');
	NewContact.setIndex(index);
	if (this->CountContact < 8)
		this->CountContact++;
	std::cout<<"You have been successfully added to your phonebook." <<std::endl;
	i++;
}

void PhoneBook::Search()
{
	int i = 0;

	base_print(1);
	while(i<CountContact)
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
	get_line(search); 
	if (search == "" || search.length() > 1)
	{
		std::cout<<"Please check index!!"<<std::endl;
		return ;
	}
	num = search[0]-'0';
	if (num >=8  || num <0){
		std::cout<<"Please check index!!"<<std::endl;
		return ;
	}
	if (this->contact[num].getFname() == "" || this->contact[num].getLname() == "" || this->contact[num].getIndex()== ""|| \
		this->contact[num].getNname() == "" )
	{
		std::cout<<"Please check index!!"<<std::endl;
		return ;
	}
	else
	{
		base_print(2);
		check_len(this->contact[num%8].getIndex());
		check_len(this->contact[num%8].getFname());
		check_len(this->contact[num%8].getLname());
		check_len(this->contact[num%8].getNname());
		check_len(this->contact[num%8].getNum());
		check_len(this->contact[num%8].getSecret());
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

void base_print(int num)
{
	if (num == 1)
	{
		std::cout <<"  Index   "<< "|";
		std::cout <<"First Name"<< "|";
		std::cout <<"Last  Name"<< "|";
		std::cout <<"Nick  Name"<< "|"<< std::endl;
	}
	if (num ==2)
	{
		std::cout <<"  Index   "<< "|";
		std::cout <<"First Name"<< "|";
		std::cout <<"Last  Name"<< "|";
		std::cout <<"Nick  Name"<< "|";
		std::cout <<"Phone  NUM"<< "|";
		std::cout <<"DK  Secret"<< "|"<< std::endl;
	}
}

void get_line(std::string &str)
{
	std::getline(std::cin, str);
    if (std::cin.eof())
       exit(1);
}

bool empty_check(const std::string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isspace(str[i])) { 
            return false;
        }
    }
    return true;
}
