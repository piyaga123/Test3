// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int Sun3and5(int maxIn) {
	int sum = 0;
	for (int i = 1; i < maxIn; i++)
	{
		if (!(i % 3) || !(i % 5))
			sum += i;
	}

	return sum;
}

int main()
{
	int s = Sun3and5(1000);

    return 0;
}

