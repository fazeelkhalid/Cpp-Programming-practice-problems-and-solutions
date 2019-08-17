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
			this->head = NULL;
		}
		
		List(const List &obj) {
			this->head = NULL;
			
			Node *temp1 = obj.head;
			Node *temp2 = this->head;
			
			while(temp1 != NULL) {
				Node *n = new Node();
				n->number = temp1->number;
				n->next = NULL;
				
				if(this->head == NULL)
					this->head = n;
				else {
					temp2->next = n;
					temp2 = temp2->next;
				}
				
				temp1 = temp1->next;
			}
		}

		void add(int X) {
			Node *n = new Node();
			n->number = X;
			n->next = NULL;
			
			if(this->isEmpty()) {
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
		
		bool isEmpty() {
			if(head == NULL) {
				return true;
			}
			else
				return false;		
		}
	
		void replace(int X,int Y) {
			Node *temp = this->head;
			
			while(temp !=NULL) {
				if(temp->number == X) {
					temp->number = Y;
				}
				temp = temp->next;
			}
			return;
		}
		
		void allRemove() {
			while(head->next != NULL) {
				Node *n = head ;
				head = head->next;
				n->next = NULL;
				delete n;
			}
			delete head;
			head = NULL;
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
	
	cout<<l.search(5);
	cout<<endl;
	
	l.allRemove();
	cout<<l.isEmpty();
	
	l.print();
	
	return 0;
	
}
