#include <iostream>
using namespace std;
class Queue {
private:
	int* queue;
	int indexQueue;
	int front;
	int rear;
public:
	Queue();
	~Queue();
	void push(const int& value);
	void pop();
	void size() const;
	void empty() const;
	void getfront() const;
	void getrear() const;
};

void process(Queue& que, const string& cmd);

Queue::Queue()
	: queue{ new int[10000] }, indexQueue{ 0 }, front{ 0 }, rear{ 0 } {}
Queue::~Queue() { delete[] queue; }
void Queue::push(const int& value) {
	queue[rear++] = value;
	indexQueue++;
}
void Queue::pop() {
	if (indexQueue != 0) {
		cout << queue[front++] << "\n";
		indexQueue--;
	}
	else {
		cout << "-1\n";
	}
}

void Queue::size() const { cout << indexQueue << "\n"; }
void Queue::empty() const { 
	if (!indexQueue)
		cout << "1\n";
	else 
		cout << "0\n";
}
void Queue::getfront() const {
	if (indexQueue != 0) {
		cout << queue[front] << "\n";
	}
	else {
		cout << "-1\n";
	}
}
void Queue::getrear() const {
	if (indexQueue != 0) {
		cout << queue[rear - 1] << "\n";
	}
	else {
		cout << "-1\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	Queue que;
	while (n--) {
		string cmd;
		cin >> cmd;
		process(que, cmd);
	}
	return 0;
}

void process(Queue& que, const string& cmd) {
	if (cmd == "push") {
		int value;
		cin >> value;
		que.push(value);
	}
	else if (cmd == "pop") {
		que.pop();
	}
	else if (cmd == "size") {
		que.size();
	}
	else if (cmd == "empty") {
		que.empty();
	}
	else if (cmd == "front") {
		que.getfront();
	}
	else if (cmd == "back") {
		que.getrear();
	}
	else {
		cout << "unexpected command\n";
	}
}