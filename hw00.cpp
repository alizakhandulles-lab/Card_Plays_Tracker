#include <iostream>
#include <fstream>
#include <string>

void Print(std::ofstream& outputFile, int** arr, int numRows, int numCols); //foward declaration

int main()
{
	int** cardSet = new int* [15]; //create 2d array of 15 rows, 5 colums of int (pointers)
	for (int i = 0; i < 15; i++) {
		cardSet[i] = new int[5];
		for (int j = 0; j < 5; j++) {
			cardSet[i][j] = 0;
		}
	}

	
	std::ifstream fileInfo("input2.txt"); // open file for reading
	std::string* cardInput = new std::string(); 
	std::getline(fileInfo, *cardInput); // store the first line of the file into a string, as there is only one line

	for (int i = 0; i < cardInput->length();) {
		int* cardSuit = new int(0); // temp holds card suit value
		int* cardValue = new int(0); // temp holds card value
		if (cardInput->at(i + 1) != '0') {  // checks if the card value is 10, as 10 is the only double digit value
			switch (cardInput->at(i)) {
			case 'P':
				cardValue = new int(0);
				i++;
				break;
			case 'R':
				cardValue = new int(10);
				i++;
				break;
			case 'N':
				cardValue = new int(11);
				i++;
				break;
			case 'B':
				cardValue = new int(12);
				i++;
				break;
			case 'Q':
				cardValue = new int(13);
				i++;
				break;
			case 'K':
				cardValue = new int(14);
				i++;
				break;
			default:
				cardValue = new int(cardInput->at(i) - '1');
				i++;
				break;
			}
		}
		else { // if the next card is 10, you cannot just subtract 1 & the index needs to move 2 spaces instead of 1
			cardValue = new int(9);
			i += 2;
		}
		switch (cardInput->at(i)) {
			case 'A':
				cardSuit = new int(0);
				break;
			case 'E':
				cardSuit = new int(1);
				break;
			case 'F':
				cardSuit = new int(2);
				break;
			case 'W':
				cardSuit = new int(3);
				break;
			case 'H':
				cardSuit = new int(4);
				break;
			default:
				break;
			}
		if (i <= cardInput->length() - 3) { // ensures index does not go out of bounds
			i += 3;
		}
		else {
			i++;
		}
		cardSet[*cardValue][*cardSuit] = 1;
		delete cardSuit;
		delete cardValue;
	}
	
	delete cardInput;

	std::ofstream outputFile("cardOutput.txt"); // open file for writing
	Print(outputFile, cardSet, 15, 5);

	for (int i = 0; i < 15; i++) {
		delete[] cardSet[i];
	}

	return 0;
}

void Print(std::ofstream& outputFile, int** arr, int numRows, int numCols)
{
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			outputFile << arr[row][col] << " ";
		}
		outputFile << std::endl;
	}
}