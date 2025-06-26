#include "../hd/Integer.hpp"


	Integer::Integer() :Integer(false, 0u) { }
	Integer::Integer(bool sign, unsigned units) :sign_(sign), value_(value_) { }
	Integer::Integer(int number) {
		if (number < 0)
		{
			sign_ = false;
			value_ = abs(number);
		}
		else 
		{
			sign_ = true;
			value_ = static_cast<unsigned>(number);
		}
	}

	void Integer::setSign(bool sign) 
	{
		this->sign_ = sign;
	}

	void Integer::setValue(unsigned value) 
	{
		this->value_ = value;
	}

	bool Integer::getSign()const 
	{
		return sign_;
	}

	long Integer::getValue()const 
	{
		return value_;
	}	

	int Integer::ToInt() {
		if (isPositive() == true) 
		{
			return int(value_);
		}
		else {
			return -int(value_);
		}

	}


	bool Integer::isSimple()const
	{
		if (value_ < 2)
		{
			return false;
		}
		for (int i = 2; i <= value_ / 2; i++)
		{
			if (value_ % i == 0)
			{
				return false;
			}
		}
		return true;
	}
	bool Integer::isOdd() 
	{
		return value_ % 2 != 0;
	}

	bool Integer::isEven() 
	{
		return value_ % 2 == 0;
	}

	bool Integer::isPositive()const 
	{
		return getSign();
	}

	bool Integer::isNegative() const
	{
		return !getSign();
	}

	bool Integer::isCoprime(Integer other)const
	{
		return std::gcd(value_, other.value_) == 1;
	}

	std::string Integer::ToString() 
	{
		return std::to_string(value_);
	}


	int Integer::Nod(Integer other)const
	{
		return std::gcd(value_, other.value_);
	}

	int Integer::Nok(Integer other)const
	{
		return std::lcm(value_, other.value_);
	}

	Integer& Integer::operator + (const Integer& other) const
	{
		Integer result;
		if (sign_ == other.sign_) 
		{
			result.sign_ = sign_;
			result.value_ = value_ + other.value_;
		}
		else {
			if (value_ > other.value_)
			{
				result.sign_ = sign_;
				result.value_ = value_ - other.value_;
			}
			else if (value_ < other.value_) 
			{
				result.sign_ = other.sign_;
				result.value_ = other.value_ - value_;
			}
			else 
			{
				result.sign_ = false;
				result.value_ = true;
			}
		}
		return result;
		
	}

	Integer Integer::operator + () 
	{
		return *this;
	}

	Integer Integer::operator * (const Integer& other) const
	{
		Integer result;
		if (sign_ == other.sign_)
		{
			result.sign_ = sign_;
			result.value_ = value_ * other.value_;
		}
		else if (sign_ != other.sign_) {

			result.sign_ = false;
			result.value_ = value_ * other.value_;
		}
		return result;
	}

	Integer Integer::operator / (const Integer& other) const
	{
		if (other.value_ == 0)
		{
			std::cerr << "Invalid input";
			exit(-1);
		}
		Integer result;
		if (sign_ == other.sign_)
		{
			result.sign_ = sign_;
			result.value_ = value_ / other.value_;
		}
		else if (sign_ != other.sign_) {

			result.sign_ = false;
			result.value_ = value_ / other.value_;
		}
		return result;
	}

	Integer& Integer::operator - (const Integer& other) const
	{
		Integer result;
		if (sign_ == other.sign_ && sign_ == true && value_ > other.value_)
		{
			result.sign_ = sign_;
			result.value_ = value_ - other.value_;
		}
		else if (sign_ == other.sign_ && sign_ == true && value_ < other.value_) {
			result.sign_ = !sign_;
			result.value_ = other.value_ - value_;
		}
		else if (sign_ == other.sign_ && sign_ == false) {
			result.sign_ = sign_;
			result.value_ = other.value_ + value_;
		}
		else if (sign_ != other.sign_ && sign_ == true && value_ < other.value_) {
			result.sign_ = other.sign_;
			result.value_ = other.value_ - value_;
		}
		else if (sign_ != other.sign_ && value_ > other.value_) {
			result.sign_ = sign_;
			result.value_ = value_ - other.value_;
		}
		else if (sign_ != other.sign_ && sign_ == false && value_ < other.value_) {
			result.sign_ = other.sign_;
			result.value_ = other.value_ - value_;
		}	
		return result;
	}

	Integer Integer::operator - ()
	{
		Integer copy{ *this };
			copy.sign_ = !copy.sign_;
			return copy;
	}

	Integer Integer::operator % (const Integer& other) const
	{
		if (other.value_ != 0)
		{
			return static_cast<Integer>(value_ % other.value_);
		}
		else
		{
			std::cerr << "Invalid value";
			exit(-1);
		}
	}
	
	bool operator == (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() == other.getValue();
		}
		return false;
	}

	bool operator != (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() != other.getValue();
		}
		return true;
	}

	bool operator > (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() > other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator < (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() < other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator <= (const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() <= other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator>=(const Integer& num, const Integer& other)
	{
		if (num.getSign() == other.getSign())
		{
			return num.getValue() >= other.getValue();
		}
		else if (num.getSign() == true && other.getSign() == false) {
			return true;
		}
		else {
			return false;
		}
	}


	Integer& Integer::operator++ ()
	{
		Integer copy{ *this };
		if (sign_ == true) {
			copy += static_cast<Integer>(1);
		}
		else {
			copy -= static_cast<Integer>(1);
		}
		return copy;
	}

	Integer& Integer::operator-- ()
	{
		Integer copy{ *this };
		if (sign_ == true) {
			copy -= static_cast<Integer>(1);
		}
		else {
			copy += static_cast<Integer>(1);
		}
		return copy;
	}
	
	Integer Integer::operator++ (int)
	{
		Integer copy{ *this };
		if (sign_ == true)
		{
			++(copy);
		}
		else {
			--(copy);
		}
		return copy;
	}

	Integer Integer::operator-- (int)
	{
		Integer copy{ *this };
		if (sign_ == true)
		{
			--(copy);
		}
		else {
			++(copy);
		}
		return copy;
	}
	
	Integer& Integer::operator += (Integer other)
	{
		return *this = *this + other;
	}

	Integer& Integer::operator -= (Integer other)
	{
		return *this = *this - other;
	}

	Integer& Integer::operator *= (const Integer& other)
	{
		return *this = *this * other;
		
	}

	Integer& Integer::operator /= (const Integer& other)
	{
		return *this = *this / other;
	}


	std::ostream& operator<<(std::ostream& out, const Integer& other) {
		if (other.sign_ == true)
		{
			out << other.value_;
		}
		else
		{
			out << '-' << other.value_;
		}
		return out;
	}

	void operator>>(std::istream& in, Integer& other)
	{
		std::string input;
		std::string inputNum;
		
		if (input[0] == '-')
		{
			for (int i = 1; i < input.length(); i++)
			{
				inputNum[i] = input[i];
			}
			other.setSign(false);
		}
		else
		{
			other.setSign(true);
			inputNum = input;
		}
		other.setValue(stoi(inputNum));
		in >> other;
	}
