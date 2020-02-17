#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
#include<string>

// overloading as friends or not?
// convention friends only for istream and ostream?
// pre and postfix don't work

class Fraction
{
    //streams operator overloading
    //ostream& operator<< (istream& inputStream, const Fraction& amount);
    friend std::ostream& operator << (std::ostream& outputStream, const Fraction& amount);

    //prefix and postfix overloading
    Fraction operator ++ ();
    Fraction operator ++ (int);
    Fraction operator -- ();
    Fraction operator -- (int);


private:
    int numerator;
    int denominator;


public:
    //constructors / destructors
    Fraction();
    Fraction(int n);
    Fraction(int n, int d);
    ~Fraction();     

    //accessors
    int getNumerator() const;
    int getDenominator() const;

    //mutators
    void setNumerator(int n);
    void setDenominator(int d);

    //methods
    void printFraction();
    void simplifyFraction();

};

//OPERATOR OVERLOADING

//basic arithmethic
const Fraction operator+ (const Fraction& firstFraction, const Fraction& secondFraction);   
const Fraction operator- (const Fraction& firstFraction, const Fraction& secondFraction);  
const Fraction operator* (const Fraction& firstFraction, const Fraction& secondFraction);   
const Fraction operator/ (const Fraction& firstFraction, const Fraction& secondFraction);   //here or as a friend?


//shorthand arithmetic assignment operators
const Fraction operator+= (Fraction& firstFraction, const Fraction& secondFraction);
const Fraction operator-= (Fraction& firstFraction, const Fraction& secondFraction);  
const Fraction operator*= (Fraction& firstFraction, const Fraction& secondFraction);   
const Fraction operator/= (Fraction& firstFraction, const Fraction& secondFraction);

//relational operators
bool operator> (const Fraction& firstFraction, const Fraction& secondFraction);
bool operator< (const Fraction& firstFraction, const Fraction& secondFraction);
bool operator>= (const Fraction& firstFraction, const Fraction& secondFraction);
bool operator<= (const Fraction& firstFraction, const Fraction& secondFraction);
bool operator== (const Fraction& firstFraction, const Fraction& secondFraction);
bool operator!= (const Fraction& firstFraction, const Fraction& secondFraction);

//prefix and postfix increment and decrement by 1


#endif // !FRACTION_H