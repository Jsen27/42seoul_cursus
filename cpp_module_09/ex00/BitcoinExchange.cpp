#include "BitcoinExchange.hpp"

bool BitcoinExchange::checkDate(const std::string& date)
{
	
}

void BitcoinExchange::checkCsvFile()
{
	std::ifstream csv("data.csv");
	std::string read;
	size_t date_size;
	float value;

	if (!csv)
		throw std::runtime_error("Error: Failed to open data file");

	if (std::getline(csv, read).eof())
		throw std::runtime_error("Error: empty file");

	while(std::getline(csv, read)){
		if (read != "data,exchange_rate"){
			date_size = read.find(',');
			
			std::istringstream(read.substr(date_size + 1, read.length())) >> value;
			bitcoinData[read.substr(0, date_size)] = value;
		}
	}	
}
