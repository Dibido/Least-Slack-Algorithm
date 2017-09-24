/*
 * JobShop.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: root
 */

#include "JobShop.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

JobShop::JobShop() :
		nrMachines(0), nrJobs(0), time(0), longestJobTimeLeft(0), allJobsFinished(
				false) {
}

JobShop::~JobShop()
{
}

JobShop::JobShop(int argc, char** argv) :
		time(0), longestJobTimeLeft(0), allJobsFinished(false) {
	//Check argument count
	if (argc != 3) {
		std::cout << "Usage : " << argv[0] << "[input] [output]" << std::endl;
		exit(-1);
	} else {
		//Read in input file
		std::string input = argv[1];
		std::ifstream istr(input);
		if (!istr.is_open()) {
			std::cout << "File could not be opened" << std::endl;
			exit(-1);
		}
		std::string line;
		for (size_t i = 0; getline(istr, line); ++i) {
			//Read out machines and jobs
			if (i == 0) {
				// Convert the characters to integer values
				static std::regex regex("\\d+");
				std::regex_iterator<std::string::iterator> rit(line.begin(),
						line.end(), regex);
				std::regex_iterator<std::string::iterator> rend;

				//Check whether the right amount of arguments were given
				if(std::distance(rit,rend) != 2){
					std::cout << "Wrong input for number of Jobs and Tasks on line 1" << std::endl;
					exit(-1);
				}

				std::string jobs = rit->str();
				this->nrJobs = std::stoi(jobs);
				++rit;
				std::string machines = rit->str();
				this->nrMachines = std::stoi(machines);

				//Create machines
				for (size_t i = 0; i < this->nrMachines; ++i) {
					Machines.push_back(Machine(i));
					std::cout << "Created Machine: " << i << std::endl;
				}
			}
			//Read out Jobs
			else {
				//Create jobs
				Job j(i - 1, line); // Since i represents the linenumber from the text file, and the first job (jobID = 0) starts at line 1, i-1.
				this->Jobs.push_back(j);
			}
		}
	}
}

void JobShop::updateSlackTimes() {
	std::vector<unsigned short> timesLeft;

	for (Job& J : Jobs) {
		J.calculateTimeLeft();
		timesLeft.push_back(J.getTaskTimeLeft());
	}

	this->longestJobTimeLeft = std::max_element(timesLeft.begin(),
			timesLeft.end())[0]; // Represents the time needed to finish the longest job.

	for (Job& J : Jobs) {
		J.setSlackTime(longestJobTimeLeft - J.getTaskTimeLeft());
	}
}

void JobShop::sortJobs() {
	std::sort(Jobs.begin(), Jobs.end());
}

bool sortByJobNr (Job& a, Job& b) {
	return (a.getJobNr() < b.getJobNr());
}

void JobShop::schedule() {
	while (!allJobsFinished) {
		//Schedule all the jobs
		updateJobs();

		this->time++;
		if (longestJobTimeLeft <= 0) {
			allJobsFinished = true;
		std::sort(Jobs.begin(),Jobs.end(),sortByJobNr); // Sorting Jobs by Jobnr, making ready for output.
		}
	}
	for (Job& J : Jobs) {
		std::cout << "Job " << J.getJobNr() << " Started at T: "
				<< J.getBeginTime() << " and finished on T: " << J.getEndTime()
				<< std::endl;

	}
}


void JobShop::updateJobs() {

	for (Job& J : Jobs) {	//Lowering time by 1 unit
		if (!J.Tasks.empty()) {
			if (J.Tasks.at(0).getMachine() != nullptr) {
				J.Tasks.at(0).setDuration(J.Tasks.at(0).getDuration() - 1);
				if (J.Tasks.at(0).getDuration() <= 0) { // If tasks duration left is 0, remove the task.
					Machines.at(J.Tasks.at(0).getMachineNr()).setInUse(false);
					J.removeCompletedTask();
				}
				if (J.Tasks.empty()) {  // If the job now has no tasks left
					J.setEndTime(time); // Time-1, because apparently the job was completed previous timeunit.
				}
			}
		}
	}
	this->updateSlackTimes();
	sortJobs();

	for (Job& J : Jobs) { //Assigning jobs to machines
		if (!J.Tasks.empty()) {
			if (J.Tasks.at(0).getMachine() == nullptr
					&& Machines.at(J.Tasks.at(0).getMachineNr()).isInUse()
							== false) {
				J.Tasks.at(0).setMachine(
						&Machines.at(J.Tasks.at(0).getMachineNr()));
				Machines.at(J.Tasks.at(0).getMachineNr()).setInUse(true);
				if (J.isJobStarted() == false) {
					J.setJobStarted(true);
					J.setBeginTime(time);
				}
			}
		}

	}
}

Job JobShop::giveLeastSlack() {
	return std::min_element(Jobs.begin(), Jobs.end())[0];
}

void JobShop::output(int argc, char** argv) {
	//Check argument count
	if (argc != 3) {
		std::cout << "Usage : " << argv[0] << "[input] [output]" << std::endl;
		exit(-1);
	} else {
		//Output to file
		std::ofstream ostr(argv[2]);
		if (!ostr.is_open()) {
			std::cout << "File could not be opened, creating file" << std::endl
					<< std::endl;
		}
		for (const Job& j : Jobs) {
			ostr << j.getJobNr() << " " << j.getBeginTime() << " "
					<< j.getEndTime() << std::endl;
		}
	}
	//Output to terminal
	for (const Job& j : Jobs) {
		std::cout << j.getJobNr() << " " << j.getBeginTime() << " "
				<< j.getEndTime() << std::endl;
	}
}
