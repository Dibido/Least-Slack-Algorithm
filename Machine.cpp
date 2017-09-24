/*
 * Machine.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: mluka_000
 */

#include "Machine.h"

Machine::Machine(unsigned short machineId) :
  inUse(false), machineId(machineId)
{
}

Machine::~Machine()
{
}

unsigned short Machine::getMachineId() const
{
	return machineId;
}

void Machine::setMachineId(unsigned char machineID)
{
	this->machineId = machineId;
}

std::ostream& operator<<(std::ostream& os, const Machine& m)
{
	os << m.getMachineId();
	return os;
}

bool Machine::isInUse() const {
	return inUse;
}

void Machine::setInUse(bool inUse) {
	this->inUse = inUse;
}
