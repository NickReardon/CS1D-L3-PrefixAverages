/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Lab #3       	: Prefix Averages
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 01 / 27 / 20
 *****************************************************************************/
#include "main.h"

using std::cout; using std::endl;


int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/

	srand((unsigned)time(NULL));

	std::ofstream timingFile;
	timingFile.open("timing.csv");

	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;


	const int testCount = 10;
	const int startSize = 50;
	const float sizeModifier = 2;
	bool sizeMultiply = true;
	long double duration[testCount][2];
	int index;
	int size;



	size = startSize;
	index = 0;

	for (int i = 0; i < testCount; i++)
	{

		int* x;
		x = new int[size];

		for (int i = 0; i < size; i++)
		{
			x[i] = rand() % 1000 + 10;
		}

		int* avg;
		t1 = std::chrono::high_resolution_clock::now();
		avg = prefixAverages1(x, size);
		t2 = std::chrono::high_resolution_clock::now();
		duration[index][0] = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		cout << "Time: " << duration[index][0] << " microseconds" << endl;
		cout << "Size: " << size << endl;
		cout << "Input: " << x[0] << ", " << x[1] << ", " << x[2] << ", " << x[3] << endl;
		cout << "Averages: " << avg[0] << ", " << avg[1] << ", " << avg[2] << ", " << avg[3] 
			<< endl << endl;

		delete[] x;
		delete[] avg;

		if (sizeMultiply)
		{
			size *= sizeModifier;
		}
		else
		{
			size += sizeModifier;
		}
		index++;
	}


	cout << "\n----------------------------\n";


	size = startSize;
	index = 0;

	for (int i = 0; i < testCount; i++)
	{

		int* x;
		x = new int[size];

		for (int i = 0; i < size; i++)
		{
			x[i] = rand() % 1000 + 10;
		}

		int* avg;
		t1 = std::chrono::high_resolution_clock::now();
		avg = prefixAverages2(x, size);
		t2 = std::chrono::high_resolution_clock::now();
		duration[index][1] = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		cout << "Time: " << duration[index][1] << " microseconds" << endl;
		cout << "Size: " << size << endl;
		cout << "Input: " << x[0] << ", " << x[1] << ", " << x[2] << ", " << x[3] << endl;
		cout << "Averages: " << avg[0] << ", " << avg[1] << ", " << avg[2] << ", " << avg[3] 
			<< endl << endl;

		delete[] x;
		delete[] avg;

		if (sizeMultiply)
		{
			size *= sizeModifier;
		}
		else
		{
			size += sizeModifier;
		}		
		index++;
	}

	size = startSize;

	timingFile << "Size,Time (microseconds), " << endl
		<< ", prefixAverages1, prefixAverages2" << endl;

	for (int i = 0; i < testCount; i++)
	{
		timingFile << size << ',' << duration[i][0] << ',' << duration[i][1] << endl;
		if (sizeMultiply)
		{
			size *= sizeModifier;
		}
		else
		{
			size += sizeModifier;
		}
	}

	timingFile.close();
	system("pause");
	return 0;
}


int* prefixAverages1(int *inputAr, int size)
{
	int *arr;
	arr = new int[size];
	int a;

	for (int i = 0; i < size; i++)
	{
		a = 0;
		for(int j = 0; j <= i; j++)
		{
			a = a + inputAr[j];
		}
		arr[i] = a / (i + 1);
	}

	return arr;
}
int* prefixAverages2(int* inputAr, int size)
{
	int* arr;
	arr = new int[size];
	int a = 0;

	for (int i = 0; i < size; i++)
	{
		a = a + inputAr[i];
		arr[i] = a / (i + 1);
	}

	return arr;
}

