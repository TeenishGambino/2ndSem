/*
CH-231-A
testa2_p3.cpp
Abiral Banjade
abanjade@jacobs-university.de
*/
#include"WindGauge.h"
#include<iostream>

using namespace std;

int main(void)
{
    WindGauge test;
    test.currentWindSpeed(15);
    test.currentWindSpeed(16);
    test.currentWindSpeed(12);
    test.currentWindSpeed(15);
    test.currentWindSpeed(15);
    test.dump();

    test.currentWindSpeed(16);
    test.currentWindSpeed(17);
    test.currentWindSpeed(16);
    test.currentWindSpeed(16);
    test.currentWindSpeed(20);
    test.currentWindSpeed(17);
    test.currentWindSpeed(16);
    test.currentWindSpeed(20);

    test.dump();

    return 0;
}