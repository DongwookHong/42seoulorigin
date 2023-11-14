#include <iostream>
#include "phonebook.hpp"
// #include "contact.hpp"

int main()
{
	Phonebook pb;
	// Contact con;
	int choice;

	while(1)
	{
		std::cout<<"Choose option <[1].ADD> <[2].SEARCH> <[3].EXIT>"<<std::endl;
		std::cin >> choice;
		if (std::cin.eof()) {
			exit(1);
		}
		if (choice < 1 || 3 < choice || std::cin.fail()) {
			std::cout << "Please check again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		std::cin.ignore();
		switch(choice)
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
    return 0;
}