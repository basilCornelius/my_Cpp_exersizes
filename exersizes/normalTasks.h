#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "fineEnterFunctions.h"
#include <vector>
#include <map> 
#include "ctype.h"


//������ 1
/*
� ��������� �����, ���������� ����� ��������� �� ����� ��, ��������� ������������ ������������� � ������������� �������� ������ { � }. 
��������� �������� ������� �� ����� � �������� � ���� ����� � ��������� ����. ��������� ������ ��������� (�����) ��������� � ��������� ��������� ���� (��������, "out . txt " ), 
������������� �� ������.
*/
void checkBracketsBalance() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 1:\n"
		"Check do {} brackets stays right in file" << std::endl
		<< std::endl;
	std::string filePath; // ���� � �����
	std::ifstream file; // ����� ������ �����
	std::ofstream inFile; // ����� ������ � ����
	char symbol; // ������ ������ �����
	int balance = 0; /*����� �������� ������ �����������, ����������++, ����� �����������, ����������--.�.�.����������, ��� ���� � ����� ������ ���������� >0?,
				 ������ �������� ���������� ������, � ���� ������ - �� �� ������� �����������, � ���� ������ �����������*/
	do {
		std::cout << "Path to file: ";
		std::cin >> filePath;
		try {
			file.open(filePath);
		}
		catch (const std::ifstream::failure& e) {
			std::cout << "this file did not opened" << std::endl
				<< "Esception: " << e.what() << std::endl;
		}
	} while (!file.is_open());
	
	while (file.get(symbol)) { //������� ������
		if (symbol == '{') {
			balance++;
		}
		else if(symbol == '}') {
			balance--;
		}
		//���� ����������� ��������� ������ �����������
		if (balance < 0) {
			std::cout << "Wrong place of closing bracket" << std::endl;
			return;
		}
	}
	//����������� ���������� balance
	if (balance > 0) { // ���� ���������� ����������� ������ ����� ���������� �����������
		std::cout << "Somewhere in file is not closed bracket" << std::endl;
	}
	else if(balance < 0) {
		std::cout << "Somewhere is a excess closing bracket" << std::endl;
	}
	else {
		std::cout << "All brackets are on their places" << std::endl;
	}
	file.close();
}

//������ 2
/*
��������� ���������� ������� ��������� ������ �����. ���������� ��������� ����� ���� �������� � ����������.
1+1/(1+1/(1+1/(1+1/�.)))
*/
void fractChain() {
	system("CLS");
	std::cout 
		<< "Normal dificulty -> TASK 2:\n"
		"Enter count of fractions in chain. Get fraction chain like: 1+1/(1+1/(1+1/(1+1/....)))" << std::endl
		<< std::endl;
	int count = enterInt("count of fractions in chain"); // ���������� ������ � ����
	float result = 0.0;
	float fracChainRecursion(int count );// ������� ��� ��������
	result = fracChainRecursion(count);
	std::cout << result << std::endl
		<< std::endl;
}
float fracChainRecursion(int count) { // ��������� ���������� � ������� ������� �������
	if (count == 0) return 1;
	return 1 + (1 / (fracChainRecursion(count-1)));
}

