// FindStringPermutations_Office.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "iostream"
#include "vector"
using namespace std;


void FindPermutations(const string& iStr, vector<string>& oStrings)
{
	if (iStr.length() == 1)
	{
		return;
	}
	
	//chop the last char
	string str(iStr);
	char c = str[str.length() - 1];
	str.pop_back();

	for (unsigned jj = 0; jj < oStrings.size(); jj++)
		FindPermutations(oStrings[jj], oStrings);


	//Insert in all locations
	for (int ii = 0; ii <= str.length(); ii++)
	{
		string newStr(str);
		newStr.insert(ii, 1, c);
		//Recurse
		oStrings.push_back(newStr);
	}


}

int main()
{
	string str("abcd");
	vector<string> permuts;
	FindPermutations(str, permuts);

	for each (string st in permuts)
	{
		cout << st << ", ";
	}

	return 0;
}

