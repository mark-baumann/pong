#include <iostream>
#include <Windows.h>


using namespace std;



	

	int gamespeed = 75;

	int balldir =2;
	int mapwidth=50;
	int maphigh=30;
	int ballX = mapwidth / 2;
	int ballY = maphigh / 2;

	int spieler1x = 5;
	int spieler1y = maphigh / 2;
	int spieler2y = maphigh / 2;
	int spieler2x = mapwidth - 5;

void player1move() {

	if(GetKeyState('W') & 0x800) {
		spieler1y--;

	}

	if(GetKeyState('S') & 0x800) {
		spieler1y++;
	}
}

void player2move() {
	if(GetKeyState('I') & 0x800) {
		spieler2y--;

	}

	if(GetKeyState('K') & 0x800) {
		spieler2y++;
	}

}

void ballLogik() {

	if (balldir == 2) {
		ballX--;
	}

	if (balldir == 1) {
		ballX--;
		ballY--;
	}

	if (balldir == 3) {
		ballX--;
		ballY++;

	}

	if (balldir == 4) {
		ballX++;
		ballY--;
	}

	if (balldir == 5) {
		ballX++;

	}

	if (balldir == 6) {
		ballX++;
		ballY++;
	}


		//ganz oben treffen
		if (ballX == spieler1x && ballY == spieler1y-2) {
			
			balldir = 4;
			
		}

		//mitte treffen
		if (ballX == spieler1x && ballY == spieler1y-1) {
			
			balldir = 5;
			
		}

		//ganz unten treffen
		if (ballX == spieler1x && ballY == spieler1y) {
			
			balldir = 6;
			
		}


		//spieler 2 ganz oben treffen
		if (ballX == spieler2x && ballY == spieler2y-2) {
			balldir = 1;
		}

		//spieler 2 mitte treffen
		if (ballX == spieler2x && ballY == spieler2y - 1) {
			balldir = 2;
		}

		if (ballX == spieler2x && ballY == spieler2y) {
			balldir = 3;
		}
			 
			


	
}

bool endgame = false;


void map(){

	for (int i=0; i<=maphigh; i++) {
		for(int j=0; j<=mapwidth; j++) {
			
			if (i==0 || i == maphigh ) {
				cout << "#";
			}

			else if (j==0 || j == mapwidth ) {
				cout << "#";
			}
			else if (spieler1x == j && spieler1y == i)
			{
				cout << "p";
			}
			else if (spieler1x == j && spieler1y-1 == i)
			{
				cout << "p";
			}
			else if (spieler1x == j && spieler1y -2 == i)
			{
				cout << "p";
			}
			else if (spieler2x == j && spieler2y == i) {
				cout<< "x";
			}
			else if (spieler2x == j && spieler2y-1 == i) {
				cout<< "x";
			}
			else if (spieler2x == j && spieler2y-2 == i) {
				cout<< "x";
			}

			else if(ballX == j && ballY == i) {

				cout<<"o";
			}

			else {
				cout << " ";
			}
			


		}
			cout<<endl;
	}
}

int main() {
	

	
	while(!endgame){
		map();
		player1move();
		player2move();
		ballLogik();
		Sleep(gamespeed);
		system("cls");
	}


	system("pause");

}