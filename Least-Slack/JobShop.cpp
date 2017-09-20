/*
 * JobShop.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#include <iostream>
#include "JobShop.h"

JobShop::JobShop()
{
	// TODO Auto-generated constructor stub

}

JobShop::JobShop(int argc, char** argv)
{
	//Check argument count
	if (argc != 3)
	{
		std::cout << "Usage : " << argv[0] << "[input] [output]" << std::endl;
	}
	else
	{
		//Read in input file
	}
}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

