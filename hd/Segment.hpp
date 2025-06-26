#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Point2d.hpp"


class Segment {
public:
	Segment(int amountOfPoints);

	~Segment();


	void Clear();

	void AddNewPoint(Point2D point);

	void RemoveDotAt(Integer index);

private:
	Point2D* shape_;
	Integer amountOfPoints_;

};

#endif // !SEGMENT_HPP
