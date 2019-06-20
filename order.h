#include "client.h"
#include "Hairdresser.h"

#include <ctime>
#include <iostream>
// ����� ��� ���������� ������
class order {
public:
	order(client inpt_clent, hairdresser inpt_hairdresser, std::time_t time, double _price) {
		this->clientInfo = inpt_clent.get_full_name;
		this->clientGUID = inpt_clent.getGUID();
		this->hairdresserInfo = inpt_hairdresser.get_full_name();
		this->hairdresserGUID = inpt_hairdresser.getGUID();
		this->orderDate = time;
		this->price = _price * inpt_clent.getDiscount();
	}

	std::string getOrderInfo() {
		std::ostringstream full_info;
		full_info << "������ " << this->clientInfo
			<< "������ " << this->hairdresserInfo
			<< "��������� " << this->price
			<< "���� " << this->orderDate;
		return full_info.str();
	}

private:
	std::string 
		clientInfo,
		clientGUID,
		hairdresserInfo,
		hairdresserGUID;
	std::time_t orderDate;
	double price;
};

