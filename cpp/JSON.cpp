#include<iostream>
#include<map>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
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
//Object 定义
class JSONObject {
	map<string, Value> obj;
	typedef map<string, Value>::iterator iterator;
public:
	JSONObject();
	Value & operator[](const string & key);
	string to_json();
	iterator find(const string & key);
	void insert(pair<string,Value> p);
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
//Array 实现
Array::Array() {}
Value & Array::operator[](int index) {
	return vec[index];
}
void Array::push_back(const Value &val) {
	vec.push_back(val);
}
string Array::to_json() {
	string str = "[";
	for (int i = 0; i < vec.size(); i++) {
		str += vec[i].to_json();		
		if (i + 1 != vec.size())
			str += ",";
	}
	str += "]";
	return str;
}
int Array::size() {
	return vec.size();
}
Array::iterator Array::begin() {
	return vec.begin();
}
Array::iterator Array::end() {
	return vec.end();
}
bool Array::empty() {
	return vec.empty();
}
void Array::clear() {
	vec.clear();
}
//Value 实现
Value::Value(){}
Value::Value(string v): v_string(v), type(STRING) {}
Value::Value(char *v): v_string(v), type(STRING) {}
Value::Value(double v): v_double(v), type(DOUBLE) {}
Value::Value(int v): v_int(v), type(INT) {}
Value::Value(JSONObject v): v_object(v), type(OBJECT) {}
Value::Value(Array v): v_array(v), type(ARRAY) {}
Value::Value(bool v): v_bool(v), type(BOOL) {}
Value & Value::operator[](const string & str) {
	return v_object[str];
}
Value & Value::operator[](int index) {
	return v_array[index];
}
Value & Value::operator=(const string & v) {
	*this = Value(v);
	return *this;
}
Value & Value::operator=(char *v) {
	*this = Value(v);
	return *this;
}
Value & Value::operator=(const double & v) {
	*this = Value(v);
	return *this;
}
Value & Value::operator=(const int & v) {
	*this = Value(v);
	return *this;
}
Value & Value::operator=(const bool & v) {
	*this = Value(v);
	return *this;
}
Value & Value::operator=(const Array &v) {
	*this = Value(v);
	return *this;
}
Value & Value::operator=(const JSONObject &v) {
	*this = Value(v);
	return *this;
}
string Value::to_string() {
	return v_string;
}
double Value::to_double() {
	return v_double;
}
int Value::to_int() {
	return v_int;
}
bool Value::to_bool() {
	return v_bool;
}
string Value::to_json() {
	string str;
	switch (type) {
	case STRING:
		str = "\"" + v_string + "\"";
		break;
	case DOUBLE:
		str = std::to_string(v_double);
		break;
	case INT:
		str = std::to_string(v_int);
		break;
	case BOOL:
		str = v_bool ? "true" : "false";
		break;
	case ARRAY:
		str = v_array.to_json();
		break;
	case OBJECT:
		str = v_object.to_json();
		break;
	}
	return str;
}
ValueType Value::get_type() {
	return type;
}
void Value::push_back(Value val) {
	v_array.push_back(val);
}
//Object 实现
JSONObject::JSONObject(){}
Value & JSONObject::operator[](const string & key) {
	return obj[key];
}
string JSONObject::to_json() {
	string str = "{";
	for (auto iter = obj.rbegin(); iter != obj.rend(); ++iter) {
		str += "\"" + iter->first + "\"" + ":"  + iter->second.to_json();
		if (++iter != obj.rend())
			str += ",";
		--iter;
	}
	str += "}";
	return str;
}
JSONObject::iterator JSONObject::find(const string & key) {
	return obj.find(key);
}
void JSONObject::insert(pair<string, Value> p) {
	obj.insert(p);
}
void JSONObject::erase(JSONObject::iterator pos) {
	obj.erase(pos);
}
JSONObject::iterator JSONObject::begin() {
	return obj.begin();
}
JSONObject::iterator JSONObject::end() {
	return obj.end();
}
int JSONObject::size() {
	return obj.size();
}
void JSONObject::clear() {
	obj.clear();
}
bool JSONObject::empty() {
	return obj.empty();
}

JSONObject read_object(const string & str, int & p);
Value read_value(const string & str, int & p);
Array read_array(const string & str, int & p);
string read_string(const string & str, int & p);
bool read_bool(const string & str, int & p);
Value read_number(const string & str, int & p);
void read_char(const string & str, int & p, const char & ch);

int main() {
	JSONObject obj;
	obj["title"] = "Thinking in c++";
	obj["price"] = 116.0; //识别成double
	obj["pages"] = 927;
	obj["authors"] = Array();
	obj["authors"].push_back(Value("Bruce Eckel")); //识别成value，无法push_back, 在Value里再定义一个push_back
	obj["authors"].push_back(Value("Chuck Allison"));
	obj["pub_info"] = JSONObject();
	obj["pub_info"]["name"] = Value("China Machine Press"); //["name"]无法实现, 需在Value里对[]进行重载	
	int i = 0;
	JSONObject test1 = read_object(obj.to_json(),i);
	cout << test1.to_json() << endl;
	//obj.clear();
	cout << obj.to_json() << endl;
	return 0;
}
JSONObject read_object(const string & str, int & p) {
	JSONObject obj;
	read_char(str, p, '{');
	while (true) {
		string key = read_string(str, p);
		read_char(str, p, ',');
		Value val = read_value(str, p);
		obj[key] = val;
		if (str[p] == '}') {
			read_char(str, p, '}');
			break;
		}
		else {
			read_char(str, p, ',');
		}
	}
	return obj;
}
Value read_value(const string & str, int & p) {
	Value val;
	if (str[p] == '{') {
		val = Value(read_object(str, p));
	}
	else if (str[p] == '\"') {
		val = Value(read_string(str, p));
	}
	else if (str[p] == '[') {
		val = Value(read_array(str, p));
	}
	else if (str[p] == 't' || str[p] == 'f') {
		val = Value(read_bool(str, p));
	}
	else if (str[p] == '-' || isdigit(str[p])) {
		val = read_number(str, p);
	}
	return val;
}
Array read_array(const string & str, int & p) {
	Array arr;
	read_char(str, p, '[');
	while (true) {
		Value val = read_value(str, p);
		arr.push_back(val);
		if (str[p] == ']') {
			read_char(str, p, ']');
			break;
		}
		else {
			read_char(str, p, ',');
		}
	}
	return arr;
}
string read_string(const string & str, int & p) { //如何读入换行符等符号
	string s;
	read_char(str, p, '"');
	while (true) {
		if (str[p] == '"') {
			read_char(str, p, '"');
			break;
		}
		else {
			s += str[p];
			read_char(str, p, str[p]);
		}
	}
	return s;
}
bool read_bool(const string & str, int & p) {
	bool b;
	if (str[p] == 't') {
		b = true;
	}
	else
		b = false;
	while (str[p] != 'e')
		read_char(str, p, str[p]);
	read_char(str, p, 'e');
	return b;
}
Value read_number(const string & str, int & p) { //是否需要考虑其他进制表示法
	string num;
	bool point = false;
	if (str[p] == '-') {
		num += '-';
		read_char(str, p, '-');
	}
	while (true) {
		if (isdigit(str[p]) || (str[p] == '.' && !point)) {
			if (str[p] == '.')
				point = true;
			num += str[p];
			read_char(str, p, str[p]);
		}
		else
			break;
	}
	if (point) {
		double num_d = std::stod(num);
		return Value(num_d);
	}
	else {
		int num_i = std::stoi(num);
		return Value(num_i);
	}
}
void read_char(const string & str, int & p, const char & ch) {
	p++;
}