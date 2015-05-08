#include "Input.h"

void WriteToFile(TestimonialList testList)
{
	ofstream outFile;
	int index;

	outFile.open("Testimonials.txt");

	for(index = 0; index < testList.GetCount(); index++)
	{
		outFile << testList.GetTestimonial(index).user << endl;
		outFile << testList.GetTestimonial(index).model << endl;
		outFile << testList.GetTestimonial(index).text << endl;
		outFile << endl;
	}

	outFile.close();
}
