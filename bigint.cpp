#include <iostream>
#include <string>
#include <vector>
#include "bigint.h"
using namespace std;

void reverse(string& s)
{
	int n = s.length();

	for (int i = 0; i < n / 2; i++)
		swap(s[i], s[n - i - 1]);
}


BigInt::BigInt(string& s) {
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] < '0' || s[i] > '9') {
			cout << "Invalid string!" << endl;
			return;
		}
	}
	reverse(s);
	digits = s;
	cout << "Checking 1" << endl;
}

BigInt::BigInt(unsigned long long n = 0) {
	while (n != 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < digits.size(); ++i) {
		digits[i] = digits[i] + '0';
	}
	cout << "Checking 2" << endl;
}

BigInt::BigInt(BigInt& other) {
	digits = other.digits;
	cout << "Checking 3" << endl;
}

//need to check 
BigInt& BigInt::operator=(const BigInt& other) {
	// Guard self assignment
	if (this == &other)
	{
		return *this;
	}
	string nstr = "";
	for (int i = 0; i < other.digits.size(); ++i) {
		nstr.push_back(other.digits[i]);
	}
	digits = nstr;
	cout << "Move assignment" << endl;
	return *this;
}

bool operator==(const BigInt& first, const BigInt& second) {
	return first.digits == second.digits;
}

bool operator!=(const BigInt& first, const BigInt& second) {
	return first.digits != second.digits;
}


ostream& operator<<(ostream& out, const BigInt& a) {
	int n = a.digits.size();
	for (int i = n -1; i >= 0; i--)
		cout << a.digits[i];
	return cout;
}

bool operator>(const BigInt& first, const BigInt& second) {
	int fl = first.digits.size();
	int sl = second.digits.size();
	if (fl > sl) {
		return true;
	}
	if (fl < sl) {
		return false;
	}
	if (fl == sl) {
		for (int i = sl - 1; i >= 0; --i) {
			return first.digits[i] > second.digits[i];
		}
	}
}

bool operator<(const BigInt& first, const BigInt& second) {
	int fl = first.digits.size();
	int sl = second.digits.size();
	if (fl < sl) {
		return true;
	}
	if (fl > sl) {
		return false;
	}
	if (fl == sl) {
		for (int i = sl - 1; i >= 0; --i) {
			return first.digits[i] < second.digits[i];
		}
	}
}

bool operator>=(const BigInt& first, const BigInt& second)
{
	return !(first < second);
}

bool operator<=(const BigInt& first, const BigInt& second)
{
	return !(first > second);
}

BigInt& BigInt::operator++()
{
	int n = digits.size();
	if (digits[0] == '9') {
		digits[0] = '0';
		for (int i = 1; i < n; ++i) {
			if (digits[i] != '9') {
				digits[i]++;
				break;
			}
			else {
				digits[i] = '0';
			}
		}

	}
	else {
		digits[0]++;
	}
	bool temp = true;
	for (int i = 0; i < n; ++i) {
		if (digits[i] != '0') {
			temp = false;
			break;
		}
	}
	if (temp) {
		digits.push_back('1');
	}
	return *this;
}

BigInt BigInt::operator++(int /* tmp */)
{
	BigInt old = *this;
	operator++(); // prefix increment
	return old;
}

BigInt& BigInt::operator--() {
	int n = digits.size();
	if (digits[0] == 0 && n == 1)
	{
		cout << "Underflow" << endl;
	}
	if (digits[0] == '0') {
		digits[0] = '9';
		for (int i = 1; i < n; ++i) {
			if (digits[i] != '0') {
				digits[i]--;
				break;
			}
			else {
				digits[i] = '9';
			}
		}

	}
	else {
		digits[0]--;
	}
	if (digits[n - 1] == '0') {
		digits.pop_back();
	}
	return *this;
}

BigInt BigInt::operator--(int /* tmp */)
{
	BigInt old = *this;
	operator--(); // prefix decrement
	return old;
}

