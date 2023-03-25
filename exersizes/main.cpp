#include <iostream>
#include <string>
#include "fineEnterFunctions.h" //мои функции с проверкой правильности ввода
#include "easyTasks.h"
#include "normalTasks.h"
using namespace std;

char doTask(void (*f)()); //функци€ запускает выбранную задачу и возвращает букву 'm', если нужно повторить меню
char selectEasyTask(); // функци€ дл€ выбора и запуска простых задач
char selectNormalTasks(); // функци€ дл€ выбора и запуска нормальных по сложности задач


/* 
MAIN
*/
int main() {
	system("mode con cols=200 lines=45"); // размер окна побольше
	int enteredNumber; // переменна€ дл€ выбора
	int categoriesCount = 2; // количество категорий, доступных дл€ выбора
	char navigationCommand = 'm'; //навигационна€ команда
	/*
		* переменна€ navigationCommand принимает значени€:
		*	"m" - main menu - нужно быть в главном меню
		*	"t" - task menu - вернутьс€ в меню задач
		*	"f" - finish завершить
	*/

	do {
		system("CLS");
		std::cout <<
			"Tasks from http://cppstudio.com/cat/285/ I have done\n"
			"Select number of dificulty and you will get a filename with code and list with tasks of this dificulty category.\n"
			"I did't done \"Beginner\" dificulty, because it is too easy and not fun. My dificulty list starts from \"Easy\"\n"
			"After selection dificulty, select task number and see how it works" << std::endl
			<< std::endl
			<< "Select category:\n"
			<< "\t[1] : Easy\n"
			<< "\t[2] : Normal\n"
			<< "\t[any another symbol or number] : finish"
			<< std::endl;
		cin >> enteredNumber;
		switch (enteredNumber) { // в зависимости от выбора
		case 1: navigationCommand = selectEasyTask(); break;
		case 2: navigationCommand = selectNormalTasks(); break;
		default: navigationCommand = 'f';
			break;
		}
		if (navigationCommand == 'f') { //если f, программа завершаетс€
			return 0;
		} 
		std::cin.clear();
		std::cin.ignore(256, '\n');
	} while (navigationCommand == 'm');


	std::cout << "Thank you! Bye." << std::endl << std::endl;

	return 0;
}

//определени€ функций, зайвленных перед main
// функци€ запуска задачи. ќборачивает функцию задачи, дава€ возможность перезапускать ее снова и снова
char doTask( void (*f)() ) {
	char userAnswer = 'y';
	do
	{
		f();
		std::cout << std::endl 
			<< "========================================\n"
			<< std::endl << "Do this task again - [y]\n"
			"back to tasks menu [t]\n"
			"back to dificulty menu [m]\n"
			"finish program: [any other key] "
			<<std::endl;

		std::cin >> userAnswer;

	} while (userAnswer == 'y' || userAnswer == 'Y');
	if (userAnswer == 't' || userAnswer == 'T') {
		return 't';
	}
	if (userAnswer == 'm' || userAnswer == 'M') {
		return 'm';
	}
	return 'f';
}

