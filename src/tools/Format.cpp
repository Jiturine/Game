#include "Format.h"
using namespace std;

regex Format::brace_regex("\\{([^}])*\\}");

string Format::ToString(int value) {
	return to_string(value);
}
string Format::ToString(float value) {
	ostringstream oss;
	oss << value;
	return oss.str();
}
string Format::ToString(double value) {
	ostringstream oss;
	oss << value;
	return oss.str();
}
string Format::ToString(long long value) {
	return to_string(value);
}
template<class T>
string Format::ToString(T value) {
	return string(value);
}
template<class T>
string Format::ToString(T* value) {
	return string(*value);
}
template<class T, class S, class... Args>
string Format::Fmt(const T& format_str, const S& str, Args&&... args) {
	string fmt_s(format_str);
	string s = ToString(str);
	smatch res;
	regex_search(fmt_s, res, brace_regex);
	fmt_s.replace(res[0].first, res[0].second, s);
	/*string res = regex_replace(fmt_s, brace_regex, s, regex_constants::format_first_only);*/
	return Fmt(fmt_s, args...);
}
template<class T>
string Format::Fmt(const T& format_str) {
	string fmt_s(format_str);
	return fmt_s;
}
