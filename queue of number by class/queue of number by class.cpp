#include<iostream>

using namespace std;

class Queue {
	private:
		int array[5];
		int size;
	
	public:
		Queue(){
			size = 0;
		}
		
		void enqueue(int a) {
			if(!isFull()) {
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
			return this->size == 5;
		}
			
		bool isEmpty() {
			return size == 0;
		}
	
		int top() {
			return array[size - 1];						
		}
		
		int bottom() {
			return array[0];
		}
		
	
};

int main() {
	
	Queue a;
	a.enqueue(126);
	a.enqueue(112);
	a.enqueue(122);
	a.enqueue(127);
	a.enqueue(13);
	
	a.dequeue();
	
	
	return 0;
}
