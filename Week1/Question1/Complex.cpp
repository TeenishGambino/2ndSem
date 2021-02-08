

//#include"Complex.h"

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

//Destructor//
Complex::~Complex()
{
    //cout<<"Destructor"<<endl;
}

//This is used to compare the complexs//
bool Complex::operator == (Complex const &obj)
{
    //Returns true when both real and obj
    //are the same//
    if ((real == obj.real)&&(imag == obj.imag))
    {
        return true;
    }
    else
    {
        return false;
    }
}

