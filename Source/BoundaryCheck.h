/*
 * BoundaryCheck.h
 *
 *  Created on: May 10, 2015
 *      Author: Matt
 */

#ifndef BOUNDARYCHECK_H_
#define BOUNDARYCHECK_H_


#include "myHeader.h"
#include "OutputErrorMessage.h"

/*************************************************************************
* Boundary Check
* ________________________________________________________________________
* This template function prompts the user for data and checks to make sure
* 	it is within the boundary values passed in.
* ________________________________________________________________________
* PRE-CONDITIONS
*	prompt   : The prompt to guide user.
*	maxValue : The max value that can be entered.
*	minValue : The minimum value that can be entered.
* POST-CONDITIONS
*	A valid input is returned to the calling function.
**************************************************************************/
template<class Type>
Type BoundaryCheck(string prompt,   // IN - The prompt to guide user.
		 	 	  Type    minValue, // IN - The minimum possible value.
		 	 	  Type    maxValue) // IN - The maximum possible value.
{
	Type validInput; // IN & CALC - Input that is checked and returned
					 //		        when valid.
	bool invalid;    // CALC      - Causes a loop when invalid input is
					 //			    entered.

	invalid = false;

	// DO WHILE - Prompts user for integer input and error checks for char and
	// 		      boundary values.
	do
	{
		cout << prompt;

		if(!(cin  >> validInput))
		{
			cout << "\n**** Please input a NUMBER between " << minValue
				 << " and " << maxValue << " ****\n\n";
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			invalid = true;

		}
		else if((validInput < minValue) || (validInput > maxValue))
		{
			OutputErrorMessage(validInput, minValue, maxValue);
			invalid = true;
		}
		else
		{
			invalid = false;
		}

	}while(invalid);

	cin.ignore(1000, '\n');
	cout << endl;

	return validInput;
}




#endif /* BOUNDARYCHECK_H_ */