//������ 3
/*
��������� ������������ ������� �� ������. � ���������� ������� ����� ������������  �������. ���������� ������ ������ ������ ����� ���������:

	> � �������������� ����������� ��������
	> ������������ ������ ������������ ������� � ����� �������������� ���������
	> ������������ ������ ������������ �������, ��������� � ��������� ������� ��������� � ������� ��������.

*/
void matrixMultipliedVector() { // ������� ������ ������ �� ������������� ��������� �������
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 3:\n"
		"Programm multiplies matrix by vector. Dimensios of matrix entered by user.\n" 
		"Programm user three ways to solve the task. Result should be the same, but difference in code."<< std::endl
		<< std::endl;

	void matrixMultipliedVectorStatic(int wdt, int hgt); // ������ ������ ������� ������
	void matrixMultiplyingVectorDynamicPointers(int wdt, int hgt); // ������ ������ ������� ������
	void matrixMultiplyingVectorUsingIndices(int wdt, int hgt); // ������ ������ ������� ������
	int matrixWidth = enterInt("Matrix width");
	int matrixHeight = enterInt("Matrix height");
	std::cout << std::endl
		<< "Choose way to solve:\n"
		"\t1. Matrix is a static 2d array.\n"
		"\t2. Matrix ia a 2d dynamic array, access using dereferencing pointers\n"
		"\t3. Matrix ia a 2d dynamic array, access using index"
		<<std::endl;
	int wayNumber = enterInt("way I choose");
	switch (wayNumber) {
	case 1: matrixMultipliedVectorStatic(matrixWidth, matrixHeight); break;
	case 2: matrixMultiplyingVectorDynamicPointers(matrixWidth, matrixHeight); break;
	case 3: matrixMultiplyingVectorUsingIndices(matrixWidth, matrixHeight); break;
	default:
		break;
	}
}
// ������� �������� ������� �� ������. ������� - ����� ������������ ���������� ������� 256�256 ���������
void matrixMultipliedVectorStatic(int wdt, int hgt) { // ������ �������, ������ � ������� ����������� �������� ������ 256�256 ��������
	if (wdt > 256 || hgt > 256) {
		std::cout << "The way, you have choosen requares 256x256 matrix dimensions maximum! create matrix by this way impossible. \n"
			"Restart program and choose another way." << std::endl;
		return;
	}
	int matrix[256][256]; // ����������� ������ ��� �������
	int vector[256]; // ������ ��� �������
	int result[256]; // ������ ��� ����������. ����� ���� �������� ��� ������� - ������ �������� ��������� �� �����, �� ���������� ��� ������, ������ ��� ��������� - ������.
	//��������� ������� ������ ��������
	system("CLS");
	std::cout
		<< "enter matrix values^ " << std::endl
		<< std::endl;

	enterStaticMatrixSize256(wdt, hgt, matrix);// ���������� �������

	std::cout << "Enter vector values: " <<std::endl; // ������ ������
	for (auto v = 0; v < wdt; v++) { // ��� �������
		std::cout << "vector value " << v+1 << ":\t";
		std::cin >> vector[v];
	}
	// �������� �� ������ � ������� ���������
	std::cout << std::endl << "Result: " << std::endl;
	for (auto row = 0; row < hgt; row++) {
		result[row] = 0;
		for (auto value = 0; value < wdt; value++) {
			result[row] += matrix[row][value] * vector[value];
		}
		std::cout << result[row] << ";\n";// ������� ��������

	}
}
// ������� �������� ������� �� ������, ������� � ������ - ������������ �������. ������ � ��������� �� ������������� ����������
void matrixMultiplyingVectorDynamicPointers(int wdt, int hgt) { 
	int** matrix = new int* [hgt]; // ��������� ������������ ������ ��� �������. �������������� � ������� �����. 
	int* vector = new int[wdt]; // ������������ ������ ��� �������
	int* result = new int[hgt]; // ������ ��� ����������. �� ������� ����� ���� �� �������� ��� ����, �� �������� �������� ��������� � ������
	// ��������� ������� ������. ����� ���������� �� ��������� ������������ �� � �������
	for (auto h = 0; h < hgt; h++) {
		*(matrix + h) = new int[wdt];
		for (auto w = 0; w < wdt; w++) {
			*(*(matrix + h) + w) = 0;
		}
		std::cout << std::endl;
	}
	enterDynamicMatrixByPointers(wdt, hgt, matrix); // ��������� �������
	std::cout << "Enter vector values: " << std::endl; // ������ ������
	for (auto v = 0; v < wdt; v++) { // 
		std::cout << "vector value " << v + 1 << ":\t";
		std::cin >> *(vector + v);
	}
	// �������� �� ������ � ������� ���������
	std::cout << std::endl << "Result: " << std::endl;
	int multiplier1 = 0;
	int multiplier2 = 0;
	for (auto row = 0; row < hgt; row++) {
		*(result + row) = 0;
		for (auto value = 0; value < wdt; value++) {
			multiplier1 = *(*(matrix + row) + value);
			multiplier2 = *(vector + value);
			*(result + row) +=  multiplier1 * multiplier2;
		}
		std::cout << *(result + row) << ";\n";// ������� ��������

	}
	// ������� ������������ �������
	for (auto i = 0; i < hgt; i++) {
		delete [] matrix[i];
	}
	delete [] matrix;
	delete [] result;
	delete [] vector;
}
// ������� �������� ������� �� ������. ������� � ������ - ������������ �������, ������ �������������� �� �������. 
void matrixMultiplyingVectorUsingIndices(int wdt, int hgt) {
	int** matrix = new int* [hgt]; // ��������� ������������ ������ ��� �������. �������������� � ������� �����. 
	int* vector = new int[wdt]; // ������������ ������ ��� �������
	int* result = new int[hgt]; // ������ ��� ����������. �� ������� ����� ���� �� �������� ��� ����, �� �������� �������� ��������� � ������
	// ��������� ������� ������. ����� ���������� �� ��������� ������������ �� � �������
	for (auto h = 0; h < hgt; h++) {
		matrix[h] = new int[wdt];
		for (auto w = 0; w < wdt; w++) {
			matrix[h][w] = 0;
		}
		std::cout << std::endl;
	}
	enterDynamicMatrixByPointers(wdt, hgt, matrix); // ��������� �������
	std::cout << "Enter vector values: " << std::endl; // ������ ������
	for (auto v = 0; v < wdt; v++) { // 
		std::cout << "vector value " << v + 1 << ":\t";
		std::cin >> vector[v];
	}
	// �������� �� ������ � ������� ���������
	std::cout << std::endl << "Result: " << std::endl;
	for (auto row = 0; row < hgt; row++) {
		result[row] = 0;
		for (auto value = 0; value < wdt; value++) {
			result[row] += matrix[row][value] * vector[value];
		}
		std::cout << result[row] << ";\n";// ������� ��������

	}
	// ������� ������������ �������
	for (auto i = 0; i < hgt; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] result;
	delete[] vector;
}

