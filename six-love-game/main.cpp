#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"

using std::cout, std::cin, std::endl, std::string, std::getline;

void intro(string);

int main(){

	string name;
	cout<<"Player enter your name: ";
	getline(cin, name);

	//Welcome message and rules of the game
	intro(name);
	system("pause");
	cout << endl;

	Player player(name); Game game;
	const int quit = 99; int short board[6][6] = { 0 }, solution[6][6] = { 0 };
	
	enum Status {WON, LOST, CONTINUE,QUIT,RETRY,END, UNDEFINED};
	enum Level {ROOKIE, TUFFTONG,HARDSEED};
	
	Status gameStatus = CONTINUE;
	Level gameLevel;
	//start of the game
	
	do
	{
		//initalizies the score and hints before each game level
		player.setHintsAndScore();

		bool exitgame = false, checkGame = false, quitgame = false; char requesthint; int short row_number, column_number, player_number(0); string gamelevel;

		do
		{
			//gets the game level
			cout << "Enter the level of game you would like to play: ";
			getline(cin, gamelevel);
			cout << endl;

			switch(game.stringToGame(gamelevel)){
				case 2:
					gameLevel = Level::ROOKIE;
					break;
				case 3:
					gameLevel = Level::TUFFTONG;
					break;
				case 4:
					gameLevel = Level::HARDSEED;
					break;	
				case 5:
					gameStatus = Status::LOST;
					player.endGame();
					cout<<"You have quit the game.";
					break;
				default:
					gameStatus = Status::UNDEFINED;
					cout<<"There is no level for your selection.";
					break;
				}
		} while (gameStatus == Status::UNDEFINED);
		
			
	
		switch(gameLevel){
			case ROOKIE:
				{
				int short hintcounter(0);
				//set the array for the game
				game.setGameArray(solution);
				//makes a copy of the solution
				game.copyGameArray(solution, board);
				//removes the elements of the array
				game.removeNumbers(board, 10);
				//Displays the array to the user
				game.displayArray(board);
				cout << endl;

				//Asks the player for input and places in the numbers in the array or if they would like to quit
				do
				{
				cout << "Enter a row number: ";
				cin >> row_number;

				//checks to see whether the user would like to quit the game
				if (row_number == quit)
				{
					gameStatus = Status::QUIT; player.endGame();
				}

				else
				{
					cout << "Enter a column number: ";
					cin >> column_number;

					//checks to see whether the user would like to quit the game
					if (column_number == quit)
					{
						gameStatus = Status::QUIT; player.endGame();
					}

					else
					{
						cout << "Enter a number for entry: ";
						cin >> player_number;

						//checks to see whether the user would like to quit the game
						if (player_number == quit)
						{
							gameStatus = Status::QUIT; player.endGame();
						}

						else
						{
							if ((row_number > 6 || row_number < 1) || (column_number > 6 || column_number < 1))
							cout << "The entry at row: " << row_number << " and column: " << column_number << " doesnt exsit. Try again. :(" << endl;

							//check if the user entry and the location that the player intend, match and assigns the location that entry
							else if (player_number == solution[row_number - 1][column_number - 1] && board[row_number - 1][column_number - 1] == 0)
							{
								board[row_number - 1][column_number - 1] = player_number;
								cout << "Your entry was correct!! :)" << endl;
							}

							//check if the user is attempting to fill a location that is filled already
							else if (board[row_number - 1][column_number - 1] != 0)
								cout << "The entry at row: " << row_number << " and column: " << column_number << " is already filled. Try again." << endl;

							//displays a message if the user attempt was unsuccessful
							else
								cout << "The number you entered was not correct. :(" << endl;
								cout << endl << "Updated Grid: " << endl;
								game.displayArray(board);
								cout << endl;

								//check if the grid is completed and display the congratulatory message 
								if (game.checkGameArray(board) == true)
								{
									cout << "Congratulations!! Player: " << player.getName() << " has won the game,\n";
									cout << "and has scored " << player.getScore() << " points at Rookie level.\n";
									gameStatus = Status::WON;
								}

								else
								{
									//requests the user to decide if they would like a hint or quit the game
									cout << "Enter 'H' for a hint, or 'Q' for quit or any OTHER character to continue: ";
									cin >> requesthint;

									//ends the game if the user quits
									if (requesthint == 'Q' || requesthint == 'q')
									{
										gameStatus = Status::QUIT; player.endGame();
									}

									else if (requesthint == 'H' || requesthint == 'h')
									{
										//ends the game if the user requests more than the allowed amount of hints
										if (player.getRookieHint() == 1)
										{
											player.endGame(); gameStatus = Status::LOST;
										}

										//adds one hint to the game if the user requests a hint
										else
										{
											for (int i = 0; i < 6; i++)
											{
												for (int j = 0; j < 6; j++)
												{
													if ((board[i][j] == 0) && player.getRookieHint() == 2)
													{
														board[i][j] = solution[i][j];
														hintcounter++;
														player.decreaseScore(hintcounter);
														player.requestHint();
													}
												}
											}

											//display the grid with the added hint
											cout << endl << "Updated Grid: " << endl;
											game.displayArray(board);
											cout << endl;

											//check if the grid is completed and display the congratulatory message 
											if (game.checkGameArray(board) == true)
											{
												cout << "Congratulations!! Player: " << player.getName() << " has won the game,\n";
												cout << "and has scored " << player.getScore() << " points at Rookie level.\n";
												gameStatus = Status::WON;
											}
										}
									}
								}
							}
						}
					}
				}
				//end of the while loop for the rookie game entries
				while (gameStatus = Status::CONTINUE);
				}//end rookie switch statement

			case TUFFTONG:
				{
						int hintcounter(0);
						//set the array for the game
						game.setGameArray(solution);
						//makes a copy of the solution
						game.copyGameArray(solution, board);
						//removes the elements of the array
						game.removeNumbers(board, 15);
						//Displays the array to the user
						game.displayArray(board);
						cout << endl;

						//Asks the player for input and places in the numbers in the array if they match
						do
						{
							cout << "Enter a row number: ";
							cin >> row_number;

							//checks to see whether the user would like to quit the game
							if (row_number == quit)
							{
								gameStatus = Status::QUIT; player.endGame();
							}

							else
							{
								cout << "Enter a column number: ";
								cin >> column_number;

								//checks to see whether the user would like to quit the game
								if (column_number == quit)
								{
									gameStatus = Status::QUIT; player.endGame();
								}

								else
								{
									cout << "Enter a number for entry: ";
									cin >> player_number;

									//checks to see whether the user would like to quit the game
									if (player_number == quit)
									{
										gameStatus = Status::QUIT; player.endGame();
									}

									else
									{
										if ((row_number > 6 || row_number < 1) || (column_number > 6 || column_number < 1))
											cout << "The entry at row: " << row_number << " and column: " << column_number << " doesnt exsit. Try again. :(" << endl;

										//check if the user entry and the location that the player intend, match and assigns the location that entry
										else if (player_number == solution[row_number - 1][column_number - 1] && board[row_number - 1][column_number - 1] == 0)
										{
											board[row_number - 1][column_number - 1] = player_number;
											cout << "Your entry was correct!! :)" << endl;
										}

										//check if the user is attempting to fill a location that is filled already
										else if (board[row_number - 1][column_number - 1] != 0)
											cout << "The entry at row: " << row_number << " and column: " << column_number << " is already filled. Try again." << endl;

										//displays a message if the user attempt was unsuccessful
										else
											cout << "The number you entered was not correct. :(" << endl;

										cout << endl << "Updated Grid: " << endl;
										game.displayArray(board);
										cout << endl;

										//check if the grid is completed and display the congratulatory message 
										if (game.checkGameArray(board) == true)
										{
											cout << "Congratulations!! Player: " << player.getName() << " has won the game,\n";
											cout << "and has scored " << player.getScore() << " points at Tuff Tong level.\n";
											gameStatus = Status::WON;
										}

										else
										{
											//requests the user to decide if they would like a hint or quit the game
											cout << "Enter 'H' for a hint, or 'Q' for quit or any OTHER character to continue: ";
											cin >> requesthint;

											//ends the game if the user quits
											if (requesthint == 'Q' || requesthint == 'q')
											{
												gameStatus = Status::QUIT; player.endGame();
											}

											else if (requesthint == 'H' || requesthint == 'h')
											{
												//ends the game if the user requests more than the allowed amount of hints
												if (player.getTuffTongHint() == 1)
												{
													player.endGame(); gameStatus = Status::LOST;
												}

												//adds one hint to the game if the user requests a hint
												else
												{
													for (int i = 0; i < 6; i++)
													{
														for (int j = 0; j < 6; j++)
														{
															if ((board[i][j] == 0) && player.getTuffTongHint() > 1)
															{
																board[i][j] = solution[i][j];
																player.requestHint();
																hintcounter++;
																player.decreaseScore(hintcounter);
																//to exit the nested for loops when an entry in added to the player's grid
																goto exittufftong;
															}
														}
													}

												exittufftong:

													//display the grid with the added hint
													cout << endl << "Updated Grid: " << endl;
													game.displayArray(board);
													cout << endl;

													//check if the grid is completed and display the congratulatory message 
													if (game.checkGameArray(board) == true)
													{
														cout << "Congratulations!! Player: " << player.getName() << " has won the game,\n";
														cout << "and has scored " << player.getScore() << " points at Tuff Tong level.\n";
														gameStatus = Status::WON;
													}
												}
											}
										}
									}
								}
							}
						}
						//end of the while loop for the tuff tong game entries
						while (gameStatus = Status::CONTINUE);
					}//end tuff tong if statement

			case HARDSEED:
				{
						int hintcounter(0);
						//initialize the solution array

						//set the array for the game
						game.setGameArray(solution);
						//makes a copy of the solution
						game.copyGameArray(solution, board);
						//removes the elements of the array
						game.removeNumbers(board, 20);
						//Displays the array to the user
						game.displayArray(board);
						cout << endl;


						//Asks the player for input and places in the numbers in the array if they match
						do
						{
							cout << "Enter a row number: ";
							cin >> row_number;

							//checks to see whether the user would like to quit the game
							if (row_number == quit)
							{
								gameStatus = Status::QUIT; player.endGame();
							}

							else
							{
								cout << "Enter a column number: ";
								cin >> column_number;

								//checks to see whether the user would like to quit the game
								if (column_number == quit)
								{
									gameStatus = Status::QUIT; player.endGame();
								}

								else
								{
									cout << "Enter a number for entry: ";
									cin >> player_number;

									//checks to see whether the user would like to quit the game
									if (player_number == quit)
									{
										gameStatus = Status::QUIT; player.endGame();
									}

									else
									{
										if ((row_number > 6 || row_number < 1) || (column_number > 6 || column_number < 1))
											cout << "The entry at row: " << row_number << " and column: " << column_number << " doesnt exsit. Try again. :(" << endl;

										//check if the user entry and the location that the player intend, match and assigns the location that entry
										else if (player_number == solution[row_number - 1][column_number - 1] && board[row_number - 1][column_number - 1] == 0)
										{
											board[row_number - 1][column_number - 1] = player_number;
											cout << "Your entry was correct!! :)" << endl;
										}

										//check if the user is attempting to fill a location that is filled already
										else if (board[row_number - 1][column_number - 1] != 0)
											cout << "The entry at row: " << row_number << " and column: " << column_number << " is already filled. Try again. :(" << endl;

										//displays a message if the user attempt was unsuccessful
										else
											cout << "The number you entered was not correct. :(" << endl;

										cout << endl << "Updated Grid: " << endl;
										game.displayArray(board);
										cout << endl;

										//check if the grid is completed and display the congratulatory message 
										if (game.checkGameArray(board) == true)
										{
											cout << "Congratulations!! Player: " << player.getName() << " has won the game,\n";
											cout << "and has scored " << player.getScore() << " points at Hard Seed level. :)\n";
											gameStatus = Status::WON;
										}

										else
										{
											//requests the user to decide if they would like a hint or quit the game
											cout << "Enter 'H' for a hint, or 'Q' for quit or any OTHER character to continue: ";
											cin >> requesthint;

											//ends the game if the user quits
											if (requesthint == 'Q' || requesthint == 'q')
											{
												exitgame = true; quitgame = true; player.endGame();
											}

											else if (requesthint == 'H' || requesthint == 'h')
											{
												//ends the game if the user requests more than the allowed amount of hints
												if (player.getHardSeedHint() == 1)
												{
													player.endGame(); gameStatus = Status::LOST;
												}
												else
												{
													//adds one hint to the game if the user requests a hint
													for (int i = 0; i < 6; i++)
													{
														for (int j = 0; j < 6; j++)
														{
															if ((board[i][j] == 0) && player.getHardSeedHint() > 1)
															{
																board[i][j] = solution[i][j];
																player.requestHint();
																hintcounter++;
																player.decreaseScore(hintcounter);
																//to exit the nested for loops when an entry in added to the player's grid
																goto exithardseed;
															}
														}
													}

												exithardseed:

													//display the grid with the added hint
													cout << endl << "Updated Grid: " << endl;
													game.displayArray(board);
													cout << endl;

													//check if the grid is completed and display the congratulatory message 
													if (game.checkGameArray(board) == true)
													{
														cout << "Congratulations!! Player: " << player.getName() << " has won the game,\n";
														cout << "and has scored " << player.getScore() << " points at Hard Seed level.\n";
														gameStatus = Status::WON;
													}
												}
											}
										}
									}
								}
							}
						}
						//end of the while loop for the hard seed game entries
						while (gameStatus == Status::CONTINUE);
					}//end hard seed if statement
			default:
				cout<<"There is no level for your selection.";
				break;
			}

		//Display a messeage if the player quits or exhausted all of their hints
		if (gameStatus == Status::QUIT || player.getRookieHint() == 0 || player.getTuffTongHint() == 0 || player.getHardSeedHint() == 0)
		{
			cout << endl;
			cout << "Game Over.\n";
			cout << "Player " << player.getName() << " has obtained " << player.getScore() << " points for this game. :(\n";
			cout << endl << "Solution: " << endl;
			game.displayArray(solution);
			cout << endl;
		}

		do
		{
				//Asks the user if they would like to play another game:
			string endgame;
			cout << "Would you like to play another game: ";
			getline(cin, endgame);
			cout << endl;

			switch(endgame){
				case "yes":
				case "YES":
				case "y":
				case "Y":
					gameStatus = Status::RETRY;
				case "no":
				case "NO":
				case "n":
				case "N":
					gameStatus = Status::END;
				default:
					cout<<"Please enter (yes/no)"<<endl;
			}
		} while (gameStatus != Status::RETRY || gameStatus != Status::END);
		
	} while (gameStatus == Status::RETRY);

	//Exit message
	cout << "Thank you for playing this game of SIX LOVE !!\n";

	return 0;
}

