#include<iostream>

using namespace std; 

class point {
	
	private:
		float Y;
		float X;
		
	public:
		point(float a, float b) {
			this->X = a;
			this->Y = b;
		}
		
		void print(){
			cout<< "(" <<this->X << "," << this->Y << ")";
		}
		
		void setX(float c) {
			this->X = c;
		}

		void setY(float c) {
			this->Y = c;
		}
		
		float getY(){
			return this->Y;
		}
		float getX(){
			return this->X;
		}

};

int main() {
	
	point p(400,30);
	p.print();
	
	cout<<endl;
	
	p.setX(5);
	p.print();
		
	cout<<endl;
	
	p.setY(19);	
	p.print();
	
	cout<<endl;
	
	cout<< p.getY();
	cout<< p.getX();
	
	
	return 0;	

}