BigInt& BigInt::operator+=(const BigInt& rhs)
{
	int n = digits.size();
	int m = rhs.digits.size();
	int carry = 0;

	if (n >= m) {
		for (int i = 0; i < m; ++i) {
			if ((rhs.digits[i] + digits[i] - '0' + carry) > '9') {
				digits[i] = digits[i] + rhs.digits[i] + carry - '0' - 10;
				carry = 1;
			}
			else {
				digits[i] = digits[i] + rhs.digits[i] + carry - '0';
				carry = 0;
			}
		}
		for (int i = m; i < n; i++)
		{
			if ((digits[i]  + carry) > '9') {
				digits[i] = digits[i]  + carry  - 10;
				carry = 1;
			}
			else {
				digits[i] = digits[i]  + carry ;
				carry = 0;
			}
		}
		if (carry == 1) 
		{
			digits.push_back('1');
		}
	}
	else {
		for (int i = 1; i <= (m - n); ++i) {
			digits.push_back('0');
		}

		for (int i = 0; i < n; ++i) {
			if ((rhs.digits[i] + digits[i] - '0' + carry) > '9') {
				digits[i] = digits[i] + rhs.digits[i] + carry - '0' - 10;
				carry = 1;
			}
			else {
				digits[i] = digits[i] + rhs.digits[i] + carry - '0';
				carry = 0;
			}
		}
		for (int i = n; i < m; i++)
		{
			if ((rhs.digits[i] + carry) > '9') {
				digits.push_back( rhs.digits[i] + carry - 10);
				carry = 1;
			}
			else {
				digits[i] = rhs.digits[i] + carry;
				carry = 0;
			}
		}
		if (carry == 0)
		{
			digits.push_back('1');
		}
	}
	return *this;
}

BigInt operator+(BigInt lhs, const BigInt& rhs)
{
	lhs += rhs;
	return lhs;
}


BigInt& BigInt::operator-=(const BigInt& rhs)
{
	int n = digits.size();
	int m = rhs.digits.size();
	int carry = 0;
	int index = 0;
	if (digits == rhs.digits) {
		digits = "0";
	}
	else {
		if (n >= m) {
			for (int i = 0; i < m; ++i) {
				if ((digits[i] - rhs.digits[i] + '0' - carry) < '0') {
					digits[i] = digits[i] - (rhs.digits[i] - '0') - carry + 10;
					carry = 1;
				}
				else {
					digits[i] = digits[i] - (rhs.digits[i] - '0') - carry;
					carry = 0;
				}
			}
			for (int i = m; i < n; i++)
			{
				if ((digits[i] - carry) < '0') {
					digits[i] = digits[i] - carry + 10;
					carry = 1;
				}
				else {
					digits[i] = digits[i] - carry;
					carry = 0;
				}
			}
		}
		else {
			cout << "Voch mi ban mi ara" << endl;
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == '0')
		{
			digits[i] = '\0';
		}
		else {
			break;
		}
	}
	return *this;
}

BigInt operator-(BigInt lhs, const BigInt& rhs)
{
	lhs -= rhs;
	return lhs;
}

BigInt& BigInt::operator*=(const BigInt& rhs) {
	int n = digits.size(), m = rhs.digits.size();
	int carry = 0;
	int sum = 0;
	vector<int> v(n + m, 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			v[i + j] += (digits[j] - '0') * (rhs.digits[i] - '0');
		}
	}
	int vs = v.size();
	int car = 0;
	for (int i = 0; i < v.size(); ++i) {
		v[i] += car;
		car = v[i] / 10;
		v[i] = v[i] % 10;
	}
	digits = "";
	if (v[vs-1] == 0) 
	{
		for (int i = 0; i < vs - 1; ++i) 
		{
			digits.push_back(v[i] + '0');
		}
	}
	else 
	{
		for (int i = 0; i < vs; ++i) 
		{
			digits.push_back(v[i] + '0');
		}
	}
	return *this;
}

BigInt operator*(BigInt lhs, const BigInt& rhs)
{
	lhs *= rhs;
	return lhs;
}

BigInt& BigInt::operator^=(BigInt& exp) {
	BigInt a(1);
	BigInt d(digits);
	if (exp == '0') {
		digits = "1";
	}
	else {
		while (exp != 0) {
			a *= d;
			exp--;
		}
	}
	digits = a.digits;
	return *this;
}

BigInt operator^(BigInt lhs,BigInt& rhs)
{
	lhs ^= rhs;
	return lhs;
}













