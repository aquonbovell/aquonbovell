#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class Player {
	string name; int score;
public:
	Player();
	Player(string playername, int playerscore) : name(playername), score(playerscore) {}
	string printName() { return name; }
	int getScore() { return score; }
	void setScore(int number) {
		score = number;
	}
	void setName(string playname) {
		name = playname;
	}
};

Player::Player() {
	name = " ";
	score = 20;
};

void removeNumbers(int A[][6], int amount);
void displayArray(int A[][6]);
void setGameArray(int A[6][6]);
void setArray(int A[6][6]);
bool checkGameArray(int A[][6]);

int main()
{
	Player play;
	bool gameexit = false, quitgame = false, completegame = false;
	char requesthint = ' ', gametype;
	int rownum, colnum, num(0), hint(2), score(20);
	const int quit = -3;
	string name, endgame;

	srand(time(0));

	int board[6][6] = { 0 };

	int solution[6][6] = { 0 };

	cout << "Welcome to game of SIX LOVE!!\nThis game features a 6x6 grid where the numbers range from 1 to 6.\n Each row has only one instant of each digit \nand similarly each column has only one instant of each digit.";
	cout << "SIX LOVE is a game with three levels:\n(1) Rookie\n(2) Tuff Tong\n(3) Hard Seed\nEnter 'r' or 'R' for Rookie, 't' or 'T' for Tuff Tong and 'h' or 'H' for Hard Seed.\nTo play successfully SIX LOVE you are required to enter a row number from 0 to 5,\nwhere 0 is the first rir and 5 is the last row\nand then a colomn number, similarly the colomn number ranges from 0 to 5.";
	cout << "You can quit at any point during the game by entering '-3' when prompted,\nhowever DO NOT enter a number when prompted for the type of game or a hint or to play another game.\nRookie has a maximum of 1 hint, Tuff Tong has a maximum of 2 hints\nand Hard Seed has a maximum of 3 hints. If you request beyound this limit \nthe game will end and you will be awarded zero points. Best of luck!!";

	system("pause");
	//enter name
	cout << "Player enter your name: ";
	getline(cin, name);
	play.setName(name);

	//enter game type
	do {
		cout << "Enter the type of game you would like to play: ";
		cin >> gametype;
		while (gametype != 'R' || gametype != 'r' || gametype != 'T' || gametype != 't' || gametype != 'H' || gametype != 'h') {
			cout << "Please Enter a valid game type: ";
			cin >> gametype;
		}
		if (gametype == 'R' || gametype == 'r') {

			//Removes 10 digits from the grid which would serve and the grid for the user to enter their numbers

			removeNumbers(board, 10);

			//Displays the grid to the user

			displayArray(board);

			//Asks user for input and places in the numbers

			do {
				cout << "enter a row: ";
				cin >> rownum;

				if (rownum == quit) {//checks to see whether the user would like to quit the game
					gameexit = true;
				}
				else {
					cout << "enter a col: ";
					cin >> colnum;

					if (colnum == quit) {//checks to see whether the user would like to quit the game
						gameexit = true;
					}
					else {
						cout << "enter a number: ";
						cin >> num;

						if (num == quit) {//checks to see whether the user would like to quit the game
							gameexit = true;
						}
						else {

							if (num == solution[rownum][colnum] && board[rownum][colnum] == 0) {//if the yser's number is equal to the number in the solution grid then the user's number would be placed into the grid that is for the user
								board[rownum][colnum] = num;
							}

							displayArray(board);

							//check to find out if the grid is completed

							completegame = checkGameArray(board);

							//if the game is completed the console will output the following

							if (completegame == true) {
								//Display a congratulatory message, identifying the player by name.
								cout << "Congratulations!! Player: " << name << " has won the game.";
								//	� Display a message showing that the player�s score(20 �(number of hints * 2n
								cout << name << " has scored " << score << " points.";
								//	� Ask the user if they would like to play another gameand present a different puzzle if
								//	they choose �yes� or quit the game if they choose �no�.
								gameexit = true;
							}

							else
							{
								//requests the user to decide if the
								cout << "enter 'n' for a hint or any character to continue: ";
								cin >> requesthint;
								if ((requesthint == 'n' || requesthint == 'N') && hint == 2) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 2) {
												board[i][j] = solution[i][j];
												hint--;
												play.setScore(18);
											}
										}
									}
								}
								else if ((requesthint == 'n' || requesthint == 'N') && hint == 1) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 1) {
												board[i][j] = solution[i][j];
												hint = 0;
												play.setScore(0);
												gameexit = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//end of the while loop for the rookie game
			while (gameexit == false || hint != 0);

			if (quitgame == true || hint == 0) {

				cout << "Game Over.";
				cout << "Player " << play.printName() << " has obtained " << play.getScore() << " points for this game.";

				displayArray(solution);
			}
		}
		else if (gametype == 'T' || gametype == 't') {

			//Removes 15 digits from the grid which would serve and the grid for the user to enter their numbers
			removeNumbers(board, 15);
			//Displays the grid to the user
			displayArray(board);
			//Asks user for input and places in the numbers
			do {
				cout << "enter a row: ";
				cin >> rownum;
				if (rownum == quit) {//checks to see whether the user would like to quit the game
					gameexit = true;//
				}
				else {
					cout << "enter a col: ";
					cin >> colnum;
					if (colnum == quit) {//checks to see whether the user would like to quit the game
						gameexit = true;
					}
					else {
						cout << "enter a number: ";
						cin >> num;
						if (num == quit) {//checks to see whether the user would like to quit the game
							gameexit = true;
						}
						else {
							if (num == solution[rownum][colnum] && board[rownum][colnum] == 0) {//if the yser's number is equal to the number in the solution grid then the user's number would be placed into the grid that is for the user
								board[rownum][colnum] = num;
							}
							displayArray(board);
							//check to find out if the grid is completed
							completegame = checkGameArray(board);
							//if the game is completed the console will output the following
							if (completegame == true) {
								//Display a congratulatory message, identifying the player by name.
								cout << "Congratulations!! Player: " << name << " has won the game.";
								//	� Display a message showing that the player�s score(20 �(number of hints * 2n
								cout << name << " has scored " << score << " points.";
								//	� Ask the user if they would like to play another gameand present a different puzzle if
								//	they choose �yes� or quit the game if they choose �no�.
								gameexit = true;
							}
							else
							{
								//requests the user to decide if they want is hint
								cout << "enter 'n' for a hint or any a character to continue: ";
								cin >> requesthint;
								if ((requesthint == 'n' || requesthint == 'N') && hint == 3) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 3) {
												board[i][j] = solution[i][j];
												hint--;
												score -= 2;
											}
										}
									}
								}
								else if ((requesthint == 'n' || requesthint == 'N') && hint == 2) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 2) {
												board[i][j] = solution[i][j];
												hint--;
												score -= 2;
											}
										}
									}
								}
								else if ((requesthint == 'n' || requesthint == 'N') && hint == 1) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 1) {
												board[i][j] = solution[i][j];
												hint = 0;
												score = 0;
												gameexit = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//end of the while loop for the tuff tong game
			while (gameexit == false || hint != 0);

			if (quitgame == true || hint == 0) {

				cout << "Game Over.";
				cout << "Player " << name << " has obtained " << score << " points for this game.";

				for (int i = 0; i < 6; i++) {// displays the updated grid
					for (int j = 0; j < 6; j++) {
						if (j == 5) {
							cout << solution[i][j] << endl;
						}
						else
							cout << solution[i][j] << "|";
					}
					if (i != 5)
						cout << "-----------" << endl;
				}
			}
			//endwhile
		}
		else if (gametype == 'H' || gametype == 'h') {

			//Removes 15 digits from the grid which would serve and the grid for the user to enter their numbers
			removeNumbers(board,20);
			//Displays the grid to the user
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (j == 5) {
						cout << board[i][j] << endl;
					}
					else
						cout << board[i][j] << "|";//Separate the numbers in the row of the grid
				}
				if (i != 5)
					cout << "-----------" << endl;//Separate the rows in the grid
			}
			//Asks user for input and places in the numbers
			do {
				cout << "enter a row: ";
				cin >> rownum;
				if (rownum == quit) {//checks to see whether the user would like to quit the game
					gameexit = true;
					quitgame = true;
					score = 0;
				}
				else {
					cout << "enter a col: ";
					cin >> colnum;
					if (colnum == quit) {//checks to see whether the user would like to quit the game
						gameexit = true;
						quitgame = true;
						score = 0;
					}
					else {
						cout << "enter a number: ";
						cin >> num;
						if (num == quit) {//checks to see whether the user would like to quit the game
							gameexit = true;
							quitgame = true;
							score = 0;
						}
						else {
							if (num == solution[rownum][colnum] && board[rownum][colnum] == 0) {//if the yser's number is equal to the number in the solution grid then the user's number would be placed into the grid that is for the user
								board[rownum][colnum] = num;
							}
							for (int i = 0; i < 6; i++) {// displays the updated grid
								for (int j = 0; j < 6; j++) {
									if (j == 5) {
										cout << board[i][j] << endl;
									}
									else
										cout << board[i][j] << "|";
								}
								if (i != 5)
									cout << "-----------" << endl;
							}
							//check to find out if the grid is completed
							for (int i = 0; i < 6; i++) {
								for (int j = 0; j < 6; j++) {
									if (board[i][j] == 0) {
										completegame = false;
									}
									else {
										completegame = true;
									}
								}
							}
							//if the game is completed the console will output the following
							if (completegame == true) {
								//Display a congratulatory message, identifying the player by name.
								cout << "Congratulations!! Player: " << name << " has won the game.";
								//	� Display a message showing that the player�s score(20 �(number of hints * 2n
								cout << name << " has scored " << score << " points.";
								//	� Ask the user if they would like to play another gameand present a different puzzle if
								//	they choose �yes� or quit the game if they choose �no�.
								gameexit = true;
							}
							else
							{
								//requests the user to decide if they want is hint
								cout << "enter 'n' for a hint or and another character to continue: ";
								cin >> requesthint;
								if ((requesthint == 'n' || requesthint == 'N') && hint == 4) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 4) {
												board[i][j] = solution[i][j];
												hint--;
												score -= 2;
											}
										}
									}
								}
								else if ((requesthint == 'n' || requesthint == 'N') && hint == 3) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 3) {
												board[i][j] = solution[i][j];
												hint--;
												score -= 2;
											}
										}
									}
								}
								else if ((requesthint == 'n' || requesthint == 'N') && hint == 2) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 2) {
												board[i][j] = solution[i][j];
												hint--;
												score -= 2;
											}
										}
									}
								}
								else if ((requesthint == 'n' || requesthint == 'N') && hint == 1) {
									for (int i = 0; i < 6; i++) {
										for (int j = 0; j < 6; j++) {
											if ((board[i][j] == 0) && hint == 1) {
												board[i][j] = solution[i][j];
												hint = 0;
												score = 0;
												gameexit = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			//end of the while loop for the tuff tong game
			while (gameexit == false || hint == 0);

			if (quitgame == true || hint == 0) {

				cout << "Game Over.";
				cout << "Player " << name << " has obtained " << score << " points for this game.";

				for (int i = 0; i < 6; i++) {// displays the updated grid
					for (int j = 0; j < 6; j++) {
						if (j == 5) {
							cout << solution[i][j] << endl;
						}
						else
							cout << solution[i][j] << "|";
					}
					if (i != 5)
						cout << "-----------" << endl;
				}
			}
			//endwhile

		}

		//Asks the user if they would like to play another game:
		cout << "Would you like to play another game: ";
		cin >> endgame;

	} while (endgame != "No" || endgame != "no" || endgame != "NO");

	cout << "Thank you for playing!!";

	return 0;
}

void removeNumbers(int A[][6], int amount) {
	int count(0), randnum(0);
	while (count != amount) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				randnum = rand() % 6 + 1;
				if ((randnum == A[i][j]) && count < amount) {
					A[i][j] = 0;
					count++;
				}
			}
		}
	}
}

void displayArray(int A[][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j == 5) {
				cout << A[i][j] << endl;
			}
			else
			{
				cout << A[i][j] << "|";
			}
		}
		if (i != 5) {
			cout << "---------" << endl;
		}
	}
}

void setGameArray(int A[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			A[i][j] = rand() % 6 + 1;
		row://to check for any duplicate numbers
			for (int k = 0; k < j; k++) {
				while (A[i][j] == A[i][k]) {
					A[i][j] = rand() % 6 + 1;
					goto row;
				}
			}

			for (int h = 0; h < i; h++) {
				while (A[i][j] == A[h][j]) {
					A[i][j] = rand() % 6 + 1;
					goto row;
				}
			}
		}
	}
}

void setArray(int A[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			A[i][j] = 0;
		}
	}
}

bool checkGameArray(int A[][6]) {
	bool gameState;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (A[i][j] == 0) {
				gameState = false;
			}
			else {
				gameState = true;
			}
		}
	}
	return gameState;
}