//������ 4
/*������ �� ������������ ��������� ������. ���������� ���� ��������� �� ������ � ����� ���������. ������������ ������ �����. 
���� ��� ������ 0 ���������� ��� � ������. ����� ������������ ������ ������ �����, ��� ���,  ���� ��� ������ 0, 
���� ���� �������� ������ ��� 2-� ��������� ������� � �������� � ������ ������ �����. � ��� �����  ��� 3-� ���������, ��� 4-��  
���� ������������ �� ������ ������������� �����.*/
void dynamicUnsignedIntArray() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 4:\n"
		"Enter unsigned int numbers untill you entered number < 0. " << std::endl
		<< std::endl;
	int counter = 0; // ������� ��������� �����
	int entered = 0; // ���������� ��� ���������� �����
	int* storage = new int[counter]; // ��������� �� ������� �������
	int* secondStorage = new int [counter]; // �����, ���� ����� ��������� ��������� ����� �����
	do {
		std::cout << "enter number : "; // ������ �����
		std::cin >> entered; // ����
		if (entered >= 0) { // ���� �������� �������� �� �������
			delete[] secondStorage; // ����������� ������ ���������
			secondStorage = new int[counter];
			for (auto i = 0; i < counter; i++) { // ���������� ������ �� ������� ������� �� ������
				secondStorage[i] = storage[i];
			}
			delete[] storage;  // ����������� ������� ������
			counter++; // ����������� �������
			storage = new int[counter]; // ������� ��������� � +1 �����
			for (auto i = 0; i < counter-1; i++) { // ��������� ����� ��������� ������� �������
				storage[i] = secondStorage[i];
			}
			storage[counter-1] = entered; // ��������� ��������� � ���������� ����� ������.
		}
		else { // ���� ��������� < 0, ��������� ����. 
			break;
		}
	} while (true);
	system("CLS"); // �������
	std::cout << "data, you have entered:" << std::endl; // ������� ������
	for (auto i = 0; i < counter; i++) {
		std::cout << storage[i] << ", ";
	}
	std::cout << std::endl;
	delete[] storage;
	delete[] secondStorage;
}


