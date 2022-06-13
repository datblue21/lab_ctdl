#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// 1a Input data of the array.
void intPut(int randArray[])
{
	for (int i = 0; i < 1000; i++)
	{
		randArray[i] = rand() % 100;
	}
}

// 1b Output data of the array.
void outPut(int randArray[])
{
	for (int i = 0; i < 1000; i++)
	{
		cout << "Arr[" << i << "] : " << randArray[i] << endl;
	}
}

// 1.b Sort the array by using all sorting algorithms that you have studied.
void bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void insertion_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp > arr[j])
			{
				break;
			}
			else
			{
				arr[j + 1] = arr[j];
			}
		}
		arr[j + 1] = temp;
	}
}

void selection_sort(int arr[], int length)
{
	int i, j, index, temp;
	for (i = 0; i < length - 1; i++)
	{
		index = i;
		for (j = i + 1; j < length; j++)
		{
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

string numberToString(float n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

// Cau 1d
int linearSearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}
// C�u 1e
int binarySearch(int array[], int x, int low, int high)
{

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (array[mid] == x)
			return mid;

		if (array[mid] < x)
			low = mid + 1;

		else
			high = mid - 1;
	}

	return -1;
}

int main()
{
	int randArray[1000];
	fstream output;
	output.open("SortingTime.txt", ios::out);

	// 1a
	intPut(randArray);
	cout << "\nElements of the array:" << endl;
	outPut(randArray);

	// 1b

	// bubble sort
	bubble_sort(randArray, 1000);
	cout << "\nArray after sorting by bubble algorithm:" << endl;
	outPut(randArray);

	// in thoi gian cua thuat toan bubble_sort
	clock_t time1 = clock();
	printf("Time: %.1f sm\n", (float)(clock() - time1) / CLOCKS_PER_SEC);
	// luu thoi gian vao file
	string time = "Execution time of the algorithm bubble sort: ";
	float timeClock = (float)(clock() - time1) / CLOCKS_PER_SEC;
	numberToString(timeClock);
	string sm = " sm\n";
	output << time + numberToString(timeClock) + sm;

	// selection sort
	selection_sort(randArray, 1000);
	cout << "\nArray after sorting according to the selection algorithm: " << endl;
	outPut(randArray);

	// in thoi gian cua thuat toan selection_sort
	clock_t time2 = clock();
	printf("Time: %.1fsm\n", (float)(clock() - time2) / CLOCKS_PER_SEC);
	// luu thoi gian vao file
	string timeSecond = "Execution time of the algorithm selection sort: ";
	float timeClockSecond = (float)(clock() - time2) / CLOCKS_PER_SEC;
	numberToString(timeClockSecond);
	string smSecond = " sm\n";
	output << timeSecond + numberToString(timeClockSecond) + smSecond;

	// insertion sort
	insertion_sort(randArray, 1000);
	cout << "\nArray after sorting by insertion sort algorithm: " << endl;
	outPut(randArray);

	// in thoi gian cua thuat toan insertion_sort
	clock_t time3 = clock();
	printf("Time: %.1fsm\n", (float)(clock() - time3) / CLOCKS_PER_SEC);

	// luu thoi gian vao file
	string timeThird = "Execution time of the algorithm selection sort: ";
	float timeClockThird = (float)(clock() - time3) / CLOCKS_PER_SEC;
	numberToString(timeClockThird);
	string smThird = " sm\n";
	output << timeThird + numberToString(timeClockThird) + smThird;
	cout << timeThird + numberToString(timeClockThird) + smThird;
	output.close(); // d�ng file output

	// d Search for a given element x from the array using  search technique
	int x;
	cout << endl
		 << "Nhap x de tim kiem theo kieu tuyen tinh va cay nhi phan: ";
	cin >> x;
	int n = sizeof(randArray) / sizeof(randArray[0]);

	int result = linearSearch(randArray, n, x);
	(result == -1)
		? cout << "Element is not present in array (tuyen tinh)\n"
		: cout << "Element is present at index " << result << "(tuyen tinh)\n";
	// e Search for a given element x from the array using binary search technique
	int result2 = binarySearch(randArray, x, 0, n - 1);
	if (result2 == -1)
		cout << "Element is not present in array (cay nhi phan)";
	else
		cout << endl
			 << "Element is found at index " << result2 << "(cay nhi phan)";
	return 0;
}
