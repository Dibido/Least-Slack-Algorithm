/*
 * Job.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#include <iostream>
//#include <utility>
#include <regex>
#include "Job.h"

Job::Job() :
		jobNr(0), slackTime(0), taskTimeLeft(0), beginTime(0), endTime(-1), jobStarted(false)
{
}

Job::Job(unsigned short jobNr, std::string taskList) :
		jobNr(jobNr), slackTime(0), beginTime(0), endTime(-1), jobStarted(false)
{
	//Dissect taskList
	static std::regex regex("\\d+");
	std::regex_iterator<std::string::iterator> rit(taskList.begin(),
			taskList.end(), regex);
	std::regex_iterator<std::string::iterator> rend;

	//Check for an even number of arguments
	if(std::distance(rit, rend) % 2 != 0){
		std::cout << "Uneven number of arguments for Job " << jobNr << "." << std::endl;
		exit(-1);
	}

	while (rit != rend)
	{
		unsigned char machineNr = std::stoi(rit->str());
		++rit;
		unsigned char duration = std::stoi(rit->str());
		++rit;
		Task T(machineNr, duration);
		Tasks.push_back(T);
	}

	calculateTimeLeft();

	std::cout << "Created Job" << std::endl;
}

Job::~Job()
{
}

void Job::calculateTimeLeft()
{
	// Sets taskTimeLeft as the sum of the time all tasks have left.
	this->taskTimeLeft = 0;
	for (Task& T : Tasks)
	{
		this->taskTimeLeft += T.getDuration();
	}

}

unsigned int Job::getTaskTimeLeft() const
{
	return taskTimeLeft;
}

void Job::setTaskTimeLeft(unsigned int taskTimeLeft)
{
	this->taskTimeLeft = taskTimeLeft;
}

unsigned short Job::getSlackTime() const
{
	return slackTime;
}

void Job::setSlackTime(unsigned short slackTime)
{
	this->slackTime = slackTime;
}

unsigned short Job::getJobNr() const
{
	return jobNr;
}

void Job::setJobNr(unsigned short jobNr)
{
	this->jobNr = jobNr;
}

unsigned long Job::getBeginTime() const
{
	return beginTime;
}

void Job::setBeginTime(unsigned long beginTime)
{
	this->beginTime = beginTime;
}

long Job::getEndTime() const
{
	return endTime;
}

void Job::setEndTime(int endTime)
{
	this->endTime = endTime;
}

bool Job::operator <(const Job& obj)
{
	return this->slackTime < obj.slackTime;
}

bool Job::isJobStarted() const {
	return jobStarted;
}

void Job::setJobStarted(bool jobStarted) {
	this->jobStarted = jobStarted;
}

void Job::removeCompletedTask() {
 Tasks.erase(Tasks.begin());
}
