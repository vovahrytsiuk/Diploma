#include "Error.h"
#include <string>

void Error::setError(std::string info, int line)
{
	if (line != 0)
	{
		error = "line " + std::to_string(line) + ": ";
	}
	error += info;

	std::cout << '\n' << error << '\n';
	std::ofstream fout;
	fout.open(pathError);
	fout << error;
}
