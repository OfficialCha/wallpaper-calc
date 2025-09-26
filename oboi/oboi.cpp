#include <iostream>
#include <Windows.h>
#include <cmath>
#include <stdlib.h>
#include <psapi.h>
#include <vector>

using namespace std;

int roomdata[3]{ 600,400,300 }; // {}     { 530,530,200 } - �������� ��� ����� ������.		�������  
int rolldata[2]{ 100,700 }; // {}				{53,1000} - �������� ��� ����� ������.			����� 
float roomPerimeter = 0;
double roomArea = 0;
float usableRoll = 0; //���������� ��������� � ������������� ��������
float lenCount = 0; //���������� ����� ������ � ����� ���� ����
float buyCount = 0; //������� ���� ������
float excess = 0;

void validArrayFill()
{
	string words[3]{" �����: "," ������: "," ������: "};
	cout << "���� ������ ������� � ������ � �����������!" << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "��� ������� �������" << words[i];
		//���������������� ���� ������ �������, � ��������� �� int, > 0
		while (!(cin >> roomdata[i]) or roomdata[i]<=0) {
			cout << "	������! ������� ����� ������������� �����: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "��� ������ �������" << words[i + 1];
		//���������������� ���� ������ �������, � ��������� �� int, > 0
		while (!(cin >> rolldata[i]) or rolldata[i]<=0)
		{
			cout << "	������! ������� ����� ������������� �����: ";
			cin.clear();
			cin.ignore(1000, '\n');
			
		}
	}
	//�������� (������ ������� > ������ ������)
	while (rolldata[1] < roomdata[2])
	{
		cout << "������! ������ ������ (" << rolldata[1] << " ��) �� ����� ���� ������ ������ ������� (" << roomdata[2] << " ��). \n	������� ����� �������� ������ ������: ";

		while (!(cin >> rolldata[1]) or rolldata[1] <= 0)
		{
			cout << "	������! ������� ����� ������������� �����: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//validArrayFill();

	roomPerimeter = 2 * (roomdata[0] + roomdata[1]); //2120
	roomArea = roomPerimeter * roomdata[2]; //424000.0
	usableRoll = floor(rolldata[1] / roomdata[2]); //5
	lenCount = ceil(roomPerimeter / rolldata[0]); //40.0
	buyCount = ceil(lenCount / usableRoll); //40.0/5=8

	excess = (((buyCount * (rolldata[0] * rolldata[1])) - roomArea) / roomArea) * 100;

	cout << "���� ������: " << buyCount << endl;
	cout << "�������: " << excess << "%" << endl;

	system("pause");

	return 0;
}