
/*
CH-231-A
a1_p1.h
Abiral Banjade
abanjade@jacobs-university.de
*/

#include"Complex.h"

using namespace std;

//Default constructor//
Complex::Complex()
{
    real = 0;
    imag = 0;
}

//Parameterized constructor//
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

//Copy constructor//
Complex::Complex(const Complex& value)
{
    real = value.real;
    imag = value.imag;
}

//Setters//
void Complex::setReal(double rea)
{
    real = rea;
}

void Complex::setImag(double ima)
{
    imag = ima;
}

//Getters//
double Complex::getImag()
{
    return imag;
}

double Complex::getReal()
{
    return real;
}

//Printing//
void Complex::print()
{
    //Doesn't show positive sign//
    cout<<noshowpos<<real;
    //Does show positive sign//
    cout<<showpos<<imag<<"i"<<endl;
}

//Adding//
Complex Complex::add(Complex value1)
{
    Complex temp;
    temp.real = real + value1.real;
    temp.imag = imag + value1.imag;

    return temp;
}

//Substracting//
Complex Complex::sub(Complex value1)
{
    Complex temp;
    temp.real = real - value1.real;
    temp.imag = imag - value1.imag;

    return temp;
}

//Multiply//
Complex Complex::mult(Complex value1)
{
    Complex temp;
    temp.real = real*value1.real - imag*value1.imag;
    temp.imag = imag*value1.real + real*value1.imag;
    return temp;
}

//Conjugate//
Complex Complex::conjugate()
{
    Complex temp;
    temp.real = getReal();
    temp.imag = -imag;

    return temp;
}

//Destructor//

Complex::~Complex()
{
    //cout<<"Destructor"<<endl;
}

bool Complex::operator == (Complex const &obj)
        {
            if ((real == obj.real)&&(imag == obj.imag))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

