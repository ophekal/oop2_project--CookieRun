#include <iostream>
#include <exception>
#include "Controller.h"

int main()
{
	try
	{
		Controller controller;
		controller.run();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
