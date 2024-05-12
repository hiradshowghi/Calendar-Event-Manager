#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int=0, int=0);
    void set(int, int);
    void print();
    void set(const Time& t); // Add this line
    bool lessThan(const Time& t); // Add this line
    bool validate(int h, int m);
    bool lessThan(const Time& t) const; // Add 'const' here
    void print() const; // Add 'const' here
    
  private:
    int hours;
    int minutes;
    int convertToMins() const;
};

#endif
