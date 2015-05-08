
#ifndef INPUT_H_
#define INPUT_H_

#include <fstream>
#include <iomanip>
#include <iostream>

#include "TestimonialList.h"
#include "TestimonialNode.h"

TestimonialList TakeInput();

void WriteToFile(TestimonialList testList);

TestimonialNode NewTestimonial();


#endif /* INPUT_H_ */
