#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  set(h, m);
}

void Time::set(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

void Time::set(const Time& t)
{
    hours = t.hours;
    minutes = t.minutes;
}

bool Time::lessThan(const Time& t)
{
    int thisTimeInMins = convertToMins();
    int tTimeInMins = t.convertToMins();
    return thisTimeInMins < tTimeInMins;
}

bool Time::validate(int h, int m)
{
    return (h >= 0 && h < 24 && m >= 0 && m < 60);
}

int Time::convertToMins() const
{
  return (hours*60 + minutes);

}

void Time::print()
{
  cout<<setfill('0')<<setw(2)<<hours<<":"
      <<setfill('0')<<setw(2)<<minutes;
}

