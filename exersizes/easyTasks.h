#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include "fineEnterFunctions.h"

// ЗАДАЧА 1
// Алгебраическая сумма :
/* Найти Y, если Y = X1 + X2 + … + Xn,   X = Z^3 - B + A^2 / tg^2?. Количество X вводятся пользователем программы. 
Для каждого X значения Z, B, А, ? разные (вводятся пользователем программы).
*/
void algebraicSumm1() {
	struct Values // структура значений для каждой Х
	{
		float Z;
		float A;
		float B;
		float Betta;
	};
	Values CurrentValuesPack; // структура копируется, поэтому удобнее заполнять вектор через временную структуру. 
	std::vector<Values>Xs;// массив, куда все будем упаковывать
	char userAnswer = 'y';
	do {
		system("CLS"); // очистить экран от результатов ввода
	//сообщаем что делаем и для чего
		std::cout << "TASK 1: \n X = Z^3 - B + A^2 / tg^2. Enter Z, B and A values for any X in your algebraic summ." << std::endl;
		//вводим данные
		CurrentValuesPack.Z = enterFloat("Z");
		CurrentValuesPack.A = enterFloat("A");
		CurrentValuesPack.B = enterFloat("B");
		CurrentValuesPack.Betta = enterFloat("Betta");

		//копируем структуру в вектор
		Xs.push_back(CurrentValuesPack);

		//вывод введенных данных на экран красиво
		std::cout << std::endl << "Entered Data:" << std::endl;
		// Z
		std::cout << "Zz:" << '\t';
		for (size_t i = 0; i < Xs.size(); i++) {
			std::cout << Xs[i].Z << '\t';
		}
		std::cout << std::endl;
		//A
		std::cout << "Aa:" << '\t';
		for (size_t i = 0; i < Xs.size(); i++) {
			std::cout << Xs[i].A << '\t';
		}
		std::cout << std::endl;
		//A
		std::cout << "Bb:" << '\t';
		for (size_t i = 0; i < Xs.size(); i++) {
			std::cout << Xs[i].B << '\t';
		}
		std::cout << std::endl;
		//Betta
		std::cout << "Betta:" << '\t';
		for (size_t i = 0; i < Xs.size(); i++) {
			std::cout << Xs[i].Betta << '\t';
		}
		std::cout << std::endl;
		std::cout << "Enter new values set (y), or get result (any key):";
		userAnswer = enterChar();
	} while (userAnswer == 'y' || userAnswer == 'Y');
	

	//когда ввели все, что нужно, вычисляем, собственно. алгебраическую сумму: X = Z^3 - B + A^2 / tg^2
	float summ = 0;
	for (size_t i = 0; i < Xs.size(); i++)
	{
		summ += (pow(Xs[i].Z, 3) - Xs[i].B + pow(Xs[i].A, 2)) / tan(Xs[i].Betta);
	}

	std::cout << "\n allgebraic summ of all X's is: " << summ << std::endl;

	return;
}

//ЗАДАЧА 2
//Алгебраическая сумма 1^k + 2^k + 3^k + … + N^k
/*Найти алгебраическую сумму для выражения: 1k + 2k + 3k + … + Nk. N и степень k вводит пользователь.*/
void algebraicSumm2() {
	float terms;
	float power;
	float summ = 0;

	system("CLS"); // чистим экран и объявляем о выполняемой задаче
	std::cout << "TASK 2: \n 1^k + 2^k + 3^k + … + N^k" << std::endl;
	std::cout << std::endl;

	terms = enterFloat("Number of terms");
	power = enterFloat("power");

	std::cout << " \nFinal result:" << std::endl;
	for (size_t i = 0; i < terms; i++)
	{
		if (i+1 < terms) {
			std::cout << i+1 << '^' << power << " + ";
		}
		else {
			std::cout << i+1 << '^' << power << " = ";
		}
		
		summ += pow(i+1, power);
	}
	std::cout << summ << std::endl;
}

//ЗАДАЧА 3
/*Организовать ввод двухзначного натурального числа с клавиатуры. Программа должна определить наименьшую и наибольшую цифры,
которые входят в состав данного натурального числа. */
void whichDigitIsGreater() {
	int enteredNumber; // введенное число
	int reminder; // остаток
	do
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');

		system("CLS");
		std::cout << "TASK 3" << std::endl; 
		std::cout << "Enter two digits number (10 - 99). The program will determine which digit is greater." << std::endl;
		std::cout << "\nEnter two digits integer number (10 - 99): ";

		if (std::cin >> enteredNumber && enteredNumber >9 && enteredNumber <100) { //если все правильно введено
			reminder = enteredNumber % 10;
			system("CLS");
			std::cout << "\nEntered number consist of two digits: " << (enteredNumber - reminder) / 10 << " and " << reminder << std::endl;
			//Если десятки больше
			if (((enteredNumber - reminder) / 10) > reminder) {
				std::cout << std::endl << ((enteredNumber - reminder) / 10) << " > " << reminder << std::endl << std::endl;
			}
			else if (((enteredNumber - reminder) / 10) < reminder)
			{
				std::cout << std::endl << ((enteredNumber - reminder) / 10) << " < " << reminder << std::endl << std::endl;
			}
			else
			{
				std::cout << std::endl << ((enteredNumber - reminder) / 10) << " = " << reminder << std::endl << std::endl;
			}
			break;
		}
		//если неправильно, то вводим заново
		std::cout << "For this simple task needed just two digits integer number (10 - 99)" << std::endl;
	} while (true);
}

