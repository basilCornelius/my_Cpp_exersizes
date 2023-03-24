#pragma once
#include <iostream>
// правильный ввод float значения
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
//правильный ввод целого числа
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
// правильный ввод char значения
char enterChar() { // перегружаем ее же для ответа y/n
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

// заполнение матрицы с отображением ранее введенных значений
void enterStaticMatrixSize256(int width, int height, int matrix[][256]) {  // принимает значения ширины матрицы, высоты и ссылку на саму двухмерную матрицу
	for (auto h = 0; h < height; h++) {
		for (auto w = 0; w < width; w++) {
			system("CLS");
			std::cout << "enter matrix values: " << std::endl << std::endl; // напоминаем что мы делаем
			if (h > 0) { // если это не первая строка
				for (auto y = 0; y < h/* предыдущие строки */; y++) { // выводим предыдущие строки
					for (auto x = 0; x < width; x++) { // выводим символы в предыдущих строках
						std::cout << matrix[y][x] << ";\t";
					}
					std::cout << std::endl;
				}

			}
			// теперь выводим строку, в которую идет ввод значений
			if (w > 0) { // если в этой строке есть еще значения
				for (auto x = 0; x < w /*предыдущие значения*/; x++) {
					std::cout << matrix[h][x] << ";\t";
				}
			}
			std::cin >> matrix[h][w]; // после вывода матрицы вводим значение
		}
	}
}
// заполнение матрицы как динамического массива
void enterDynamicMatrixByPointers(int width, int height, int **matrix) {  // принимает значения ширины матрицы, высоты и ссылку на саму двухмерную матрицу
	for (auto h = 0; h < height; h++) {
		for (auto w = 0; w < width; w++) {
			system("CLS");
			std::cout << "enter matrix values: " << std::endl << std::endl; // напоминаем что мы делаем
			if (h > 0) { // если это не первая строка
				for (auto y = 0; y < h/* предыдущие строки */; y++) { // выводим предыдущие строки
					for (auto x = 0; x < width; x++) { // выводим символы в предыдущих строках
						std::cout << *(*(matrix + y)+x) << ";\t";
					}
					std::cout << std::endl;
				}

			}
			// теперь выводим строку, в которую идет ввод значений
			if (w > 0) { // если в этой строке есть еще значения
				for (auto x = 0; x < w /*предыдущие значения*/; x++) {
					std::cout << *(*(matrix + h) + x) << ";\t";
				}
			}
			std::cin >> *(*(matrix + h) + w); // после вывода матрицы вводим значение
		}
	}
}

// очистка экрана и перенаписание шапки
void clearAndRewrite(std::string text) {
	system("CLS");
	std::cout << text << std::endl;
}