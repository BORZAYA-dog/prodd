#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

int main() {
	std::vector<std::string> blocked_usrs = {"Cat", "Capibara", "Sheep", "Rabbit"};
	std::map<std::string, int> tradeost;
	std::map<std::string, int> prices;
	tradeost["Americano"] = 125;
	tradeost["Capuccino"] = 0;
	tradeost["JackDaniels"] = 3;
	tradeost["beer"] = -3;
	std::vector<std::string> adult = {"JackDaniels", "beer"};
	prices["Americano"] = 100;
	prices["Cappuccino"] = 115;
	prices["JackDaniels"] = 900;
	prices["beer"] = 50;
	std::string cekpet = "0x000ff";
	std::string nama;
	std::cout<<"Name?"<<std::endl;
	std::cin>>nama;
	for (int i = 0; i < blocked_usrs.size(); i++) {
		if (blocked_usrs[i] == nama) {
			std::cout<<"Access denied"<<std::endl;
			return 0;
		}
	}
	int age;
	bool pool;
	bool is_promo;
	std::cout<<"Age?"<<std::endl;
	std::cin>>age;
	std::cout<<"Promo?"<<std::endl;
	std::string promo;
	std::cin>>promo;
	is_promo = (promo == cekpet) ? true : false;
	std::cout<<"Write decired drinks and quantities like Americano 2 format"<<std::endl;
	std::string line;
	std::getline(std::cin >> std::ws, line);

	std::map<std::string, int> drinks;
	std::string drink;
	int quant;
	std::stringstream ss(line);
	while (ss >> drink >> quant) {
		drinks[drink] = quant;
	}
	int cost = 0;
	for (const auto& [key, value] : drinks) {
		if ((age < 18) && (std::find(adult.begin(), adult.end(), key)) != adult.end()) {
			std::cout<<key<<"Access denied. Reason: you kid."<<std::endl;
			return 0;
		}
		if (value > tradeost[key]) {
			std::cout << "Access denied. Reason: you ordered more than we have" << std::endl;
		}
		cost += value*prices[key];

	}
	if (cost >= 10000) {
		std::cout<<"Access accepted."<<std::endl;
		std::cout<<"Congradulations: your discount is 15%"<<std::endl;
		std::cout<<"Your total cost: "<< cost * 0.85f << std::endl;
		return 0;
	}
	if ((is_promo) and (cost >= 5000)) {
		std::cout<<"Access accepted."<<std::endl;
		std::cout<<"Congradulations: your discount is 10%"<<std::endl;
		std::cout<<"Your total cost: "<< cost * 0.9f << std::endl;
		return 0;
	}
	std::cout<<"Access accepted."<<std::endl;
	std::cout<<"Your total cost: "<< cost<< std::endl;
	return 0;


}