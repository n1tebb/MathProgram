/*#include "..\hd\String.h"


String::String() 
{
	size_ = 0;
	capacity_ = 0;
	str_ = 0;
}
String::String(int num) 
{
	str_ = allocator_.allocate(num);
	size_ = 0;
	capacity_ = num;
}

String::String(const char* str) 
{
	str_ = allocator_.allocate(strlen(str));
	std::memcpy(str_, str, strlen(str));
	capacity_ = strlen(str);
}

String::~String() {
	delete[] this;
}

String::String(const String& other) 
{
	str_ = other.str_;
	size_ = other.size_;
	capacity_ = other.capacity_;
}

String& String::operator=(const String& other) {
	str_ = other.str_;
	size_ = other.size_;
	capacity_ = other.capacity_;
	return *this;
}
String::String(String&& other)noexcept {
	
	str_ = 0;
	size_ = 0;
	capacity_ = 0;
	std::swap(size_, other.size_);
	std::swap(capacity_, other.capacity_);
	std::swap(str_, other.str_);
}
String& String::operator=(String&& other)noexcept {
	str_ = 0;
	size_ = 0;
	capacity_ = 0;
	std::swap(size_, other.size_);
	std::swap(capacity_, other.capacity_);
	std::swap(str_, other.str_);
	return *this;
}


void String::reserve(int new_capacity) {
	if (new_capacity > 0)
	{
		capacity_ = new_capacity;
	}
}

void String::clean() {
	for (int i = 0; i < size_; i++)
	{
		str_[i] = '/0';
	}
	size_ = 0;
}

void String::shrink_to_fit() {
	capacity_ -= (capacity_ - size_);
	capacity_ + 1;
}

bool String::empty()const {
	return str_ == "";
}

int String::capacity()const {
	return capacity_;
}
int String::size()const {
	return size_;
}

String operator+(const String& lsd, const String& rsd) 
{
	String res(lsd.size_ + rsd.size_);
	
	for (int i = 0; i < strlen(lsd.str_); i++)
	{
		res.str_[i] = lsd.str_[i];
	}
	for (int i = strlen(lsd.str_); i < strlen(lsd.str_) + strlen(rsd.str_); i++)
	{
		res.str_[i] = rsd.str_[i - strlen(lsd.str_)];
	}
	return res;
}

String operator+(const String& lsd, char ch) {
	String res(lsd.size_ + 1);
	for (int i = 0; i < strlen(lsd.str_); i++)
	{
		res.str_[i] = lsd.str_[i];
	}
	res.str_[res.size_] = ch;
	return res;
}

String operator+(char ch, const String& rsd) {
	String res(rsd.size_ + 1);
	res.str_[0] = ch;
	for (int i = 1; i < strlen(rsd.str_) + 1; i++)
	{
		res.str_[i] = rsd.str_[i];
	}

	return res;
}


String& String::operator+=(const String& other) {
	*this = *this + other;
	return *this;
}
String& String::operator+=(char ch) {
	*this = *this + ch;
	return *this;
}

bool operator<(const String& lsd, const String& rsd) {
	return lsd.size_ < rsd.size_;
}
bool operator>(const String& lsd, const String& rsd) {
	return lsd.size_ > rsd.size_;
}
bool operator>=(const String& lsd, const String& rsd) {
	return lsd.size_ >= rsd.size_;
}
bool operator<=(const String& lsd, const String& rsd) {
	return lsd.size_ <= lsd.size_;
}
bool operator==(const String& lsd, const String& rsd) {
	return lsd.size_ == rsd.size_;
}
bool operator!=(const String& lsd, const String& rsd) {
	return lsd.size_ != rsd.size_;
}

char& String::operator[](int i)noexcept {
	return str_[i];
}

const char& String::operator[](int i)const noexcept {

	return str_[i];
}

char& String::at(int i) {
	return str_[i]; 
}

const char& String::at(int i)const {
	return str_[i];
}



char* String::data() {
	char* ptr = str_;
	return ptr;
}
const char* String::c_str()const {
	return str_;
}

std::ostream& operator<<(std::ostream& out, const String& rsd) {
	out << rsd;
	return out;
}

std::istream& operator>>(std::istream& out, const String& rsd) {
	out >> rsd;
	return out;
}

void String::push_back(const char& ch)
{
	*this += ch;
}

void String::push_back(char&& ch)
{
	*this += ch;
}

void String::pop_back()
{
	str_[::strlen(str_) - 1] = '/0';
	size_ - 1;
	capacity_ - 1;
}
*/