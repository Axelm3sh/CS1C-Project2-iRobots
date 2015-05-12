

#ifndef TESTIMONIALLIST_H_
#define TESTIMONIALLIST_H_

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "TestimonialNode.h"
using namespace std;

class TestimonialList
{
public:
	TestimonialList();
	~TestimonialList();

	void Add(TestimonialNode newTestimonial);
	TestimonialNode GetTestimonial(int position);
	void PrintAll();
	int GetCount();

	void DeleteTestimonial(int position);

private:
	vector <TestimonialNode> Testimonials;

};



#endif
