#pragma once

#ifndef MATRIX_HPP


#include <iostream>
#include "../hd/Integer.hpp"




class Matrix {
private:
	size_t xSize_;
	size_t ySize_;
	Integer** matrix_;


public:
	Matrix(Integer x, Integer y);

	bool operator==(Matrix matrix);
	void operator=(Matrix matrix);

	void operator+=(Matrix matrix);
	void operator-=(Matrix matrix);
	void operator/=(Matrix matrix);
	void operator*=(Matrix matrix);


	Matrix operator+(Matrix matrix);
	Matrix operator-(Matrix matrix);
	Matrix operator/(Matrix matrix);
	Matrix operator*(Matrix matrix);
	Integer* operator[](size_t index);

	Matrix UpDownMatrix();


	void MatrixOut();

	friend std::ostream& operator<<(std::ostream& outs, const Matrix& rso);


};




#endif // !MATRIX_HPP