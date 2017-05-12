#include<iostream>
#include<map>
#include<string>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
struct location {
	float lon;
	float lat;
};
float compute(map<string, location> cities, string city1, string city2) {
	return 6371 * acos(sin(cities[city1].lat)*sin(cities[city2].lat) + cos(cities[city1].lat)*cos(cities[city2].lat)*cos(cities[city1].lon - cities[city2].lon));
}
int main() {
	map<string, location> cities;
	cities["Beijing"] = location{ 116,40 };
	cities["London"].lon = -0.5, cities["London"].lat = 51.5;
	cities["Sydney"].lon = 151, cities["Sydney"].lat = -34;
	cities["Chicago"].lon = -87.6, cities["Chicago"].lat = 41.8;
	cout << compute(cities,"Beijing","London") << endl;
	return 0;
}