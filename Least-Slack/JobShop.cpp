/*
 * JobShop.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#include "JobShop.h"

#include <iostream>
#include <fstream>
#include <string>

JobShop::JobShop()
{
}

JobShop::JobShop(int argc, char** argv)
{
	//Check argument count
	if (argc != 3)
	{
		std::cout << "Usage : " << argv[0] << "[input] [output]" << std::endl;
		exit(-1);
	}
	else
	{
		//Read in input file
		std::string input = argv[1];
		std::ifstream istr(input);
		if(!istr.is_open()){
			std::cout << "File could not be opened" << std::endl;
			exit(-1);
		}
		std::string line;
		for (size_t i = 0; getline(istr, line); ++i)
		{
			if (i == 0)
			{
				this->nrMachines = line[0];
				this->nrJobs = line[3];
			}
		}

	}
}

JobShop::~JobShop()
{
}

