#include "../hd/Segment.hpp"



Segment::Segment(int amountOfPoints) 
{
	shape_ = new Point2D[amountOfPoints];
	amountOfPoints_ = amountOfPoints;
}


Segment::~Segment() 
{
	delete[] shape_;
}

void Segment::Clear() 
{
	shape_ = NULL;
}

void Segment::AddNewPoint(Point2D point) 
{
	amountOfPoints_ += 1;
	Point2D* newShape = new Point2D[amountOfPoints_.ToInt()];
	for (int i = 0; i < amountOfPoints_.ToInt(); i++) 
	{
		newShape[i] = shape_[i];
	}
	newShape[amountOfPoints_.ToInt() - 1] = point;
}

void Segment::RemoveDotAt(Integer index) {}
