#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fmatrix("C:\\Users\\Pavel\\Desktop\\cpp1\\matrix.txt");
	ifstream ffree("C:\\Users\\Pavel\\Desktop\\cpp1\\free.txt");
	float matrix[30][30];
	float matrixCopy[30][30];
	float free[30];
	float x[30];
	float freeNew[30];
	float freeCopy[30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			fmatrix >> matrix[i][j];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			matrixCopy[i][j]=matrix[i][j];
	for (int i = 0; i < 30; i++)
		ffree >> free[i];
	for (int i = 0; i < 30; i++)
		freeCopy[i] = free[i];
	for (int k = 0; k < 29; k++) //Прямой ход Гаусса
	{
		for (int j = k + 1; j < 30; j++)
		{
			float r = matrix[j][k] / matrix[k][k];
			for (int i = k; i < 30; i++)
				matrix[j][i] -= matrix[k][i] * r;
			free[j] -= free[k] * r;
		}
	}
	for (int i = 0; i < 30; i++)
		x[i] = 0;
	for (int k = 29; k >= 0; k--)//Обратный ход Гаусса
	{
		float r = 0;
		for (int j = k + 1; j < 30; j++)
		{
			float g = matrix[k][j] * x[j];
			r += g;
		}
		x[k] = (free[k]-r) / matrix[k][k];;
	}
	for (int i = 0; i < 30; i++)
		freeNew[i] = 0;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			freeNew[i] += matrixCopy[i][j] * x[j];
	for (int i = 0; i < 30; i++)
		cout << "Check" << i+1 << " " << freeNew[i] << endl;
	float e = abs(freeNew[0] - freeCopy[0]);
	for (int q = 1; q < 30; q++)
		if (e < abs((freeNew[q] - freeCopy[q])))
			e = abs(freeNew[q] - freeCopy[q]);
	for (int w = 0; w < 30; w++)
		cout << "Root number " << w+1 << ": " << x[w] << endl;
	cout << "Max diffrence " << e << endl;
	system("pause");
	return 0;
}