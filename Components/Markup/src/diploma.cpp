
#include "Parcer.h"

int main()
{
	Parcer parcer;
	bool parcingStatus = true;

	if (parcer.checkFile())
	{
		if (parcer.parcing())
		{

		}
		else
		{
			parcingStatus = false;
		}
	}
	else
	{
		parcingStatus = false;
		std::cout << parcer.getError();
	}

	//std::cout << parcer.getWARN();
}