//ЗАДАЧА 4
/* Напишите программу , в которой по извесной начальной скорости V и времени полета тела T определяется угол aльфа 
под которым тело брошено по отношению к горизонту (воспользуйтесь соотношением a = arcsin(gT/2V) ). */
void flightAngle() {
	float v; // начальная скорость
	float t; // время полетв
	float G = 9.8; //гравитационная постоянная
	const float PI = asinf(1);

	system("CLS");
	//Рассказываем о задаче
	std::cout << "TASK 4:" << std::endl;
	std::cout << "Function determines angle of trowed body, using entered start velocity (V) and time of flight (T) by a = arcsin(gT/2V)."
		<< std::endl << std::endl;
	v = enterFloat("start velocity talue (V)");
	t = enterFloat("time of flight (T)");
	system("CLS");
	std::cout << "angle of flying body, throwed with velocity " << v << ", flied " << t << " is " << asinf((G * t) / (2 * v)) * (90/PI) << std::endl << std::endl;
}

//ЗАДАЧА 5
/*Возвести, введенное с клавиатуры число, в степень n, степень тоже вводится с клавиатуры. Возведение в степень организовать с использованием циклов.
Примечание: не использовать функцию pow для нахождения степени. */
void noPowPower() {
	float foundation; // число
	int pow; // степень
	float result; // результат

	system("CLS");
	std::cout << "TASK 5: \n "
		<< "Enter foundation and power values and get result... No pow()! Honestly!"
		<< std::endl << std::endl;
	foundation = enterFloat("foundation");
	pow = enterInt("power");
	result = 1;
	//если не 0 то вычисляем, используя цикл
	if (pow != 0)
	{
		for (size_t i = 0; i < pow; i++)
		{
			result *= foundation;
		}
	}
	else
	{
		result = 1;
	}
	system("CLS");
	std::cout << foundation << '^' << pow << " = " << result << std::endl << std::endl;
}

//ЗАДАЧА 6:
/*по введенному номеру дня недели вывести его название, используя оператор множественного выбора.
Нумерация дней недели начинается с 1 – понедельник, 2 — вторник и т.д.*/
//чот задачки все проще и проще
void selectDay() {
	int selection; // переменная выбора
	system("CLS"); //очищаем экран
	std::cout << "TASK 6:\nSelect day, entering number." << std::endl;
	std::cout //выводим условие
		<< "\n\t1.\tMonday"
		<< "\n\t2.\tTuesday"
		<< "\n\t3.\tWednesday"
		<< "\n\t4.\tThursday"
		<< "\n\t5.\tFriday"
		<< "\n\t6.\tSaturday"
		<< "\n\t7.\tSunday" 
		<< std::endl << std::endl;

	do // корректный ввод должен быть 1 - 7, поэтому проверка в проверке
	{
		selection = enterInt("day number"); //вводим число, используя йункцию с проверкой
		if (selection > 0 && selection <= 7) // если введенное число соответствует условию
		{
			switch (selection) {
			case 1: std::cout << "\nMonday!\n" << std::endl; break;
			case 2: std::cout << "\nTuesday!\n" << std::endl; break;
			case 3: std::cout << "\nWednesday!\n" << std::endl; break;
			case 4: std::cout << "\nThursday!\n" << std::endl; break;
			case 5: std::cout << "\nFriday!\n" << std::endl; break;
			case 6: std::cout << "\nSaturday!\n" << std::endl; break;
			case 7: std::cout << "\nSunday!\n" << std::endl; break;
			default: break;
			}
			break;
		}
		else
		{
			std::cout << "There is just 7 days in the week. Select number 1 - 7! " << std::endl;
		}
	} while (true);
}

//ЗАДАЧА 7:
/*программа, которая позволяет пользователю ввести в консоль три координаты вектора x, y, и z, с основанием у начала координат. 
Вычислите длину этого вектора и выведите её обратно в консоль.*/
void vectorLength() {
	system("CLS");
	std::cout << "TASK 7:\nEnter x, y and z values of vector and get its length." << std::endl;
	float x, y, z = 0; //координаты
	x = enterFloat("x");
	y = enterFloat("y");
	z = enterFloat("z");

	std::cout << "vector length is " << sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2)) << std::endl << std::endl;
}

//ЗАДАЧА 8:
/*Вычислить все значения функции z(x,m) = xm sinm(xm), не используя функцию pow, для значений аргументов:
    x от -1.1 до 0.3 с шагом 0.2;
    m от 1 до 5 с шагом 1.            */
void noPowFunction() {
	std::cout  // объявляем задачу
		<< "TASK 8:\nCalculate values of function Z(X,m) = X^m * SIN^m(X*m), no using pow() function"
		<< "\nX is from -1.1 to 0.3 with step 0.2;"
		<< "\nm is from 1 to 5 with step 1"
		<< std::endl
		<< std::endl;
	//переменные 
	float x = -1.1;
	float xStep = 0.2; // шаг для значения X
	float m = 1;
	float xPowM = 1; //X в степени m, вычисленный без использования pow()
	float sinPowM = 1; //то же для синуса
	//цикл
	do // каждое значение Х
	{
		std::cout << "X = " << x << std::endl;
		do // каждое значение m
		{
			xPowM *= x;
			sinPowM *= sinf(x * m);
			std::cout << "\t m = "<< m << ":  Z(X, m) = " << xPowM * sinPowM << std::endl;
			m++;
		} while (m <=5);
		x += xStep;
		m = 1; // m снова равен 1 по условию задачи. 
	} while (x<=0.3);
}

