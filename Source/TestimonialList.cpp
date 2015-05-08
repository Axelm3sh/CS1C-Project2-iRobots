#include "TestimonialList.h"

TestimonialList::TestimonialList()
{

}

TestimonialList::~TestimonialList()
{

}

void TestimonialList::Add(TestimonialNode newTestimonial)
{
	Testimonials.push_back(newTestimonial);
}

TestimonialNode TestimonialList::GetTestimonial(int position)
{
	return Testimonials.at(position);
}

void TestimonialList::PrintAll()
{
	unsigned int index;

	for(index = 0; index < Testimonials.size(); index++)
	{
		cout << Testimonials.at(index).user << endl;
		cout << Testimonials.at(index).model << endl;
		cout << Testimonials.at(index).text << endl;
		cout << endl;
	}
}

int TestimonialList::GetCount()
{
	return Testimonials.size();
}
