// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <regex>
#include <algorithm>
#include <iostream>

using namespace std;


string CleanupString(const string& iStr) {
	//regex re("^[a-Z]");
	string retStr(iStr);
	retStr.erase(
		remove_if(
			retStr.begin(),
			retStr.end(),
			[](char c) {return !(isalpha(c) || isblank(c) || c == ','); }
			),
		retStr.end()
		);

	return retStr;
}

string CleanCompactString(const string& iStr) {
	//regex re("^[a-Z]");
	string retStr(iStr);
	retStr.erase(
		remove_if(
			retStr.begin(),
			retStr.end(),
			[](char c) {return !isalpha(c); }
			),
		retStr.end()
		);

	transform(retStr.begin(), retStr.end(), retStr.begin(), ::tolower);
	return retStr;
}

void TryString() {

	string str("the %%$quick, QUICK **brown fo???x &&jumped over+___= the moon???");
	CleanupString(str);
	cout << str;
}

bool IsPalindromic(const string& iStr) {

	string str = CleanCompactString(iStr);
	for (int ii = 0, jj = str.size() - 1; ii < jj; ii++, jj--) {
		if (str[ii] != str[jj])
			return false;
	}

	return true;
}

int main()
{
	bool flag = IsPalindromic("Sore was I ere I saw Eros.");
	bool flag1 = IsPalindromic("\"Stop!\" nine myriad murmur. \"Put up rum, rum, dairymen, in pots.\"");

	IsPalindromic("");
	IsPalindromic("abba");
	IsPalindromic("baba");
	IsPalindromic("baby");
	IsPalindromic("-1");

	TryString();

    return 0;
}

