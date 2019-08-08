#include<iostream>

using namespace std;

class Queue {
	int array[5];
	int size;
	public:
	Queue(){
		size = 0;
	}
	
	void enqueue(int a) {
		array[size] = a;
		size++;
	}	
};

int main() {
	Queue q;
	
	q.enqueue(109);
	q.enqueue(19);
	q.enqueue(9);
 	
 	return 0;
 	
 }
