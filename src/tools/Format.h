#pragma once
#include <regex>
#include <sstream>
using namespace std;

class Format {
public:
	template<class T, class S, class... Args>
	static string Fmt(const T& format_str, const S& str, Args&&... args);
	template<class T>
	static string Fmt(const T& format_str);
	static string ToString(int value);
	static string ToString(float value);
	static string ToString(double value);
	static string ToString(long long value);
	template<class T>
	static string ToString(T value);
	template<class T>
	static string ToString(T* value);
private:
	static regex brace_regex;
};
