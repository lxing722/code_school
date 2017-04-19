#pragma once
#ifndef JSON_H
#define JSON_H
#include<map>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::map;
using std::pair;
//ValueType 定义
enum ValueType {
	STRING,
	DOUBLE,
	BOOL,
	INT,
	OBJECT,
	ARRAY
};
//Array 定义
class Value;
class Array {
	vector<Value> vec;
	typedef vector<Value>::iterator iterator;
public:
	Array();
	Value & operator[](int index);
	void push_back(const Value &val);
	string to_json();
	int size();
	iterator begin();
	iterator end();
	bool empty();
	void clear();
};
//JsonObject 定义
class JSONObject {
	map<string, Value> obj;	
public:
	typedef map<string, Value>::iterator iterator;
	JSONObject();
	Value & operator[](const string & key);
	string to_json();
	iterator find(const string & key);
	void insert(pair<string, Value> p);
	void erase(iterator pos);
	iterator begin();
	iterator end();
	int size();
	void clear();
	bool empty();
};
//Value 定义
class Value {
	string v_string;
	double v_double;
	bool v_bool;
	int v_int;
	JSONObject v_object;
	Array v_array;
	ValueType type;
public:
	Value();
	Value(string v);
	Value(char *v);
	Value(double v);
	Value(int v);
	Value(JSONObject v);
	Value(Array v);
	Value(bool v);
	Value & operator[](const string & str);
	Value & operator[](int index);
	Value & operator=(const string & v);
	Value & operator=(char *v);
	Value & operator=(const double & v);
	Value & operator=(const int & v);
	Value & operator=(const bool & v);
	Value & operator=(const Array &v);
	Value & operator=(const JSONObject &v);
	string to_string();
	double to_double();
	int to_int();
	bool to_bool();
	string to_json();
	ValueType get_type();
	void push_back(Value val);
};
//函数定义
JSONObject read_object(const string & str, int & p);
Value read_value(const string & str, int & p);
Array read_array(const string & str, int & p);
string read_string(const string & str, int & p);
bool read_bool(const string & str, int & p);
Value read_number(const string & str, int & p);
void read_char(const string & str, int & p, const char & ch);
#endif // !1
