#include<iostream>
#include<conio.h>
#include<Windows.h>
#include <time.h>
#include "mygraphics.h"

using namespace std;

int allienX;
int allienY;
int HFireY;
int HFireX;
bool is_destroy = true; // hero fire destroy or not
bool is_fire = false; // fire by hero or not
int allienNumber[8]; //select which allien will fire
int counter = 0; //count allien
int allienFireX[8]; // x component of allien fire
int allienFireY[8]; // y component of allien fire
int index = 0; // handle allienFireY and allienFireX array
int allDestroy; // it will tell all destroy or not;
int numberOfFire = 0; // number of fire by allien
bool assignJustOnce; // refire by allien
bool first_call = true; //it will call random function just once
int lives = 10; // it give the live to hero
int score = 0; // store the score

BOOL setxy(int x, int y) {// this will set cursor position
	COORD c = {x,y};
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void delaay(int number_of_seconds) { 
    int milli_seconds = 100 * number_of_seconds; // Converting time into milli_seconds  
    clock_t start_time = clock();     // Stroing start time 
    while (clock() < start_time + milli_seconds); // looping till required time is not acheived 
} 

bool one_decrease_at_once = true; // only decrease one lives

void randomFire() {
	
	srand(time(0));
	for(int i = 1; i < 8; i++) {
		allienNumber[i] = rand() % 32;
	}
	assignJustOnce = true;
	one_decrease_at_once = true; // only decrease one lives
}
int s = 50;
int t = 150;

int defenderX; // hero x component
int defenderY; // hero y component

void destroyHero(int heroX, int heroY){
	s--;
	if(s == 0){
		t--;
		s=50;
	}
	for(int i = 0; i <= 7; i++) {
		if(heroY == allienFireY[i]){
			for(int j = 0; j <= 7; j++) {
				if(heroX == allienFireX[index]) {
					if(one_decrease_at_once) // only decrease one lives
						lives--;
					one_decrease_at_once = false;
				}

			}
		}
	}
}

int dAllien[] = {1,12,13,14,15,16,17,18,19,10,18,17,16,15,14,13,14,15,16,17,18,19,10,14,14,15,16,17,1,1,1,1}; // indicate which allien is alive 
void drawAllienFire(int x, int y) { //draw and move allien fire
	if(assignJustOnce) { // 
		allienFireX[index] = x;
		allienFireY[index] = y;
		numberOfFire ++;
		allDestroy = 0;
	} 
	if(allienFireY[index] < 29) {
		setxy(allienFireX[index], allienFireY[index]);
		cout << char(186);
	}
	else{ // it will draw space if fire reach at a certain place
		setxy(allienFireX[index], allienFireY[index]);
		cout << char(32);
		allienFireY[index] = 28;
		allDestroy ++;
	}
	destroyHero( defenderX, defenderY);
	
	allienFireY[index]++;
	index++;
	if(index == 7){
		index = 0;
		assignJustOnce = false;
	}
}

int i = 0; // limitization of allienFireX and allienFireY array 

void DrawAllien(int x, int y, int width, int height, int curPosX=0, int curPosY=0) {// Giving a single allien
	

	setxy(x+1 , y);
	for(int i = 1; i < width; i++)
		cout << char(248);
	cout << char();
	setxy(x,height + y);
	cout << char(200);
	 
	for(int i = 1; i < width; i++)
		cout << char(94);
	cout << char(188);
	
	for(int i = y + 1; i < height + y; i++) {
		setxy(x,i);
		cout<< char(186);
		setxy(x + width,i);
		cout<< char(186);
	}
	counter ++; // count number of alliens
	if(first_call) {
		randomFire();
		first_call = false;
	}
	
	if(allDestroy >= 100) { // it will call randomFire when all fires are destroy
		first_call = true;
		allDestroy = 0;
	}
	
	for(int i = 0; i < 8; i++) { //it will draw fire
		if(counter == allienNumber[i]){
			drawAllienFire(x+1,y+2);	
		}
	}
	if(counter == 32) {
		counter = 0;
	}
	
	setxy(curPosX,curPosY);
}

int COUNT = 0;
int aNumber = 0; //index for the status of allien
bool destroyAllien = true; //destroy only one allien at a time

void Allien(int initialValueX,int initialValueY) { // for multiple allien
	
	for(int y = initialValueY; y < 10 + initialValueY ; y += 3 ) {
		for(int x = initialValueX + 20; x < 100 + initialValueX; x += 10) {
			if(dAllien[aNumber]) {
			DrawAllien(x, y, 3, 1, x , y);
			allienX = x;
			allienY = y;
			if(HFireX >= allienX - 1 && HFireX <= allienX + 4 && HFireY == allienY-2)
				if(destroyAllien) {
					dAllien[COUNT] = 0;
					score += 10;
					destroyAllien = false;
					is_destroy = true;
					is_fire = false;
				}
			}
			aNumber++;
			COUNT ++;
			if(COUNT == 32) {
				COUNT = 0;
			}
			if(aNumber == 32){
				aNumber = 0;
			}
		}
	}
}

void hero(int heroX,int heroY,int curPosX = 0,int curPosY = 0) { // move hero
	
	setxy(heroX , heroY); //heroX + 1 , heroy
	cout << char(94); 
	defenderX = heroX;
	defenderY = heroY;
	setxy(heroX , heroY + 1); //heroX + 1 , heroY + 1
	cout << char(178);
	setxy(curPosX,curPosY); 
}

void heroFire(int heroX, int heroY,int allienX, int allienY) { //draw herro fire
	
	if(is_destroy){
		HFireX = heroX;
		HFireY = heroY;
		destroyAllien = true;
		is_destroy = false;		
	}
	int temp = allienY - 10;
	
	if(temp == HFireY){
		is_destroy = true;
		is_fire = false;
	}
	setxy(HFireX , HFireY); 
	cout<< char(94);
	HFireY--;
}

void remainingLive(int live){
	for(int i = 0; i < live*4 ;i++) {
		cout<<char(178);
	}
}

void Download() {
    for(int i = 1; i <= 50; i++){
		showConsoleCursor(false);
		system("CLS");
		setxy(55,12);
  		cout<<"Loading ";
 		
		for(int j = 1; j <= i; j ++) {
			setxy(33+j,  14);
			cout<<char(219);
		}
  		cout<<2*i<<"%";
 		if( i >= 1 && i <= 20) {
  			setxy(45,16);
			cout<<"Creating Temporary files";
		}
		else if( i >= 20 && i<=40) {
			setxy(45,16);
  			cout<<"Accessing Main Memory";
		}
		else if(i >=40 && i<=48) {
			setxy(45,16);
			cout<<"Accessing Cache";
		}
		else{
			setxy(55,16);
			cout<<"Complete. ";
		}
		delaay(1);
	}
	
	delaay(10);
	
}

int mHeroX; // select speed for hero
float mallienfX; // select forward speed for allien
float mallienrx; // select reverse speed for allien
void Instruction(){
	char c;
	system("CLS");
	showConsoleCursor(false);
	cout<<"******* INSTRUCTION *******\n";
	cout<<"\"A\" for right movement\n";
	cout<<"\"D\" for left movement\n";
	cout<<"\"F\" for fire\n";
	cout<<"\"Q\" for close game\n";
	cout<<"Lives = 5\n";
	cout<<"Press \'N\' for normal\n";
	cout<<"Press \'M\' for medium\n";
	cout<<"Press \'H\' for hard : ";
	reenter:
	cin >> c;
	if(c == 'n' || c == 'N') {
		t = 150;
		mHeroX = 2;
		mallienfX = 0.125;
		mallienrx = 0.25;
	}
	else if(c == 'm' || c == 'M') {
		t = 120;
		mHeroX = 4;
		mallienfX = 0.25;
		mallienrx = 0.5;
	}
	else if(c == 'h' || c == 'H') {
		t = 60;
		mHeroX = 7;
		mallienfX = 0.5;
		mallienrx = 1;
	}
	else {
		cout<<"\nPlease reenter : ";
		goto reenter;
	}
	cout<<"Time deadline "<<t<<" sec \n";
	cout<<"Press Enter to Continue \n";
	getch();
	
}

void congratulation(){
	showConsoleCursor(false);
	//C
	drawLine(80,100,170,100,200,120,120);
	drawLine(100,115,170,115,250,120,120);
	drawLine(170,100,170,115,195,185,57);
	drawLine(80,100,80,250,250);
	drawLine(100,115,100,235,250);
	drawLine(80,250,170,250,210,230,0);
	drawLine(100,235,170,235,250);
	drawLine(170,250,170,235,198,65,32);

	//O
	drawRectangle(210,150,255,250,250,25,150);
	
	//N
	drawLine(290,150,290,250,210,20,210);
	drawLine(290,150,330,250,20,210,150);
	drawLine(330,150,330,250,200,20,210);
	
	//G
	drawLine(350,150,350,250,210,20,210);
	drawLine(350,150,380,150,200,25,59);
	drawLine(350,250,380,250,200,25,59);
	drawLine(380,200,380,250,210,20,210);
	drawLine(375,200,380,200,200,25,59);

	//R
	drawLine(395,150,395,250,240,21,39);
	drawLine(395,150,425,150,210,25,255);
	drawLine(395,200,425,200,21,150,150);
	drawLine(425,150,425,200,210,35,100);
	drawLine(395,200,425,250,250,150,140);

	//A
	drawLine(445,250,460,150,210,255,32);
	drawLine(460,150,475,250,200,32,58);
	drawLine(450,195,470,195,54,98,37);

	//T
	drawLine(490,150,520,150,240,250,10);
	drawLine(505,150,505,250,250,154,168);

	//U
	drawLine(530,150,530,250,210,250,289);
	drawLine(530,250,555,250,250,154,165);
	drawLine(555,150,555,250,255,120,100);

	//L
	drawLine(570,150,570,250,210,250,265);
	drawLine(570,250,600,250,210,250,265);

	//A
	drawLine(610,250,625,150,210,250,145);
	drawLine(625,150,640,250,210,250,100);
	drawLine(615,195,635,195,145,250,189);

	//T
	drawLine(655,150,685,150,210,178,98);
	drawLine(670,150,670,250,210,78,98);

	//I
	drawLine(700,150,710,150,210,78,64);
	drawLine(700,250,710,250,78,98,250);
	drawLine(705,150,705,250,58,78,98);

	//O
	drawRectangle(730,150,775,250,210,78,54);

	//N
	drawLine(795,150,795,250,154,68,52);
	drawLine(795,150,835,250,75,154,32);
	drawLine(835,150,835,250,190,54,21);

	//S
	drawLine(850,150,870,150,150,54,15);
	drawLine(850,150,850,200,162,98,65);
	drawLine(850,200,870,200,154,87,65);
	drawLine(870,200,870,250,117,78,65);
	drawLine(850,250,870,250,198,35,255);

	drawLine(60,285,890,285,255,120,150);
	drawLine(80,295,870,295,210,150,187);

	cout<<"Press Enter to Continue \n";
	getch();

}

void gameover() {
	showConsoleCursor(false);

	//G
	drawLine(100,70,100,250,210,250,15);
	drawLine(100,70,150,70,245,87,98);
	drawLine(100,250,150,250,287,156,98);
	drawLine(150,175,150,250,185,89,65);
	drawLine(140,175,160,175,65,98,78);

	//A
	drawLine(170,250,185,150,210,178,98);
	drawLine(185,150,200,250,178,210,98);
	drawLine(175,195,195,195,154,87,98);

	//M
	drawLine(215,150,215,250,210,250,15);
	drawLine(215,150,230,250,185,89,65);
	drawLine(230,250,245,150,245,87,98);
	drawLine(245,150,245,250,287,156,98);

	//E
	drawLine(260,150,260,250,65,187,250);
	drawLine(260,150,285,150,210,54,98);
	drawLine(260,200,275,200,245,87,98);
	drawLine(260,250,285,250,24,87,255);

	//O
	drawEllipse(480,70,590,250,210,65,87);

	//V
	drawLine(610,150,625,250,254,98,78);
	drawLine(625,250,640,150,187,45,98);

	//E
	drawLine(655,150,655,250,210,54,87);
	drawLine(655,150,680,150,287,189,65);
	drawLine(655,200,670,200,245,78,89);
	drawLine(655,250,680,250,178,89,45);

	//R
	drawLine(695,150,695,250,287,89,32);
	drawLine(695,150,720,150,287,98,78);
	drawLine(695,200,720,200,98,78,45);
	drawLine(720,150,720,200,210,254,87);
	drawLine(695,200,720,250,287,54,65);

	drawLine(60,260,290,260,289,52,87);
	drawLine(70,270,285,270,287,87,98);
	drawLine(465,260,735,260,289,52,87);
	drawLine(465,270,720,270,287,87,98);
	drawRectangle(290,260,465,270,210,65,98,210,98,65);

	cout<<"Press Enter to Continue \n";
	getch();
}
void displayOnScreen () {
	setxy(18,0);
	showConsoleCursor(false);
	cout<<"SCORE = " <<score;
	setxy(33,0);
	cout<<"LIVES = ";
	remainingLive(lives);
	setxy(90,0);
	cout<<"TIME LEFT = "<< t;	
	setxy(18,1);
	cout<<"======================================================================================";			
}
void handle(char &move, int &heroX, int &HeroY, bool &gameOver,float &i, int &j){
	if(move == 'd' || move == 'D'){ // move leftward
		heroX += mHeroX;
	}
	else if(move == 'a' || move == 'A') { //move rightward
		heroX -= mHeroX;
	}
	else if(move == 'f' || move == 'F') { // fire from hero
		is_fire = true;	
	}
	else if (move == 'q' || move == 'Q') {
		i = 10;
		j = 10;
		gameOver = true;	
		system("CLS");
	}
					
	if(heroX <= 20) { //for restrict the movement of hero
		heroX = 20;
	}
	else if( heroX >= 100) {
		heroX = 100;
	}
}

void handle(char &move, int &heroX, int &HeroY, bool &gameOver,int &i, int &j){
	if(move == 'd' || move == 'D'){ // move leftward
		heroX += mHeroX;
	}
	else if(move == 'a' || move == 'A') { //move rightward
		heroX -= mHeroX;
	}
	else if(move == 'f' || move == 'F') { // fire from hero
		is_fire = true;	
	}
	else if (move == 'q' || move == 'Q') {
		i = 10;
		j = 10;
		gameOver = true;	
		system("CLS");
	}
					
	if(heroX <= 20) { //for restrict the movement of hero
		heroX = 20;
	}
	else if( heroX >= 100) {
		heroX = 100;
	}
}

int main() {
	
	int verticalMovement = 2; // vertical movement of hero
	char move; // for moving an hero
	int heroX = 45;
	int heroY = 26;
	int fireX;
	int fireY;
	float i;
	bool gameOver = false;
	Download();
	Instruction();
	while(!gameOver) {
		for(int j = 0; j < 10; j = j++ ) { // moves allien downward 	
			for(i = 0; i < 10; i = i + mallienfX) { //moves allien right left		
				system("CLS");
				showConsoleCursor(false);
				displayOnScreen ();
				Allien(i , verticalMovement );
				hero(heroX, heroY);

				fireX = heroX;
				fireY = heroY;
				
				if(is_fire ) {
					heroFire( fireX, fireY, allienX, allienY);
				}
			
				if(kbhit()){
					move = getch();						// input for movement of hero
					handle(move,heroX,heroY, gameOver, i,j);
				}
				if(lives == 0 || score == 320 || t == 0) {
					i = 10;
					j = 10;
					system("CLS");
					gameOver = true;
				}
			}		
				
			for(int i = 9; i > 0; i = i - mallienrx) {							
				system("CLS");
				showConsoleCursor(false);
				displayOnScreen ();			
				Allien(i , verticalMovement );
				hero(heroX, heroY);
				
				if(is_fire ) {		
					heroFire( heroX, heroY, allienX, allienY);	
				}
				if(kbhit()){
					
					move = getch();					//movement of hero	
					handle(move, heroX, heroY, gameOver,i,j);
				}
				if(lives == 0 || score == 320 || t == 0) {
					i = 0;
					system("CLS");
				
				}
			}
			if(verticalMovement != 16) {
				verticalMovement++;
			}
			
		}
	}
	system ("CLS");

	if(score == 320) 
		congratulation();
	else if ( lives == 0 || t == 0)
		gameover();
	
	return 0;
}

