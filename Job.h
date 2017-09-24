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
	std::vector<Task> Tasks;
	Job();
	Job(unsigned short jobNr, std::string taskList);
	virtual ~Job();

	void calculateTimeLeft();

	bool operator<(const Job& obj);

	unsigned int getTaskTimeLeft() const;
	void setTaskTimeLeft(unsigned int taskTimeLeft);

	unsigned short getSlackTime() const;
	void setSlackTime(unsigned short slackTime);

	unsigned short getJobNr() const;
	void setJobNr(unsigned short jobNr);

	unsigned long getBeginTime() const;
	void setBeginTime(unsigned long beginTime);

	long getEndTime() const;
	void setEndTime(int endTime);

	void removeCompletedTask();
	bool isJobStarted() const;
	void setJobStarted(bool jobStarted);

private:

	unsigned short jobNr;
	unsigned short slackTime;

	unsigned int taskTimeLeft;

	unsigned long beginTime;
	long endTime;
	bool jobStarted;
};

#endif /* JOB_H_ */
