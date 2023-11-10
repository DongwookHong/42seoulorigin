#pragma once

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string Fname;
		std::string Lname;
		std::string Nname;
		std::string Num;
		std::string Secret;

	public:
		Contact();
		~Contact();
		
		std::string getFname()  const;
		std::string getLname()  const;
		std::string getNname()  const;
		std::string getNum()    const;
		std::string getSecret() const;

		void setFname(std::string fame);
		void setLname(std::string lname);
		void setNname(std::string nname);
		void setNum(std::string num);
		void setSecret(std::string secret);
};