//Задача 9:
/*Дан одномерный массив, длину массива задаёт пользователь. Вычислить сумму квадратов тех чисел, модуль которых превышает значение 2,5.*/
void twoAndHalfSquared() {
	system("CLS");
	//описание
	std::cout 
		<< "TASK 9:\nEnter numbers into array, then get the squared ones, which >= 2.5 (modulo)"
		<< std::endl;
	//переменные
	int arrSize; // размер массива, который введет пользователь. Но я бы юзал вектор лучше. Ну да ладно
	arrSize = enterInt("size of array"); // вводим, не стесняемся
	float *myArray = new float [arrSize]; // создаем динамический массив
	float sum = 0; // для суммы
	//Решение
	//заполняем массив числами:
	for (size_t i = 0; i < arrSize; i++)
	{
		myArray[i] = enterFloat(std::to_string(i+1) + "th value");
	}
	system("CLS"); // очистим экран после ввода
	//и выведем массив на экран:
	std::cout << "Entered " << arrSize << " numbers are:" << std::endl;
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cout << myArray[i];
		i + 1 != arrSize ? std::cout << ", " : std::cout << '.' << std::endl; // если последний элемент в массиве, то ставим точку. Иначе - запятую
	}
	//суммируем подходящие числа
	for (size_t i = 0; i < arrSize; i++)
	{
		if (abs(myArray[i]) >= 2.5)
		{
			sum += powf(myArray[i], 2);
		}
	}
	//когда стало понятно, что это был последний подходящий элемент, удаляем запятую и пробел и ставим точку
	//с помощью классной команды \b
	std::cout << "Summ of values greater or equale |2.5| is "  << sum 
		<< std::endl 
		<< std::endl;
	delete [] myArray; //подчищаем за собой
}

//ЗАДАЧА 10:
/*Вычислить значение выражения по формуле (все переменные принимают действительные значения): (1-tg x)^(ctg x)+ cos(x-y).*/
void taskTen() {
	//ОПИСАНИЕ
	system("CLS");
	std::cout << "TASK 10:\nEnter X and Y values and get (1-tg x)^(ctg x)+ cos(x-y) result." << std::endl << std::endl;
	
	//ПЕРЕМЕННЫЕ
	float x, y; 
	const double pi = 3.141592;

	//РЕШЕНИЕ
	//ввод переменных от пользователя
	x = enterFloat("x (degree)");
	y = enterFloat("y (degree)");
	x = x * pi / 180;
	y = y * pi / 180;// перевод в радианы
	std::cout
		<< "(1-tg x)^(ctg x)+ cos(x-y) = "
		<< pow ( 1-tan(x), (sin(x) / cos(x))) + cosf(x - y)
		<< std::endl << std::endl;
}

//ЗАДАЧА 11:
/*Конгруэнтный метод создания псевдослучайных чисел.
Из условия задачи не понял ничего, пришлось гуглить*/
void congruentRnd() {
	system("CLS");
	std::cout << "TASK 11:\nCreate congruent generator random numbers, using formula: Xn+1 = (a*Xn + C) mod M\n";
	int m = 350 ; //модуль  >=2 для деления с остатком
	int a = 270; //множитель (0 <= a < m);
	int c = 330; // приращение (0 <= c < m) 
	int x = 1; //начальное значение (0 <= X < m)
	float floatX; // десятичное значение

	//выведем 15 чисел
	std::cout << std::endl << "15 random numbers:" << std::endl << std::setprecision(2);
	for (size_t i = 0; i < 15; i++)
	{
		x = ((x * a + c) / 160) % (m +1);
		floatX =  (x / float(m));
		std::cout << floatX << ", ";
	}
	std::cout << "\b\b." 
		<< std::endl 
		<< std::endl;
}

//ЗАДАЧА 12
/*Определить номер четверти плоскости, в которой находится точка с координатами X и Y , причем XY != 0. Координаты вводить с клавиатуры.*/
void determineQuad() {
	system("CLS");
	std::cout << "TASK12:\n"
		<< "Program etermines quadrant of entered X and Y values"
		<< std::endl;
	int x, y; //координаты
	int quadNum[2][2] = { {0, 0}, {0, 0} };
	x = enterInt("x");
	y = enterInt("y");

	system("CLS");
	std::cout << "TASK12:\n"
		<< "Program etermines quadrant of entered X and Y values"
		<< std::endl
		<< std::endl;
	std::cout << "Entered values are: X = " << x << "; Y = " << y << std::endl;
	std::cout << std::endl;
		
	//Если оба значения не равны 0
	if (x != 0 && y != 0)
	{
		if (x > 0) {
			y > 0 ? std::cout << "I quad" << std::endl : std::cout << "IV quad" << std::endl;
		}
		if (x < 0)
		{
			y > 0 ? std::cout << "II quad" << std::endl : std::cout << "III quad" << std::endl;
		}
	}

	//если какое-то значение == 0
	if (x == 0 && y != 0)
	{
		y > 0 ? std::cout << "I or II quad" << std::endl : std::cout << "II or IV quad" << std::endl;
	}
	if (y == 0 && x != 0)
	{
		x > 0 ? std::cout << "I or IV quad" << std::endl : std::cout << "II or III quad" << std::endl;
	}
	if (y == 0 && x == 0) {
		std::cout << "this is a center. No quads" << std::endl;
	}
}

