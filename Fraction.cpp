#include "Fraction.h"
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

//Constructors and Destructors
Fraction::Fraction()
   : numerator(0), denominator(1)
{
}

Fraction::Fraction(int n)
{
    numerator = n;
    denominator = 1;
}

Fraction::Fraction(int n, int d)
{
    assert(d != 0);
    if (d < 0)
    {
        numerator = -n;
        denominator = -d;
    }
    else
    {
        numerator = n;
        denominator = d;
    }
}

Fraction::~Fraction()
{
}


// accessors
int Fraction::getDenominator() const
{
    return denominator;
}

int Fraction::getNumerator() const
{
    return numerator;
}

void Fraction::setNumerator(int n)
{
    numerator = n;
}

void Fraction::setDenominator(int d)
{
    denominator = d;
}

// methods
void Fraction::printFraction()
{
    if (numerator == 0)
        cout << setw(5) << 0 << endl;
    if (denominator == 1)
        cout << setw(5) << numerator << endl;
    else
        cout << setw(5) << numerator << "/" << denominator << endl;
}

void Fraction::simplifyFraction()
{
    while (true)
    {
        if (numerator % 2 == 0 && denominator % 2 == 0)
        {
            numerator = numerator / 2;
            denominator = denominator / 2;
        }
        else if (numerator % 3 == 0 && denominator % 3 == 0)
        {
            numerator = numerator / 3;
            denominator = denominator / 3;
        }
        else
            break;
    }
    if (denominator < 0)
    {
        denominator * -1;
        numerator * -1;
    }

}


// overloaded streams
std::ostream& operator << (std::ostream& outputStream, const Fraction& amount)
{
    if (amount.getNumerator() == 0)
        outputStream << setw(5) << 0;
    if (amount.getDenominator() == 1)
        outputStream << setw(5) << amount.getNumerator();
    else
        outputStream << setw(5) << amount.getNumerator() << "/" << amount.getDenominator();

    return outputStream;
}

//prefix and postfix overloading
Fraction Fraction::operator ++ ()
{
    int tempNumerator;
    tempNumerator = getNumerator() + getDenominator();
    return Fraction(tempNumerator, getDenominator());
}
Fraction Fraction::operator ++ (int)
{
    int tempNumerator;
    tempNumerator = getNumerator() + getDenominator();
    return Fraction(tempNumerator, getDenominator());
}
Fraction Fraction::operator -- ()
{
    int tempNumerator;
    tempNumerator = getNumerator() - getDenominator();
    return Fraction(tempNumerator, getDenominator());
}
Fraction Fraction::operator -- (int)
{
    int tempNumerator;
    tempNumerator = getNumerator() - getDenominator();
    return Fraction(tempNumerator, getDenominator());
}


// overloaded operators
// basic arithmetic
const Fraction operator+ (const Fraction& firstFraction, const Fraction& secondFraction)
{
    int localNum = 0, localDenom = 0;

    localNum = firstFraction.getNumerator() * secondFraction.getDenominator() + secondFraction.getNumerator() * firstFraction.getDenominator();
    localDenom = firstFraction.getDenominator() * secondFraction.getDenominator();

    Fraction localFraction(localNum, localDenom);
    localFraction.simplifyFraction();
    return localFraction;
}

const Fraction operator- (const Fraction& firstFraction, const Fraction& secondFraction)
{
    int localNum = 0, localDenom = 0;

    localNum = firstFraction.getNumerator() * secondFraction.getDenominator() - secondFraction.getNumerator() * firstFraction.getDenominator();
    localDenom = firstFraction.getDenominator() * secondFraction.getDenominator();

    Fraction localFraction(localNum, localDenom);
    localFraction.simplifyFraction();
    return localFraction;
}

const Fraction operator* (const Fraction& firstFraction, const Fraction& secondFraction)
{
    int localNum, localDenom;
    localNum = firstFraction.getNumerator() * secondFraction.getNumerator();
    localDenom = firstFraction.getDenominator() * secondFraction.getDenominator();

    Fraction localFraction(localNum, localDenom);
    localFraction.simplifyFraction();
    return localFraction;
}

