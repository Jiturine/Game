#pragma once

using namespace std;
class Debug {
public:
	template<class T, class... Args>
	static void Log(const T& log_str, Args&&... args) {
		Print(Format::Fmt(log_str, forward<Args>(args)...));
	}
	static void Log(const string& log_str) {
		Print(log_str);
	}
	static void Print(const string& str) {
		cout << str << endl;
	}
};