#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    void set(int, int, int);
    void set(Date& d);
    void print();
    bool equals(Date& d); // Add 'const' here
    bool lessThan(Date& d); // Add 'const' here
    bool validate(int d, int m, int y); // Add this line

  private:
    int    day;
    int    month;
    int    year;

    int  lastDayInMonth(int, int);
    bool leapYear(int);
    string getMonthStr(int);
    

};

#endif
