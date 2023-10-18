#include<iostream>

using namespace std;

const int Max_size = 10000;

class Cqueue {
private:
	int first = 0, last = 0;
	int count = 0;
	int arr[Max_size] = { 0, };
public:
	Cqueue() {}
	Cqueue(const Cqueue& Q) {}
	~Cqueue() {}
	void Push(int input) {
		if (last < 10000 && first!=last+1) {
			last++;
			arr[count++] = input;
		}
		else if (last == 10000 && first!=0) {
			last = 0;
			count = 0;
			arr[count] = input;
		}
	}
	int Pop() {
		if (last - first == 0) return -1;
		else return arr[first++];
	}
	int Size() {
		if (first < last) {
			return last - first;
		}
		else if (first > last) {
			return 10000 - first + last + 2;
		}
		return 0;
	}
	bool isEmpty() {
		if (last - first != 0) {
			return false;
		}
		else return true;
	}
	int aFront() {
		if (last - first == 0) return -1;
		else return arr[first];
	}
	int aBack() {
		if (last - first == 0) return -1;
		else return arr[last-1];
	}
};

int main()
{
	int n, k;
	string s;
	Cqueue q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> k;
			q.Push(k);
		}
		if (s == "pop") {
			cout << q.Pop() << endl;
		}
		if (s == "size") {
			cout << q.Size() << endl;
		}
		if (s == "empty") {
			cout << q.isEmpty() << endl;
		}
		if (s == "front") {
			cout << q.aFront() << endl;
		}
		if (s == "back") {
			cout << q.aBack() << endl;
		}
	}

	return 0;
}