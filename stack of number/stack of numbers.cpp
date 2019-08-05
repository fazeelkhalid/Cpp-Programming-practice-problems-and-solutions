#include<iostream>

using namespace std;

class Stack {
	private:
		int array[5];
		int size;
			
	public:

		Stack() {
			size = 0;
		}
		
		void push(int val) {
			if(size < 5) {
				array[size] = val;
				size++;
			}
			else 
				cout<<"Not enough sapce in stack";
		}
		
		int pop() {
			if(size > 0) {
				size--;
				return array[size];
			}
			else 
				cout<<"Stack Empty";
		}
		
		bool isFull() {
			if(this->size < 5) {
				return false;
			}
			else
				return true;
		}
		
		bool isEmpty() {
			if(size == 0) {
				return true;
			}
			else
				return false;
		}

		int top() {
			return array[--size];						
		}
};

int main() {
	Stack s;
	
	s.push(43);
	s.push(90);
	s.push(64)
	cout<<s.top();
	return 0;
}
