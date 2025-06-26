#pragma once

#include "Point2d.hpp"
#include "Real.hpp"
#include <vector>
#include <cmath>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Real Square() const = 0;
    virtual Real Perimetr() const = 0;
    virtual Point2D Center() const = 0;
    
    virtual void Print() const;
};

class Triangle : public Figure {
private:
    Point2D vertex1_;
    Point2D vertex2_;
    Point2D vertex3_;
    
    Real Distance(const Point2D& p1, const Point2D& p2) const;
    
public:
    Triangle();
    Triangle(const Point2D& v1, const Point2D& v2, const Point2D& v3);
    
    Real Square() const override;
    Real Perimetr() const override;
    Point2D Center() const override;
    
    void SetVertices(const Point2D& v1, const Point2D& v2, const Point2D& v3);
    Point2D GetVertex1() const { return vertex1_; }
    Point2D GetVertex2() const { return vertex2_; }
    Point2D GetVertex3() const { return vertex3_; }
};

class Parallelogramm : public Figure {
private:
    Point2D vertex1_;
    Point2D vertex2_;
    Point2D vertex3_;
    Point2D vertex4_;
    
    Real Distance(const Point2D& p1, const Point2D& p2) const;
    
public:
    Parallelogramm();
    Parallelogramm(const Point2D& v1, const Point2D& v2, const Point2D& v3, const Point2D& v4);
    
    Real Square() const override;
    Real Perimetr() const override;
    Point2D Center() const override;
    
    void SetVertices(const Point2D& v1, const Point2D& v2, const Point2D& v3, const Point2D& v4);
    Point2D GetVertex1() const { return vertex1_; }
    Point2D GetVertex2() const { return vertex2_; }
    Point2D GetVertex3() const { return vertex3_; }
    Point2D GetVertex4() const { return vertex4_; }
};

class Circle : public Figure {
private:
    Point2D center_;
    Real radius_;
    
public:
    Circle();
    Circle(const Point2D& center, const Real& radius);
    
    Real Square() const override;
    Real Perimetr() const override;
    Point2D Center() const override;
    
    void SetCenter(const Point2D& center);
    void SetRadius(const Real& radius);
    Point2D GetCenter() const { return center_; }
    Real GetRadius() const { return radius_; }
};

