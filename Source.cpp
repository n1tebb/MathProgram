#include <iostream>
#include "hd/Integer.hpp"
#include "hd/Fraction.hpp"
#include "hd/String.h"
#include "hd/Figure.hpp"
#include "hd/Real.hpp"
#include "hd/Point2d.hpp"
#include "hd/Matrix.hpp"
#include "hd/Vector.hpp"
#include "hd/Segment.hpp"

// Поддержка русской кодировки в Windows
#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

int main() {
	    // Настройка кодировки для Windows
    #ifdef _WIN32
        // Устанавливаем UTF-8 кодировку для консоли
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

	cout << "=== Демонстрация работы всех классов библиотеки ===" << endl;
	cout << endl;

	try {
		// === ДЕМОНСТРАЦИЯ КЛАССА INTEGER ===
		cout << "--- КЛАСС INTEGER ---" << endl;
		Integer int1(15);
		Integer int2(25);
		cout << "Число 1: " << int1.ToString() << endl;
		cout << "Число 2: " << int2.ToString() << endl;
		cout << "Сумма: " << (int1 + int2).ToString() << endl;
		cout << "Произведение: " << (int1 * int2).ToString() << endl;
		cout << "НОД: " << int1.Nod(int2) << endl;
		cout << "НОК: " << int1.Nok(int2) << endl;
		cout << endl;

		// === ДЕМОНСТРАЦИЯ КЛАССА FRACTION ===
		cout << "--- КЛАСС FRACTION ---" << endl;
		Fraction frac1(3, 4);
		Fraction frac2(5, 6);
		cout << "Дробь 1: " << frac1 << endl;
		cout << "Дробь 2: " << frac2 << endl;
		cout << "Целая часть дроби 1: " << frac1.FtoInteger().ToString() << endl;
		cout << "Целая часть дроби 2: " << frac2.FtoInteger().ToString() << endl;
		cout << endl;

		// === ДЕМОНСТРАЦИЯ КЛАССА REAL ===
		cout << "--- КЛАСС REAL ---" << endl;
		Real real1(Integer(3), Integer(1));  // 3/1 = 3.00
		Real real2(Integer(5), Integer(2));  // 5/2 = 2.50
		cout << "Вещественное число 1: " << real1.ToString() << endl;
		cout << "Вещественное число 2: " << real2.ToString() << endl;
		cout << endl;
		Integer zero(0);
		Integer one(1);
		Integer two(2);
		Integer three(3);
		Integer four(4);
		Integer five(5);
		
		Point2D p1(Real(Fraction(zero, one)), Real(Fraction(zero, one)));
		Point2D p2(Real(Fraction(three, one)), Real(Fraction(zero, one)));
		Point2D p3(Real(Fraction(zero, one)), Real(Fraction(four, one)));

		// === ДЕМОНСТРАЦИЯ ГЕОМЕТРИЧЕСКИХ ФИГУР ===
		cout << "--- ТРЕУГОЛЬНИК ---" << endl;
		Triangle triangle(p1, p2, p3);
		
		cout << "Треугольник создан успешно" << endl;
		cout << "Вычисляем площадь треугольника..." << endl;
		Real triangleArea = triangle.Square();
		cout << "Площадь: " << triangleArea.ToString() << endl;
		
		cout << "--- КРУГ ---" << endl;
		Point2D circleCenter(Real(Fraction(one, one)), Real(Fraction(one, one)));
		Real radius(Fraction(five, one));
		
		Circle circle(circleCenter, radius);
		
		cout << "Круг создан успешно" << endl;
		cout << "Вычисляем площадь круга..." << endl;
		Real circleArea = circle.Square();
		cout << "Площадь: " << circleArea.ToString() << endl;
		
		cout << "--- ПАРАЛЛЕЛОГРАММ ---" << endl;
		Point2D p5(Real(Fraction(one, one)), Real(Fraction(one, one)));
		Point2D p6(Real(Fraction(four, one)), Real(Fraction(one, one)));
		Point2D p7(Real(Fraction(five, one)), Real(Fraction(three, one)));
		Point2D p8(Real(Fraction(two, one)), Real(Fraction(three, one)));
		
		Parallelogramm parallelogram(p5, p6, p7, p8);
		
		cout << "Параллелограмм создан успешно" << endl;
		cout << "Вычисляем площадь параллелограмма..." << endl;
		Real parallelogramArea = parallelogram.Square();
		cout << "Площадь: " << parallelogramArea.ToString() << endl;
		
		cout << "--- Полиморфная работа с фигурами ---" << endl;
		
		Figure* figures[] = { &triangle, &parallelogram, &circle };
		const char* figureNames[] = { "Треугольник", "Параллелограмм", "Круг" };
		
		for (int i = 0; i < 3; i++) {
			cout << figureNames[i] << ": ";
			Real area = figures[i]->Square();
			cout << "площадь = " << area.ToString() << endl;
		}
		
	} catch (...) {
		cout << "Произошла ошибка при выполнении программы" << endl;
	}
	
	#ifdef _WIN32
		cout << "Нажмите любую клавишу для выхода..." << endl;
		system("pause > nul");
	#endif
	
	return 0;
}                                             