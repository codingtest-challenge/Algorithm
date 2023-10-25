#include<iostream>

using namespace std;

const int Max_size = 10000;

class Deque {
private:
	int first = 0, last = 0;
	int arr[Max_size] = { 0, };
public:
	Deque() {}
	Deque(const Deque& Q) {}
	~Deque() {}
	void PushFront(int input) {
		if (first > 0 && first != last) {
			arr[--first] = input;
		}
		else if (first == 0) {
			first = 9999;
			arr[first] = input;
		}
	}
	void PushBack(int input) {
		if (last < 9999 && first != last + 1) {
			arr[last++] = input;
		}
		else if (last == 9999 && first != 0) {
			last = 0;
			arr[9999] = input;
		}
	}
	int PopFront() {
		if (first == last) return -1;
		else if (first < 9999 && first != last) {
			return arr[first++];
		}
		else if (first == 9999) {
			first = 0;
			return arr[9999];
		}
	}
	int PopBack() {
		if (first == last) return -1;
		else if (last > 0 && first != last) {
			return arr[--last];
		}
		else if (last == 0) {
			last = 9999;
			return arr[last];
		}
	}
	int Size() {
		if (first < last) {
			return last - first;
		}
		else if (first > last) {
			return 10000 - first + last;
		}
		return 0;
	}
	bool isEmpty() {
		if (last - first != 0) {
			return false;
		}
		else return true;
	}
	int Front() {
		if (last - first == 0) return -1;
		else return arr[first];
	}
	int Back() {
		if (last - first == 0) return -1;
		else if (last == 0) return arr[9999];
		else return arr[last - 1];
	}
};

int main()
{
	int n, k;
	string s;
	Deque d;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_front") {
			cin >> k;
			d.PushFront(k);
		}
		else if (s == "push_back") {
			cin >> k;
			d.PushBack(k);
		}
		if (s == "pop_front") {
			cout << d.PopFront() << endl;
		}
		if (s == "pop_back") {
			cout << d.PopBack() << endl;
		}
		if (s == "size") {
			cout << d.Size() << endl;
		}
		if (s == "empty") {
			cout << d.isEmpty() << endl;
		}
		if (s == "front") {
			cout << d.Front() << endl;
		}
		if (s == "back") {
			cout << d.Back() << endl;
		}
	}

	return 0;
}