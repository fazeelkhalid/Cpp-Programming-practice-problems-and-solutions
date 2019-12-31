#include<iostream>
#include<cmath>

using namespace std;

void car_to_pol(float x,float y,float &R,float &Q) {
	
	R = sqrt(x*x + y*y);  		//R is the sum of x component and y component
	Q = atan2(y, x) * (180 / 3.141592) ;   	//Q is the angle

}

void pol_to_car(float R, float Q, float &x, float &y) {
	Q *= 3.1415 / 180;
	x = R * cos(Q);		 //R is x component
	y = R * sin(Q);		// Q is y component
}

int main() {

	int opetion;
	
	cout<<"********** PRESS **********\n1 for carrtesian to polar\n2 for polar to carrtesion :";
	cin>>opetion;
	if(opetion == 1) {
		float x;
		float y;
		float R;
		float Q;
		
		cout<<"input x component :";
		cin>>x; 	//x component
		cout<<"input y component :";
		cin>>y;		 //y component
		
		car_to_pol(x,y,R,Q);
		
		cout<<"carrtesian coordintes : "<<"("<<x<<","<<y<<")\n";
		cout<<"polar coordintes : "<<"("<<R<<","<<Q<<")";
	}

	else if(opetion == 2) {
		float R;
		float Q;
		float x;
		float y;
		
		cout<<"input sum of x and y component :";
		cin>>R; 	//sum of x component and y component
		cout<<"input angle :";
		cin>>Q;		//angle
		
		pol_to_car(R,Q,x,y);
		
		cout<<"polar coordintes : "<<"("<<R<<","<<Q<<")\n";
		cout<<"carrtesian coordintes : "<<"("<<x<<","<<y<<")\n";
	}
	else {
		cout<<"Enter correct operation";
	}
	
	system ("pause");
	return 0;

}
