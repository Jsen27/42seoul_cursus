#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {(void) ref;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {(void) ref; return *this;}

BitcoinExchange::~BitcoinExchange()
{
	//구현 해야함
}

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
			if (checkValue(read.substr(date_size + 1, read.length() - date_size)));
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
	if (!str.compare("date | value"))
		throw std::runtime_error("Error: invalid format in the input file");
	fs.close();
}

void BitcoinExchange::checkInputDate(const std::string& date)
{
	std::istringstream iss(date);
	std::string read;
	int year, month, day;
	int flag = 0;

	if (date.find('-', date.length() - 1) != std::string::npos)
		throw std::runtime_error("Error: incorrect date formate => " + date);
	
	while (std::getline(iss, read, '-')) {
		if (flag == 0) {
			std::istringstream(read) >> year;
			if (year < 2009 || year > 2022)
				throw std::runtime_error("Error: invalid year => " + date);
		}
		if (flag == 1) {
			std::istringstream(read) >> month;
			if (month < 1 || month > 12)
				throw std::runtime_error("Error: invalid month => " + date);
		}
		if (flag == 2) {
			std::istringstream(read) >> day;
			if (day < 1 || day > 31) 
				throw std::runtime_error("Error: bad input => " + date);
		}
		if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
			throw std::runtime_error("Error: incorrect days => " + date);
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			if (day > 29 && month == 2)
			throw std::runtime_error("Error: incorrect days => " + date);
		} else if (day > 28 && month == 2)
			throw std::runtime_error("Error: incorrect days => " + date);
		
		flag++;
	}
	if (flag != 3)
		throw std::runtime_error("Error : Wrong format => " + date);
}

void BitcoinExchange::exchange(std::string file)
{
	std::string date, str;
	std::istringstream formats(file);
	float value;
	int flag = 0;

	while (std::getline(formats, str, ' ')){
		if (flag == 0){
			checkInputDate(str);
			date = str;
		}
		else if (flag == 1 && str != "|")
			throw std::runtime_error("Error: bad input => " + file);
		else if (flag == 2){

		}
	}
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