//ЗАДАЧА 13
/*Составить алгоритм определяющий, есть ли среди цифр введенного трехзначного числа — одинаковые. Число вводится с клавиатуры.
Сделал чуть больше, чем было нужно. Программа не только отмечает, что повторы есть, но и показывает такие цифры*/
void isEqualDigits() {
	//описание
	
	//переменные
	unsigned long num;
	int currentDigit; // переменная для конкретной цифры, которая будет сравниваться.
	std::vector <int> digits; //контейнер для хранения цифр
	std::vector <int> repeatedDigits; // соберем сюда повторяющиеся цифры
	char userAnswer = 'y';
	//выполнение
	system("CLS");
	std::cout << "TASK 13:\nAlgorithm defines if equal digits are in entered number" << std::endl;
	num = enterInt("integer number");
	//определить разрядность
	//std::cout << "Entered: " << num << std::endl << std::endl;
	digits.push_back(num % 10);
	int num2 = num - num % 10; 
	while (true)
	{
		if (!(num2 /= 10))
		{
			break;
		}
		digits.push_back(num2%10);
	}
	//сравнить все цифры
	do
	{
		currentDigit = digits[digits.size() - 1]; // текущая цифра - это последний элемент в векторе
		digits.pop_back(); //удаляем последний элемент
		if (std::find(digits.begin(), digits.end(), currentDigit) != digits.end())// если находим число в контейнере
		{
			repeatedDigits.push_back(currentDigit); // добавляем число в массив с повторяемыми значениями
			for (auto i = digits.begin(); i != digits.begin(); i++) // удаляем все повторы из контейнера с исходными цифрами
			{
				if (*i == currentDigit)
				{
					digits.erase(i);
				}
			}
		}

	} while (!digits.empty());

	if (!repeatedDigits.empty()) //если повторы есть
	{ //выводим повторяющиеся значения
		std::cout << "repeating digits are: ";
		for (auto i : repeatedDigits)
		{
			std::cout << i << ", ";
		}
		std::cout << "\b\b." << std::endl; //если вывод закончен, меняем последнюю запятую на точку. 
	}
	else { //если повторов нет
		std::cout << "There is not any repeating digit in entered number1" << std::endl;
	}
	repeatedDigits.clear(); // очистим контейнер
}

//ЗАДАЧА 14
/*Дан текст произвольной длины оканчивающийся символом  '#'. Определить количество строк в тексте, 
каждая строка заканчивается символом перевода строки '\n'*/
void countRows() {
	system("CLS");
	std::cout << "TASK 14:\nEnter text. Algorythm counts rows. Use '#' character for finish " << std::endl;
	char ch;
	int rowsCount = 0;
	std::cout << "Enter text:" << std::endl;

	while ((ch = std::cin.get()) != '#')
	{
		if (ch == '\n') rowsCount++;

	};
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << std::endl << "Total rows entered: " << rowsCount << std::endl;
}

//ЗАДАЧА 15:
/*Напишите программу, которая должна определить, пройдет ли кирпич в отверстие. 
Размеры отверстия (длина и высота) вводит пользователь. Тоже самое касается габаритов кирпича, пользователь вводит 
в программу значения длины, ширины и высоты кирпича.*/
void checkBrick() {
	//описание
	system("CLS");
	std::cout << "TASK 15:\nSet sizes of hole and sizes of brick. Algorythm determines if brick can be pushed in hole." << std::endl;
	//Переменные
	float holeWidth;
	float holeHeight;
	std::vector<float> brick; // размеры кирпича в векторе
	bool isWidthtOk = false; //соотношение с отверстием одной из сторон (равные значения будем считать подходящими)
	bool isHeightOk = false; // соотношение с отверстием второй из сторон (равные значения будем считать подходящими)
	//ввод данных
	holeWidth = enterFloat("hole width");
	holeHeight = enterFloat("hole height");
	for (auto sideNum = 0; sideNum < 3; sideNum++) {
		brick.push_back(enterFloat("side " + std::to_string(sideNum+1))); // вводим данные кирпича. distance() позволяет найти индекс
	}
	//проверка
	for (auto side = brick.begin(); side != brick.end(); side++) {// каждый размер куба сравниваем с каждой стороной отверстия
		if (*side <= holeWidth) { // с шириной отверстия
			isWidthtOk = true; // отмечаем, что одна сторона - ок
			brick.erase(side);//удаляем это значение из вектора
			break; // прервать цикл на случай, если подходящих размеров больше 1
		}
	}
	for (auto i = brick.begin(); i != brick.end(); i++) {
		if (*i <= holeHeight) { // сравниваем оставшиеся грани с высотой отверстия
			isHeightOk = true; // сообщаем, что высота подходит
			break; // прерываем цикл, чтобы не тратить время
		}
	}
	//смотрим на результаты
	if (isHeightOk && isWidthtOk) { // если оба размера пропускают кирпич
		std::cout << "Yes, this brick can be pushed into this hole." << std::endl;
	}
	else {
		std::cout << "No, this brick can't be pushed into this hole." << std::endl;
	}
}

