/*
 * main.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: dibran
 */
#include <iostream>
#include "JobShop.h"

int main(int argc, char **argv) {
	//Create JobShop
	JobShop js(argc, argv);
	//Schedule the tasks
	js.schedule();
	//Output the results to the terminal and output file
	js.output(argc, argv);
	return 0;
}
