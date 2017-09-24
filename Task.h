/*
 * Task.h
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#ifndef TASK_H_
#define TASK_H_
#include "Machine.h"

class Task
{
public:
	Task(unsigned short Machine, unsigned short duration);
	virtual ~Task();

	unsigned short getDuration() const;
	void setDuration(int duration);

	unsigned short getMachineNr() const;
	void setMachineNr(int machineNr);

	Machine* getMachine();
	void setMachine(Machine* machine);
private:
	unsigned short machineNr;
	unsigned short duration;
	Machine* machine;
};

#endif /* TASK_H_ */
