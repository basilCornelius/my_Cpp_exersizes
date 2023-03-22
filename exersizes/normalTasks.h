#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "fineEnterFunctions.h"
#include <vector>


//ЗАДАЧА 1
/*
В текстовом файле, содержащем текст программы на языке Си, проверить соответствие открывающихся и закрывающихся фигурных скобок { и }. 
Результат проверки вывести на экран и записать в виде фразы в текстовый файл. Результат работы программы (вывод) поместить в отдельный текстовый файл (например, "out . txt " ), 
продублировав на экране.
*/
void checkBracketsBalance() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 1:\n"
		"Check do {} brackets stays right in file" << std::endl
		<< std::endl;
	std::string filePath; // путь к файлу
	std::ifstream file; // поток чтения файла
	std::ofstream inFile; // поток записи в файл
	char symbol; // каждый символ файла
	int balance = 0; /*когда фигурная скобка открывается, переменная++, когда закрывается, переменная--.Т.о.получается, что если в конце концов переменная >0?,
				 значит осталась незакрытая скобак, а если меньше - не не хватает открывающей, а есть лишняя закрывающая*/
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
	
	while (file.get(symbol)) { //считаем скобки
		if (symbol == '{') {
			balance++;
		}
		else if(symbol == '}') {
			balance--;
		}
		//если закрывающая появилась прежде открывающей
		if (balance < 0) {
			std::cout << "Wrong place of closing bracket" << std::endl;
			return;
		}
	}
	//анализируем переменную balance
	if (balance > 0) { // если количество закрывающих скобок равно количеству открывающих
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

//ЗАДАЧА 2
/*
Используя показатели функции вычислить цепную дробь. Количество елементов дроби надо задавать с клавиатуры.
1+1/(1+1/(1+1/(1+1/….)))
*/
void fractChain() {
	system("CLS");
	std::cout 
		<< "Normal dificulty -> TASK 2:\n"
		"Enter count of fractions in chain. Get fraction chain like: 1+1/(1+1/(1+1/(1+1/....)))" << std::endl
		<< std::endl;
	int count = enterInt("count of fractions in chain"); // количество дробей в цепи
	float result = 0.0;
	float fracChainRecursion(int count );// функция для рекурсии
	result = fracChainRecursion(count);
	std::cout << result << std::endl
		<< std::endl;
}
float fracChainRecursion(int count) { // описываем заявленную в функции задания функцию
	if (count == 0) return 1;
	return 1 + (1 / (fracChainRecursion(count-1)));
}

//ЗАДАЧА 3
/*
вычислить произведение матрицы на вектор. В полученном векторе найти макисмальный  элемент. необходимо решить данную задачу тремя способами:

	> с использованием статических массивов
	> использовать только динамические массивы с явным разыменованием указателя
	> использовать только динамические массивы, адресацию к элементам массива выполнять с помощью индексов.

*/
void matrixMultipliedVector() { // функция выбора одного из перечисленных требуемых способа
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 3:\n"
		"Programm multiplies matrix by vector. Dimensios of matrix entered by user.\n" 
		"Programm user three ways to solve the task. Result should be the same, but difference in code."<< std::endl
		<< std::endl;

	void matrixMultipliedVectorStatic(int wdt, int hgt); // первый способ решения задачи
	void matrixMultiplyingVectorDynamicPointers(int wdt, int hgt); // второй способ решения задачи
	void matrixMultiplyingVectorUsingIndices(int wdt, int hgt); // третий способ решения задачи
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
// функция умножает матрицу на вектор. Матрица - часть статического двумерного массива 256х256 элементов
void matrixMultipliedVectorStatic(int wdt, int hgt) { // первая функция, решает с помощью статических массивов длиной 256х256 максимум
	if (wdt > 256 || hgt > 256) {
		std::cout << "The way, you have choosen requares 256x256 matrix dimensions maximum! create matrix by this way impossible. \n"
			"Restart program and choose another way." << std::endl;
		return;
	}
	int matrix[256][256]; // статический массив для матрицы
	int vector[256]; // массив для вектора
	int result[256]; // массив для результата. Можно было обойтись без массива - просто выводить результат на экран, но логичестки это вернее, потому что результат - вектор.
	//заполнить матрицу вводом значений
	system("CLS");
	std::cout
		<< "enter matrix values^ " << std::endl
		<< std::endl;

	enterStaticMatrixSize256(wdt, hgt, matrix);// заполнение матрицы

	std::cout << "Enter vector values: " <<std::endl; // теперь вектор
	for (auto v = 0; v < wdt; v++) { // тут попроще
		std::cout << "vector value " << v+1 << ":\t";
		std::cin >> vector[v];
	}
	// умножаем на вектор и выводим результат
	std::cout << std::endl << "Result: " << std::endl;
	for (auto row = 0; row < hgt; row++) {
		result[row] = 0;
		for (auto value = 0; value < wdt; value++) {
			result[row] += matrix[row][value] * vector[value];
		}
		std::cout << result[row] << ";\n";// выводим значение

	}
}
// Функция умножает матрицу на вектор, матрица и вектор - динамические массивы. Доступ к элементам по разыменованию указателей
void matrixMultiplyingVectorDynamicPointers(int wdt, int hgt) { 
	int** matrix = new int* [hgt]; // двумерный динамический массив для матрицы. Инициализируем в функции ввода. 
	int* vector = new int[wdt]; // динамический массив для вектора
	int* result = new int[hgt]; // вектор для результата. По заданию можно было бы обойтись без него, но логичнее выводить результат в массив
	// заполнить матрицу нулями. Иначе компилятор не позволяет использовать ее в функции
	for (auto h = 0; h < hgt; h++) {
		*(matrix + h) = new int[wdt];
		for (auto w = 0; w < wdt; w++) {
			*(*(matrix + h) + w) = 0;
		}
		std::cout << std::endl;
	}
	enterDynamicMatrixByPointers(wdt, hgt, matrix); // заполнить матрицу
	std::cout << "Enter vector values: " << std::endl; // теперь вектор
	for (auto v = 0; v < wdt; v++) { // 
		std::cout << "vector value " << v + 1 << ":\t";
		std::cin >> *(vector + v);
	}
	// умножаем на вектор и выводим результат
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
		std::cout << *(result + row) << ";\n";// выводим значение

	}
	// удаляем динамические массивы
	for (auto i = 0; i < hgt; i++) {
		delete [] matrix[i];
	}
	delete [] matrix;
	delete [] result;
	delete [] vector;
}
// функция умножает матрицу на вектор. Матрица и вектор - динамические массивы, доступ осуществляется по индексу. 
void matrixMultiplyingVectorUsingIndices(int wdt, int hgt) {
	int** matrix = new int* [hgt]; // двумерный динамический массив для матрицы. Инициализируем в функции ввода. 
	int* vector = new int[wdt]; // динамический массив для вектора
	int* result = new int[hgt]; // вектор для результата. По заданию можно было бы обойтись без него, но логичнее выводить результат в массив
	// заполнить матрицу нулями. Иначе компилятор не позволяет использовать ее в функции
	for (auto h = 0; h < hgt; h++) {
		matrix[h] = new int[wdt];
		for (auto w = 0; w < wdt; w++) {
			matrix[h][w] = 0;
		}
		std::cout << std::endl;
	}
	enterDynamicMatrixByPointers(wdt, hgt, matrix); // заполнить матрицу
	std::cout << "Enter vector values: " << std::endl; // теперь вектор
	for (auto v = 0; v < wdt; v++) { // 
		std::cout << "vector value " << v + 1 << ":\t";
		std::cin >> vector[v];
	}
	// умножаем на вектор и выводим результат
	std::cout << std::endl << "Result: " << std::endl;
	for (auto row = 0; row < hgt; row++) {
		result[row] = 0;
		for (auto value = 0; value < wdt; value++) {
			result[row] += matrix[row][value] * vector[value];
		}
		std::cout << result[row] << ";\n";// выводим значение

	}
	// удаляем динамические массивы
	for (auto i = 0; i < hgt; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] result;
	delete[] vector;
}

//Задача 4
/*Задача на динамическое выделение памяти. Изначально есть указатель на массив с одним элементом. Пользователь вводит число. 
Если оно больше 0 записываем его в массив. Далее пользователь вводит второе число, тут уже,  если оно больше 0, 
надо пере выделять память для 2-х элементов массива и записать в массив второе число. И так далее…  для 3-х элементов, для 4-х…  
пока пользователь не введет отрицательное число.*/
void dynamicUnsignedIntArray() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 4:\n"
		"Enter unsigned int numbers untill you entered number < 0. " << std::endl
		<< std::endl;
	int counter = 0; // счетчик введенных чисел
	int entered = 0; // переменная для введенного числа
	int* storage = new int[counter]; // указатель на будущие массивы
	int* secondStorage = new int [counter]; // место, куда будем сохранять введенные ранее числа
	do {
		std::cout << "enter number : "; // запрос ввода
		std::cin >> entered; // ввод
		if (entered >= 0) { // если веденное подходит по условию
			delete[] secondStorage; // пересоздаем второе хранилище
			secondStorage = new int[counter];
			for (auto i = 0; i < counter; i++) { // перемещаем данные из первого массива во второй
				secondStorage[i] = storage[i];
			}
			delete[] storage;  // пересоздаем главный массив
			counter++; // увеличиваем счетчик
			storage = new int[counter]; // создаем хранилице с +1 ячеек
			for (auto i = 0; i < counter-1; i++) { // заполняем новое хранилище старыми данными
				storage[i] = secondStorage[i];
			}
			storage[counter-1] = entered; // добавляем введенное к заполенным ранее данным.
		}
		else { // если введенное < 0, прерываем цикл. 
			break;
		}
	} while (true);
	system("CLS"); // выводим
	std::cout << "data, you have entered:" << std::endl; // выводим данные
	for (auto i = 0; i < counter; i++) {
		std::cout << storage[i] << ", ";
	}
	std::cout << std::endl;
	delete[] storage;
	delete[] secondStorage;
}