// ������ 5
/*���������� ������� ���������, ������� �������� ������� ���� int � ������. �������� ��������� ���� ��������� (������ ���������) 
� �������� ������ ��� �������� ������ ����� ���������. ���������� ������������ ������ ������ � �������� �� � �������� ������� ���������. 
����� ������������ ���������� ������� �����: ������ ��� ������ (������� ��� ���� ������ ���������) ���� ����� �� ���������. 
���� ������������ ���������� ���� � ���������� �������� ����� ������ ��� ��������� �� ������ ��������� � �������� � ��� ��������� 
������������� ����� ������. ���� ��������� ����� ������ ������������, ���� ������������ �� ������� ����� �� ���������.*/
void structArray() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 5:\n"
		"Create persons (name and age) as much as you whant." << std::endl
		<< std::endl;

	struct Person { // ���������
		std::string name;
		int age; 
	};
	// ���� ����������� ����� ������. ��� �����.
	std::vector<Person*> persons; // ��� �������
	char answer = 'y'; // ����� �� ������: "���������� ��� ���"
	int personsCounter = 0;
	do {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		persons.push_back(new Person);
		std::cout << "new person!\n\tname: ";
		std::cin >> persons[personsCounter]->name;
		std::cout << "\tage: ";
		std::cin >> persons[personsCounter]->age;
		std::cout << "person created. To create new one, press 'y', to finish - any another symbol: ";
		std::cin >> answer;
		personsCounter++;
	} while (answer == 'y');
	system("CLS");
	std::cout << "You have created " << personsCounter << " persons. They are: " << std::endl;
	int personNum = 1; // ����� ������� ��� ������
	for (auto prsn : persons) {
		std::cout << personNum++ << ". " << prsn->name<< ": " << prsn->age << std::endl;
		delete prsn;
	}
}

//������ 6
/*��������� �������� ���������, ������� ��������� ������ ����������� nxn �� ��������� �������:
	  1  3  4 10 11
      2  5  9 12 19
      6  8 13 18 20
      7 14 17 21 24
     15 16 22 23 25
�� ����, ���������� ������� ������ ���� �� ���������, ������ - ����, ����� - �������.������ ���������� ��� � ���������������.*/
void zigZagArray() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 6:\n"
		"Creating array NxN with zigZag filling." << std::endl
		<< std::endl;
	int size = enterInt("side of square array"); // ������ �������. �� ����������
	int** massiv = new int* [size];
	for (auto i = 0; i < size; i++) { // ������ ������ ���������
		massiv[i] = new int[size];
	}
	int w = 0; // ���������� ��������������� �������� ���������� �������
	int h = 0; // ���������� ������������� �������� �������
	char direction = 'd'; // ����������� ����������. ����� ��� ����
	int value = 0; // ��������, ������� ����������� ������. 
	do { 
		massiv[h][w] = value;
		value++;
		// ��������� �� � ����� �� �������
		if (h==size-1 && direction == 'd') { //���� �������� ������ �������, �������� ����
			w++; // ������� �� ������� ������
			direction = 'u'; // ������ �����������
			continue; // ������� ����
		}
		if (w == 0 && direction == 'd') { // ���� � ����� ������� � ��������� ����
			h++; // ������� �� ������ ����
			direction = 'u'; // ������ �����������
			continue; // ������� ����
		}
		if (w == size-1 && direction == 'u') { // ���� � ������� ���� � ��������� �����
			h++; // ������� �� ������ ����
			direction = 'd'; // ������ �����������
			continue; 
		}
		if (h == 0 && direction == 'u') { // ���� � �������� ���� � �������� ���� �����
			w++; // ��������� �������
			direction = 'd'; // ������ �����������
			continue;
		}
		if (direction == 'd') { // ���� �������� ����
			w--;
			h++;
		}
		else if (direction == 'u') { // � ���� �����
			w++;
			h--;
		}
	} while ( !(h > size-1 || w > size-1) );
	
	// �������
	std::cout << std::endl << std::setiosflags(std::ios::left);
	for (auto hgt = 0; hgt < size; hgt++) {
		for (auto wdt = 0; wdt < size; wdt++) {
			std::cout << massiv[hgt][wdt] << ",\t";
		}
		std::cout << std::endl; 
	}
	//������
	for (auto i = 0; i < size; i++) {
		delete[]massiv[i];
	}
	delete[]massiv;
}

