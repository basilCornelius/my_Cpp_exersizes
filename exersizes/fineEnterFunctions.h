#pragma once
#include <iostream>
// ���������� ���� float ��������
float enterFloat(std::string valueName) {
	float value;
	do {
		std::cout << valueName << " = ";
		if (std::cin >> value) {
			break;
		}
		else {
			std::cout << std::endl << valueName << " must be a float!" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
	} while (true);
	return value;
}
//���������� ���� ������ �����
int enterInt(std::string valueName) {
	int value;
	do {
		std::cout << valueName << " = ";
		if (std::cin >> value) {
			break;
		}
		else {
			std::cout << std::endl << valueName << " must be an integer!" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
	} while (true);
	return value;
}
// ���������� ���� char ��������
char enterChar() { // ����������� �� �� ��� ������ y/n
	char value;
	do {
		if (std::cin >> value && std::cin.good()) {
			break;
		}
		else {
			std::cout << "unknown command. Use letters to approve (y) or deny (any)." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');;
		}

	} while (true);
	return value;
}

// ���������� ������� � ������������ ����� ��������� ��������
void enterStaticMatrixSize256(int width, int height, int matrix[][256]) {  // ��������� �������� ������ �������, ������ � ������ �� ���� ���������� �������
	for (auto h = 0; h < height; h++) {
		for (auto w = 0; w < width; w++) {
			system("CLS");
			std::cout << "enter matrix values: " << std::endl << std::endl; // ���������� ��� �� ������
			if (h > 0) { // ���� ��� �� ������ ������
				for (auto y = 0; y < h/* ���������� ������ */; y++) { // ������� ���������� ������
					for (auto x = 0; x < width; x++) { // ������� ������� � ���������� �������
						std::cout << matrix[y][x] << ";\t";
					}
					std::cout << std::endl;
				}

			}
			// ������ ������� ������, � ������� ���� ���� ��������
			if (w > 0) { // ���� � ���� ������ ���� ��� ��������
				for (auto x = 0; x < w /*���������� ��������*/; x++) {
					std::cout << matrix[h][x] << ";\t";
				}
			}
			std::cin >> matrix[h][w]; // ����� ������ ������� ������ ��������
		}
	}
}
// ���������� ������� ��� ������������� �������
void enterDynamicMatrixByPointers(int width, int height, int **matrix) {  // ��������� �������� ������ �������, ������ � ������ �� ���� ���������� �������
	for (auto h = 0; h < height; h++) {
		for (auto w = 0; w < width; w++) {
			system("CLS");
			std::cout << "enter matrix values: " << std::endl << std::endl; // ���������� ��� �� ������
			if (h > 0) { // ���� ��� �� ������ ������
				for (auto y = 0; y < h/* ���������� ������ */; y++) { // ������� ���������� ������
					for (auto x = 0; x < width; x++) { // ������� ������� � ���������� �������
						std::cout << *(*(matrix + y)+x) << ";\t";
					}
					std::cout << std::endl;
				}

			}
			// ������ ������� ������, � ������� ���� ���� ��������
			if (w > 0) { // ���� � ���� ������ ���� ��� ��������
				for (auto x = 0; x < w /*���������� ��������*/; x++) {
					std::cout << *(*(matrix + h) + x) << ";\t";
				}
			}
			std::cin >> *(*(matrix + h) + w); // ����� ������ ������� ������ ��������
		}
	}
}

// ������� ������ � ������������� �����
void clearAndRewrite(std::string text) {
	system("CLS");
	std::cout << text << std::endl;
}