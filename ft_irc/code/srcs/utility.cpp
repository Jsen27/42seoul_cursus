#include "utility.hpp"

std::vector<std::string> ut::split(std::string str, std::string const sep)
{
    std::vector<std::string> result;

    if (str.find(sep) == std::string::npos)
        result.push_back(str);

    while (str.find(sep) != std::string::npos)
    {
        if (str.find(sep) == 0)
        {
            str.erase(0);
            continue;
        }
        else
            result.push_back(str.substr(0, str.find(sep)));
        str.erase(0, str.find(sep) + 1);
        if ((str.find(sep) == std::string::npos))
        {
            result.push_back(str);
            break;
        }
    }
    return result;
}


std::vector<std::string> ut::splitCommand(std::string &request)
{
    std::vector<std::string>    sumCommand;
    std::string                 temp = "";
    std::size_t                 pos;

    
    
    while(!isalpha(request[0]) || request.empty())
    {
        request.erase(0, 1);
    }
    
    if(request.empty())
    {
        sumCommand[0] = nullptr;
        return sumCommand;
    }
    
    if(request.find(' ') != std::string::npos)
    {
        pos  = request.find(' ');
        temp = request.substr(0,pos);
        sumCommand.push_back(temp);
        request.erase(0, request.find(' ')+1);
    }
    if(request.find(" :") != std::string::npos)
    {
        pos = request.find(" :");
        temp = request.substr(0,pos);
        sumCommand.push_back(temp);
        temp = request.substr(pos+2);
        sumCommand.push_back(temp);
        request.erase(request.begin()+pos, request.end());
    }
    else
    {
        sumCommand.push_back(request);
    }
    return sumCommand;
}

std::vector<std::string> ut::splitForCmd(std::string &request)
{
    std::vector<std::string> arguments;
    std::string temp = "";
    if (request.find('\n') != std::string::npos) {
        request.erase(request.find('\n'));
    }
    if (request.find('\r') != std::string::npos) {
        request.erase(request.find('\r'));
    }
    if (request.find(' ') == std::string::npos){
        arguments.push_back(request);
    } else {
        if (request.find(':') != std::string::npos){
            temp = request.substr(request.find(':') + 1);
            request.erase(request.find(':') - 1, request.size() - 1);
        }
        while (!request.empty()) {
            if (request[0] == ' '){
                request.erase(0);
                continue;
            }
            if (request.find(' ') != std::string::npos) {
                arguments.push_back(request.substr(0, request.find(' ')));
                request.erase(0, request.find(' ') + 1);
            } else {
            arguments.push_back(request);
            request.erase(request.begin(), request.end());
            }
        }
        if (!temp.empty())
            arguments.push_back(temp);
    }
    return arguments;
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' ||
			c == '\n' || c == ' ')
		return (1);
	return (0);
}


/* Удаление пробелов в начале  */

std::string ut::ProcessingStr(std::string &str)
{

     while(ft_isspace(str[0]))
            str.erase(0, 1);
            
    return (str);
}