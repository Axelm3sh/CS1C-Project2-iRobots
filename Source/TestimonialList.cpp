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
		cout << index+1 << '.' << endl;
		cout << Testimonials.at(index).user << endl;
		cout << Testimonials.at(index).model << endl;
		cout << Testimonials.at(index).text << endl;
		cout << endl;
		cout << "";
	}
}

int TestimonialList::GetCount()
{
	return Testimonials.size();
}

void TestimonialList::DeleteTestimonial(int position)
{
	vector<TestimonialNode>::iterator target;

	int index;

	target = Testimonials.begin();

	for(index = 1; index < position; index++)
	{
		target++;
	}

	Testimonials.erase(target);
}
