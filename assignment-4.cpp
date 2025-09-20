#include <iostream>
using namespace std;

#define SIZE 10

// 1) Simple Queue
class SimpleQueue {
	int data[SIZE];
	int front, rear;
public:
	SimpleQueue() {
		front = rear = -1;
	}
	void enqueue(int x) {
		if (rear == SIZE - 1) {
			cout << "Full\n";
			return;
		}
		if (front == -1) front = 0;
		data[++rear] = x;
	}
	void dequeue() {
		if (front == -1 || front > rear) {
			cout << "Empty\n";
			return;
		}
		cout << "Removed: " << data[front++] << "\n";
		if (front > rear) front = rear = -1;
	}
	bool isEmpty() {
		return front == -1;
	}
	bool isFull() {
		return rear == SIZE - 1;
	}
	void display() {
		if (isEmpty()) {
			cout << "Empty\n";
			return;
		}
		for (int i = front; i <= rear; i++) cout << data[i] << " ";
		cout << "\n";
	}
	void peek() {
		if (isEmpty()) cout << "Empty\n";
		else cout << data[front] << "\n";
	}
};

// 2) Circular Queue
class CircularQueue {
	int data[SIZE];
	int front, rear, count;
public:
	CircularQueue() {
		front = rear = count = 0;
	}
	void enqueue(int x) {
		if (count == SIZE) {
			cout << "Full\n";
			return;
		}
		data[rear] = x;
		rear = (rear + 1) % SIZE;
		count++;
	}
	void dequeue() {
		if (count == 0) {
			cout << "Empty\n";
			return;
		}
		cout << "Removed: " << data[front] << "\n";
		front = (front + 1) % SIZE;
		count--;
	}
	bool isEmpty() {
		return count == 0;
	}
	bool isFull() {
		return count == SIZE;
	}
	void display() {
		if (isEmpty()) {
			cout << "Empty\n";
			return;
		}
		int i = front;
		for (int c = 0; c < count; c++) {
			cout << data[i] << " ";
			i = (i + 1) % SIZE;
		}
		cout << "\n";
	}
	void peek() {
		if (isEmpty()) cout << "Empty\n";
		else cout << data[front] << "\n";
	}
};

// 3) Interleave halves of a queue
void interleaveQueue(int arr[], int n) {
	int half = n / 2;
	int q1[SIZE], q2[SIZE];
	int f1 = 0, r1 = half - 1, f2 = 0, r2 = n - half - 1;
	for (int i = 0; i < half; i++) q1[i] = arr[i];
	for (int i = half; i < n; i++) q2[i - half] = arr[i];
	for (int i = 0; i < half; i++) {
		cout << q1[i] << " " << q2[i] << " ";
	}
	cout << "\n";
}

// 4) First non-repeating character using queue
void firstNonRepeating(char s[], int len) {
	char q[SIZE];
	int freq[256] = {0};
	int f = 0, r = -1;
	for (int i = 0; i < len; i++) {
		char c = s[i];
		freq[(int)c]++;
		q[++r] = c;
		while (f <= r && freq[(int)q[f]] > 1) f++;
		if (f > r) cout << -1 << " ";
		else cout << q[f] << " ";
	}
	cout << "\n";
}

// 5a) Stack using two queues
class StackTwoQueues {
	int q1[SIZE], q2[SIZE];
	int f1, r1, f2, r2;
public:
	StackTwoQueues() {
		f1 = f2 = 0;
		r1 = r2 = -1;
	}
	void push(int x) {
		q2[++r2] = x;
		for (int i = f1; i <= r1; i++) q2[++r2] = q1[i];
		f1 = 0;
		r1 = r2;
		r2 = -1;
		for (int i = f1; i <= r1; i++) q1[i] = q2[i];
	}
	void pop() {
		if (r1 < f1) {
			cout << "Empty\n";
			return;
		}
		cout << "Popped: " << q1[f1++] << "\n";
		if (f1 > r1) {
			f1 = 0;
			r1 = -1;
		}
	}
	void display() {
		for (int i = f1; i <= r1; i++) cout << q1[i] << " ";
		cout << "\n";
	}
};

// 5b) Stack using one queue
class StackOneQueue {
	int q[SIZE];
	int f, r, c;
public:
	StackOneQueue() {
		f = 0;
		r = -1;
		c = 0;
	}
	void push(int x) {
		q[++r] = x;
		c++;
		for (int i = 0; i < c - 1; i++) {
			int tmp = q[f++];
			q[++r] = tmp;
		}
	}
	void pop() {
		if (c == 0) {
			cout << "Empty\n";
			return;
		}
		cout << "Popped: " << q[f++] << "\n";
		c--;
	}
	void display() {
		for (int i = f; i <= r; i++) cout << q[i] << " ";
		cout << "\n";
	}
};

int main() {
	SimpleQueue sq;
	CircularQueue cq;
	StackTwoQueues stq;
	StackOneQueue soq;
	int choice, val;
	while (true) {
		cout << "1 SimpleQueue 2 CircularQueue 3 Interleave 4 FirstNonRepeat 5 Stack2Q 6 Stack1Q 0 Exit\n";
		cin >> choice;
		if (choice == 0) break;
		if (choice == 1) {
			int ch;
			cin >> ch;
			if (ch == 1) {
				cin >> val;
				sq.enqueue(val);
			}
			else if (ch == 2) sq.dequeue();
			else if (ch == 3) cout << sq.isEmpty() << "\n";
			else if (ch == 4) cout << sq.isFull() << "\n";
			else if (ch == 5) sq.display();
			else if (ch == 6) sq.peek();
		} else if (choice == 2) {
			int ch;
			cin >> ch;
			if (ch == 1) {
				cin >> val;
				cq.enqueue(val);
			}
			else if (ch == 2) cq.dequeue();
			else if (ch == 3) cout << cq.isEmpty() << "\n";
			else if (ch == 4) cout << cq.isFull() << "\n";
			else if (ch == 5) cq.display();
			else if (ch == 6) cq.peek();
		} else if (choice == 3) {
			int n;
			cin >> n;
			int a[SIZE];
			for (int i = 0; i < n; i++) cin >> a[i];
			interleaveQueue(a, n);
		} else if (choice == 4) {
			int n;
			cin >> n;
			char str[SIZE];
			for (int i = 0; i < n; i++) cin >> str[i];
			firstNonRepeating(str, n);
		} else if (choice == 5) {
			int ch;
			cin >> ch;
			if (ch == 1) {
				cin >> val;
				stq.push(val);
			}
			else if (ch == 2) stq.pop();
			else if (ch == 3) stq.display();
		} else if (choice == 6) {
			int ch;
			cin >> ch;
			if (ch == 1) {
				cin >> val;
				soq.push(val);
			}
			else if (ch == 2) soq.pop();
			else if (ch == 3) soq.display();
		}
	}
	return 0;
}
