#include"json.h"
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
		if (i + 1 != vec.size())  //确认是不是数组最后一个值，以确定加不加逗号
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
Value::Value() {}
Value::Value(string v) : v_string(v), type(STRING) {}
Value::Value(char *v) : v_string(v), type(STRING) {}
Value::Value(double v) : v_double(v), type(DOUBLE) {}
Value::Value(int v) : v_int(v), type(INT) {}
Value::Value(JSONObject v) : v_object(v), type(OBJECT) {}
Value::Value(Array v) : v_array(v), type(ARRAY) {}
Value::Value(bool v) : v_bool(v), type(BOOL) {}
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
//JSONObject 实现
JSONObject::JSONObject() {}
Value & JSONObject::operator[](const string & key) {
	return obj[key];
}
string JSONObject::to_json() {
	string str = "{";
	for (auto iter = obj.rbegin(); iter != obj.rend(); ++iter) {
		str += "\"" + iter->first + "\"" + ":" + iter->second.to_json();
		if (++iter != obj.rend())  //确认是不是json最后一个值，以确认加不加逗号
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
//函数实现
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
string read_string(const string & str, int & p) {
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
Value read_number(const string & str, int & p) {
	string num;  //用来提取数字部位
	bool point = false;  //设定一个bool值point，如果point为真，则表示数字有小数点，数值为double，否则为int
	if (str[p] == '-') {
		num += '-';
		read_char(str, p, '-');
	}
	while (true) {
		if (isdigit(str[p]) || (str[p] == '.' && !point)) {
			if (str[p] == '.')   //有小数点，point设置成真
				point = true;
			num += str[p];
			read_char(str, p, str[p]);
		}
		else
			break;
	}
	if (point) {
		double num_d = std::stod(num); //将字符串转化为double
		return Value(num_d);
	}
	else {
		int num_i = std::stoi(num);  //将字符串转化成int
		return Value(num_i);
	}
}
void read_char(const string & str, int & p, const char & ch) {
	p++;
}