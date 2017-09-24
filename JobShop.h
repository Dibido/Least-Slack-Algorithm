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

	void schedule();
	void output(int argc, char **argv);
private:
	std::vector<Job> Jobs;
	std::vector<Machine> Machines;


	void sortJobs(); // Sorts the Job-vector, using the < operator (on slacktime). Element with lowest slacktime will be first in the vector.
	void updateJobs();


	unsigned short nrMachines;
	unsigned short nrJobs;
	unsigned long time;
	unsigned short longestJobTimeLeft;
	bool allJobsFinished;

	void updateSlackTimes();
	Job giveLeastSlack();
};

#endif /* JOBSHOP_H_ */
