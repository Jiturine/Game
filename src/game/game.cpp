#include "game.h"

using namespace std;

int main() {
	List<float>* list = new List<float>(1.5f, 2.5f, 3.5f, 4.6f, 5.7f);
	Debug::Log("{}", list);
	list->Insert(10.2f, 3);
	Debug::Log("{}", list);
	return 0;
}