// ������ 7
/*�� ��������� ������������� x, ��������� ������ ���������� �� x �� ��������� ������������ �������:
yi+1= 0.5 ( yi + 3 x / ( 2 yi2 + x / yi )).
��������� ����������� y0=x. �������� ���������� ��� |yi+1-yi|<10^-5. ����� ������� ������� � ����� ������ ���������� ��� ������������� ����������� �������.*/
void cubicRoot() { // ������� ��� �������
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 7:\n"
		"Describe cubic root of entered number" << std::endl
		<< std::endl;
	float x = enterFloat("number to describe cubic root");
	float yi1 = 0.0; // ������� �������� y
	float yi = x; // ������� �������� y
	while (true) {
		yi1 = 0.5 * (yi + 3 * x / (2 * yi * yi + x / yi));
		if (abs(yi1 - yi) < powf(10.0, -5.0)) {
			break;
		}
		yi = yi1;
	};
	std::cout << "cube " << x << " is " << yi << std::endl;
}

//������ 8
/*
��������� ������ ��������� �������������� ������ (����� ������ 255 ��������):

    1) ������ ���������� �������
    2) ������ � ������ ��������
    3) � ��������� ����� (������ ������ ������� ����� � ������ )
    4) ������ ������ � ������ ��������
    5) ��� � �����������(� ��������� �����).
    ������ 'x' ��� 'X' � ����� �� ���������

������������ � ��������� ����, ����� ������� ����� ������ �������� ����� ��������. ��������� ������ ����������� ���� ������������ �� ������  ������ 'f'.
*/
void stringMorpher() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 8:\n"
		"Enter string and modify it described ways." << std::endl
		<< std::endl;
	/*
	���� �����: �������� ������ ����� getline, ����� ��������� �������� �� ����� �� ��������.
	����� ���� � �������� ���� ������������ ��������������� �����������. ������ ����������� ���� 
	����� ����� �����, � ���� �������.
	*/
	char ch = 0; // ����� ��� �����
	int counter = 0; // ������� ��������
	bool isFirstChar = false; // �����������, ����� ������ ������� ������ ����
	bool isVeryFirstChar = true; // ������ ����� �����������
	std::string word;  // �����
	std::vector <std::string> text; // ��������� ��� �������� �����
	char command = 0; // ������� ��� ������ �����������
	//����
	std::cin.clear();
	std::cin.ignore(); // �������� ����� �� ���������� ������ (����)
	std::cout << "Enter text (255 chars max): ";
	while (ch != '\n') {
		std::cin.get(ch);
		counter++;
		if (ch == ' ' || ch == '\n') {
			text.push_back(word);
			word.clear();
		}
		else {
			word += ch;
		}
		if (counter == 255) {
			std::cout << "\nlimit 255 symbols reached." << std::endl;
			break;
		}
	};
	// ���� ��������
	// ���������, ���� �� ����� ������ ������� "���������"
	do {
		std::cout << std::endl; // ���� �������� � ��������� �������
		std::cout << "\nSelect modificator:"
			<< "\n'1' - CAPS"
			<< "\n'2' - low register"
			<< "\n'3' - Every Word Is Capitalised"
			<< "\n'4' - eVERY fIRST sYMBOL iN lOW rEGISTER"
			<< "\n'5' - First letter is capitalised"
			<< "\n 'x' or 'X' - finish"
			<< std::endl;
		// ���� �������
		std::cout << "Enter modificator: ";
		do { // ������� �������� ���� �� ����� ������ ��������
			std::cin >> command;
			if (command == '1', '2', '3', '4', '5', 'x', 'X') {
				break;
			}
			else {
				std::cout << "Wrong command. Use numbers 1 -5 to choose action or 'x' to finish. Enter again: ";
			}
		} while (true);
		// ���� � - �� ��������
		if (command == 'x' || command == 'X') {
			break;
		}
		// ����������� ������
		std::cout << std::endl; // ��������� �� ������
		for (std::string wrd : text) { // ���������� �����
			isFirstChar = true; // ������ ����� ����� ���������� � ������ �����. �������? �������..
			for (char letter : wrd) { // ���������� �����
				if (command == '1') {
					letter = toupper(letter); // ������ ����� � ������� �������
					std::cout << letter;
				}
				if (command == '2') { // ������ ����� ����� � ������ �������
					letter = tolower(letter);
					std::cout << letter;
				}
				if (command == '3' || command == '4') { // ������ ������ ����� ������� ����� � ������� ��� ������ �������, � ��������� - ��������
					if (isFirstChar) {
						command == '3' ? letter = toupper(letter) : letter = tolower(letter);
						std::cout << letter;
						isFirstChar = false;
					}
					else {
						command == '3' ? letter = tolower(letter) : letter = toupper(letter);
						std::cout << letter;
					}
				}
				if (command == '5') { // ��������� ������ ����� �����������
					isVeryFirstChar ? letter = toupper(letter) : letter = tolower(letter); // ���� ��� ������ ����� �����������, ��������� � ������� �������. ����� - � ������. 
					std::cout << letter; // �����
					letter == '.' || letter == '!' || letter == '?' ? isVeryFirstChar = true : isVeryFirstChar = false; // ���� ������ �������� �����������, �� ��������� ������ - ���������
				}
			}
			std::cout << ' ';
		}
		std::cout << std::endl << "Do you whant modify this string again& (y/n): " << std::endl; // ���������� ���������� ��� ��� ��� ���

	} while (command != 'n' || command != 'N');
}