//ЗАДАЧА 16
/*Составить программу, которая будет печатать ромб одним из значков (* или + или #) 
Выбор значков организовать оператором switch.*/
void asciiRomb() {
	//Описание
	system("CLS");
	std::cout << "TASK 16:\nDraw a rhombus, using '*', '+' or '#' with height and width, entered by user" << std::endl;
	//Главные переменные
	unsigned int height; //нечетная высота
	unsigned int width; // нечетная ширина
	unsigned int charNumber; //номер символа
	char selectedChar = ' '; // символ
	char emptyChar = ' '; // символ для пустот (пробел, но пока писал код, нужна была точка)
	//Ввод данных
	do { //провернка на позитивность и четность
		height = enterInt("rhombus height (positive and odd)");
		if ( height <= 0 || height % 2 == 0) { //если введено неверно
			std::cout << "Rhombus height sould be positive and odd!" << std::endl;
		}
		else {
			break;
		}
	} while (true);
	do { // то же самое с шириной
		width = enterInt("rhombus width (positive and odd)");
		if (width <= 0 || width % 2 == 0) { //если введено неверно
			std::cout << "Rhombus width sould be positive and odd!" << std::endl;
		}
		else {
			break;
		}
	} while (true);
	std::cout << "Select symbol:\n\t1.use *\n\t2. use +\n\t3. use #" << std::endl;
	do { // вводим выбор символа
		charNumber = enterInt("symbol number");
		if (charNumber < 1 || charNumber > 3) {
			std::cout << "use 1, 2, or 3 to choose symbol" << std::endl;
		}
		else {
			break;
		}
	} while (true);
	switch (charNumber) { //назначаем символ в зависимости от выбранного числа
	case 1: selectedChar = '*'; break;
	case 2: selectedChar = '+'; break;
	case 3: selectedChar = '#'; break;
	default: selectedChar = ' ';
		break;
	}
	
	/*
	Выполнение
	* попробуем через создание одной диагонали и отзеркаливания ее
	* массив для диагонали 
	*/
	
	//Вспомогательные переменные
	char** rhombus = new char* [height]; //двумерный динамический массив для всего ромба, куда будет отзеркаливаться диагональ
	float proportion = float(height) / float(width); //отношение высоты и ширины
	float x = 0.0; // координата X для диагонали, которую будем округлять до целого
	int xIndexPos = 0; //Округленная координата в массиве символов: X
	int xIndexNeg = 0; // та же координата, но отраженная. Она не отрицательная, а просто ближе к 0
	//заполнение массива ромба пустыми символами (пока точка, чтобы видно было, что там что-то есть)
	for (int h= 0; h< height; h++) {
		rhombus[h] = new char[width];
		for (int w = 0; w < width; w++) {
			rhombus[h][w] = emptyChar;
		}
	}
	//рисуем ромб в массиве
	for (auto h = 0; h < (height+1)/2; h++) {
		x = h / proportion; // y = kx => x = y/k
		x - int(x) >= 0.5 ? xIndexPos = int(x) + 1 : xIndexPos = int(x); // округление координаты xPositive
		// сейчас xIndexPos - это дельта сдвига от центра. На основе ее вычислим отраженную координату xIndexNeg
		xIndexNeg = (width / 2) - xIndexPos;
		xIndexPos += width / 2; // а саму позитивную координату сдвигаем в правый квадрант

		if (xIndexPos < width) { //проверяем выход за границы массива
			rhombus[h][xIndexPos] = selectedChar; // 1 квадрант (+х, +у)
			rhombus[h][xIndexNeg] = selectedChar; // 2 квадрант (-х, +у)
			rhombus[height - h-1][xIndexNeg] = selectedChar; // 3 квадрант (-х, -у)
			rhombus[height - h-1][xIndexPos] = selectedChar;// 4 квадрант (+х, -у)
			if (proportion < 1 && h > 0) {// теперь нужно проверить, если высота меньше ширины, нужно ли дорисовать дополнительный символ в строке
				/*
				х....
				..х..
				....х
				проверяем символ над и слева-сверху текущего символа, если там пусто, закрашиваем предыдущий
				*/
				if (rhombus[h-1][xIndexPos - 1] == emptyChar && rhombus[h-1][xIndexPos] == emptyChar) {
					rhombus[h][xIndexPos-1] = selectedChar; // 1 квадрант (+х, +у)
					rhombus[h][xIndexNeg+1] = selectedChar; // 2 квадрант (-х, +у)
					rhombus[height - h - 1][xIndexNeg+1] = selectedChar; // 3 квадрант (-х, -у)
					rhombus[height - h - 1][xIndexPos-1] = selectedChar;// 4 квадрант (+х, -у)
				}
			}
		}
		else {
			rhombus[h][width - 1] = selectedChar;
			rhombus[h][0] = selectedChar; // если же выход за границы был, вставляем рисующий символ в крайние позиции
		}
	}

	//выводим массив на экран
	std::cout << std::endl << "Your rhombus!" << std::endl;
	for (int yIndex = 0; yIndex < height; yIndex++) {
		for (int xIndex = 0; xIndex < width; xIndex++) {
			std::cout << rhombus[yIndex][xIndex];
		}
		std::cout << std::endl;
	}

	//удалить двумерный массивы:
	for (int i = 0; i < height; i++) {
		delete [] rhombus[i];
	}
	delete[] rhombus;
}


//ЗАДАЧА 17
/*Составить программу, которая на входе должна получать последовательность цифр, после чего  программа показывает цифру, 
порядковый номер которой ввел пользователь.*/
void chooseNumber() {
	system("CLS");
	std::cout << "TASK 17:\nSelect any number from random" << std::endl;
	//сделаем, чтобы было рандомное количество рандомных чисел. 
	srand(time(NULL)); // зерно для рандомайзера
	int numbersCount = rand()%10+1; // количество цифр в массиве.
	int* numbers = new int[numbersCount]; // массив для цифр
	int selection; // переменная для выбора
	//Выполнение
	//заполняем массив рандомом
	for (auto i = 0; i < numbersCount; i++) {
		numbers[i] = rand() % 10;
		std::cout << numbers[i]; //сразу выводим
	}
	std::cout << std::endl;
	//выброть и проверить ввод на попадание в количество возможных
	do {
		selection = enterInt("number of one digit (0 - " + std::to_string(numbersCount) + ")");
		if (selection >0 && selection <= numbersCount) {
			break;
		}
		else {
			std::cout << "selection number must be in range 0 - " << numbersCount << std::endl;
		}
	} while (true);
	std::cout << std::endl << "You have selected " << numbers[selection-1];
	delete[] numbers;
}

//ЗАДАЧА 18
/*
Написать программу преобразования десятичного числа в шестнадцатеричное.
*/
void fromDeciToHex() {
	system("CLS");
	std::cout <<
		"TASK 18\nEnter decimal number and get it hexadecimal value" << std::endl;
	int num = enterInt("decimal number");
	std::cout << "hexagonal " << num << " is: " << std::hex << num;
}

