#pragma once
#include <fstream>
#include <stack>

#include "Error.h"
#include "Form.h"


class Parcer
{
public:
	Parcer();
	~Parcer();
	bool checkFile();
	bool parcing();

	std::string getError() { return error.getError(); }
private:
	const std::string pathFile{ "CppUi.txt" };
	
	std::ifstream fin;

	int line{ 0 };
	std::string activeString{""};
	std::string parcingString{""};
	std::string valueString{""};
	std::stack<std::string> scope;
	
	bool onlyScope = false;


	Error error;
	Form form;
	

	bool createWidget();
	bool paramWidget();

	bool getWidget();
	bool getParam();
	bool getValue();
	bool checkParam();
};

