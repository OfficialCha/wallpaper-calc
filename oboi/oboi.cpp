#include <iostream>
#include <Windows.h>
#include <cmath>
#include <stdlib.h>
#include <psapi.h>
#include <vector>

using namespace std;

int roomdata[3]{ 625,400,300 }; // {}     { 530,530,200 } - значения для теста логики.		Комната  
int rolldata[2]{ 100,700 }; // {}				{53,1000} - значения для теста логики.			Рулон 
float roomPerimeter = 0;
double roomArea = 0;
float rollArea = 0;
int usableRoll = 0; //количество пригодных к использованию отрезков
float lenCount = 0; //количество ширин рулона в длине всех стен
float buyCount = 0; //сколько надо купить
float heightExcessPerRoll = 0;
int excess = 0;

void validArrayFill()
{
	string words[3]{" длину: "," ширину: "," высоту: "};
	cout << "Ввод данных комнаты и рулона в сантиметрах!" << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Для комнаты введите" << words[i];
		//пользовательский ввод данных комнаты, с проверкой на int, > 0
		while (!(cin >> roomdata[i]) or roomdata[i]<=0) {
			cout << "	Ошибка! Введите целое положительное число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "Для рулона введите" << words[i + 1];
		//пользовательский ввод данных комнаты, с проверкой на int, > 0
		while (!(cin >> rolldata[i]) or rolldata[i]<=0)
		{
			cout << "	Ошибка! Введите целое положительное число: ";
			cin.clear();
			cin.ignore(1000, '\n');
			
		}
	}
	//проверка (высота комнаты > высота рулона)
	while (rolldata[1] < roomdata[2])
	{
		cout << "Ошибка! Высота рулона (" << rolldata[1] << " см) не может быть меньше высоты комнаты (" << roomdata[2] << " см). \n	Введите новое значение высоты рулона: ";

		while (!(cin >> rolldata[1]) or rolldata[1] <= 0)
		{
			cout << "	Ошибка! Введите целое положительное число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	validArrayFill();

	roomPerimeter = 2 * (roomdata[0] + roomdata[1]); //2050
	roomArea = roomPerimeter * roomdata[2]; //300000 or 307500
	rollArea = rolldata[0] * rolldata[1]; //70000
	usableRoll = floor(rolldata[1] / roomdata[2]); //2
	lenCount = (roomPerimeter / rolldata[0]); //20.5
	buyCount = ceil(ceil(lenCount) / usableRoll); //21/2=11
	heightExcessPerRoll = (rolldata[1] - (usableRoll * roomdata[2]))*rolldata[0]; //(высотарулона-(полезная высота))*ширинарулона = площадь обрезков по высоте
	
	
	int startExcess1 = (buyCount * rolldata[0] * usableRoll - roomPerimeter);
	if (!((startExcess1 / 50) % usableRoll == 0))
	{
		startExcess1 += (roomdata[2] * startExcess1);//схуяли это работает
	}
	
	
	excess = (((buyCount * heightExcessPerRoll) + startExcess1) / (buyCount * rollArea)) * 100;

	cout << "Надо купить: " << buyCount << endl;
	cout << "Избыток: " << excess << "%" << endl;

	system("pause");

	return 0;
}