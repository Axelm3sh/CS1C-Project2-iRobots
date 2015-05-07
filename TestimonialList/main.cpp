#include "Input.h"
#include "Testimonials.h"
using namespace std;

int main()
{
	TestimonialList test1;

	test1 = TakeInput();

	test1.PrintAll();

	test1.Add("xyz");

	WriteToFile(test1);
}
