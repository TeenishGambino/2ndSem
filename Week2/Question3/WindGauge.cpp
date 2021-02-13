/*
CH-231-A
a2_p3.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/
#include"WindGauge.h"
#include<deque>
#include<algorithm>
#include<numeric>

using namespace std;

WindGauge::WindGauge(int period)
{
    wspeed_size = period;
}

void WindGauge::currentWindSpeed(int speed)
{
    if(wspeed.size() < wspeed_size)
    {
        wspeed.push_front(speed);
    }
    else
    {
        wspeed.push_front(speed);
        wspeed.pop_back();
    }
}

int WindGauge::highest() const
{
    /*
    deque<int>::iterator it;
    it = this->wspeed.begin();
    int max = *it;
    ++it;

    for(it; it != wspeed.end(); ++it)
    {
        if (*it > max)
        {
            max = *it;
        }
    }
    return max;
    */

    return *(max_element(this->wspeed.begin(), this->wspeed.end()));

}

int WindGauge::lowest() const
{
    /*
    deque <int>::iterator it;
    it = wspeed.begin();
    int low = *it;
    ++it;

    for(it; it != wspeed.end(); ++it)
    {
        if (*it < low)
        {
            low = *it;
        }
    }*/
    return *(min_element(this->wspeed.begin(), this->wspeed.end()));
}

int WindGauge::average() const
{
   
    deque <int>::iterator it;
    int size = 0;
    int total = 0;
     /*
    for (it = wspeed.begin(); it != wspeed.end(); ++it)
    {
        total += *it;
        size++;
    }
    */
    total = accumulate(this->wspeed.begin(), this->wspeed.end(), 0);
    size = wspeed.size();
    return (total/size);
}

void WindGauge::dump()
{
    cout<<"Highest: " << this->highest()<<endl;
    cout<<"Lowest: "<<this->lowest()<<endl;
    cout<<"Average: "<<this->average()<<endl;
    //cout<<"Size is: "<<this->wspeed_size<<endl;
}