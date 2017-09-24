/*
 * Machine.h
 *
 *  Created on: 22 sep. 2017
 *      Author: mluka_000
 */

#ifndef MACHINE_H_
#define MACHINE_H_
#include <ostream>

class Machine
{
public:
	Machine(unsigned short machineId);
	virtual ~Machine();

	unsigned short getMachineId() const;
	void setMachineId(unsigned char machineId);

	bool isInUse() const;
	void setInUse(bool inUse);

private:
	bool inUse;
	unsigned short machineId;
};

std::ostream& operator<<(std::ostream& os, const Machine& m);

#endif /* MACHINE_H_ */
