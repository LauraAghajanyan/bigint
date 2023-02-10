#include <iostream>
#include <string>
#include <vector>
#include "bigint.h"
using namespace std;


int main() {
	//  10
	//0044
	//5555
	// 
	//ctors work++ 4228
	string s1 = "22";
	string s2 = "4";
	BigInt first(s1);
	BigInt second(12345);
	BigInt third(s2);
	BigInt fourth(second);
	
	// first = 54321, second = 54321 ,third = erkar tvi hakarakin, fourth = 54321
	//third = first; //this one works too ++

	//++
	//cout << first;
	/*cout << endl;
	cout << second;
	cout << endl;
	cout << third;
	cout << endl;
	cout << fourth;
	cout << endl;
	cout << (first == second);
	cout << endl;
	cout << (first == fourth);
	cout << endl;
	cout << (fourth == second);
	cout << endl;
	cout << (first == third);
	cout << endl;
	cout << (first != second);*/

	//works fine
	/*cout << (third > second);
	cout << (third > first);
	cout << (fourth > first);*/

	//works fineee
	/*cout << (first < second);
	cout << (first < third);
	cout << (second < fourth);*/

	//yaaay works
	/*cout << (first <= second);
	cout << (second >= fourth);
	cout << (second >= third);*/
	cout << endl;
	//cout << (++first);
	//cout << (++second);
	//cout << (first++);
	
	//cout << first;

	//cout << (--first);
	first ^= third;
	cout << first;

	cout << endl;
	return 0;
}