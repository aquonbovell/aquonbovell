#include <iostream>
#include "Game.h"

int main()
{
	std::string name, age, level, requesthint, row_number, column_number, number;
	size_t row_num, column_num, num;
	bool isInvalidRowNumber, isInvalidColumnNumber, isInvalidNumber;

	std::cout << "Enter your name: >> ";
	std::getline(std::cin, name);
	std::cout << "Enter your age: >> ";
	std::getline(std::cin, age);

	Game game(name, stoi(age));

	do
	{
		// level selection
		do
		{
			std::cout << "Enter the level you would like to play: >> ";
			std::getline(std::cin >> std::ws, level);
			switch (game.stringToLevel(level))
			{
			case 1:
				game.level = game.Level::ROOKIE;
				game.status = game.Status::CONTINUE;
				std::cout << "Selection was successful\nContinuing..." << std::endl;
				break;
			case 2:
				game.level = game.Level::TUFFTONG;
				game.status = game.Status::CONTINUE;
				std::cout << "Selection was successful\nContinuing..." << std::endl;
				break;
			case 3:
				game.level = game.Level::HARDSEED;
				game.status = game.Status::CONTINUE;
				std::cout << "Selection was successful\nContinuing..." << std::endl;
				break;
			case 4:
				game.status = game.Status::QUIT;
				std::cout << "Quitting...\nSad to see you go." << std::endl;
				break;
			default:
				game.status = game.Status::UNDEFINED;
				std::cout << "There is no level for your selection.\nRetry please." << std::endl;
				break;
			}
		} while (game.status == game.Status::UNDEFINED);

		game.reset();
		game.createGame();
		game.createCopy();
		game.removeSlots(game.level);
		game.displayArray();
		std::cout << std::endl;

		do
		{
			// loops until all the slots are filled
			do
			{
				// loops until the correct number is entered
				std::cout << "Enter a row number: >> ";
				std::getline(std::cin, row_number);
				row_num = game.stringToInt(row_number);
				row_num--;
				switch (row_num)
				{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					isInvalidRowNumber = false;
					do
					{
						std::cout << "Enter a column number: >> ";
						std::getline(std::cin, column_number);
						column_num = game.stringToInt(column_number);
						column_num--;
						switch (column_num)
						{
						case 0:
						case 1:
						case 2:
						case 3:
						case 4:
						case 5:
							isInvalidColumnNumber = false;
							do
							{
								std::cout << "Enter a number: >> ";
								std::getline(std::cin, number);
								num = game.stringToInt(number);

								switch (num)
								{
								case 1:
								case 2:
								case 3:
								case 4:
								case 5:
								case 6:
									isInvalidNumber = false;
									if (game.isFilled(row_num, column_num))
									{
										std::cout << "This slot is filled!!\nSelect another slot to fill." << std::endl;
									}
									else
									{
										std::cout << "Your entry " << (game.isInputCorrect(row_num, column_num, num) ? "was" : "was not") << "correct." << std::endl;
									}

									game.displayArray();

									if (game.isCompleted())
									{
										game.congratulatoryMessage();
										game.status = game.Status::WON;
									}
									else
									{
										do
										{
											std::cout << "Do you want a hint or do you want to quit or continue? (h/q/c) >> ";
											std::getline(std::cin, requesthint);
											switch (game.stringToStatus(requesthint))
											{
											case 1:
												if (game.levelToHints(game.level) == 1)
												{
													// display ending game
													std::cout << "Ending game...\nYou have reached your maximum hints." << std::endl;
													game.endGame();
													game.status = game.Status::LOST;
												}
												else
												{
													// display hint successful
													game.addHint(game.level);
													game.displayArray();
												}

												if (game.isCompleted())
												{
													game.congratulatoryMessage();
													game.status = game.Status::WON;
												}
												break;
											case 2:
												std::cout << "Quitting game..." << std::endl;
												game.endGame();
												game.status = game.Status::QUIT;
												break;
											case 3:
												std::cout << "Continuing..." << std::endl;
												break;
											default:
												game.status = game.Status::UNDEFINED;
												std::cout << "There is no option for your selection.\nRetry please." << std::endl;
												break;
											}
										} while (game.status == game.Status::UNDEFINED);
									}
									break;
								case 10:
									isInvalidNumber = false;
									std::cout << "Quitting game..." << std::endl;
									game.endGame();
									game.status = game.Status::QUIT;
									break;
								default:
									isInvalidNumber = true;
									std::cout << "Your number is invalid.\nRetry please.";
									break;
								}
							} while (isInvalidNumber);
							// player num
							break;
						case 10:
							isInvalidColumnNumber = false;
							std::cout << "Quitting game..." << std::endl;
							game.endGame();
							game.status = game.Status::QUIT;
							break;
						default:
							isInvalidColumnNumber = true;
							std::cout << "Your number is invalid.\nRetry please.";
							break;
						}
					} while (isInvalidColumnNumber); // col num
					break;
				case 10:
					isInvalidRowNumber = false;
					std::cout << "Quitting game..." << std::endl;
					game.endGame();
					game.status = game.Status::QUIT;
					break;
				default:
					isInvalidRowNumber = true;
					std::cout << "There is no option for your selection.\nRetry please.";
					break;
				}
			} while (isInvalidRowNumber);									// continues if the row number is not 1-5 or 10
		} while (game.status == game.Status::CONTINUE); // continues game if the status is continue

		if (game.status == game.Status::QUIT || game.status == game.Status::LOST)
			game.endGameMessage();

		do
		{
			// Asks the user if they would like to play another game:
			std::string endgame;
			std::cout << "Would you like to play another game: >> ";
			std::getline(std::cin, endgame);
			std::cout << std::endl;

			switch (game.stringToEndgame(endgame))
			{
			case 1:
				game.status = game.Status::RETRY;
			case 0:
				game.status = game.Status::END;
			default:
				game.status = game.Status::UNDEFINED;
				std::cout << "There is no option for your selection.\nRetry please." << std::endl;
			}
		} while (game.status == game.Status::UNDEFINED);
	} while (game.status == game.Status::RETRY);

	std::cout << "Good Bye. 👋" << std::endl;
	return 0;
}