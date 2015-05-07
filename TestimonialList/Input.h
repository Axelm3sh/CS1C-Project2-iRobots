/*
 * Input.h
 *
 *  Created on: Apr 27, 2015
 *      Author: Clive
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <fstream>
#include <iomanip>

#include "Testimonials.h"

TestimonialList TakeInput();

void WriteToFile(TestimonialList testList);



#endif /* INPUT_H_ */
