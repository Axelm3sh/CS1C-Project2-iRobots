#include "Input.h"

TestimonialList TakeInput()
{
	ifstream testimonialInput;
	string receivedString;
	TestimonialList testimonialList;

	testimonialInput.open("Testimonials.txt");

	while(testimonialInput)
	{
		getline(testimonialInput, receivedString);

		testimonialList.Add(receivedString);

	}

	testimonialInput.close();

	return testimonialList;
}
