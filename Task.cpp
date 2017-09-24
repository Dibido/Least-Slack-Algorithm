/*
 * Task.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#include "Task.h"
#include <iostream>
#include <string>

Task::Task(unsigned short machine, unsigned short duration):machine(nullptr)
{
	this->machineNr = machine;
	this->duration = duration;
	std::cout << "Created task, M:" << machineNr << " D: " << this->duration
			<< std::endl;
}

Task::~Task()
{
}

unsigned short Task::getDuration() const
{
	return duration;
}

void Task::setDuration(int duration)
{
	this->duration = duration;
}

unsigned short Task::getMachineNr() const
{
	return machineNr;
}

void Task::setMachineNr(int machineNr)
{
	this->machineNr = machineNr;
}

Machine* Task::getMachine()
{
	return machine;
}

void Task::setMachine(Machine* machine)
{
	this->machine = machine;
}
