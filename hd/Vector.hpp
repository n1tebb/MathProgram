#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP
#include "Real.hpp"




class Vector {
public:
	Vector();
	Vector(Real CoordinateX, Real CoordinateY);


	friend std::ostream& operator<< (std::ostream& out, Vector& read);

	friend std::istream& operator>>(std::istream& in, Vector& write);

	void operator=(Vector other);
	Vector operator+(Vector other);
	Vector operator-(Vector other);
	Vector operator*(Vector other);
	Vector operator/(Vector other);

	Vector Normalize();

	Real GetX();
	Real GetY();

private:
	Real coordinateX_;
	Real coordinateY_;
};



#endif // !VECTOR2D_HPP