//ЗАДАЧА 19
/*
Программа должна, в качестве входных данных, принимать пятизначные числа и определять, является ли введенное пятизначное число палиндромом.
*/
void isNumberAPalindrom() {
	system("CLS");
	std::cout <<
		"TASK 19\nEnter 5 digits integer value" << std::endl;
	//Не буду делать ввод посимвольно в строку, чтобы введенное число оставалось числом. Вдруг нужно использовать его для чего-то
	//в общем, буду использовать числа
	int enteredNumber;
	int enteredCopy; // переменная для обработки введенного 
	do {
		enteredNumber = enterInt("5 digits integer"); 
		if (enteredNumber <= 9999 || enteredNumber >= 100000) { // проверить на пятизначность
			std::cout << "Entered value is not 5 digits" << std::endl;
		} else {
			break;
		}
	} while (true);
	enteredCopy = enteredNumber;
	//заливаем введенное число поциферно в массив
	int fiveDigits[5] = { 0, 0, 0, 0, 0 };
	int devider = 10;
	for (auto i = 0; i < 5; i++) {
		fiveDigits[i] = enteredCopy % devider;
		enteredCopy -= fiveDigits[i];
		enteredCopy /= 10;
	}
	//теперь восстановим число в обратном порядке
	enteredCopy = 0; //используем для этого уже заведенную переменную
	for (auto i = 0; i < 5; i++) {
		enteredCopy += fiveDigits[i];
		enteredCopy *= 10;
	}
	//делим на 10, потому что после цикла лишнее умножение
	enteredCopy /= 10;
	enteredNumber == enteredCopy ? std::cout << "entered number is palindrome!" : std::cout << "Entered number is not palindrome";
}

//Задача 20
/*

*/
void ctdWithStep() {
	//Честно? Скопипастил готовое решение, так как задача простая, а гуглить школьную программу не хотелось
	//Зато задача 16 про ромб - мое решение, лучше, чем предложенное в источнике
	float h = 0.1, // шаг табулирования
		a = 5.0 / 100, // левая граница интервала
		b = a + 0.5; // правая граница интервала
	std::cout << "y = ";
	for (a; a <= b; a += 0.1) // цикл табулирования функции
	{
		std::cout << std::setprecision(3/*три знака после запятой*/)
			<< pow(cos(log(a)) / sin(log(a)/*ctg(x)=cos(x)/sin(x)*/), 2) << "; "; // запрограммированная формула
	}
	std::cout << std::endl;
}

//Задача 21
/*
Простой тест с вариантами ответов
*/
void simpleTest() {
	system("CLS");
	std::cout << "TASK 21\nSimple test. Read question and choose answer number. Finally get a sum of points" << std::endl <<std::endl;
	//Использую самый простой вариант: последовательное выведение закодированных вопросов и наращивание переменной. Задача Easy и условие подразумевают именно это 
	int totalPoints = 0; //всего очков
	int answerNumber; // выбор варианта ответа
	std::cout << "Test: can you be a pirate! Read question and select a number of right answer." << std::endl << std::endl;
	std::cout << "\nI. You see a old ship. Your decision:\n"
		"1. shout from all weapons!\n"
		"2. take it on abordage!\n"
		"3. Let it go.\n";
	std::cout << std::endl;
	answerNumber = enterInt("answer");
	switch (answerNumber) {
	case 1: totalPoints++; break;
	case 2: totalPoints += 2;  break;
	default:
		break;
	}

	std::cout << "\nII. What drink do you prefer?:\n"
		"1. Green tea\n"
		"2. BLACK tea!!! Jaaaarrr!\n"
		"3. Beer \n"
		"4. Rum\n";
	std::cout << std::endl;
	answerNumber = enterInt("answer");
	switch (answerNumber) {
	case 3: totalPoints++; break;
	case 4: totalPoints += 2;  break;
	default:
		break;
	}

	std::cout << "\nIII. You have lost a limb\n"
		"1. I will do nothing\n"
		"2. I will order a cyber  artificial limb\n"
		"3. wooden stick or iron hook my choise!\n";
	std::cout << std::endl;
	answerNumber = enterInt("answer");
	answerNumber == 3 ? totalPoints++ : totalPoints;

	std::cout << "\nIV. Your pet\n"
		"1. big red parrot!\n"
		"2. wolf with wooden legs\n"
		"3. sheep (because pirates loves ships) \n"
		"4. one eyed monkey with triangle hat\n";
	std::cout << std::endl;
	answerNumber = enterInt("answer");
	switch (answerNumber) {
	case 1: totalPoints +=2; break;
	case 4: totalPoints ++;  break;
	default:
		break;
	}

	std::cout << "\nV. Which girls do you prefer to keep on your ship?\n"
		"1. Blond\n"
		"2. Ginger\n"
		"3. Wooden at the bow of the ship \n"
		"4. No girls on the ship!\n";
	std::cout << std::endl;
	answerNumber = enterInt("answer");
	switch (answerNumber) {
	case 3: totalPoints++; break;
	case 4: totalPoints += 2;  break;
	default:
		break;
	}

	std::cout << "\nVI. What should you do with your loot?\n"
		"1. Give to poor people\n"
		"2. throw away all the treasures in tavern or whorehouse\n"
		"3. bring it to family \n"
		"4. grave it on nameless island and make unreadable map in three pieces, then hide those pieses in different strange places\n";
	std::cout << std::endl;
	answerNumber = enterInt("answer");
	switch (answerNumber) {
	case 2: totalPoints ++; break;
	case 4: totalPoints += 2;  break;
	default:
		break;
	}
	system("CLS");
	std::cout << "final result:" << std::endl;
	if (totalPoints < 4) {
		std::cout << "please! dont stand a pirate! It is not your way..." << std::endl;
		return;
	}
	else if (totalPoints < 9) {
		std::cout << "You can be a pirate, but will not get a title \"Sea Threater\"" << std::endl;
		return;
	}
	else {
		std::cout << "OMG! what is your name& John Silver??" << std::endl;
	}
}

