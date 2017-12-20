// ConsoleApplication11.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <Windows.h>

using namespace std;

int printmenu();//����
void printarr(int** arr, int rows, int cols);//���� �������
int** deletearr(int** arr, int rows);//�������� �������
int sampling(int chislo);//����� ������
void manualinput(int** arr, int rows, int cols);//���������� ������� � ����������
void randominput(int** arr, int rows, int cols);//��������� ����������
void summarr(int** arr, int rows, int cols);//����� ��������� ���� ������� ���������
void thrinkarr(int** arr, int &rows, int &cols);//������ �������
int main()
{
	setlocale(LC_ALL, "Russian");//������� �����
	setlocale(LC_ALL, "rus");
	int cols = 0, rows = 0, chislo = 0, f = 0, summ = 0, m = 0, t = 0, i = 0, j = 0;
	int **arr = NULL;
	bool Exit = false;


	while (!Exit)
	{
		int menu = 0;
		menu = printmenu();
		
		switch (menu)
		{
		case 1://���� ��������� �������
		{
			
			deletearr(arr, rows);
			f = 1;
			cout << "������� ���������� ����� �������\n";
			rows = sampling(chislo);
			cout << "������� ���������� �������� �������\n";
			cols = sampling(chislo);
			arr = new int*[rows];//������� ���������� (�������)
			for (int i = 0; i < rows; i++)
			{
				arr[i] = new int[cols];
			}
			int t = 0;
			cout << "���� �� ������, ����� ������ ��� �������� ���������� ����������, �� ������� 1.\n���� ������ ��������� ��� ��������������, �� ������� 2\n";
			cin >> t;
			while ((t < 1) || (t > 2))
			{
				cout << "������� ������������ ��������!\n";
				cin >> t;
			}
			if (t == 1)
			{
				randominput(arr, rows, cols);
			}
			else
			{
				manualinput(arr, rows, cols);
			}
			break;
		}
		case 2://����� ��������� ������������� ���� ������� ���������
		{
			
			if (f == 0)
			{
				cout << "������ �����������! ������� ������!\n";
			}
			else
			{
				summarr(arr, rows, cols);

			}
			break;
		}

		case 3://������ �������
		{
			if (f == 0)
			{
				cout << "������ �����������! ������� ������!\n";
			}
			else
			{
			 thrinkarr(arr, rows, cols);
			}
			break;
		}
		case 4://����� ������� �� �����
		{
			if (f == 0)
			{
				cout << "������ �����������! ������� ������!\n";
			}
			else
		
			printarr(arr, rows, cols);
			break;
		}
		case 0:
		{
			{
				Exit = true;
				break;
			}
			break;
		}
		default:
		{
			cout << "������ ������ ���� ���. ����������, ���������� �����.";
			getchar();
			getchar();
		}
		}
	}

	deletearr(arr, rows);
	return 0;
}
	


	int printmenu()
	{
		
		cout << "���� ���������\n1. ���� ��������� �������\n2. ����� ������� ��������� ������������� ���� ������� ���������\n3. ��������� �������\n4. ����� ������� �� �����\n0. �����\n";
		int m;
		cin >> m;
		return m;

	}
	
	void printarr(int **arr, int rows, int cols)
	{
			
			cout << "���������� ������:\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << arr[i][j] << "\t";

				}
				cout << endl;
			}
	}
	int** deletearr(int** arr, int rows)//������� ������
		{
			int i;

			if (arr != NULL)
			{
				for (i = 0; i < rows; i++)
				{
					delete[] arr[i];
				}
				delete[] arr;
			}
			return arr;
		}
	int sampling(int chislo)
	{
		cin >> chislo;
		while (chislo <= 0)
		{
			cout << "������� ������������ ��������!\n";
			cin >> chislo;
		}
		return chislo;
	}
		void manualinput(int** arr, int rows, int cols)
		{
			cout << "������� �������� �������\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{

					cin >> arr[i][j];//���� � ����������
				}
			}
			
		}
	void randominput(int** arr, int rows, int cols)
		{
			
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					arr[i][j] = rand();
				}

			}
			
		}
	void summarr(int** arr, int rows, int cols)
		{
			int summ = 0, max = 0;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (j > i)
					{
						max = arr[i][j];
						summ += abs(max);
					}
				}
			}
			cout << "����� ������� ���������\n";
			cout << summ << "\n";
		
		}
	void thrinkarr(int **arr, int &rows, int &cols)
	{
		
			int i, j, t = 0, x;
			for (i = 0; i < rows; i++)
			{
				t = 0;
				for (j = 0; j < cols; j++)
				{
					if (arr[i][j] != 0)
					{
						t = 1;
					}
				}
				if (t == 0)
				{
					for (x = i; x < rows - 1; x++)
					{
						for (j = 0; j < cols; j++)
						{
							arr[x][j] = arr[x + 1][j];
						}
					}
					rows--;
					i--;
				}
			}
			for (i = 0; i < cols; i++)
			{
				t = 0;
				for (j = 0; j < rows; j++)
				{
					if (arr[j][i] != 0)
					{
						t = 1;
					}
				}
				if (t == 0)
				{
					for (x = i; x < cols - 1; x++)
					{
						for (j = 0; j < rows; j++)
						{
							arr[j][x] = arr[j][x + 1];
						}
					}
					cols--;
					i--;
				}
			}
	
	
}
			