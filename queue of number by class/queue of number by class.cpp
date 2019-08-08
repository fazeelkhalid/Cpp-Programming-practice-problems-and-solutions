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
		if(size < 5) {
			array[size] = a;
			size++;
		}
		else
			cout<<"Queue full";
	}
	
	int dequeue() {
		size--;
		return array[size];
	}
	
	bool isFull() {
		if(this->size < 5) {
			cout<<"Queue not full";
		}
		else
			cout<<"Queue is full";
	}
		
	void isEmpty() {
		if(size == 0) {
			cout<<"Queue is empty";
		}
		else
			cout<<"Queue not empty";
	}

	int top() {
		return array[--size];						
	}
	
	int bottom() {
		return array[0];
	}
	
};

int main() {
	Queue q;
	
	q.enqueue(109);
	q.enqueue(19);
	q.enqueue(9);
 	q.enqueue(92);
 	q.enqueue(39);
 	q.enqueue(392);
 	
 	
 	q.isEmpty();
 	
	cout<<endl;
	q.dequeue();
	cout<<q.top();
 	
	return 0;

}
