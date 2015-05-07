

#ifndef TESTIMONIALS_H_
#define TESTIMONIALS_H_

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class TestimonialList
{
public:
	TestimonialList();
	~TestimonialList();

	void Add(string newTestimonial);
	string GetTestimonial(int position);
	void PrintAll();
	int GetCount();



private:
	vector <string> Testimonials;

};



#endif
