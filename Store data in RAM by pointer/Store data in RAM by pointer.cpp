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
			cout<<temp->number<<endl;
			temp = temp->next;
		}
		return;
	}
	
	void delet(int X) {
		Node *temp;
		temp = this->head;
		while(temp->number != X) {
			temp = temp->next;
		}
		if(temp->number == X) {
			delete(temp);
		}
		else 
		cout<<X<<" that you enter is not present";
	}	
};

int main() {
	List l;
	int X;
	
	cout<<"Enter number: ";
	cin>>X;
	l.add(X);
	
	cout<<"Enter number: ";
	cin>>X;
	l.add(X);
	
	cout<<"Enter number: ";
	cin>>X;
	l.add(X);
	
	l.print();
	
	cout<<"Number you want to delete: ";
	cin>>X;
	l.delet(X);
	
	l.print();
	
	return 0;

}
