#pragma once

using namespace std;

template<class T>
class List {
public:
	class Node {
	public:
		T data;
		Node* next;
		Node(T data, Node* next) :data(data), next(next) {}
		Node(Node* next) : data(NULL), next(next) {}
		Node(T data) : data(data), next(nullptr) {}
		Node() : data(NULL), next(nullptr) {}
		operator string() {
			return Format::ToString(data);
		}
	};
	Node* head;
	Node* tail;
	int size;
	List() {
		head = new Node();
		tail = head;
		size = 0;
	}
	~List() {
		Node* p;
		while (head->next != nullptr)
		{
			p = head->next;
			head->next = p->next;
			delete p;
		}
		delete head;
	}
	template<class... Args>
	List(const T& data, Args&&... args) {
		head = new Node();
		tail = head;
		size = 0;
		Add(data, args...);
	}
	template<class... Args>
	void Add(const T& data, Args&&... args) {
		Node* p = new Node(data);
		tail->next = p;
		tail = p;
		size++;
		Add(args...);
	}
	template<class... Args>
	void Insert(T data, int index, Args&&... args) {
		if (index > size) {
			Debug::Log("Failed To Insert.");
			return;
		}
		Node* p = head;
		for (int i = 1; i <= index; i++) {
			p = p->next;
		}
		Node* q = new Node(data, p->next);
		p->next = q;
		if (p == tail) {
			tail = q;
		}
		size++;
	}
	void Delete(int index) {
		if (index > size) {
			Debug::Log("Failed To Delete.");
			return;
		}
		Node* p = head;
		for (int i = 1; i < index; i++) {
			p = p->next;
		}
		Node* q = p->next;
		p->next = q->next;
		delete q;
		size--;
	}
	void Delete(T data) {
		Node* p = head;
		bool find = false;
		while (p->next != nullptr) {
			if (p->next->data == data) {
				find = true;
				break;
			}
			p = p->next;
		}
		if (!find) {
			Debug::Log("Failed To Delete.");
			return;
		}
		Node* q = p->next;
		p->next = q->next;
		delete q;
		size--;
		return;
	}
	static List<T>* Create() {
		List<T>* p = new List<T>();
		return p;
	}
	operator string() {
		string res = "";
		for (Node* p = head->next; p != nullptr; p = p->next) {
			res += Format::ToString(p->data);
			res += " ";
		}
		return res;
	}
private:
	void Add(void) {
		return;
	}
};
