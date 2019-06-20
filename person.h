#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>
#include <windows.h>
#include <iostream>

class person {
public:
	// Конструктор класса human
	person(
		std::string last_name, 
		std::string name, 
		std::string second_name, 
		std::string _phone, 
		std::string _eMail,
		sex sex)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
		this->phone = _phone;
		this->eMail = _eMail;
		this->_sex = sex;
	}

	person copy() {
		return person(last_name, name, second_name, phone, eMail, _sex);
	}
	// Генерирует уникальный идентификатор объекта
	std::string genGUID() {
		UUID uuid;
		UuidCreate(&uuid);
		char* str;
		UuidToStringA(&uuid, (RPC_CSTR*)& str);
		RpcStringFreeA((RPC_CSTR*)& str);
		return str;
	}
	
	// Получение ФИО человека
	std::string get_full_name()
	{
		std::ostringstream full_name;
		full_name << this->last_name << " "
			<< this->name << " "
			<< this->second_name;
		return full_name.str();
	}

private:
	std::string 
		guid,
		name,
		last_name,
		second_name,
		phone,
		eMail;
	sex _sex;
};

enum sex {
	man, wooman
};
#endif
