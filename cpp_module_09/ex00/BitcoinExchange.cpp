#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	bitcoinData.insert(ref.bitcoinData.begin(), ref.bitcoinData.end());
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	if (&ref != this)
		bitcoinData.insert(ref.bitcoinData.begin(), ref.bitcoinData.end());
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::checkValue(const std::string& value)
{
	char *end = nullptr;
	float fvalue = std::strtod(value.c_str(), &end);
	if (fvalue == 0 && !std::isdigit(value[0]))
		return false;
	if (*end && std::strcmp(end, "f"))
		return false;
	if (fvalue < 0)
		return false;

	return true;
}

bool BitcoinExchange::checkDataDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	std::string read;
	std::istringstream iss(date);
	int year, month, day;
	int flag = 0;

	while (std::getline(iss, read, '-')){
		if (flag == 0){
			std::istringstream(read) >> year;
			if (year < 1000 || year > 9999)
				return false;
		}
		else if (flag == 1){
			std::istringstream(read) >> month;
			if (month < 1 || month > 12)
				return false;
		}
		else if (flag == 2){
			std::istringstream(read) >> day;
			if (day < 1 || day > 31)
				return false;
      		if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
				return false;
     		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        		if (day > 29 && month == 2)
					return false;
			} else if (day > 28 && month == 2)
				return false;
		}
		flag++;
	}
	if (flag == 4)
		return false;

	return true;
}

void BitcoinExchange::insertDataMap()
{
	std::ifstream csv("data.csv");
	std::string read;
	size_t date_size;
	float value;

	if (!csv)
		throw std::runtime_error("Error: failed to open data file");
	if (std::getline(csv, read).eof())
		throw std::runtime_error("Error: empty data file");

	while(std::getline(csv, read)){
		if (read != "data,exchange_rate"){
			date_size = read.find(',');
			if (checkDataDate(read.substr(0, date_size)) == false)
				throw std::runtime_error("Error: invalid date in the csv file");
			if (checkValue(read.substr(date_size + 1, read.length() - date_size)) == false)
				throw std::runtime_error("Error: invalid exchange rate in the csv file");
			std::istringstream(read.substr(date_size + 1, read.length())) >> value;
			bitcoinData.insert(std::make_pair(read.substr(0, date_size), value));
		}
	}	
}

void BitcoinExchange::checkInputFile(char* file)
{
	std::fstream fs;
	std::string str;

	fs.open(file, std::ifstream::in);
	if(!fs.is_open())
		throw std::runtime_error("Error: failed to open input file");
	if (std::getline(fs, str).eof())
		throw std::runtime_error("Error: empty input file");
	if (str.compare("date | value") != 0)
		throw std::runtime_error("Error: invalid format in the input file");
	fs.close();
}

bool BitcoinExchange::checkInputDate(const std::string& date)
{
	std::istringstream iss(date);
	std::string read;
	int year, month, day;
	int flag = 0;

	if (date.find('-', date.length() - 1) != std::string::npos){
		std::cout << "Error: incorrect date formate => " << date << std::endl;
		return false;
	}
	while (std::getline(iss, read, '-')) {
		if (flag == 0) {
			std::istringstream(read) >> year;
			if (year < 2009 || year > 2022){
				std::cout << "Error: invalid year => " << date << std::endl;
				return false;
			}
		}
		if (flag == 1) {
			std::istringstream(read) >> month;
			if (month < 1 || month > 12){
				std::cout << "Error: invalid month => " << date << std::endl;
				return false;
			}
		}
		if (flag == 2) {
			std::istringstream(read) >> day;
			if (day < 1 || day > 31){
				std::cout << "Error: bad input => " << date << std::endl;
				return false;
			}
		}
		if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)){
			std::cout << "Error: incorrect days => " << date << std::endl;
			return false;
		}
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			if (day > 29 && month == 2){
				std::cout << "Error: incorrect days => " << date << std::endl;
				return false;
			}
		} else if (day > 28 && month == 2){
			std::cout << "Error: incorrect days => " << date << std::endl;
			return false;
		}		
		flag++;
	}
	if (flag != 3){
		std::cout << "Error: Wrong format => " << date << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkInputValue(const std::string& value)
{
	char* end = nullptr;
	double dvalue = strtod(value.c_str(), &end);

	if (value.find('.') == 0 || value.find('.', value.length() - 1) != std::string::npos){
		std::cout << "Error: not a number." << std::endl;
		return false;
	}
	if (dvalue == 0 && !std::isdigit(value[0])){
		std::cout << "Error: not a number." << std::endl;
		return false;
	}
	if (*end && std::strcmp(end, "f")){
		std::cout << "Error: not a number." << std::endl;
		return false;
	}
	if (dvalue < 0){
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value.length() > 10 || (value.length() == 10 && dvalue > 2147483647)){
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::printBitcoin(std::string date, float value)
{
	std::map<std::string, float>::const_iterator iter = bitcoinData.find(date);
	float result = 0;

	if (iter == bitcoinData.end()){
		iter = bitcoinData.lower_bound(date);
		if (iter == bitcoinData.begin()){
			std::cout << "Error: Invalid date." << std::endl;
			return ;	
		}
		iter--;
	} 
	result = iter->second * value;
	
	std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::exchange(std::string file)
{
	std::string date, str;
	std::istringstream formats(file);
	float value;
	int flag = 0;

	while (std::getline(formats, str, ' ')){
		if (flag == 0){
			if (checkInputDate(str) == false)
				return ;
			date = str;
		}
		else if (flag == 1 && str != "|"){
			std::cout << "Error: bad input => " << file << std::endl;
			return ;
		}
		else if (flag == 2){
			if (checkInputValue(str) == false)
				return ;
			value = std::strtod(str.c_str(), nullptr);
			if (value > 1000){
				std::cout << "Error: too large a number." << std::endl;
				return ;
			}
		}
		flag++;
	}
	if (flag != 3){
		std::cout << "Error: bad input => " << file << std::endl;
		return ;
	}
	printBitcoin(date, value);
}

void BitcoinExchange::bitcoin(char* file)
{
	try
	{
		insertDataMap();
		checkInputFile(file);

		std::ifstream inputfile(file);
		std::string read;

		std::getline(inputfile, read);
		while (std::getline(inputfile, read))
			exchange(read);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
