#include "Testimonials.h"

TestimonialList::TestimonialList()
{

}

TestimonialList::~TestimonialList()
{

}

void TestimonialList::Add(string newTestimonial)
{
	Testimonials.push_back(newTestimonial);
}

string TestimonialList::GetTestimonial(int position)
{
	return Testimonials.at(position);
}

void TestimonialList::PrintAll()
{
	unsigned int index;

	for(index = 0; index < Testimonials.size(); index++)
	{
		cout << Testimonials.at(index) << endl;
	}
}

int TestimonialList::GetCount()
{
	return Testimonials.size();
}