void intro(string name){
	cout << "Welcome "<<name<<" to the game of SIX LOVE!!"<<endl<<
	"This game features a 6x6 grid where, the elements in the grid range from 1 to 6."<<endl<<
	"Each row and column has only one instant of each digit."<<endl<<endl<<
	"This game has three levels:\n   (1) Rookie \n   (2) Tuff Tong \n   (3) Hard Seed"<<endl<<endl<<
	"Rules:"<<endl<<endl<<"To choose a level you must enter the first letter that corresponds to intended level (i.e. 'r' or 'R' for Rookie)."<<endl<<
	"To play successfully you are required to enter a row number from 1 to 6 (inlcusive)," <<endl<<
    "similarly with column number and your input, to fill the slots that have zeros."<<endl<<endl<<
	"At any prompt during the game you can quit by entering the number '99'."<<endl<<
	"HOWEVER, DO NOT ENTER A NUMBER WHEN PROMPT FOR A HINT, INSTEAD ENTER THE LETTER 'Q'"<<endl<<endl<<
	"Rookie has a maximum of 1 hint, Tuff Tong has a maximum of 2 hints and Hard Seed has a maximum of 3 hints."<<endl<<
	"Request any higher than the amount allotted for each level, the game will end and you will be awarded zero points."<<endl<<endl<<"Enjoy the game!!"<<endl<<endl;
}