#include "../hd/Vector.hpp"




Vector::Vector() {
	coordinateX_ = Real();
	coordinateY_ = Real();
}
Vector::Vector(Real CoordinateX, Real CoordinateY) {
	coordinateX_ = CoordinateX;
	coordinateY_ = CoordinateY;
}


std::ostream& operator<< (std::ostream& out, Vector& read) {
	std::cout << "(X:" << read.coordinateX_ << "; Y:" << read.coordinateY_ << ")";
	return out;
}






void Vector::operator=(Vector other) {
	this->coordinateX_ = this->coordinateX_ + other.coordinateX_;
	this->coordinateY_ = this->coordinateY_ + other.coordinateY_;
}

Vector Vector::operator+(Vector other) {
	Vector answer;

	answer.coordinateX_ = this->coordinateX_ + other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ + other.coordinateY_;


	return answer;
}
Vector Vector::operator-(Vector other) {
	Vector answer;

	answer.coordinateX_ = this->coordinateX_ - other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ - other.coordinateY_;

	return answer;
}
Vector Vector::operator*(Vector other) {
	Vector answer;

	answer.coordinateX_ = this->coordinateX_ * other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ * other.coordinateY_;

	return answer;
}
Vector Vector::operator/(Vector other) {
	Vector answer;

	answer.coordinateX_ = this->coordinateX_ / other.coordinateX_;
	answer.coordinateY_ = this->coordinateY_ / other.coordinateY_;

	return answer;
}




Real Vector::GetX() {
	return coordinateX_;
}
Real Vector::GetY() {
	return coordinateY_;
}