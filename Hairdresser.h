#ifndef HAIRDRESSER_H
#define HAIRDRESSER_H

#include "person.h"

class hairdresser : public person {
public:
	hairdresser(
		std::string last_name,
		std::string name,
		std::string second_name,
		std::string _phone,
		std::string _eMail,
		sex _sex,
		masterType _type
	) : person(
		last_name,
		name,
		second_name,
		_phone,
		_eMail,
		_sex
	) {
		this->stage = 0;
		this->guid = genGUID();
		this->type = _type;
	}

	int getStage() {
		return stage;
	}

	std::string getGUID() {
		return guid;
	}

private:
	int stage;
	std::string guid;
	masterType type;
};

enum masterType {
	man, women, unisex, nails
};
#endif
