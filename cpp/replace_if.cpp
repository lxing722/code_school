#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;
using std::cout;
using std::cout;
using std::endl;
bool isEven(int a) {
	return a % 2 == 0;
}
template<class T,class U,class P>
void my_replace_if(T begin, T end, U pred, P b) {
	while (begin != end) {
		if (pred(*begin))
			*begin = b;
		begin++;
	}
};
int main() {
	vector<int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);
	my_replace_if(v.begin(), v.end(), isEven, 3);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}