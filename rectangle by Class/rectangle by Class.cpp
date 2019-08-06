#include<iostream>

using namespace std;

struct Rectangle {
	private:
		float height;
		float width;
		float area;
	
	public:
		Rectangle() {
			height = 0;
			width = 0;
			area = height * width;
		}
		
		Rectangle(float h, float w) {
			height = h;
			width = w;
			area = h * w;
		}
		
		void print() {
			cout<<"Height: "<<this->height<<"\nWidth: " << this->width<<"\nArea: "<<area;
		}
		
		void setHeight(float h) {
			this->height = h;
			this->area = this->height * this->width;
		}
		
		void setWidth(float w) {
			this->width = w;
			this->area = this->height * this->width;
		}
};

int main() {
	struct Rectangle r(90, 60);
	r.print();
	cout<<endl<<"------------"<<endl;
	r.setHeight(180);
	r.print();
}