// ������ 9
/*
��������� ���������, ������� ����� ������������ ��������� ����� � ��������� [a;b] � ��������� ��� ��������� ������ �������� 10 �� 10.
����� � ����� ������� ����� �����. 
� ������� ���������� ����� ����� ������ � ����������� ���������. �������� ������ ������� �������, ������ � ����������� ��������� � ������ ������ �������. 
������������ ������� ����� �� �����.
*/
void tenArray() {
	clearAndRewrite("Normal dificulty->TASK 9:\n" // ������� ��������� ������� �����, ����������� ������� � ����� ������. 
		"Generate 10x10 array< using random values from entered range.\n"
	"Then find minimal value and swap this row with first");
	srand(time(NULL)); // �����
	float arr[10][10]; // ������
	int min = 0;
	int max = 0;
	float bufferRow[10]; // ������
	int rowNumber = 0; // ����� ������-��������� �� ���������� ��������
	float savedMinimal = 0.0; // �������� �� ���������� ��������. 
	float isFirst = true; // ���� ��� ������ �������� �������.

	do { // ���� � ��������� �� ������������
		min = enterInt("nter minimal value") * 1000; // ����������� ��������
		max = enterInt("Enter maximal value") * 1000; // ������������ ��������
		if (min > max) {
			std::cout << "Wrong data: minimum > maximum. Reenter." << std::endl;
		}
		else {
			break;
		}
	} while (true);

	// ����������� ������
	int current = 0; // �������� ��� ������� � ������
	for (size_t row = 0; row < 10; row++) {
		for (size_t col = 0; col < 10; col++) {
			current = min + rand() % (max - min);
			arr[row][col] = float(current) / 1000;
			std::cout << arr[row][col] << '\t';// �������
			if (!isFirst) { // ���� ��� ��� �� ������ ���������������
				if (savedMinimal > arr[row][col]) {
					savedMinimal = arr[row][col]; // ��� ������������ � ����������� ��������� � �����������, ���� �������
					rowNumber = row; // � ����� ������ ������������
				}
			}
			else { // � ���� ������, ��� ������ ������������ ��� �����������
				savedMinimal = arr[row][col];
				isFirst = false; // � ������ ���� �� ������������
			}
		}
		std::cout << std::endl;
	}
	// ������� ����������� ��������
	std::cout << "\nMinimal value is " << savedMinimal << " in row " << rowNumber + 1 << std::endl;
	for (size_t i = 0; i < 10; i++) { // ����� �����
		if (rowNumber != 0) { // ���� ����������� �������� �� ���������� � ������ ������
			bufferRow[i] = arr[rowNumber][i]; // ���������� � ����� ��������
			arr[rowNumber][i] = arr[0][i]; // �� ����� ���� �������� ������������ �������� �� ������ ������, ��� ��� ����� ������ ������ �������
			arr[0][i] = bufferRow[i]; // ������ �������
		}
	}
	// ������� ������ � ����� ������������� �����
	if (rowNumber !=0) { // ���� ��� ����������
		std::cout << "New matrix with swapped first and " << rowNumber + 1 << " rows" << std::endl << std::endl;
		for (size_t row = 0; row < 10; row++) {
			for (size_t col = 0; col < 10; col++) {
				std::cout << arr[row][col] << '\t';
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "Minimal value is in first row. Swapping dont needed" << std::endl;
	}
}

// ������ 10
/*
���������� ���������� ���������� ������� �������, �� ��������� ������. ����� �������, ������� ��� ������� = 1. 
*/
void charCounter() {
	clearAndRewrite("Normal dificulty->TASK 10:\n" 
		"Enter any string. Function will count every symbol how many times it is in this stroke.");

	std::string entered; // ������ ������
	std::map <char, int> charSet; // ������ ������ ��������� ��� �������� �������� ������-����������.
	std::map <char, int>::iterator it; // �������� ��� ������
	char current; // ����� ��� ������������ ��������. 
	// ���� ������ 
	std::cout << "\nEnter text to analyze: ";
	std::cin.ignore(); // �������� ����� �� ������� ����� ������ �� ���������� ������
	std::getline(std::cin, entered); // ������ ������ � ���������
	// ���������
	for (size_t ch = 0; ch < entered.size(); ch++) {
		current = char(entered[ch]);
		if (!charSet.empty() || (it = charSet.find(current)) != charSet.end()) { // ���� ��� �� ������ ������ � ���� ����� ������
			charSet[current]++; // ������������� �������� �� �����
		}
		else { // ���� ������ ������� ��� ��� ��������� ����,
			charSet.insert(std::make_pair(current, 1)); // �������� ����� ������� �� ��������� 1
		}
	}
	//�����
	std::cout << "\nStatistics for symbols in entered text: " << std::endl << std::endl;
	for (auto &keyChar : charSet) {
		if (keyChar.first != ' ') { // ��� ���� ��������, �� ���������� ��������
			std::cout << keyChar.first;
		}
		else { // � ������ ������� ��� ��������: "Space"
			std::cout << "spaces";
		}
		std::cout <<  ": " << keyChar.second << std::endl;
		
	}
}

// ������ 11
/*
��� ������ ������� n, ��������� ��� ���������� �������, ����� ��� �������� ����� �������...��� ������ "normal" ���������? ��� ��, ��?
*/
void findOdds() {
	clearAndRewrite("Normal dificulty->TASK 11:\n" 
		"Enter count of numbers. Algorythm generates array of randoms and select only odds from it.");
	//��� ��� � ������ ������������ ����� "������", �������� ������������ �������. �� � � ����� �������� �������
	unsigned int n = 0; // ������ �������
	// ����
	std::cout << "\nEnter count of numbers: ";
	std::cin.ignore(); // ������� �����
	std::cin >> n;
	// �������� ��������
	int* randoms = new int[n];
	int* odds = new int[n]; // ������ �������� ����� �� ����� ���� ������ ���������, �����?
	//���������� ���������� � �������� ������������
	int oddNum = 0; // �������� ��� ������� �������� �����
	for (size_t i = 0; i < n; i++) {
		randoms[i] = rand() % 100; // � ������� �� ����� ��� ����� ������ 100
		if (randoms[i] % 2 != 0) { // ���� ��� �������� �����
			odds[oddNum] = randoms[i]; // ������� ��� � ��������������� ������. 
			oddNum++;
		}
	}
	//�����
	std::cout << "Array:\t";
	for (size_t i = 0; i < n; i++) {
		std::cout << randoms[i] << "; ";
	}
	std::cout << "\b\b.\nOdds:\t";
	for (size_t i = 0; i < oddNum; i++) {
		std::cout << odds[i] << "; ";
	}
	std::cout << "\b\b."; // ������� ��������� "; " � ��������� �����
	// ������ �� �����
	delete [] randoms;
	delete [] odds;
}

// ������ 12
/*
����������� ���������, � ������� ����� ������������ ����, ����� ������� ���� ������ ���� ������������ �� �������������� �������. 
��� ���������� ������ ��������� � ������� ��������, � ������������ �� ������ � ����. ������������ ���������� ������ ���������� �������� 
(�������, �����, �����������), ����� ����������� ���������� ������ ���� � ��������� �����.

������� ���������:

	������� ��� ����� ������ �������������;
	������� ��� ������ ������ � ����;
	������ ������ �� �����;
	����� ������ �� �����;
	���������� ������;
	�������� ������;
	����� ���������� �� ��������;
	���������� ���������� ��������;

������� �������� ���������� � ������:
	���� ���������
	����-�� ������������ �����
	�����������
	������� �� ��� �������
	�������������� id�
	����������� ���� ���������
*/

// ����� "��������"
class Worker { // ������ �������� - �����.
	std::string firstName; // ���
	std::string secondName; // �������
	std::string job; // ���������
	unsigned int timeSpent; // ������������ ����
	float hourPayment; // ��������� �����
	float salary; // ��������
public:
	Worker() {
		std::cout << "\nEnter data for new worker.\nFirst name: ";
		std::getline(std::cin, firstName);
		std::cout << "Second name: ";
		std::getline(std::cin, secondName);
		std::cout << "Job: ";
		std::getline(std::cin, job);
		timeSpent = enterInt("Time spent");
		hourPayment = enterFloat("Hour payment");
		salary = timeSpent * hourPayment;
	};
	//�������
	std::string getFirstName() {
		if (firstName != "") {
			return firstName;
		}
		else {
			return "no name";
		}
	}
	std::string getSecondName() {
		if (secondName != "") {
			return secondName;
		}
		else {
			return "No second name";
		}
	}
	std::string getJob() {
		if (job != "") {
			return job;
		}
		else {
			return "no job data";
		}
	}
	unsigned int getTimeSpent() {
		if (timeSpent) {
			return timeSpent;
		}
		else {
			return 0;
		}
	}
	float getHourPayment() {
		if (hourPayment) {
			return hourPayment;
		}
		else {
			return 0;
		}
	}
	float getSalary() {
		if (salary) {
			return salary;
		}
		else {
			return 0;
		}
	}
	//����� � �������
	void print() {
		std::cout
			<< firstName << "\t|\t"
			<< secondName << "\t|\t"
			<< job << "\t|\t"
			<< timeSpent << "\t|\t"
			<< hourPayment << "\t|\t"
			<< salary << "\t|\t"
			<< std::endl;
	}
};
// ���������� �������������� �������
char laborersMenu(); // ������� ������, ����� ���� � ���� �������
Worker newWorker(); // ������� ������ ��������

void laborers() {
	std::vector<Worker> workers; // ��������� ��� �������
	char command; // ������ ��� �������
	//����

	command = laborersMenu();
	//���������
	if (command == 'N') { // ���� ������� ������
		workers.push_back(newWorker());
	}

	// ������
	workers.clear();
}

//�������� ��������������� �������:

char laborersMenu() {
	char command = 0; // �������
	char avaibleChars[] = { 'N','E','F','D', 'S', 'L', 'V', 'C', 'Q' }; // ��� ��������, ����� �� ������� if
	bool isEnteredRight = true;  // ��� �������� ������������ �����
	//������������ ����
	clearAndRewrite("Normal dificulty->TASK 12:\n"
		"Manage workers data, using menu.");
	//����� ����
	std::cout
		<< "Select action:"
		<< "\n[N] Add new worker;"
		<< "\n[E] Edit data;"
		<< "\n[F] Find worker;"
		<< "\n[D] Delete worker;"
		<< "\n[S] Saveto file;"
		<< "\n[L] load from file;"
		<< "\n[V] View all workers;"
		<< "\n[C] Sort data;"
		<< "\n[Q] quit.";
	do { // ���� � ��������� �� ������������
		if (!isEnteredRight) {
			std::cout << "Invalid command. Select from menu. Reenter." << std::endl; // ���� ���� �������� �����������, ������ ����� �����������. ����������
		}
		std::cin.ignore();
		std::cout << "\nAction: ";
		command = enterChar();
		command = toupper(command);
		for (size_t i = 0; i < sizeof(avaibleChars)/sizeof(*avaibleChars); i++) { // ���� �� ������� ���-�� �� ������
			if (command!=avaibleChars[i]) {
				isEnteredRight = false;
			}
			else {
				std::cin.ignore(); // ���� ����� �������, ���� ������
				isEnteredRight = true;
				break;
			}
		}
	} while (!isEnteredRight);
	return command;
}
Worker newWorker() {
	Worker worker;
	return worker;
}