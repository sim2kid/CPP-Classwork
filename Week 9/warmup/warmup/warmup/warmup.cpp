// warmup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solutions {
public:
	static string lcp(vector<string>& strs) {
		string ans = "";
		ans = strs[0];
		while (!(ans.compare("") == 0)) {
			bool failed = false;
			for (string i : strs) {
				if (!(i.substr(0,ans.length()).compare((string) ans) == 0)) {
					failed = true;
					break;
				}
			}
			if (!failed) {
				break;
			}
			else {
				ans = ans.substr(0, ans.length() - 1);
			}
		}
		return ans;
	}
};

int main()
{
	vector<string> s;
	s.push_back("flower");
	s.push_back("flow");
	s.push_back("flight");
	std::cout << "Should be 'fl' ans ['" << Solutions::lcp(s) << "']." << std::endl;

	vector<string> p;

	p.push_back("kevin");
	p.push_back("kevvivivinnnn");
	p.push_back("kev the k man!");

	std::cout << "Should be 'kev' ans ['" << Solutions::lcp(p) << "']." << std::endl;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
