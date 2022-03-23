#include "GAClass.h"
#include "Labirynth.h"
#include "Utilities.h"
#include <thread>
#include <time.h>

//										{0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27}
GAClass::GAClass() : colisionMap{		{1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
										{1, 12, 10, 10, 10, 10, 16, 10, 10, 10, 10, 10, 14,  1,  1, 12, 10, 10, 10, 10, 10, 16, 10, 10, 10, 10, 14,  1},
										{1, 11,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1, 11,  1},
										{1, 11,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1, 11,  1},
										{1, 11,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1, 11,  1},
										{1, 17, 10, 10, 10, 10, 20, 10, 10, 16, 10, 10, 18, 10, 10, 18, 10, 10, 16, 10, 10, 20, 10, 10, 10, 10, 19,  1},
										{1, 11,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1, 11,  1},
										{1, 11,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1, 11,  1},
										{1, 13, 10, 10, 10, 10, 19,  1,  1, 13, 10, 10, 14,  1,  1, 12, 10, 10, 15,  1,  1, 17, 10, 10, 10, 10, 15,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1,  1},
								/*11*/	{1,  1,  1,  1,  1,  1, 11,  1,  1, 12, 10, 10, 18, 10, 10, 18, 10, 10, 14,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{2, 10, 10, 10, 10, 10, 20, 10, 10, 19,  1,  1,  1,  1,  1,  1,  1,  1, 17, 10, 10, 20, 10, 10, 10, 10, 10,  2},	//FIXME: wartosc teleportacji duszkow
										{1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1, 17, 10, 10, 10, 10, 10, 10, 10, 10, 19,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1},
										{1, 12, 10, 10, 10, 10, 20, 10, 10, 18, 10, 10, 14,  1,  1, 12, 10, 10, 18, 10, 10, 20, 10, 10, 10, 10, 14,  1},
										{1, 11,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1, 11,  1},
										{1, 11,  1,  1,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1, 11,  1,  1,  1,  1, 11,  1},
								/*24*/	{1, 13, 10, 14,  1,  1, 17, 10, 10, 16, 10, 10, 18, 10, 10, 18, 10, 10, 16, 10, 10, 19,  1,  1, 12, 10, 15,  1},
										{1,  1,  1, 11,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1, 11,  1,  1,  1},
										{1,  1,  1, 11,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1, 11,  1,  1,  1},
										{1, 12, 10, 18, 10, 10, 15,  1,  1, 13, 10, 10, 14,  1,  1, 12, 10, 10, 15,  1,  1, 13, 10, 10, 18, 10, 14,  1},
										{1, 11,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1},
										{1, 11,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1,  1, 11,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 11,  1},
										{1, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 18, 10, 10, 18, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 15,  1},
										{1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1},
										{1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1}
							}
{

}

void GAControler(Labirynth colision, std::vector<Ghosts> ghostsVector, int y, int x, char type, GAClass &newTour) {
	
	cout << "\n" << x << " " << y << "\n";
	newTour.generateFirstPopulation(ghostsVector, y, x, type);

	//if (type == 'p') {
	//	/*for (int i = 0; i < newTour.randomToursPinky.size(); i++) {
	//		for (int j = 0; j < 20; j++) {
	//			cout << newTour.randomToursPinky[i][j] << " ";
	//		}
	//		cout << "\n";
	//	}*/
	//	newTour.randomToursPinky.clear();
	//}

	//else if (type == 'i') {
	//	/*for (int i = 0; i < newTour.randomToursInky.size(); i++) {
	//		for (int j = 0; j < 20; j++) {
	//			cout << newTour.randomToursInky[i][j] << " ";
	//		}
	//		cout << "\n";
	//	}*/
	//	newTour.randomToursInky.clear();
	//}

	//else if (type == 'c') {
	//	/*for (int i = 0; i < newTour.randomToursClyde.size(); i++) {
	//		for (int j = 0; j < 20; j++) {
	//			cout << newTour.randomToursClyde[i][j] << " ";
	//		}
	//		cout << "\n";
	//	}*/
	//	newTour.randomToursClyde.clear();
	//}
	//else if (type == 'b') {
	//	/*for (int i = 0; i < newTour.randomToursBlinky.size(); i++) {
	//		for (int j = 0; j < 20; j++) {
	//			cout << newTour.randomToursBlinky[i][j] << " ";
	//		}
	//		cout << "\n";
	//	}*/
	//	newTour.randomToursBlinky.clear();
	//}
	
	

}

void GAClass::generateFirstPopulation(std::vector<Ghosts> ghostsVector, int _y, int _x, char type) {
	int number = 0, iterat = 0, x = _x, y = _y, ity = 0;
	vector<char> tour;
	while (iterat < 8) {
		while (tour.size() < 20) {
			if (this->colisionMap[y][x] == 2) {
				switch (x) {
				case 27:
					while (this->colisionMap[y][x - 1] != 1 && tour.size() < 20) {
						tour.push_back('l');
						x--;
					}
					break;
				case 0:
					while (this->colisionMap[y][x + 1] != 1 && tour.size() < 20) {
						tour.push_back('r');
						x++;
					}
					break;
				}
			}

			if (this->colisionMap[y][x] == 10) {
				number = randomNumber(2);
				switch (number) {
				case 0:
					while (this->colisionMap[y][x] == 10 && tour.size() < 20) {
						tour.push_back('r');
						x++;
					}
					break;
				case 1:
					while (this->colisionMap[y][x] == 10 && tour.size() < 20) {
						tour.push_back('l');
						x--;
					}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 11) {
				number = randomNumber(2);
				switch (number) {
				case 0:
					while (this->colisionMap[y][x] == 11 && tour.size() < 20) {
						tour.push_back('u');
						y--;
					}
					break;
				case 1:
					while (this->colisionMap[y][x] == 11 && tour.size() < 20) {
						tour.push_back('d');
						y++;
					}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 12) {
				number = randomNumber(2);
				switch (number) {
				case 0:
					//while (this->colisionMap[y][x + 1] != 1 && tour.size() < 20) {
						tour.push_back('r');
						x++;
					//}
					break;
				case 1:
					//while (this->colisionMap[y + 1][x] != 1 && tour.size() < 20) {
						tour.push_back('d');
						y++;
					//}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 13) {
				number = randomNumber(2);
				switch (number) {
				case 0:
					//while (this->colisionMap[y - 1][x] != 1 && tour.size() < 20) {
						tour.push_back('u');
						y--;
					//}
					break;
				case 1:
					//while (this->colisionMap[y][x + 1] != 1 && tour.size() < 20) {
						tour.push_back('r');
						x++;
					//}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 14) {
				number = randomNumber(2);
				switch (number) {
				case 0:
					//while (this->colisionMap[y][x - 1] != 1 && tour.size() < 20) {
						tour.push_back('l');
						x--;
					//}
					break;
				case 1:
					//while (this->colisionMap[y + 1][x] != 1 && tour.size() < 20) {
						tour.push_back('d');
						y++;
					//}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 15) {
				number = randomNumber(2);
				switch (number) {
				case 0:
				//	while (this->colisionMap[y - 1][x] != 1 && tour.size() < 20) {
						tour.push_back('u');
						y--;
				//	}
					break;
				case 1:
				//	while (this->colisionMap[y][x - 1] != 1 && tour.size() < 20) {
						tour.push_back('l');
						x--;
				//	}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 16) {
				number = randomNumber(3);
				switch (number) {
				case 0:
				//	while (this->colisionMap[y][x + 1] != 1 && tour.size() < 20) {
						tour.push_back('r');
						x++;
				//	}
					break;
				case 1:
				//	while (this->colisionMap[y][x - 1] != 1 && tour.size() < 20) {
						tour.push_back('l');
						x--;
				//	}
					break;
				case 2:
				//	while (this->colisionMap[y + 1][x] != 1 && tour.size() < 20) {
						tour.push_back('d');
						y++;
				//	}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 17) {
				number = randomNumber(3);
				switch (number) {
				case 0:
				//	while (this->colisionMap[y - 1][x] != 1 && tour.size() < 20) {
						tour.push_back('u');
						y--;
				//	}
					break;
				case 1:
				//	while (this->colisionMap[y + 1][x] != 1 && tour.size() < 20) {
						tour.push_back('d');
						y++;
				//	}
					break;
				case 2:
				//	while (this->colisionMap[y][x + 1] != 1 && tour.size() < 20) {
						tour.push_back('r');
						x++;
				//	}
					break;
				}
			}
			else if (this->colisionMap[y][x] == 18) {
				number = randomNumber(3);
				switch (number) {
				case 0:
				//	while (this->colisionMap[y - 1][x] != 1 && tour.size() < 20) {
						tour.push_back('u');
						y--;
				//	}
					break;
				case 1:
				//	while (this->colisionMap[y][x + 1] != 1 && tour.size() < 20) {
						tour.push_back('r');
						x++;
				//	}
					break;
				case 2:
				//	while (this->colisionMap[y][x - 1] != 1 && tour.size() < 20) {
						tour.push_back('l');
						x--;
				//	}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 19) {
				number = randomNumber(3);
				switch (number) {
				case 0:
				//	while (this->colisionMap[y - 1][x] != 1 && tour.size() < 20) {
						tour.push_back('u');
						y--;
				//	}
					break;
				case 1:
				//	while (this->colisionMap[y + 1][x] != 1 && tour.size() < 20) {
						tour.push_back('d');
						y++;
				//	}
					break;
				case 2:
				//	while (this->colisionMap[y][x - 1] != 1 && tour.size() < 20) {
						tour.push_back('l');
						x--;
				//	}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 20) {
				number = randomNumber(4);
				switch (number) {
				case 0:
				//	while (this->colisionMap[y - 1][x] != 1 && tour.size() < 20) {
						tour.push_back('u');
						y--;
				//	}
					break;
				case 1:
				//	while (this->colisionMap[y + 1][x] != 1 && tour.size() < 20) {
						tour.push_back('d');
						y++;
				//	}
					break;
				case 2:
				//	while (this->colisionMap[y][x - 1] != 1 && tour.size() < 20) {
						tour.push_back('l');
						x--;
				//	}
					break;
				case 3:
				//	while (this->colisionMap[y][x + 1] != 1 && tour.size() < 20) {
						tour.push_back('r');
						x++;
				//	}
					break;
				}
			}

			else if (this->colisionMap[y][x] == 1) {
				if (this->colisionMap[y - 1][x] != 1) {
					if(!tour.empty())
					tour.pop_back();
					y--;
					cout << " ";
					ity--;
				}
				else if (this->colisionMap[y + 1][x] != 1) {
					if (!tour.empty())
					tour.pop_back();
					y++;
					cout << " ";
					ity--;
				}
				else if (this->colisionMap[y][x - 1] != 1) {
					if (!tour.empty())
					tour.pop_back();
					x--;
					cout << " ";
					ity--;
				}
				else if (this->colisionMap[y][x + 1] != 1) {
					if (!tour.empty())
					tour.pop_back();
					x++;
					cout << " ";
					ity--;
				}
				else {
					//cout << tour.size() << endl;
					
					/*auto end = tour.end();
					cout << *end << type;*/
				}
			}
			//cout << y << " " << x << "\n";
			//cout << tour.size() << endl;
			//if(ity>=0 && ity <20)
			//cout << tour[ity];
			//ity++;
			else
			cout << "BLAD\n";
		}
		iterat++;
		switch (type) {
		case 'p':
			this->randomToursPinky.push_back(tour);
			break;
		case 'i':
			this->randomToursInky.push_back(tour);
			break;
		case 'c':
			this->randomToursClyde.push_back(tour);
			break;
		case 'b':
			this->randomToursBlinky.push_back(tour);
			break;
		}
		ity = 0;
		tour.clear();
	}
}

void GAClass::selection() {

}