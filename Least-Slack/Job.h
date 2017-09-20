/*
 * Job.h
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#ifndef JOB_H_
#define JOB_H_

#include <string>
#include <vector>

#include "Task.h"

class Job
{
public:
	Job();
	Job(int jobNr, std::string taskList);
	virtual ~Job();
private:
	std::vector<Task> tasks;
	int jobNr;
};

#endif /* JOB_H_ */