const Fraction operator/ (const Fraction& firstFraction, const Fraction& secondFraction)
{
    int localNum, localDenom;
    localNum = firstFraction.getNumerator() * secondFraction.getDenominator();
    localDenom = firstFraction.getDenominator() * secondFraction.getNumerator();

    Fraction localFraction(localNum, localDenom);
    localFraction.simplifyFraction();
    return localFraction;
}

//shorthand arithmetic assignment operators
const Fraction operator+= (Fraction& firstFraction, const Fraction& secondFraction)
{
    int tempNumerator, tempDenominator;
    tempNumerator = firstFraction.getNumerator() * secondFraction.getDenominator() + secondFraction.getNumerator() * firstFraction.getDenominator();
    tempDenominator = firstFraction.getDenominator() * secondFraction.getDenominator();

    firstFraction.setNumerator(tempNumerator);
    firstFraction.setDenominator(tempDenominator);

    firstFraction.simplifyFraction();
    return firstFraction;
}

const Fraction operator-= (Fraction& firstFraction, const Fraction& secondFraction)
{
    int tempNumerator, tempDenominator;
    tempNumerator = firstFraction.getNumerator() * secondFraction.getDenominator() - secondFraction.getNumerator() * firstFraction.getDenominator();
    tempDenominator = firstFraction.getDenominator() * secondFraction.getDenominator();

    firstFraction.setNumerator(tempNumerator);
    firstFraction.setDenominator(tempDenominator);

    firstFraction.simplifyFraction();
    return firstFraction;
}

const Fraction operator*= (Fraction& firstFraction, const Fraction& secondFraction)
{
    int tempNumerator, tempDenominator;
    tempNumerator = firstFraction.getNumerator() *  secondFraction.getNumerator();
    tempDenominator = firstFraction.getDenominator() * secondFraction.getDenominator();

    firstFraction.setNumerator(tempNumerator);
    firstFraction.setDenominator(tempDenominator);

    firstFraction.simplifyFraction();
    return firstFraction;
}

const Fraction operator/= (Fraction& firstFraction, const Fraction& secondFraction)
{
    int tempNumerator, tempDenominator;
    tempNumerator = firstFraction.getNumerator() *  secondFraction.getDenominator();
    tempDenominator = firstFraction.getDenominator() * secondFraction.getNumerator();

    firstFraction.setNumerator(tempNumerator);
    firstFraction.setDenominator(tempDenominator);

    firstFraction.simplifyFraction();
    return firstFraction;
}


//relational operators
bool operator> (const Fraction& firstFraction, const Fraction& secondFraction)
{
    Fraction temp1, temp2;
    temp1.setNumerator(firstFraction.getNumerator() * secondFraction.getDenominator());
    temp1.setDenominator(firstFraction.getDenominator() * secondFraction.getDenominator());

    temp2.setNumerator(secondFraction.getNumerator() * firstFraction.getDenominator());
    temp2.setDenominator(firstFraction.getDenominator() * secondFraction.getDenominator());

    if (temp1.getNumerator() > temp2.getNumerator())
    {
        return true;
    }
    else
        return false;
}

bool operator< (const Fraction& firstFraction, const Fraction& secondFraction)
{
    return (secondFraction > firstFraction);
}

bool operator>= (const Fraction& firstFraction, const Fraction& secondFraction)
{
    return !(firstFraction < secondFraction);
}
bool operator<= (const Fraction& firstFraction, const Fraction& secondFraction)
{
    return !(firstFraction > secondFraction);
    }
bool operator== (const Fraction& firstFraction, const Fraction& secondFraction)
{
    return !((firstFraction > secondFraction) || (secondFraction > firstFraction));
    }
bool operator!= (const Fraction& firstFraction, const Fraction& secondFraction)
{
    return !(firstFraction == secondFraction);
}