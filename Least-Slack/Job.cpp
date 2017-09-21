/*
 * Job.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#include <iostream>
#include <regex>
#include "Job.h"

Job::Job() :
		jobNr(0)
{
}

Job::Job(int jobNr, std::string taskList) :
		jobNr(jobNr)
{
	//Dissect taskList and create tasks.
	std::regex regex("\\d+\\s+");;
	std::regex_iterator<std::string::iterator> rit(taskList.begin(), taskList.end(), regex);
	std::regex_iterator<std::string::iterator> rend;

	while (rit != rend)
	{
		std::cout << rit->str() << " " << std::endl;
		//TODO: create tasks and put them into the tasks vector
		++rit;
	}
}

Job::~Job()
{
}

