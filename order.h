#include "client.h"
#include "Hairdresser.h"

#include <ctime>
#include <iostream>
// Класс для построения записи
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
		full_info << "Клиент " << this->clientInfo
			<< "Мастер " << this->hairdresserInfo
			<< "Стоимость " << this->price
			<< "Дата " << this->orderDate;
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

