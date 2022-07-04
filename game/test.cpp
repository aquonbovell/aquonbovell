#include <iostream>
#include <limits>
#include "Game.h"

using std::cout, std::cin, std::endl, std::string, std::getline;

int main()
{
	std::string name, level;
	size_t age, row_number, column_number, number;
	bool invalidRowNumber, invalidColumnNumber, invalidPlayerNumber;
	char requesthint;

	cout << "Enter your name: ";
	std::getline(std::cin, name);
	cout << "Enter your age: ";
	std::cin >> age;

	// Displays the welcome message and rules of the game and initialises all data-members of the Player's class
	Game game(name, age);

	do
	{
		cout << "Enter the level you would like to play: ";
		std::getline(std::cin >> std::ws, level);
		switch (game.stringToLevel(level))
		{
		case 1:
			game.level = game.Level::ROOKIE;
			game.status = game.Status::CONTINUE;
			break;
		case 2:
			game.level = game.Level::TUFFTONG;
			game.status = game.Status::CONTINUE;
			break;
		case 3:
			game.level = game.Level::HARDSEED;
			game.status = game.Status::CONTINUE;
			break;
		case 4:
			game.status = game.Status::QUIT;
			cout << "Quitting... \nSad to see you go." << endl;
			break;
		default:
			game.status = game.Status::UNDEFINED;
			cout << "There is no level with your selection.\nRetry please." << endl;
		}
	} while (game.status == game.Status::UNDEFINED);

	game.reset();
	game.createGame(game.solutionArray);
	game.createCopy(game.solutionArray, game.playerArray);

	switch (game.level)
	{
	case game.Level::ROOKIE:
		game.removeSlots(game.playerArray, 10);
		game.displayArray(game.playerArray);
		cout << endl;
		do
		{
			do
			{
				while (std::cout << "Enter a row number: " && !(std::cin >> row_number))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
					std::cout << "Invalid input." << endl
										<< " Please re-enter." << endl;
				}
				row_number--;
				switch (row_number)
				{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					invalidRowNumber = false;
					do
					{
						while (std::cout << "Enter a column number: " && !(std::cin >> column_number))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
							std::cout << "Invalid input." << endl
												<< " Please re-enter." << endl;
						}
						column_number--;

						switch (column_number)
						{
						case 0:
						case 1:
						case 2:
						case 3:
						case 4:
						case 5:
							invalidColumnNumber = false;
							do
							{
								while (std::cout << "Enter a number: " && !(std::cin >> number))
								{
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
									std::cout << "Invalid input." << endl
														<< " Please re-enter." << endl;
								}

								switch (number)
								{
								case 1:
								case 2:
								case 3:
								case 4:
								case 5:
								case 6:
									invalidPlayerNumber = false;
									if (game.isFilled(game.playerArray, row_number, column_number))
									{
										cout << "This slot is filled!!\nSelect another slot to fill." << endl;
									}
									else if (game.isInputCorrect(game.solutionArray, game.playerArray, row_number, column_number, number))
									{
										cout << "Your entry was correct!! :)" << endl;
									}
									else
										cout << "Your entry was not correct!! :(" << endl;

									game.displayArray(game.playerArray);

									if (game.isCompleted(game.playerArray))
									{
										cout << "Congratulations!! " << game.getName() << " has won the game," << endl
												 << "and has scored " << game.getScore() << " points at Rookie level." << endl;
										game.status = game.Status::WON;
									}
									else
									{
										do
										{
											cout << "Enter 'H' for a hint, or 'Q' for quit or 'C' to continue: ";
											cin >> requesthint;
											switch (requesthint)
											{
											case 'H':
											case 'h':
												if (game.getRookieHint() == 1)
												{
													game.endGame();
													game.status = game.Status::LOST;
												}
												else
												{
													game.addHint(game.level);
													game.displayArray(game.playerArray);
												}

												if (game.isCompleted(game.playerArray))
												{
													cout << "Congratulations!! " << game.getName() << " has won the game," << endl
															 << "and has scored " << game.getScore() << " points at Rookie level." << endl;
													game.status = game.Status::WON;
												}
												break;
											case 'Q':
											case 'q':
												game.endGame();
												game.status = game.Status::QUIT;
												break;
											case 'C':
											case 'c':
												break;
											default:
												requesthint = 'N';
												cout << "There is no option for your selection.\nRetry please.";
												break;
											}
										} while (requesthint == 'N');
									}
									break;
								case 10:
									game.status = game.Status::QUIT;
									game.endGame();
									invalidPlayerNumber = false;
									break;
								default:
									invalidPlayerNumber = true;
									cout << "There is no option for your selection.\nRetry please.";
									break;
								}
							} while (invalidPlayerNumber);
							// player num
							break;
						case 10:
							invalidColumnNumber = false;
							game.status = game.Status::QUIT;
							game.endGame();
							break;
						default:
							invalidColumnNumber = true;
							cout << "There is no option for your selection.\nRetry please.";
							break;
						}
					} while (invalidColumnNumber); // col num
					break;
				case 10:
					invalidRowNumber = false;
					game.status = game.Status::QUIT;
					game.endGame();
					break;
				default:
					invalidRowNumber = true;
					cout << "There is no option for your selection.\nRetry please.";
					break;
				}
			} while (invalidRowNumber); // row num
		} while (game.status == game.Status::CONTINUE);
		break; // end rookie switch statement
	default:
		break;
	}

	// Status statusOfTheGame = Status::CONTINUE; Level levelOfTheGame;
	// do
	// {
	// 	//initalizies and re-initalises the score and hints before each game level
	// 	testPlayer.setHintsAndScore(); char requesthint; int short row_number, column_number, player_number{0}, hintcounter{0}; bool invalidPlayerNumber{false}, invalidColumnNumber{false}, invalidRowNumber {false};
	// 	std::string gameLevel;

	// 	do{
	// 		cout << "Enter the game level you would like to play: "; getline(cin, gameLevel);

	// 		switch (testPlayer.stringToGame(gameLevel))
	// 		{
	// 		case 20:
	// 			levelOfTheGame = Level::ROOKIE; statusOfTheGame = Status::CONTINUE;
	// 			break;
	// 		case 21:
	// 			levelOfTheGame = Level::TUFFTONG; statusOfTheGame = Status::CONTINUE;
	// 			break;
	// 		case 22:
	// 			levelOfTheGame = Level::HARDSEED; statusOfTheGame = Status::CONTINUE;
	// 			break;
	// 		case 50:
	// 			statusOfTheGame = Status::QUIT; testPlayer.endGame();
	// 			cout << "You have quit the game. Sad to see you go."<<endl;
	// 			break;
	// 		default:
	// 			statusOfTheGame = Status::UNDEFINED;
	// 			cout << "Your selection is invalid."<<endl;
	// 		}
	// 	} while(statusOfTheGame == Status::UNDEFINED);

	// 	switch (levelOfTheGame){
	// 		case ROOKIE:
	// 			testPlayer.removeNumbers(10); testPlayer.displayPlayersBoard(); cout << endl;
	// 			do
	// 			{
	// 				do
	// 				{
	// 					while (std::cout << "Enter a row number: " && !(std::cin >> row_number) ){
	// 						std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 						std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 						}
	// 					row_number--;
	// 					switch (row_number)
	// 					{
	// 					case 0:case 1:case 2:case 3:case 4:case 5:
	// 						invalidRowNumber = false;
	// 						do
	// 						{
	// 							while (std::cout << "Enter a column number: " && !(std::cin >> column_number) ){
	// 							std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 							std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 							}
	// 							column_number--;

	// 							switch(column_number){
	// 								case 0:case 1:case 2:case 3:case 4:case 5:
	// 								invalidColumnNumber = false;
	// 									do
	// 									{
	// 										while (std::cout << "Enter a number: " && !(std::cin >> player_number) ){
	// 											std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 											std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 										}

	// 										switch(player_number){
	// 											case 1:case 2:case 3:case 4:case 5:case 6:
	// 												invalidPlayerNumber=false;
	// 												if (testPlayer.checkIfBoardIsFilled(row_number,column_number)){
	// 													cout << "This slot is filled!! :("<<endl;
	// 												}
	// 												else if (testPlayer.checkBoard(row_number,column_number,player_number)){
	// 													cout<< "Your entry was correct!! :)"<<endl;
	// 												}else if (!testPlayer.checkBoard(row_number,column_number,player_number)){
	// 													cout<< "Your entry was not correct!! :("<<endl;
	// 												}
	// 												testPlayer.displayPlayersBoard();

	// 												if (testPlayer.checkPlayersBoard()){
	// 													cout << "Congratulations!! Player: " << testPlayer.getName() << " has won the game,"<<endl
	// 														<<"and has scored " << testPlayer.getScore() << " points at Rookie level."<<endl;
	// 													statusOfTheGame = Status::WON;
	// 												}
	// 												else
	// 												{
	// 													do{
	// 														cout << "Enter 'H' for a hint, or 'Q' for quit or 'C' to continue: ";
	// 														cin >> requesthint;
	// 														switch(requesthint){
	// 															case 'H':case 'h':
	// 																if (testPlayer.getRookieHint() == 1){
	// 																	testPlayer.endGame(); statusOfTheGame = Status::LOST;
	// 																}
	// 																else{
	// 																	testPlayer.giveAHint(hintcounter); testPlayer.displayPlayersBoard();
	// 																}

	// 																if (testPlayer.checkPlayersBoard()){
	// 																	cout << "Congratulations!! Player: " << testPlayer.getName() << " has won the game,"<<endl
	// 																	<<"and has scored " << testPlayer.getScore() << " points at Rookie level."<<endl;
	// 																	statusOfTheGame = Status::WON;
	// 																}
	// 																break;
	// 															case 'Q':case 'q':
	// 																testPlayer.endGame(); statusOfTheGame = Status::LOST;
	// 																break;
	// 															case 'C':case 'c':
	// 																break;
	// 															default:
	// 																requesthint='N'; cout<< "Invalid selection.";
	// 																break;
	// 														}
	// 													}while (requesthint=='N');
	// 												}
	// 												break;
	// 											case 50:
	// 												statusOfTheGame = Status::QUIT; testPlayer.endGame(); invalidPlayerNumber = false;
	// 												break;
	// 											default:
	// 												cout<< "Invalid selection.";
	// 												invalidPlayerNumber = true;
	// 												break;
	// 											}
	// 									}while (invalidPlayerNumber);
	// 									//player num
	// 									break;
	// 								case 50:
	// 								invalidColumnNumber = false;
	// 									statusOfTheGame = Status::QUIT;
	// 									testPlayer.endGame();
	// 								break;
	// 							default:
	// 								invalidColumnNumber = true;
	// 								cout<< "Invalid selection.";
	// 								break;
	// 							}
	// 						} while (invalidColumnNumber);//col num
	// 						break;
	// 					case 50:
	// 						invalidRowNumber = false;
	// 						statusOfTheGame = Status::QUIT;
	// 						testPlayer.endGame();
	// 						break;
	// 					default:
	// 						invalidRowNumber = true;
	// 						cout<< "Invalid selection.";
	// 						break;
	// 					}
	// 				}while(invalidRowNumber);//row num
	// 			}while (statusOfTheGame == Status::CONTINUE);
	// 			break; // end rookie switch statement
	// 		case TUFFTONG:
	// 			testPlayer.removeNumbers(15); testPlayer.displayPlayersBoard(); cout << endl;
	// 			// Asks the player for input
	// 			do
	// 			{
	// 				do
	// 				{
	// 					while (std::cout << "Enter a row number: " && !(std::cin >> row_number) ){
	// 						std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 						std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 						}
	// 					row_number--;
	// 					switch (row_number)
	// 					{
	// 					case 0:case 1:case 2:case 3:case 4:case 5:
	// 						invalidRowNumber = false;
	// 						do
	// 						{
	// 							while (std::cout << "Enter a column number: " && !(std::cin >> column_number) ){
	// 							std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 							std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 							}
	// 							column_number--;

	// 							switch(column_number){
	// 								case 0:case 1:case 2:case 3:case 4:case 5:
	// 								invalidColumnNumber = false;
	// 									do
	// 									{
	// 										while (std::cout << "Enter a number: " && !(std::cin >> player_number) ){
	// 											std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 											std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 										}

	// 										switch(player_number){
	// 											case 1:case 2:case 3:case 4:case 5:case 6:
	// 												invalidPlayerNumber=false;
	// 												if (testPlayer.checkIfBoardIsFilled(row_number,column_number)){
	// 													cout << "This slot is filled!! :("<<endl;
	// 												}
	// 												else if (testPlayer.checkBoard(row_number,column_number,player_number)){
	// 													cout<< "Your entry was correct!! :)"<<endl;
	// 												}else if (!testPlayer.checkBoard(row_number,column_number,player_number)){
	// 													cout<< "Your entry was not correct!! :("<<endl;
	// 												}
	// 												testPlayer.displayPlayersBoard();

	// 												if (testPlayer.checkPlayersBoard()){
	// 													cout << "Congratulations!! Player: " << testPlayer.getName() << " has won the game,"<<endl
	// 														<<"and has scored " << testPlayer.getScore() << " points at Rookie level."<<endl;
	// 													statusOfTheGame = Status::WON;
	// 												}
	// 												else
	// 												{
	// 													do{
	// 														cout << "Enter 'H' for a hint, or 'Q' for quit or 'C' to continue: ";
	// 														cin >> requesthint;
	// 														switch(requesthint){
	// 															case 'H':case 'h':
	// 																if (testPlayer.getTuffTongHint() == 1){
	// 																	testPlayer.endGame(); statusOfTheGame = Status::LOST;
	// 																}
	// 																else{
	// 																	testPlayer.giveAHint(hintcounter); testPlayer.displayPlayersBoard();
	// 																}

	// 																if (testPlayer.checkPlayersBoard()){
	// 																	cout << "Congratulations!! Player: " << testPlayer.getName() << " has won the game,"<<endl
	// 																	<<"and has scored " << testPlayer.getScore() << " points at Rookie level."<<endl;
	// 																	statusOfTheGame = Status::WON;
	// 																}
	// 																break;
	// 															case 'Q':case 'q':
	// 																testPlayer.endGame(); statusOfTheGame = Status::LOST;
	// 																break;
	// 															case 'C':case 'c':
	// 																break;
	// 															default:
	// 																requesthint='N'; cout<< "Invalid selection.";
	// 																break;
	// 														}
	// 													}while (requesthint=='N');
	// 												}
	// 												break;
	// 											case 50:
	// 												statusOfTheGame = Status::QUIT; testPlayer.endGame(); invalidPlayerNumber = false;
	// 												break;
	// 											default:
	// 												cout<< "Invalid selection.";
	// 												invalidPlayerNumber = true;
	// 												break;
	// 											}
	// 									}while (invalidPlayerNumber);
	// 									//player num
	// 									break;
	// 								case 50:
	// 									invalidColumnNumber = false;
	// 									statusOfTheGame = Status::QUIT;
	// 									testPlayer.endGame();
	// 								break;
	// 							default:
	// 								invalidColumnNumber = true;
	// 								cout<< "Invalid selection.";
	// 								break;
	// 							}
	// 						} while (invalidColumnNumber);//col num
	// 						break;
	// 					case 50:
	// 						invalidRowNumber = false;
	// 						statusOfTheGame = Status::QUIT;
	// 						testPlayer.endGame();
	// 						break;
	// 					default:
	// 						invalidRowNumber = true;
	// 						cout<< "Invalid selection.";
	// 						break;
	// 					}
	// 				}while(invalidRowNumber);//row num
	// 			}while (statusOfTheGame == Status::CONTINUE);
	// 			break; // end tufftong switch statement
	// 		case HARDSEED:
	// 			testPlayer.removeNumbers(20); testPlayer.displayPlayersBoard(); cout << endl;
	// 			do
	// 			{
	// 				do
	// 				{
	// 					while (std::cout << "Enter a row number: " && !(std::cin >> row_number) ){
	// 						std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 						std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 						}
	// 					row_number--;
	// 					switch (row_number)
	// 					{
	// 					case 0:case 1:case 2:case 3:case 4:case 5:
	// 						invalidRowNumber = false;
	// 						do
	// 						{
	// 							while (std::cout << "Enter a column number: " && !(std::cin >> column_number) ){
	// 							std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 							std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 							}
	// 							column_number--;

	// 							switch(column_number){
	// 								case 0:case 1:case 2:case 3:case 4:case 5:
	// 								invalidColumnNumber = false;
	// 									do
	// 									{
	// 										while (std::cout << "Enter a number: " && !(std::cin >> player_number) ){
	// 											std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	// 											std::cout << "Invalid input."<<endl<<" Please re-enter."<<endl;
	// 										}

	// 										switch(player_number){
	// 											case 1:case 2:case 3:case 4:case 5:case 6:
	// 												invalidPlayerNumber=false;
	// 												if (testPlayer.checkIfBoardIsFilled(row_number,column_number)){
	// 													cout << "This slot is filled!! :("<<endl;
	// 												}
	// 												else if (testPlayer.checkBoard(row_number,column_number,player_number)){
	// 													cout<< "Your entry was correct!! :)"<<endl;
	// 												}else if (!testPlayer.checkBoard(row_number,column_number,player_number)){
	// 													cout<< "Your entry was not correct!! :("<<endl;
	// 												}
	// 												testPlayer.displayPlayersBoard();

	// 												if (testPlayer.checkPlayersBoard()){
	// 													cout << "Congratulations!! Player: " << testPlayer.getName() << " has won the game,"<<endl
	// 														<<"and has scored " << testPlayer.getScore() << " points at Rookie level."<<endl;
	// 													statusOfTheGame = Status::WON;
	// 												}
	// 												else
	// 												{
	// 													do{
	// 														cout << "Enter 'H' for a hint, or 'Q' for quit or 'C' to continue: ";
	// 														cin >> requesthint;
	// 														switch(requesthint){
	// 															case 'H':case 'h':
	// 																if (testPlayer.getHardSeedHint() == 1){
	// 																	testPlayer.endGame(); statusOfTheGame = Status::LOST;
	// 																}
	// 																else{
	// 																	testPlayer.giveAHint(hintcounter); testPlayer.displayPlayersBoard();
	// 																}

	// 																if (testPlayer.checkPlayersBoard()){
	// 																	cout << "Congratulations!! Player: " << testPlayer.getName() << " has won the game,"<<endl
	// 																	<<"and has scored " << testPlayer.getScore() << " points at Rookie level."<<endl;
	// 																	statusOfTheGame = Status::WON;
	// 																}
	// 																break;
	// 															case 'Q':case 'q':
	// 																testPlayer.endGame(); statusOfTheGame = Status::LOST;
	// 																break;
	// 															case 'C':case 'c':
	// 																break;
	// 															default:
	// 																requesthint='N'; cout<< "Invalid selection.";
	// 																break;
	// 														}
	// 													}while (requesthint=='N');
	// 												}
	// 												break;
	// 											case 50:
	// 												statusOfTheGame = Status::QUIT; testPlayer.endGame(); invalidPlayerNumber = false;
	// 												break;
	// 											default:
	// 												cout<< "Invalid selection.";
	// 												invalidPlayerNumber = true;
	// 												break;
	// 											}
	// 									}while (invalidPlayerNumber);
	// 									//player num
	// 									break;
	// 								case 50:
	// 									invalidColumnNumber = false;
	// 									statusOfTheGame = Status::QUIT;
	// 									testPlayer.endGame();
	// 								break;
	// 							default:
	// 								invalidColumnNumber = true;
	// 								cout<< "Invalid selection.";
	// 								break;
	// 							}
	// 						} while (invalidColumnNumber);//col num
	// 						break;
	// 					case 50:
	// 						invalidRowNumber = false;
	// 						statusOfTheGame = Status::QUIT;
	// 						testPlayer.endGame();
	// 						break;
	// 					default:
	// 						invalidRowNumber = true;
	// 						cout<< "Invalid selection.";
	// 						break;
	// 					}
	// 				}while(invalidRowNumber);//row num
	// 			}while (statusOfTheGame == Status::CONTINUE);
	// 			break; // end hardseed switch statement
	// 		default:
	// 			cout<<"Your selection is invalid."<<endl;
	// 		break;
	// 		}

	// 	// Display a messeage if the player quits or exhausted all of their hints
	// 	if (statusOfTheGame == Status::QUIT && testPlayer.getScore() == 0)
	// 	{
	// 		cout << endl << "Game Over."<<endl<<"Player " << testPlayer.getName() << " has obtained " << testPlayer.getScore()
	// 			<< " points for this game. :("<<endl << "Solution is: " << endl;
	// 		testPlayer.displaySolutionBoard();

	// 		do
	// 		{
	// 			// Asks the user if they would like to play another game:
	// 			string endgame;
	// 			cout << "Would you like to play another game: ";
	// 			getline(cin, endgame);
	// 			cout << endl;

	// 			switch (testPlayer.stringToGameEnd(endgame))
	// 			{
	// 			case 91:
	// 				statusOfTheGame = Status::RETRY;
	// 			case 92:
	// 				statusOfTheGame = Status::END;
	// 			default:
	// 				statusOfTheGame = Status::UNDEFINED;
	// 				cout << "Please enter (yes/no)" << endl;
	// 			}
	// 		} while (statusOfTheGame == Status::UNDEFINED);
	// 	}

	// } while (statusOfTheGame == Status::RETRY);
	// // Exit message
	// cout << "Thank you for playing this game";
	return 0;
}