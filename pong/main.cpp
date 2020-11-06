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

	int spieler1win = 0;
	int spieler2win = 0;

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



	//wemn der ball wie Auftrifft dann schleuder ihn dementsprechend weg
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


	//Bewegung der Spieler
	
		if (ballX == spieler1x && ballY == spieler1y-2) {
			
			balldir = 4;
			
		}
		if (ballX == spieler1x && ballY == spieler1y-1) {
			
			balldir = 5;
			
		}
		if (ballX == spieler1x && ballY == spieler1y) {
			
			balldir = 6;
			
		}


		if(ballX == spieler2x && ballY == spieler2y-2) {
			balldir = 1;
		}

		if(ballX == spieler2x && ballY == spieler2y-1) {
			balldir = 2;
		}

		if(ballX == spieler2x && ballY == spieler2y) {
			balldir = 3;
		}

		if(ballY == 0 ) {
			if(balldir == 1) {
				balldir = 3;
			}else {
				balldir = 6;
			}
		}

		if( ballY == maphigh){
			if(balldir == 3) {
				balldir = 1;
			} else {
				balldir = 4;
			}
		}
		
		if(ballX == 0) {
			spieler2win++;
			ballX = mapwidth / 2;
			ballY = maphigh / 2;
		}

		if (ballX == mapwidth){
			spieler1win++;
			ballY = maphigh / 2;
			ballX = mapwidth / 2;
		}
}





bool endgame = false;


void map(){

	for (int i=0; i<=maphigh; i++) {
		for(int j=0; j<=mapwidth; j++) {
			
			//erzeuge mir den  Rand an der linken und rechten Seite
			if (i==0 || i == maphigh ) {
				cout << "#";
			}

			//erzeuge mir den Rand oben und unten
			else if (j==0 || j == mapwidth ) {
				cout << "#";
			}

			//erzeuge mir den Spieler p
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

			//erzeuge mir den Spieler X
			else if (spieler2x == j && spieler2y == i) {
				cout<< "x";
			}
			else if (spieler2x == j && spieler2y-1 == i) {
				cout<< "x";
			}
			else if (spieler2x == j && spieler2y-2 == i) {
				cout<< "x";
			}

			//erzeuge mir den Ball
			else if(ballX == j && ballY == i) {

				cout<<"o";
			}


			//erzeuge sonst alles durch Leerzeichen
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
		cout<<endl;
		cout<<"Spieler 1 Win: "<<spieler1win <<"\t";
		cout<<"Spieler 2 Win: "<<spieler2win;
		player1move();
		player2move();
		ballLogik();
		Sleep(gamespeed);
		system("cls");
		
	}


	system("pause");

}