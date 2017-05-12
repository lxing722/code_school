#include<iostream>
#include<string>
#include"json.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
int main() {
	//write JSONObject
	JSONObject obj;
	obj["title"] = "Thinking in c++";
	obj["price"] = 116.0; 
	obj["pages"] = 927;
	obj["authors"] = Array();
	obj["authors"].push_back(Value("Bruce Eckel")); 
	obj["authors"].push_back(Value("Chuck Allison"));
	obj["pub_info"] = JSONObject();
	obj["pub_info"]["name"] = Value("China Machine Press"); 
	//test begin end
	cout << "test begin and end" << endl;
	for (auto iter = obj.begin(); iter != obj.end(); iter++)
		cout << iter->first << ":" << iter->second.to_json() << endl;
	//find
	cout << "\ntest find: find price" << endl;
	JSONObject::iterator iter1 = obj.find("price");
	cout << iter1->first << ": " << iter1->second.to_json() << endl;
	//insert
	cout << "\ntest insert: insert sold:true" << endl;
	pair<string, Value> p = pair<string,Value>("sold", Value(true));
	obj.insert(p);
	cout << obj.to_json() << endl;
	//erase
	cout << "\ntest erase: erase sold:true" << endl;
	JSONObject::iterator iter3 = obj.find("sold");
	obj.erase(iter3);
	cout << obj.to_json() << endl;
	//size
	cout << "\ntest size" << endl;
	cout << "The size of obj is " << obj.size() << endl;
	//json parser
	cout << "\ntest json parser" << endl;
	int i = 0;
	JSONObject test1 = read_object(obj.to_json(), i);
	cout << test1.to_json() << endl;
	//clear
	cout << "\ntest clear" << endl;
	obj.clear();
	cout << obj.to_json() << endl;
	//empty
	cout << "\ntest empty" << endl;
	if (obj.empty())
		cout << "The json object is empty!" << endl;
	return 0;
}