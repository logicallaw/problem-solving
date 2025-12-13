#include <iostream>
using namespace std;
class Queue {
private:
	int* queue;
	int front, rear, indexQueue;
public:
	Queue(const int& n);
	~Queue();
	void push();
	void pop();
	int size() const;
	void getrear() const;
};

Queue::Queue(const int& n)
	: queue{ new int[1000000] }, front{ 0 }, rear{ n - 1 }, indexQueue{ n } {
	for (int i{ 0 }; i < n; i++) {
		queue[i] = i + 1;
	}
}
Queue::~Queue() { delete[] queue; }
void Queue::push() {
	queue[++rear] = queue[front++];
}
void Queue::pop() {
	front++;
	indexQueue--;
}
int Queue::size() const { 
	return indexQueue;
}
void Queue::getrear() const {
	cout << queue[rear] << "\n";
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	Queue que{ n };
	while (que.size() != 1) {
		//pop
		que.pop();
		if (que.size() == 1)
			break;
		//push
		que.push();
	}

	que.getrear();

	return 0;
}