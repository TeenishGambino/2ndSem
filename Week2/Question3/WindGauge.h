/*
CH-231-A
a2_p3.h
Abiral Banjade
abanjade@jacobs-university.de
*/
#include<iostream>
#include<deque>

using namespace std;

class WindGauge {
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void dump();
    private:
        deque<int> wspeed; 
        int wspeed_size; 
           // add properties and/or method(s) here
};
