#pragma once


#include <cmath>
#include <iostream>
#include "../hd/Integer.hpp"

class Fraction
{
public:
	Fraction();
	Fraction(Integer num, Integer denum);
	Fraction(const Integer& number);

	void SetSign(bool sign);
	void setDenum(Integer num);
	void setNum(Integer denum);

	bool GetSign();
	Integer GetNumerator();
	Integer GetDenominator();

	friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);

	bool isProper()const;

	bool isImProper()const;

	bool isNumPositive()const;

	bool isNumNegative()const;

	bool isSame(const Fraction& other) const;

	bool isEqual(const Fraction& other);

	Fraction ReduceFraction();

	Integer FtoInteger();

	Fraction ReverseFraction();

	Integer CountUnits() const;

	Integer WholePart()const { return num_ / denum_; }

	Integer CountRemainder() const;

	Fraction operator+(const Fraction& other) const;

	Fraction operator-(const Fraction& other) const;

	Fraction operator*(const Fraction& other) const;

	Fraction operator/(const Fraction& other) const;


	bool operator==(Fraction& other);

	bool operator!=(Fraction& other);

	bool operator<(Fraction& other);

	bool operator>(Fraction& other);

	bool operator<=(Fraction& other);

	bool operator>=(Fraction& other);


	void operator+=(const Fraction& other);

	void operator-=(const Fraction& other);

	void operator*=(const Fraction& other);

	void operator/=(const Fraction& other);


	Fraction operator++(int);

	Fraction operator--(int);

	Fraction operator++();

	Fraction operator--();

	Fraction operator+();

	Fraction operator-() const;

private:
	bool sign_;
	Integer num_;
	Integer denum_;
};
