#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"

class client : public person {
public:	
	client(
		std::string last_name,
		std::string name,
		std::string second_name,
		std::string _phone,
		std::string _eMail,
		sex _sex
	) : person(
		last_name,
		name,
		second_name,
		_phone,
		_eMail,
		_sex
	) {
		this->discount = 0;
		this->guid = genGUID();
	}

	std::string getGUID() {
		return guid;
	}

	double getDiscount() {
		return (100 - discount) / 100;
	}

	// 
	void setDiscount(int count) {
		switch (count) {
		case (int)3: 
			this->discount = 3;
			break;
		case (int)5: 
			this->discount = 4;
			break;
		}
		
	}

private:
	int discount;
	std::string guid;
};
#endif
