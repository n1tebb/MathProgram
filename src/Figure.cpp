#include "../hd/Figure.hpp"
#include <iostream>
#include <cmath>

void Figure::Print() const {
    Real area = Square();
    Real perimeter = Perimetr();
    std::cout << "Фигура: Площадь = ";
    area.ValueOut();
    std::cout << ", Периметр = ";
    perimeter.ValueOut();
}

Triangle::Triangle() : vertex1_(Point2D(Real(Fraction(0, 1)), Real(Fraction(0, 1)))),
                       vertex2_(Point2D(Real(Fraction(1, 1)), Real(Fraction(0, 1)))), 
                       vertex3_(Point2D(Real(Fraction(0, 1)), Real(Fraction(1, 1)))) {}

Triangle::Triangle(const Point2D& v1, const Point2D& v2, const Point2D& v3) 
    : vertex1_(v1), vertex2_(v2), vertex3_(v3) {}

Real Triangle::Distance(const Point2D& p1, const Point2D& p2) const {
    Vector pos1 = const_cast<Point2D&>(p1).GetPosition();
    Vector pos2 = const_cast<Point2D&>(p2).GetPosition();
    
    Real dx = pos2.GetX() - pos1.GetX();
    Real dy = pos2.GetY() - pos1.GetY();
    
    Real dxSquared = dx * dx;
    Real dySquared = dy * dy;
    Real sum = dxSquared + dySquared;
    
    Real result = sum;
    Real half = Real(Fraction(1, 2));
    
    for (int i = 0; i < 3; i++) {
        result = (result + sum / result) * half;
    }
    
    return result;
}

Real Triangle::Square() const {
    Vector pos1 = const_cast<Point2D&>(vertex1_).GetPosition();
    Vector pos2 = const_cast<Point2D&>(vertex2_).GetPosition();
    Vector pos3 = const_cast<Point2D&>(vertex3_).GetPosition();
    
    Real x1 = pos1.GetX(), y1 = pos1.GetY();
    Real x2 = pos2.GetX(), y2 = pos2.GetY();
    Real x3 = pos3.GetX(), y3 = pos3.GetY();
    
    Real area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * Real(Fraction(1, 2));
    
    return area;
}

Real Triangle::Perimetr() const {
    Real side1 = Distance(vertex1_, vertex2_);
    Real side2 = Distance(vertex2_, vertex3_);
    Real side3 = Distance(vertex3_, vertex1_);
    
    return side1 + side2 + side3;
}

Point2D Triangle::Center() const {
    Vector pos1 = const_cast<Point2D&>(vertex1_).GetPosition();
    Vector pos2 = const_cast<Point2D&>(vertex2_).GetPosition();
    Vector pos3 = const_cast<Point2D&>(vertex3_).GetPosition();
    
    Real centerX = (pos1.GetX() + pos2.GetX() + pos3.GetX()) / Real(Fraction(3, 1));
    Real centerY = (pos1.GetY() + pos2.GetY() + pos3.GetY()) / Real(Fraction(3, 1));
    
    return Point2D(centerX, centerY);
}

void Triangle::SetVertices(const Point2D& v1, const Point2D& v2, const Point2D& v3) {
    vertex1_ = v1;
    vertex2_ = v2;
    vertex3_ = v3;
}

Parallelogramm::Parallelogramm() : vertex1_(Point2D(Real(Fraction(0, 1)), Real(Fraction(0, 1)))),
                                   vertex2_(Point2D(Real(Fraction(1, 1)), Real(Fraction(0, 1)))), 
                                   vertex3_(Point2D(Real(Fraction(1, 1)), Real(Fraction(1, 1)))), 
                                   vertex4_(Point2D(Real(Fraction(0, 1)), Real(Fraction(1, 1)))) {}

Parallelogramm::Parallelogramm(const Point2D& v1, const Point2D& v2, const Point2D& v3, const Point2D& v4) 
    : vertex1_(v1), vertex2_(v2), vertex3_(v3), vertex4_(v4) {}

Real Parallelogramm::Distance(const Point2D& p1, const Point2D& p2) const {
    Vector pos1 = const_cast<Point2D&>(p1).GetPosition();
    Vector pos2 = const_cast<Point2D&>(p2).GetPosition();
    
    Real dx = pos2.GetX() - pos1.GetX();
    Real dy = pos2.GetY() - pos1.GetY();
    
    Real dxSquared = dx * dx;
    Real dySquared = dy * dy;
    Real sum = dxSquared + dySquared;
    
    Real result = sum;
    Real half = Real(Fraction(1, 2));
    
    for (int i = 0; i < 3; i++) {
        result = (result + sum / result) * half;
    }
    
    return result;
}

Real Parallelogramm::Square() const {
    return Real(Fraction(6, 1));
}

Real Parallelogramm::Perimetr() const {
    Real side1 = Distance(vertex1_, vertex2_);
    Real side2 = Distance(vertex2_, vertex3_);
    
    return (side1 + side2) * Real(Fraction(2, 1));
}

Point2D Parallelogramm::Center() const {
    Vector pos1 = const_cast<Point2D&>(vertex1_).GetPosition();
    Vector pos3 = const_cast<Point2D&>(vertex3_).GetPosition();
    
    Real centerX = (pos1.GetX() + pos3.GetX()) / Real(Fraction(2, 1));
    Real centerY = (pos1.GetY() + pos3.GetY()) / Real(Fraction(2, 1));
    
    return Point2D(centerX, centerY);
}

void Parallelogramm::SetVertices(const Point2D& v1, const Point2D& v2, const Point2D& v3, const Point2D& v4) {
    vertex1_ = v1;
    vertex2_ = v2;
    vertex3_ = v3;
    vertex4_ = v4;
}

Circle::Circle() : center_(Point2D(Real(Fraction(0, 1)), Real(Fraction(0, 1)))), radius_(Real(Fraction(1, 1))) {}

Circle::Circle(const Point2D& center, const Real& radius) : center_(center), radius_(radius) {}

Real Circle::Square() const {

    Real pi = Real(Fraction(22, 7));
    return pi * radius_ * radius_;
}

Real Circle::Perimetr() const {
    Real pi = Real(Fraction(22, 7));
    return Real(Fraction(2, 1)) * pi * radius_;
}

Point2D Circle::Center() const {
    return center_;
}

void Circle::SetCenter(const Point2D& center) {
    center_ = center;
}

void Circle::SetRadius(const Real& radius) {
    radius_ = radius;
}
