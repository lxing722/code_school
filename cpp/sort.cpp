#include<iostream>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
struct Node {
	double x, y;
};
bool cmp(Node a, Node b) {
	return (a.x*a.x + a.y*a.y) < (b.x*b.x + b.y*b.y);
}
int main() {
	Node n1, n2, n3;
	n1.x = 1, n1.y = 2;
	n2.x = 2, n2.y = 2;
	n3.x = 2, n3.y = 3;
	vector<Node> v;
	v.push_back(n1);
	v.push_back(n3);
	v.push_back(n2);
	for (vector<Node>::iterator itr = v.begin(); itr != v.end(); itr++)
		cout << (*itr).x << " " << (*itr).y << endl;
	std::sort(v.begin(), v.end(), cmp);
	for (vector<Node>::iterator itr = v.begin(); itr != v.end(); itr++)
		cout << (*itr).x<< " " << (*itr).y << endl;
	return 0;
}