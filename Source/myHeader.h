#ifndef MYHEADER_H_
#define MYHEADER_H_


#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include <sstream>
#include <iomanip>
#include "Date.h"
#include "nodeTemplate.h"
#include "CustomerList.h"

using namespace std;

const string login =
		"Welcome to the iRobot Shop!\n"
		"[1] User\n"
		"[2] Admin\n"
		"[0] EXIT\n"
		"Please enter one of the above options: ";

const string mainMenu =
		"[1] iRobot Shop\n"
		"[2] GET INFORMATION\n"
		"[3] TESTIMONIALS\n"
		"[4] REQUEST A PAMPHLET\n"
		"[0] EXIT\n"
		"Please enter one of the above options: ";


const string mainMenuAdmin =
		"[1] iRobot Shop\n"
		"[2] GET INFORMATION\n"
		"[3] TESTIMONIALS\n"
		"[4] REQUEST A PAMPHLET\n"
		"[5] EDIT CUSTOMER INFORMATION\n"
		"[6] VIEW/PRINT CUSTOMER LIST\n"
		"[0] EXIT\n"
		"Please enter one of the above options: ";


const string shopMenu =
		"[1] PURCHASE ROBOT\n"
		"[2] EDIT PREVIOUS TRANSACTION\n"
		"[0] EXIT\n"
		"Please enter one of the above options: ";


const string testimonialMenu =
		"[1] READ TESTIMONIALS\n"
		  "[2] ADD TESTIMONIAL\n"
		"[0] EXIT\n"
		"Please enter one of the above options: ";


const string getInfoMenu =
		"[1] ROBOT DESCRIPTION\n"
		  "[2] WARRANTY/SERVICE INFORMATION\n"
		  "[3] PAYMENT PLANS\n"
		  "[4] FAQ\n"
		  "[5] SUITABLE ENVIRONMENTS\n"
		  "[6] SALES PITCH\n"
		  "[7] CONTACT US\n"
		"[0] EXIT\n"
"Please enter one of the above options: ";


const string viewCustomerListMenu =
		"[1] VIEW CUSTOMER LIST\n"
		"[2] EDIT CUSTOMER LIST\n"
		"[3] PRINT CUSTOMER LIST\n"
		"[0] EXIT\n"
		"Please enter one of the above options: ";



const string salesPitch =
		"If you are looking for a brand new, state of the art robot...\n"
		"\nTHEN LOOK NO FURTHER!!!\n\n"
		"No other company beats iRobot's high-quality standards.\n"
		"What makes our robots so special is that they are made of\n"
		"extremely durable metals that are guaranteed to last 20 life-times!\n"
		"All of our robots are hand-crafted by California's top engineers and\n"
		"undergo supreme testing. You can not go wrong when you choose iRobot.\n"
		"We have the perfect models and styles to suite the tastes of everyone.\n"
		"iRobots are programmed by the world's top computer scientists with\n"
		"high end next-generation artificial intelligence interfaces.\n"
		"Each and every robot is programmed to be your friend as well as complete general\n"
		"everyday tasks.  Different models are specially designed to accomplish a more specific\n"
		"set of tasks in order to function with optimum performance!\n"
		"If you do not find exactly what you are looking for then we will gladly\n"
		"special order and even design the iRobot of your dreams!!!\n\n"
		"PRESS [--key to be determined--] to start your order now!\n";

const string suitableEnvironment =
		"iRobots are suitable for so many environments it would take a novel\n"
		"to list them all, so here is a list of all environments that are NOT (currently) suitable for your new robot...\n\n"
		"1. The Ocean (our robots are water-proof, they just have a fear of sharks)\n"
		"2. Space (robot performance is significantly decreases in a zero-gravity environment)\n"
		"3. Greenland (our robots get cold...) \n\n";

const string paymentPlans =
		"Pricing Plan:\n"
		"Our robots are offered in 3 models:\n\n"
		"A. Silver -\n"
		"The silver model detects common organic explosive residues,"
		" and alerts the user to potential explosives.\n"
		"For the budget oriented customer who does not expect heavy use or sophisticated terrorists\n"
		"$50000\n\n"

		"B. Gold - \n"
		"This model not only detects explosives, "
		"but has the ability to dispose of explosives remotely.\n"
		"Recommended for users who expect a high volume of explosives.\n"
		"$250000\n\n"

		"C. Platinum -\n"
		"The top of the line model uses advanced spectrometry and radiographic \n"
		"tools to detect all known types of explosives, no matter how well they're hidden.\n"
		"Has all the features of the silver and gold models\n"
		"Recommended for institutional users dealing with sophisticated terrorists\n"
		"$500000\n\n";

const string warrentyInfo =
		"Maintenance Plan:\n"
		"The annual cost of the plan is 15% of the model of the robot originally purchased.\n"
		"It covers all routine maintenance and qualification, along with replacement of consumable parts,\n"
		"and repair of damage caused by explosions.\n\n"

		"Guarantee:\n"
		"For the first 24 months after robot purchase, all malfunctions due to manufacturing \n"
		"or quality defects will be repaired at the expense of the manufacturer. \n"
		"This does not include damage caused by user error.\n\n";

#endif /* MYHEADER_H_ */
