/*
 * JobShop.h
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <vector>
#include "Job.h"

class JobShop
{
public:
	JobShop();
	JobShop(int argc, char **argv);
	virtual ~JobShop();
private:
	std::vector<Job> jobs;
	int nrMachines;
	int nrJobs;
};

#endif /* JOBSHOP_H_ */
