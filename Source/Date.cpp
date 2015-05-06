
#include "Date.h"

/************************************************************************
    CONSTRUCTORS & DESTRUCTOR
 ************************************************************************/

Date::Date()
{
	dateMonth = 0;
	dateDay   = 0;
	dateYear  = 0;

}

Date::Date(int month,
		   int day,
		   int year)
{
	SetDate(month, day, year);
}

Date::~Date() { }


/************************************************************************
	 MUTATORS
 ************************************************************************/

// Sets the date given a month day and year
void Date::SetDate(int month,
				   int day,
				   int year)
{
		// Set the Date
		dateMonth = month;
		dateDay   = day;
		dateYear  = year;
}

/**************************************************************************
     ACCESSORS
***************************************************************************/
void Date::GetDate(int &month,
				   int &day,
				   int &year) const
{
	  month = dateMonth;
	  day   = dateDay;
	  year  = dateYear;
}

int  Date::GetYear() const
{
	return dateYear;
}

int  Date::GetMonth() const
{
	return dateMonth;
}

int  Date::GetDay() const
{
	return dateDay;
}

string Date::DisplayDate() const
{
	ostringstream output; //OUT - stores output info, returned as string

	// Check if Day or Month are < 10 and add a leading 0 if necessary
	if (dateMonth < 10)
	{
		output << '0';
	}
	output << dateMonth << '/';
	if (dateDay < 10)
	{
		output << '0';
	}
	output << dateDay   << '/'
		   << dateYear;

	return output.str();
}

bool Date::operator<(const Date& other){
	bool lessThan = false;
		if(dateYear < other.dateYear){
			lessThan = true;
		}
		else{
			if(dateYear == other.dateYear){
				if(dateMonth < other.dateMonth)
				{
					lessThan = true;
				}
				if(dateMonth == other.dateMonth){
					if(dateDay < dateDay)
					{
						lessThan = true;
					}
				}
			}
		}
		return lessThan;
}

