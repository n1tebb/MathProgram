#pragma once

#include <iostream>
#include <cmath>
#include <numeric>
#include <string>

class Integer
{
public:
	//Êîíñòðóêòîðû
	Integer();
	Integer(bool sign, unsigned units);
	Integer(int number);
	//Ñåòåðû
	void setSign(bool sign);
	void setValue(unsigned value);
	//Ãåòåðû
	bool getSign()const;
	long getValue()const;
	int ToInt();
	// Ôóíêöèè ïðîâåðêè ñîñòîÿíèÿ
	//bool isPrimeNum();
	
	bool isOdd();
	bool isEven();
	bool isPositive()const;
	bool isNegative()const;
	int Nod(Integer other)const;
	bool isCoprime(Integer other)const;
	std::string ToString();
	int Nok(Integer other)const;
	bool isSimple()const;

	//Ïåðåãðóçêè îïåðàòîðîâ

	//Àëãåáðàè÷åñêèå îïåðàòîðû
	Integer& operator + (const Integer& counter)const;
	//Óíàðíûé +
	Integer operator + ();

	Integer operator * (const Integer& counter)const;

	Integer operator / (const Integer& counter)const;

	Integer& operator - (const Integer& other) const;
	//Óíàðíûé -
	Integer operator - ();

	Integer operator % (const Integer& counter)const;


	// Îïåðàòîðû ñðàâíåíèÿ
	friend bool operator == (const Integer& num, const Integer& other);

	friend bool operator != (const Integer& num, const Integer& other);

	friend bool operator > (const Integer& num, const Integer& other);

	friend bool operator < (const Integer& num, const Integer& other);

	friend bool operator <= (const Integer& num, const Integer& other);

	friend bool operator >= (const Integer& num, const Integer& other);

	//Ïðåôåêñíûé Äåêðåìåíò, Èíêðåìåíò
	Integer& operator++ ();

	Integer& operator-- ();

	// Ïîñòôèêñíûé Äåêðåìåíò, Èíêðèìåíò
	Integer operator++ (int);

	Integer operator-- (int);

	// îïåðàòîðû ïðèñâîåíèÿ
	Integer& operator += (Integer other);

	Integer& operator -= (Integer other);

	Integer& operator *= (const Integer& counter);

	Integer& operator /= (const Integer& counter);
	
	//Îïåðàòîð âûâîäà
	friend std::ostream& operator<<(std::ostream& out, const Integer& other);

private:
	bool sign_;
	long value_;

};
