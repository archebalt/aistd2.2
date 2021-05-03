#include <iostream>
#include"Huffman.h"
#include <string>
#include <iomanip>
using namespace std;



int main()
{
	
	string str;
	getline(cin, str);
	huffman a(str);
	cout << endl;
	int before = str.size() * 8;
	string Coded = a.res();
	int after = Coded.size();
	cout << Coded;
	cout << endl;
	string deCoded = a.deCode();
	cout << deCoded << endl;
	cout << "source text in bits: " << before;
	cout << endl;
	cout << "new text in bits: " << after;
	cout << endl;
	float coef = (before*1000.0) / (after * 1000);
	cout << "coefficient: " << coef;
	cout << endl;
	return 0;
}