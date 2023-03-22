#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "fineEnterFunctions.h"
#include <vector>


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

	std::string entered;
	char command;
	do {
		std::cout << "enter string (250 chars max): ";
		std::cin >> entered; // ������ ������
		if (entered.size() > 250) { // ��������� ������
			entered.clear();
			std::cout << "entered string contents more that 250 symbols" << std::endl;
		}
		else {
			break;
		}
	} while (true);

	std::cout << "\nSelect modificator:"
		<< "\n'1' - CAPS"
		<< "\n'2' - low register"
		<< "\n'3' - Every Word Is Capitalised"
		<< "\n'4' - eVERY fIRST sYMBOL iN lOW rEGISTER"
		<< "\n'5' - First letter is capitalised"
		<< "\n 'x' or 'X' - finish"
		<< std::endl;
	do {
		std::cout << "Choose modification: ";
		std::cin >> command;
		if (
			command != '1' 
			|| command != '2'
			|| command != '3'

			) {

		}
	} while (true);

}