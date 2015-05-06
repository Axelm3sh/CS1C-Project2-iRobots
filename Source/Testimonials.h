/*************************************************************************
* Testimonials
* ________________________________________________________________________
* This class handles testimonials being added dynamically, data
* is kept on a single string per customer, output formatted by word wrap.
* ________________________________________________________________________
* PRE-CONDITIONS
*	inputFile    : file to read testimonies from. Testimonies must be
*					separated by a newline per customer.
*	...
* POST-CONDITIONS
*	<none>
*	...
**************************************************************************/
#ifndef TESTIMONIALS_H_
#define TESTIMONIALS_H_

#include "myHeader.h"
#include <vector>
#include <fstream>

class Testimonial
{
public:
	Testimonial();
	~Testimonial();

	void AddTestimonial(string data);
	string GetTestimonial(int position);

private:
	vector<string> testimonials;
	int count;

};



#endif /* TESTIMONIALS_H_ */
