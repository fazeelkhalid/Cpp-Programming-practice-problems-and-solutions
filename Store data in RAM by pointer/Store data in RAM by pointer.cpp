#include<iostream>

using namespace std;

class Node {
	public:
		Node *next;
		int number;
};

class List {
	private:
		Node *head;

	public:
		List() {
			head = NULL;
		}

	void add(int X) {
		Node *n = new Node();
		n->number = X;
		n->next = NULL;
		
		if(this->head == NULL) {
			this->head = n;
			return;
		}
		
		Node *temp;
		temp = this->head ;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
		return;
	}
	
	void print() {
		Node *temp;
		temp = this->head;
		
		while(temp != NULL) {		
			cout<<temp->number<<", ";
			temp = temp->next;
		}
		cout<<endl;
		return;
	}
	
	void remove(int X) {
		Node *temp;
		temp = this->head;
		Node *a;
		
		if(head->number == X) {
			head = head->next;
			delete temp;	
			return ;
		}
		
		
		while(temp->next != NULL) {
			if(temp->next->number == X){
				a = temp->next;
				temp->next = temp->next->next;
				a->next = NULL;
				delete a;
				return;
			}
			temp = temp->next;
		}
	}
	
	bool search(int X) {
		Node *temp = this->head;
		
		while(temp !=NULL) {
			
			if(temp->number == X) {
				return true;
			}		
			
			temp = temp->next;
		}
	
		return false;
	}
};

int main() {
	List l;
	l.add(5);
	l.add(10);
	l.add(15);
	l.add(99);
	
	l.print();
	
	l.remove(15);
	
	l.print();
	
	cout<<l.search(45);

	return 0;
}
