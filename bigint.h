#include <iostream>
#include <string>
using namespace std;


class BigInt {
public:
	BigInt(unsigned long long);
	BigInt(string& );
	BigInt(BigInt&);
public:
	BigInt& operator=(const BigInt&);

	BigInt& operator++();
	BigInt operator++(int);
	BigInt& operator--();
	BigInt operator--(int);
	
	vector<int> mult(BigInt&, char);
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);

	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);

	friend ostream& operator<<(ostream&, const BigInt& a);
	friend istream& operator>>(istream&, BigInt&);

	//Addition and Subtraction
	BigInt& operator+=(const BigInt&);
	friend BigInt operator+(BigInt, const BigInt&);
	BigInt& operator-=(const BigInt&);
	friend BigInt operator-(BigInt, const BigInt&);

	//Multiplication and Division
	BigInt& operator*=(const BigInt&);
	friend BigInt operator*(BigInt, const BigInt&);
	BigInt& operator/=(const BigInt&);
	friend BigInt operator/(BigInt, const BigInt&);

	//Modulo
	BigInt& operator%=(const BigInt&);
	friend BigInt operator%(BigInt, const BigInt&);

	//Power Function
	BigInt& operator^=(BigInt&);
	friend BigInt operator^(BigInt, BigInt&);

	string toString() const { return digits; }
private:
	string digits;
};
































////Read and Write
//std::ostream& operator<<(std::ostream&, const BigInt&);
//std::istream& operator>>(std::istream&, BigInt&);
//
//class BigInt
//{
//
//public:
//	BigInt(unsigned long long n = 0);
//	BigInt(const string&);
//	BigInt(const BigInt&);
//
//	/* * * * Operator Overloading * * * */
//
//	// assignment
//	BigInt& operator=(const BigInt&);
//	// assignment: copy and swap idiom (strong exception safety guarantee)
//	// BigInt& operator=(BigInt) noexcept;
//
//	//Post/Pre - Incrementation
//	BigInt& operator++();
//	BigInt operator++(int);
//	BigInt& operator--();
//	BigInt operator--(int);
//
//	//Comparison operators
//	friend bool operator==(const BigInt&, const BigInt&);
//	friend bool operator!=(const BigInt&, const BigInt&);
//
//	friend bool operator>(const BigInt&, const BigInt&);
//	friend bool operator>=(const BigInt&, const BigInt&);
//	friend bool operator<(const BigInt&, const BigInt&);
//	friend bool operator<=(const BigInt&, const BigInt&);
//
//	//Addition and Subtraction
//	BigInt& operator+=(const BigInt&);
//	friend BigInt operator+(BigInt, const BigInt&);
//	BigInt& operator-=(const BigInt&);
//	friend BigInt operator-(BigInt, const BigInt&);
//
//	//Multiplication and Division
//	BigInt& operator*=(const BigInt&);
//	friend BigInt operator*(BigInt, const BigInt&);
//	BigInt& operator/=(const BigInt&);
//	friend BigInt operator/(BigInt, const BigInt&);
//
//	//Modulo
//	BigInt& operator%=(const BigInt&);
//	friend BigInt operator%(BigInt, const BigInt&);
//
//	//Power Function
//	BigInt& operator^=(const BigInt&);
//	friend BigInt operator^(BigInt, const BigInt&);
//
//	string toString() const { return digits; }
//
//private:
//	string digits;
//
//};
//
//
