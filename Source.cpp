#include <iostream>
#include <stdio.h>

using namespace std;

struct masina
{
	int cod;
	char* marca;
	char* model;
	float pret;
};

void citireVector(masina* m, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Cod: ";
		cin >> m[i].cod;

		cout << "Marca: ";
		char buffer [30];
		cin >> buffer;
		m [i].marca = new char [strlen(buffer) + 1];
		strcpy_s(m [i].marca, strlen(buffer) + 1, buffer);
		cout << "Model: ";

		char buffer2 [30];
		cin >> buffer2;
		m [i].model = new char [strlen(buffer2) + 1];
		strcpy_s(m [i].model, strlen(buffer2) + 1, buffer2);

		cout << "Pret: ";
		cin >> m [i].pret;
	}
}

void afisareVector(masina* m, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Cod: " << m [i].cod << "\nMarca: " << m [i].marca << "\nModel: " << m [i].model << "\nPret: " << m [i].pret << endl;
	}
}

void dezalocareVector(masina* m, int n)
{
	for(int i = 0; i < n; i++)
	{
		delete [] m [i].marca;
		delete [] m [i].model;
	}
	delete [] m;
}

void citire4Vectori(int* cod, char** marca, char** model, float* pret, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Cod: ";
		cin >> cod [i];

		cout << "Marca: ";
		char buffer [30];
		cin >> buffer;
		marca [i] = new char [strlen(buffer) + 1];
		strcpy_s(marca [i], strlen(buffer) + 1, buffer);

		cout << "Model: ";
		char buffer2 [30];
		cin >> buffer2;
		model [i] = new char [strlen(buffer2) + 1];
		strcpy_s(model [i], strlen(buffer2) + 1, buffer2);

		cout << "Pret: ";
		cin >> pret [i];
	}
}

void afisare4Vetori(int* cod, char** marca, char** model, float* pret, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Cod: " << cod [i] << "\nMarca: " << marca [i] << "\nModel: " << model [i] << "\nPret: " << pret [i] << endl;
	}
}

void dezalocare4Vectori(int* cod, char** marca, char** model, float* pret, int n)
{
	delete [] cod;
	for(int i = 0; i < n; i++)
	{
		delete [] marca [i];
		delete [] model [i];
	}
	delete [] pret;
}

void citireMatrice(float** mat, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << "Matricea[" << i << "][" << j << "]: ";
			cin >> mat [i][j];
		}
	}
}

void afisareMatrice(float** mat, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << mat [i][j] << " ";
		}
		cout << endl;
	}
}

void dezalocareMatrice(float** mat, int n)
{
	for(int i = 0; i < n; i++)
	{
		delete [] mat [i];
	}
	delete [] mat;
}

float sumaTotala(float** mat, int n)
{
	float suma = 0;
	for(int i = 0; i < n; i++)
	{
		suma += mat [i][1] * mat [i][2];
		
	}
	return suma;
}

int main()
{

	int n;
	cout << "Nr. produse: ";
	cin >> n;
	masina* m = new masina [n];
	citireVector(m, n);

	afisareVector(m, n);

	dezalocareVector(m, n);

	int* cod = new int [n];
	char** marca = new char* [n];
	char** model = new char* [n];
	float* pret = new float [n];

	citire4Vectori(cod, marca, model, pret,n);
	afisare4Vetori(cod, marca, model, pret,n);
	dezalocare4Vectori(cod, marca, model, pret, n);

	float** mat = new float* [n];
	for(int i = 0; i < n; i++)
	{
		mat [i] = new float [3];
	}
	citireMatrice(mat, n);
	afisareMatrice(mat, n);
	cout << "Suma totala este: " << sumaTotala(mat, n);
	dezalocareMatrice(mat, n);
}