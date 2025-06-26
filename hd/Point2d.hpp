#ifndef POINT2D_HPP
#define POINT2D_HPP
#include "Real.hpp"
#include "Vector.hpp"



class Point2D {
public:
	Point2D();
	Point2D(Real x, Real y);
	void SetPosition(Real x, Real y);
	Vector GetPosition();

private:
	Real coordinateX_;
	Real coordinateY_;
};



#endif // !POINT2D_HPP
