#include "../hd/Real.hpp"
#include <cstdio>







Real::Real() 
{
    value = Fraction(1, 1);
}
Real::Real(Integer divided, Integer divider) 
{
    value = Fraction(divided, divider);
}
Real::Real(Fraction frac) 
{
    value = frac;
}


Real Real::operator+(Real other) 
{
    return Real(value + other.value);
}

Real Real::operator-(Real other) 
{
    return Real(value - other.value);
}

Real Real::operator*(Real other) 
{
    return Real(value * other.value);
}

Real Real::operator/(Real other) 
{
    return Real(value / other.value);
}


Real Real::operator+=(Real other) 
{
    value += other.value;
    return *this;
}

Real Real::operator-=(Real other) 
{
    value -= other.value;
    return *this;
}

Real Real::operator*=(Real other) 
{
    value *= other.value;
    return *this;
}

Real Real::operator/=(Real other) 
{
    value /= other.value;
    return *this;
}


Real Real::operator=(Real other) 
{
    value = other.value;
    return *this;
}
Real Real::operator=(int other) 
{
    value = Fraction(other, 1);;
    return *this;
}





std::ostream& operator<<(std::ostream& out, Real& read) {
    read.ValueOut();
    return out;
};

void Real::SetValue(Integer num, Integer denum) {
    value.GetNumerator().setValue(num.ToInt());
    value.GetDenominator().setValue(denum.ToInt());
}

void SetValue(Fraction value) {}
void SetValue(Real value) {}

void Real::ValueOut() {
    std::cout << ToString() << std::endl;
}

std::string Real::ToString() 
{
    double doubleValue = (double)value.GetNumerator().ToInt() / (double)value.GetDenominator().ToInt();
    
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%.2f", doubleValue);
    
    return std::string(buffer);
}

void Real::CalcAfterDot() 
{
    afterDot = "";
    Integer numerator = value.GetNumerator();
    Integer denominator = value.GetDenominator();

    Integer integerPart = value.FtoInteger();
    Integer remain = numerator - (integerPart * denominator);

    int maxDigits = 2;
    while (remain != 0 && maxDigits-- > 0) 
    {
        remain = remain * 10;
        Integer digit = remain / denominator;
        afterDot += digit.ToString();
        remain = remain - (digit * denominator);
    }

    while (afterDot.length() < 2) {
        afterDot += "0";
    }

    if (afterDot == "") {
        afterDot = "00";
    }
}