//ќтображение списка и выбор простых задач
char selectEasyTask() {
	int taskSelected = 0; // ответ пользовател€ - выбор номера задачи
	char command = 't';
	system("CLS"); // очистим экран
	do // выбор задачки посмотреть
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		system("CLS");
		std::cout << "Here are tasks of \"Easy\" dificulty category. Choose task number to see result or any another number or symbol to return to previous menu:" << endl;
		std::cout 
			<< "\t 1) algebraic summ Y = X1 + X2 + Е + Xn, where   X = Z^3 - B + A^2 / tg^2? \n"
			<< "\t 2) algebraic summ Y1^k + 2^k + 3^k + Е + N^k \n"
			<< "\t 3) Which digit is greater? \n"
			<< "\t 4) Angle of throwed body \n"
			<< "\t 5) Raising a number to a power using cycle  \n"
			<< "\t 6) Choose a day of the week  \n"
			<< "\t 7) Determine vector length \n"
			<< "\t 8) z(x,m) = x^m * sin^m(x*m), but no pow() function using \n"
			<< "\t 9) Raise to square numbers >=|2.5|\n"
			<< "\t 10) (1-tg x)^(ctg x)+ cos(x-y) with entered X and Y\n"
			<< "\t 11) Congruent method receiving random number\n"
			<< "\t 12) Find a quad of entered X and Y coords\n"
			<< "\t 13) Define if in number equal digits are\n"
			<< "\t 14) Count rows in entered text\n"
			<< "\t 15) Check manching between hole and brick sizes\n"
			<< "\t 16) Draw ASCII romb\n"
			<< "\t 17) Choose number\n"
			<< "\t 18) Convert decimal number to hex\n"
			<< "\t 19) describe is entered 5digits number a palindrome\n"
			<< "\t 20) Tab function y=ctg^2lnx\n"
			<< "\t 21) Simple test: can you be a pirate\n"
			<< "\t 22) Matrix trace \n"
			<< "\t 23) Average value of float array \n"
			<< "\t 24) sum  1/sin1+1/(sin1+sin2)+ ... 1/(sin1+ ... +sinn) with entered n \n"
			<< "\t 25) sum of all multiple by five numbers in entered integer\n"
			<< "\t 26) table of square numbers\n"
			<< "\t 27) table of multiplication of entered number by range 1 -10 \n"
			<< "\t 28) get points of intersection of two function graphs: ax^2 + bx + c and y=kx+b \n"
			<< "\t 29) Check is entered number integer \n"
			<< "\t 30) Enter numbers while not entered 1 \n"
			<< "\t 31) some triangles \n"
			<< "\t any another symbol or number: back to previous menu"
			<< endl;

			cin >> taskSelected; //если ввод неверный, выйдет в главное меню

			//в зависимости от ответа, запускаем нужную функцию из библиотеки задач
			void (*task)(); //указатель на функцию
			switch (taskSelected)
			{
			case 1: command = doTask(&algebraicSumm1); break;
			case 2: command = doTask(&algebraicSumm2); break;
			case 3: command = doTask(&whichDigitIsGreater); break;
			case 4: command = doTask(&flightAngle); break;
			case 5: command = doTask(&noPowPower); break;
			case 6: command = doTask(&selectDay); break;
			case 7: command = doTask(&vectorLength); break;
			case 8: command = doTask(&noPowFunction); break;
			case 9: command = doTask(&twoAndHalfSquared);  break;
			case 10: command = doTask(&taskTen);  break;
			case 11: command = doTask(&congruentRnd); break;
			case 12: command = doTask(&determineQuad); break;
			case 13: command = doTask(&isEqualDigits); break;
			case 14: command = doTask(&countRows);  break;
			case 15: command = doTask(&checkBrick);  break;
			case 16: command = doTask(&asciiRomb);  break;
			case 17: command = doTask(&chooseNumber); break;
			case 18: command = doTask(&fromDeciToHex);  break;
			case 19: command = doTask(&isNumberAPalindrom); break;
			case 20: command = doTask(&ctdWithStep); break;
			case 21: command = doTask(&simpleTest); break;
			case 22: command = doTask(&matrixTrace); break;
			case 23: command = doTask(&averageFloatArray); break;
			case 24: command = doTask(&sumOfSinuses); break;
			case 25: command = doTask(&devidableByFiveSum);  break;
			case 26: command = doTask(&tableOfPowerTwo); break;
			case 27: command = doTask(&tableOfMultiplication); break;
			case 28: command = doTask(&getIntersection); break;
			case 29: command = doTask(&isNumberInteger);  break;
			case 30: command = doTask(&enterNumbersTillOne); break;
			case 31: command = doTask(&someTriangles); break;
			default: return 'm';
			}
	} while (command == 't'); // "Tasks menu" получаем из функции doTask()
	return command;
}

//отображение и выбор задач нормальной сложности
char selectNormalTasks() {
	int taskSelected = 0; // ответ пользовател€ - выбор номера задачи
	char command = 't';
	system("CLS"); // очистим экран
	do // выбор задачки посмотреть
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		system("CLS");
		std::cout << "Here are tasks of \"normal\" dificulty category. Choose task number to see result or any another number or symbol to return to previous menu:" << endl;
		std::cout
			<< "\t 1) Check C code from file to balance \'{}\' brackets \n"
			<< "\t 2) Get result of 1+1/(1+1/(1+1/(1+1/....))) with entered length \n"
			<< "\t 3) Multiply matrix on vector \n"
			<< "\t 4) Enter numbers in recreating dynamics array \n"
			<< "\t 5) Create structures and get them access by pointers \n"
			<< "\t 6) 2d-array filled zigzag\n"
			<< "\t 7) cubic root, no using special functions\n"
			<< "\t 8) String morphing\n"
			<< "\t 9) 10x10 array of random numbers with finding minimal one\n"
			<< "\t 10) Count every entered symbol in string\n"
			<< "\t 11) Find and output all odd numbers from random array\n"
			<< "\t 12) manage workers\n"
			<< "\t any another symbol or number: back to previous menu"
			<< endl;

		cin >> taskSelected; //если ввод неверный, выйдет в главное меню

		//в зависимости от ответа, запускаем нужную функцию из библиотеки задач
		void (*task)(); //указатель на функцию
		switch (taskSelected) {
		case 1: command = doTask(&checkBracketsBalance); break;
		case 2: command = doTask(&fractChain); break;
		case 3: command = doTask(&matrixMultipliedVector); break;
		case 4: command = doTask(&dynamicUnsignedIntArray ); break;
		case 5: command = doTask(&structArray); break;
		case 6: command = doTask(&zigZagArray); break;
		case 7: command = doTask(&cubicRoot); break;
		case 8: command = doTask(&stringMorpher); break;
		case 9: command = doTask(&tenArray); break;
		case 10: command = doTask(&charCounter); break;
		case 11: command = doTask(&findOdds); break;
		case 12: command = doTask(&laborers); break;
		default: return 'm';
		}
	} while (command == 't'); // "Tasks menu" получаем из функции doTask()
	return command;
}