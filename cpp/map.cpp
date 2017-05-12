#include<iostream>
#include<string>
#include<map>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string word;
	std::map<string, int> test;
	while (cin >> word) {
		if (word == "#")
			break;
		++test[word];		
	}
	for (auto iter = test.begin(); iter != test.end(); iter++)
		cout << iter->first << ":" << iter->second << endl;
	return 0;
}