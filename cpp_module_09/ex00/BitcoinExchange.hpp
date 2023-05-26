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

	bool checkDate(const std::string &date);
	void checkCsvFile();
};


#endif
