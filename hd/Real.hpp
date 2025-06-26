#ifndef REAL_HPP
#define REAL_HPP

#include "Fraction.hpp"


class Real {
public:

	Real();
	Real(Integer divider, Integer divided);
	Real(Fraction frac);


	Real operator+(Real other);
	Real operator-(Real other);
	Real operator*(Real other);
	Real operator/(Real other);

	Real operator+=(Real other);
	Real operator-=(Real other);
	Real operator*=(Real other);
	Real operator/=(Real other);

	Real operator=(Real other);
	Real operator=(int other);




	friend std::ostream& operator<< (std::ostream& out, Real& read);

	void SetValue(Integer divider, Integer divided);
	void SetValue(Fraction value);
	void SetValue(Real value);

	void ValueOut();

	std::string ToString();

	void CalcAfterDot();

private:


	Fraction value;
	std::string afterDot;
};



#endif // !REAL_HPP
