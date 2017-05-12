#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
bool cmp(string str1, string str2) {
	for (int i = 0;i<str1.size();i++) {
		str1[i] = std::tolower(str1[i]);
	}
	for (int i = 0; i<str2.size(); i++) {
		str2[i] = std::tolower(str2[i]);
	}
	return str1 < str2;
}
int main() {
	vector<string> test;
	test.push_back("hello");
	test.push_back("my");
	test.push_back("Darling");
	std::sort(test.begin(), test.end(), cmp);
	for (auto iter = test.begin(); iter != test.end(); ++iter)
		cout << *iter << endl;
	return 0;
}
