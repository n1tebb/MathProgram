#include "../hd/Point2d.hpp"



Point2D::Point2D() {
	coordinateX_ = 0;
	coordinateY_ = 0;
}

Point2D::Point2D(Real x, Real y) {
	coordinateX_ = x;
	coordinateY_ = y;
}

void Point2D::SetPosition(Real x, Real y) {
	coordinateX_ = x;
	coordinateY_ = y;
}

Vector Point2D::GetPosition() {
	return Vector(coordinateX_, coordinateY_);
}