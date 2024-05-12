#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  set(d, m, y);
}

void Date::set(int d, int m, int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth(m, y) ) ? d : 0 );
}

void Date::set(Date& d)
{
  set(d.day, d.month, d.year);
}

bool Date::equals(Date& d)
{
    return (day == d.day && month == d.month && year == d.year);
}


bool Date::lessThan(Date& d)
{
    if (year < d.year)
        return true;
    else if (year == d.year && month < d.month)
        return true;
    else if (year == d.year && month == d.month && day < d.day)
        return true;
    return false;
}



void Date::print()
{
  cout << right << setfill('0') << setw(4) << year << "-"
       << setw(2) << month << "-"
       << setw(2) << day;
}

int Date::lastDayInMonth(int m, int y)
{ 
  switch(m)
  {
    case 2:
      if (leapYear(y))
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30; 
  }
}

bool Date::leapYear(int y)
{ 
  if ( y%400 == 0 ||
       (y%4 == 0 && y%100 != 0) )
    return true;
  else
    return false;
}   
  
string Date::getMonthStr(int m)
{
  string monthStrings[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( m >= 1 && m <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
} 


bool Date::validate(int d, int m, int y) {
    // Implement validation logic here
    // For example:
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > lastDayInMonth(m, y)) {
        return false; // Return false if the date is invalid
    }
    return true; // Return true if the date is valid
}