//Задача 22
/*
Найти след матрицы,  след матрицы — сумма элементов главной диагонали. Размер матрицы вводит пользователь, матрицу заполнять случайными числами.
*/
void matrixTrace() {
	system("CLS");
	std::cout
		<< "TASK 22:\nMatrix trace. Enter dimentions of matrix, get matrix with random numbers and it's trace (sum of main diagonal)" << std::endl;
	unsigned int matrixWidth;
	unsigned int matrixHeight;
	srand(time(NULL)); // рандомим рандом
	//вводим данные
	do { // пользователь вводит ширину
		 matrixWidth = enterInt("matrix width (1-10)"); 
		if (matrixWidth < 1 || matrixWidth > 10) {
			std::cout << "Matrix width should be in range from 1 to 10 including. Entered is not." << std::endl;
		}
		else { break; }
	} while (true); 
	do {// и высоту матрицы
		matrixHeight = enterInt("matrix height (1-10)");
		if (matrixHeight < 1 || matrixHeight > 10) {
			std::cout << "Matrix height should be in range from 1 to 10 including. Entered is not." << std::endl;
		}
		else { break; }
	} while (true);
	int matrixTrace = 0; // сумма
	int **matrix = new int*[matrixHeight];
	std::cout << std::endl;//отбиваем строчкой вывод
	std::cout << "Your matrix:" << std::endl;
	for (auto y = 0; y < matrixHeight; y++) { // заполняем матрицу
		matrix[y] = new int[matrixWidth];
		for (auto x = 0; x < matrixWidth; x++) {
			matrix[y][x] = rand() % 100 + 1; // заполняем случайными значениями от 1 до 100
			std::cout << matrix[y][x] << '\t'; // выводим
			x == y ? matrixTrace += matrix[y][x] : matrixTrace;// если число на диагонали, суммируем в переменную
		}
		std::cout << std::endl;
	}
	//выводим сумму:
	std::cout << std::endl << "matrix trace is: " << matrixTrace << std::endl;

	for (auto i = 0; i < matrixHeight; i++) { // удаляем матрицу
		delete matrix[i];
	}
	delete [] matrix;
}

//ЗАДАЧА 23
/*
Внезапно среднее арифметическое массива из float чисел. В задаче описана необходимость создать функцию, которая принимает этот массив и его размер в качестве аргумента. 
Поэтому в функции задачи определяется функция среднего арифметического
*/
void averageFloatArray() {
	system("CLS");
	srand(time(NULL));
	std::cout
		<< "TASK 23:\n Enter size of array. Function takes array with this size and returns average value of random floats in this array" << std::endl
		<< std::endl;
	unsigned int arraySize = enterInt("Array size"); // размер массива
	float* usingArray = new float[arraySize]; // массив
	float averageArr(float *arr, int arrSize); //объяеление функции, которая раскрыта за скобками функции задания (ниже)
	//заполнить массив случайными значениями
	std::cout 
		<< std::endl 
		<< "get your array:\n"
		<< std::endl;
	for (auto i = 0; i < arraySize; i++) {
		usingArray[i] = rand(); // создать значение
		std::cout << usingArray[i] << '\t'; // вывести его
	}
	std::cout << std::endl 
		<< std::endl << "average value is " << averageArr(usingArray, arraySize);
	delete[] usingArray;
}
//определение функции, объявленной в функции задания
float averageArr(float* arr, int arrSize) {
	float summ = 0.0;
	for (auto i = 0; i < arrSize; i++) {
		summ += arr[i];
	}
	return summ / arrSize;
}

//Задача 24
/*
Вычислить сумму 1/sin1+1/(sin1+sin2)+…1/(sin1+…+sinn), где n — заданное натуральное число.
*/
void sumOfSinuses() {
	system("CLS");
	srand(time(NULL));
	std::cout
		<< "TASK 24:\n Enter N and get result of 1/sin1 + 1/(sin1+sin2) + ... 1/(sin1+ ... +sinN)" << std::endl
		<< std::endl;
	int n = enterInt("number af iterations");
	const float PI = 3.14159;
	float denominator =0.0;
	float result = 0.0;
	for (auto i = 1; i <= n; i++) {
		for (auto k = 0; k <= i; k++) {
			denominator += sin(k * PI / 180);
		}
		result += 1 / denominator;
		denominator = 0.0; // обнулить знаменатель
	}
	std::cout << std::endl << std::endl << "1/sin1+1/(sin1+sin2)+ ... 1/(sin1+ ... +sin" << n << ") = " << result << std::endl;
}

//ЗАДАЧА 25
/*
С помощью цикла while разработать программу, которая будет вычислять сумму чисел нацело делящихся на 5. Цикл задать от 0 до введенного с клавиатуры числа.
*/
void devidableByFiveSum() {
	system("CLS");
	std::cout <<
		"TASK 25:\nEnter number and get sum of all numbers, devidable by five, included" << std::endl << std::endl;
	int enteredNumber = enterInt("number"); // исходное число
	int currentDividableNumber = 5; // каждое новое слагаемое
	int summ = 0; // сумма
	 while (currentDividableNumber <= enteredNumber) {
		 summ += currentDividableNumber;
		 currentDividableNumber += 5;
	 };
	 std::cout << "sum of all multiple of five numbers, included in " << enteredNumber << " is: " << summ << std::endl;
}

//ЗАДАЧА 26
/*
Программа должна выводить таблицу квадратов чисел от 1 до 5 (необходимо использовать табуляцию 
и перенос на новую строку, см. управляющие символы). В первом столбце должны находиться числа от 1 до 5 во втором столбце — квадраты этих чисел.
*/
void tableOfPowerTwo() {
	system("CLS");
	std::cout <<
		"TASK 26:\nJust get sqared numbers from 1 to 5 included" << std::endl 
		<< std::endl
		<<"numbers\tSquares" << std::endl
		<< "------\t-------" << std::endl;
	for (auto n = 1; n <= 5; n++) {
		std::cout
			<< n << '\t' << pow(n, 2) << std::endl;
	}
}

