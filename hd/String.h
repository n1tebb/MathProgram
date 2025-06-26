/*
#pragma once

#include <string.h>
#include <iostream>
#include <climits>
#include <cstddef>

class String
{
public:
	String();
	explicit String(int num);
	String(const char* str);

	// rule of 3 
	~String(); //Деструктор
	String(const String& other); // Конструктор копирования
	String& operator=(const String& other); //Оператор переприсваивания копирования Copy assign operator

	// rule of 5 
	String(String&& other)noexcept; // Конструктор переноса
	String& operator=(String&& other)noexcept; // оператор переноса переприсваивания

	void reserve(int new_capacity);
	void shrink_to_fit();
	void clean();
	bool empty()const;

	int capacity()const;
	int size()const;


	String& operator+=(const String& other);
	String& operator+=(char ch);
	friend String operator+(const String& lsd, const String& rsd);
	friend String operator+(const String& lsd, char ch);
	friend String operator+(char ch, const String& rsd);


	friend bool operator<(const String& lsd, const String& rsd);
	friend bool operator>(const String& lsd, const String& rsd);
	friend bool operator>=(const String& lsd, const String& rsd);
	friend bool operator<=(const String& lsd, const String& rsd);
	friend bool operator==(const String& lsd, const String& rsd);
	friend bool operator!=(const String& lsd, const String& rsd);

	char& operator[](int i)noexcept;
	const char& operator[](int i)const noexcept;

	char& at(int i);
	const char& at(int i)const;

	friend std::ostream& operator<<(std::ostream& out, const String& rsd);
	friend std::istream& operator>>(std::istream& out, const String& rsd);

	char* data();
	const char* c_str()const;

	class iterator
	{
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = int;
		using pointer = int*;
		using reference = int&;

		iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }
		iterator& operator++() { m_ptr++; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
		friend bool operator== (const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
	};

	iterator begin() { return iterator(&m_data[0]); }
	iterator end() { return iterator(&m_data[200]); }

	class const_iterator{};
	class right_iterator{};
	class const_right_iterator {};

	iterator begin();
	iterator end();
	
	right_iterator rbegin();
	right_iterator rend();

	const_iterator cend()const;
	const_iterator cbegin()const;

	const_right_iterator crbegin()const;
	const_right_iterator crend()const;

	void insert(iterator& obj,char ch);
	void emplace(iterator& obj, char ch);

	void push_back(const char& ch);
	void push_back(char&& ch);

	void pop_back();



private:
	
	struct
	{
		char* allocate(int size) {
			char(*size_) = new char[size];
			return size_;
		}
		void deallocate(char* place) {
			delete[] place;
		}
		void reallocate(char*& place, int old_size, int new_size) 
		{
			char* newPlace = new char[new_size];
			for (int i = 0; i < old_size && i < new_size; i++)
			{
				newPlace[i] = place[i];
			}
			delete[] place;
			place = newPlace;
		}
	}allocator_;

	char* str_;
	size_t size_;
	size_t capacity_;
};
*/