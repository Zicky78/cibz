#pragma once
#include <iostream>

using namespace std;

class FooBar {
	public:
		FooBar() { data = 1; }
		~FooBar() { cout << "Goodbye." << endl; }
		bool data;

};