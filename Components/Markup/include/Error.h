#pragma once
#include <iostream>
#include<fstream>

class Error
{
public:
	Error() = default;
	~Error() = default;
	void setError(std::string info,int line);
	std::string getError() { return error; }
private:
	const std::string pathError{ "Error.txt" };

	std::string error{""};

};

