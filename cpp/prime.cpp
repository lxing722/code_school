#include<iostream>
#include<type_traits>
using std::cin;
using std::cout;
using std::endl;
bool is_prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}
template<int N> 
void prime() {
	if (is_prime(N))
		cout << N << " " << endl;
	prime<N - 1>();
};
template<>
void prime<1>() {
	return ;
};
template <int N>
int factorial() {
	return N*factorial<N - 1>();
};
template <>
int factorial<0>() {
	return 1;
};
template<int M,int N>
class matrix {	
public:
	int	value[M][N];
	void give_value() {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++)
				cin >> value[i][j];
		}
	}
	void print_value() {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << value[i][j] << " ";
			}
			cout << endl;
		}
	}
	template<int R>
	matrix<M, R> multiplication(matrix<N, R> other) {
		matrix<M, R> temp;
		int sum;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < R; j++) {
				sum = 0;
				for (int k = 0; k < N; k++) {
					sum += value[i][k] * other.value[k][j];

				}
				temp.value[i][j] = sum;
			}
		}
		return temp;
	}
};
int main() {
	//prime<100>();
	//cout << factorial<10>() << endl;
	matrix<3, 3> test1;
	matrix<3, 2> test2;
	matrix<3, 2> test3;
	test1.give_value();
	test2.give_value();
	test3 = test1.multiplication(test2);
	test3.print_value();
	return 0;
}