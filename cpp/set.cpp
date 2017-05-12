#include<iostream>
#include<set>
int main() {
	int n, num;
	std::set<int> test;
	std::multiset<int> test2;
	std::cin >> n;
	for (int i = 0; i < n;i++) {
		std::cin >> num;
		test.insert(num);
		test2.insert(num);
	}
	for (auto itr = test.begin(); itr != test.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
	for (auto itr = test2.begin(); itr != test2.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
	return 0;
}