// ЗАДАЧА 5
/*Необходимо создать структуру, которая содержит элемент типа int и строку. Объявить указатель типа структуры (объект структуры) 
и выделить память для хранения данных одной структуры. Предложить пользователю внести данные и записать их в элементы объекта структуры. 
Далее пользователю необходимо сделать выбор: внести еще данные (создать еще один объект структуры) либо выйти из программы. 
Если пользователь продолжает ввод — необходимо выделить новую память для указателя на объект структуры и дописать в нее введенные 
пользователем новые данные. Цикл выделения новой памяти продолжается, пока пользователь не выберет выход из программы.*/
void structArray() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 5:\n"
		"Create persons (name and age) as much as you whant." << std::endl
		<< std::endl;

	struct Person { // структура
		std::string name;
		int age; 
	};
	// буду действовать через вектор. Так проще.
	std::vector<Person*> persons; // все персоны
	char answer = 'y'; // ответ на вопрос: "продолжить или нет"
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
	int personNum = 1; // номер персоны для отчета
	for (auto prsn : persons) {
		std::cout << personNum++ << ". " << prsn->name<< ": " << prsn->age << std::endl;
		delete prsn;
	}
}

//ЗАДАЧА 6
/*Требуется написать программу, которая заполняет массив размерности nxn по заданному правилу:
	  1  3  4 10 11
      2  5  9 12 19
      6  8 13 18 20
      7 14 17 21 24
     15 16 22 23 25
То есть, заполнение массива должно быть по диагонали, сверху - вниз, слева - направо.Причем заполнение еще и зигзагообразное.*/
void zigZagArray() {
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 6:\n"
		"Creating array NxN with zigZag filling." << std::endl
		<< std::endl;
	int size = enterInt("side of square array"); // размер массива. Он квадратный
	int** massiv = new int* [size];
	for (auto i = 0; i < size; i++) { // делаем массив двумерным
		massiv[i] = new int[size];
	}
	int w = 0; // координата горизонтального значения двумерного массива
	int h = 0; // координата вертикального значения матрицы
	char direction = 'd'; // направление заполнение. Вверх или вниз
	int value = 0; // значение, которым заполняется массив. 
	do { 
		massiv[h][w] = value;
		value++;
		// проверяем не у краев ли массива
		if (h==size-1 && direction == 'd') { //если достигли нижней границы, двигаясь вниз
			w++; // прыгаем на столбец вперед
			direction = 'u'; // меняем направление
			continue; // скипаем цикл
		}
		if (w == 0 && direction == 'd') { // если у левой границы и двигались вниз
			h++; // прыгаем на строку ниже
			direction = 'u'; // меняем направление
			continue; // скипаем цикл
		}
		if (w == size-1 && direction == 'u') { // если у правого края и двигались вверх
			h++; // прыгаем на строку ниже
			direction = 'd'; // меняем направление
			continue; 
		}
		if (h == 0 && direction == 'u') { // если у верхнего края и движение было вверх
			w++; // следующий столбец
			direction = 'd'; // меняем направление
			continue;
		}
		if (direction == 'd') { // если движемся вниз
			w--;
			h++;
		}
		else if (direction == 'u') { // а если вверх
			w++;
			h--;
		}
	} while ( !(h > size-1 || w > size-1) );
	
	// выводим
	std::cout << std::endl << std::setiosflags(std::ios::left);
	for (auto hgt = 0; hgt < size; hgt++) {
		for (auto wdt = 0; wdt < size; wdt++) {
			std::cout << massiv[hgt][wdt] << ",\t";
		}
		std::cout << std::endl; 
	}
	//чистим
	for (auto i = 0; i < size; i++) {
		delete[]massiv[i];
	}
	delete[]massiv;
}

