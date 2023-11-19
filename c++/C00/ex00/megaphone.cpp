#include <iostream>

int main(int ac , char **av)
{
	int i;
	int j;

	i = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for(int i =1; av[i]; i++)
			for (int j =0; av[i][j]; j++)
				av[i][j] = toupper(av[i][j]);
		for(int i =1; av[i]; i++)
			std::cout<<av[i];
		std::cout<<std::endl;
	}
}