//ЗАДАЧА 27
/*
С помощью оператора цикла for, разработать программу, которая будет выводить таблицу умножения введенного пользователем числа с клавиатуры.
*/
void tableOfMultiplication() {
	system("CLS");
	std::cout <<
		"TASK 27:\nEnter number and get table of multiplying it with numbers from 1 to 10" << std::endl
		<< std::endl;
	int sourceNum = enterFloat("number for multiplying");
	for (auto i = 1; i <= 10; i++) {
		std::cout
			<< i << " * " << sourceNum << " = " << i * sourceNum << std::endl;
	}
}

//ЗАДАЧА 28
/*
Программа должна находить точку пересечения двух линий. Даны следующие уравнения: y = ax2 + bx + c и y = dx + k.
*/
void getIntersection() {
	system("CLS");
	std::cout 
		<< "TASK 28:\nEnter data of two graphs:\n\t1) y=ax^2+bx+c;\n\t2) y=kx+b\nAnd get coords of those intersection" << std::endl 
		<< std::endl
		<<"Coefficients for function (y = ax^2 + bx + c):" << std::endl;
	//коэффициенты для 1 графика
	float a = enterFloat("a");
	float b = enterFloat("b");
	float c = enterFloat("c");
	std::cout << "Coefficients for second function (y = kx + b):";
	//коэффициенты для второго графика
	float k = enterFloat("k");
	float bSecond = enterFloat("b");
	//переменные для вычисления
	float bFinal = -1 * (b-k); 
	float cFinal = -1 * (c - bSecond);
	float discriminant = pow(bFinal, 2) - 4 * a * cFinal;
	float xOne = 0.0; // координаты
	float xTwo = 0.0;
	float yOne = 0.0;
	float yTwo = 0.0;
	//Вычисление
	if (discriminant < 0) {
		std::cout << "No intersections." << std::endl;
		return;
	}
	else if (discriminant == 0) {
		xOne = -bFinal / 2 * a;
		yOne = k * xOne + bSecond;
		std::cout << "intersect point is: [" << xOne << " : " << yOne << "]" << std::endl;
		return;
	}
	else if (discriminant > 0) {
		xOne = ( - bFinal + sqrtf(discriminant)) / (2 * a);
		xTwo = ( - bFinal - sqrtf(discriminant)) / (2 * a);
		yOne = a * powf(xOne, 2) + bSecond * xOne + cFinal;
		yTwo= a * powf(xTwo, 2) + bSecond * xTwo + cFinal;
		std::cout << "There are two points of intersection: [" << xOne << " : " << yOne << "] and [" << xTwo << " : " << yTwo << "]" << std::endl;
	}
}

//ЗАДАЧА 29
/*
Программа проверяет, является ли введенное с клавиатуры число — целым числом.
Серьезно?
*/
void isNumberInteger() {
	system("CLS");
	std::cout <<
		"TASK29:\nEnter any number. Function describes if it integer." << std::endl
		<< std::endl;
	float enteredNumber = enterFloat("number to check");
	if (enteredNumber == int(enteredNumber)) {
		std::cout << std::endl << "Entered number is integer" << std::endl;
	}
	else {
		std::cout << std::endl << "Entered number is not integer" << std::endl;
	}
}

//ЗАДАЧА 30
/*
Используя оператор цикла do while, составить программу, которая будет требовать ввод цифр с клавиатуры до тех пор, пока не будет введена цифра 1.
СЕРЬЕЗНО?! После ромба и пересечений графиков?
*/
void enterNumbersTillOne() {
	system("CLS");
	std::cout 
		<< "TASK 30:\nEnter numbers till it will not 1. After entered 1 programm stops." << std::endl 
		<< std::endl;
	float enteredNumber = 0.0;
	do {
		enteredNumber = enterFloat("number");
	} while (enteredNumber != 1);
}

//ЗАДАЧА 31
/*
* Требуется вывести в консоль от 1-го до 6-ти равнобедренных треугольников. Высота и количество треугольников зависят от того какое число введет пользователь.
*/
void someTriangles() {
	system("CLS");
	std::cout
		<< "TASK 31:\nEnter number in range 1 - 6 and get this number of triangles with this height" << std::endl 
		<< std::endl;
	int trianglesHeightAndCount;
	do {
		trianglesHeightAndCount = enterInt("Count and height of triangles (1 - 6)");
		if (trianglesHeightAndCount < 1 || trianglesHeightAndCount > 6) {
			std::cout << "Needed a number in range from 1 to 6" << std::endl;
		}
		else { 
			break; 
		}
	} while (true);
	char* oneHalfTriangle = new char[trianglesHeightAndCount]; // пол-треугольника
	for (auto i = 0; i < trianglesHeightAndCount; i++) { //заполнить массив пробелами
		oneHalfTriangle[i] = ' ';
	}
	// выполнение
	std::cout << std::endl; // зазор
	for (auto row = 1; row <= trianglesHeightAndCount; row++) { // строка
		oneHalfTriangle[trianglesHeightAndCount - row] = '#'; // прибавляем количество рисующих символов с конца массива взамен пробелов
		for (auto triangle = 1; triangle <= trianglesHeightAndCount; triangle++) { //первый треугольник пошел
			for (auto symbol = 0; symbol < trianglesHeightAndCount; symbol++) { // первая половина треугольника
				std::cout << oneHalfTriangle[symbol];
			}
			for (auto symbol = trianglesHeightAndCount - 2; symbol >= 0; symbol--) { // вторая половина треугольника за исключением одного центрального символа
				std::cout << oneHalfTriangle[symbol];
			}
			std::cout << ' '; // пробел между треугольниками
		}
		std::cout << std::endl; // перенос строки
	}
	delete[] oneHalfTriangle; // удалить динамический массив
}