// ЗАДАЧА 7
/*По заданному вещественному x, вычислить корень кубический из x по следующей итерационной формуле:
yi+1= 0.5 ( yi + 3 x / ( 2 yi2 + x / yi )).
Начальное приближение y0=x. Итерации прекратить при |yi+1-yi|<10^-5. Смысл данного задания — найти корень кубический без использования специальных функций.*/
void cubicRoot() { // функция для запуска
	system("CLS");
	std::cout
		<< "Normal dificulty -> TASK 7:\n"
		"Describe cubic root of entered number" << std::endl
		<< std::endl;
	float x = enterFloat("number to describe cubic root");
	float yi1 = 0.0; // искомое значение y
	float yi = x; // текущее значение y
	while (true) {
		yi1 = 0.5 * (yi + 3 * x / (2 * yi * yi + x / yi));
		if (abs(yi1 - yi) < powf(10.0, -5.0)) {
			break;
		}
		yi = yi1;
	};
	std::cout << "cube " << x << " is " << yi << std::endl;
}

//ЗАДАЧА 8
/*
Программа должна выполнять преобразования строки (длина строки 255 символов):

    1) СТРОКА ЗАГЛАВНЫМИ БУКВАМИ
    2) строка в нижнем регистре
    3) С Заглавной Буквы (Первый Символ Каждого Слова В Строке )
    4) пЕРВЫЙ сИМВОЛ в нИЖНЕМ рЕГИСТРЕ
    5) Как в предложении(с заглавной буквы).
    Символ 'x' или 'X' — выход из программы

Организовать в программе меню, через которое можно удобно выбирать любое действие. Программа должна выполняться пока пользователь не введет  символ 'f'.
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
		std::cin >> entered; // вводим строку
		if (entered.size() > 250) { // проверяем размер
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