#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> bitcoinData;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange& operator=(const BitcoinExchange& ref);
	~BitcoinExchange();

	bool checkValue(const std::string& value);
	bool checkDataDate(const std::string& date);
	void insertDataMap();

	void checkInputFile(char* file);
	bool checkInputDate(const std::string& date);
	bool checkInputValue(const std::string& value);
	void printBitcoin(std::string date, float value);

	void exchange(std::string file);

	void bitcoin(char* file);
};


#endif
