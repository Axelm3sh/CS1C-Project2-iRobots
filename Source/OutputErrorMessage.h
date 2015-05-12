/*
 * OutputErrorMessage.h
 *
 *  Created on: May 10, 2015
 *      Author: Matt
 */

#ifndef OUTPUTERRORMESSAGE_H_
#define OUTPUTERRORMESSAGE_H_

#include "myHeader.h"

/*************************************************************************
* OutputErrorMessage
* ________________________________________________________________________
* This template function calculates a setw for two lines of error messages and
* 	outputs the messages.
* ________________________________________________________________________
* PRE-CONDITIONS
*	value    : Value entered by user.
*	minValue : Minimum value user allowed to enter.
*	maxValue : Maximum value user allowed to enter.
* POST-CONDITIONS
*	<none>
*	Outputs the error message
**************************************************************************/
template <class Type>
void OutputErrorMessage(Type value,    // IN - Value inputted from user.
				  	    Type minValue, // IN - Max possible value entered.
				  	    Type maxValue) // IN - Min possible value entered.
{

	ostringstream errMsg1;       // CALC - First line of error message.
	ostringstream errMsg2;       // CALC - Second line of error message.
	string        errMsg1Str;    // CALC - String created for first line.
	string 		  errMsg2Str;    // CALC - String created for second line.
	int 		  errMsg1Length; // CALC - Length of first line.
	int 		  errMsg2Length; // CALC - Length of second line.
	int   		  setWidth;      // CALC - The setw to create aligned
								 //		   error messages.

	// Creates stream containing first line of error message.
	errMsg1 << "The number " << value
		    << " is an invalid entry";

	// Creates stream containing second line of error message.
	errMsg2 <<"Please input a number between "
			<< minValue << " and " << maxValue;

	// Converts each line of error message to a single string
	errMsg1Str = errMsg1.str();
	errMsg2Str = errMsg2.str();

	// Gets length of error message string.
	errMsg1Length = errMsg1Str.length();
	errMsg2Length = errMsg2Str.length();

	// Defaults setw to length of first string.
	setWidth = errMsg1Length;

	// Checks which string is larger and uses that as a setw.
	if(errMsg1Length > errMsg2Length)
	{
		setWidth = errMsg1Length;
	}
	else
	{
		if(errMsg2Length > errMsg1Length)
		{
			setWidth = errMsg2Length;
		}
	}

	// Outputs the error message.
	cout << left;
	cout << "\n**** ";
	cout << setw(setWidth) << errMsg1Str;
	cout << " ****";

	cout << "\n**** ";
	cout << setw(setWidth) << errMsg2Str;
	cout << " ****\n\n";
}




#endif /* OUTPUTERRORMESSAGE_H_ */
