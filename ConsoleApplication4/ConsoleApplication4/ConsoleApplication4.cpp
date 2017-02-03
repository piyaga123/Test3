// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int findSL(vector<int>& A) {

	int max =  numeric_limits<int>::min();
	int max2 = max;

	for (int ii : A) {
		if (ii > max) {
			max2 = max;
			max = ii;
		}
		else if (ii > max2) {
			max2 = ii;
		}
	}

	return max2;
}

int main()
{
	vector<int> t1 = { 3,2,7,9,11,13,12,8,6 };
	int x = findSL(t1);
	cout << x;
	return 0;
}

