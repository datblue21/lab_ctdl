#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void random(int *a, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        *(a + i) = rand() % 1000;
    }
}

void export_array(int *a, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(a + i) << ' ';
    }
}

// 2cach: 1 tao mang moi
//            2 xoa tren mang cu

void delOdd(int *a, int &SIZE)
{
    int b[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        b[i] = *(a + i);
    }
    int length = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (b[i] % 2 == 0)
        {
            *(a + length) = b[i];
            length++;
        }
    }
    SIZE = length;
}

void delOdd1(int *a, int &SIZE)
{
    int current = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (*(a + i) % 2 == 0)
        {
            *(a + current) = *(a + i);
            current++;
        }
    }
    SIZE = current;
}

int main()
{
    int SIZE;
    cin >> SIZE;
    int *a;
    a = (int *)malloc(SIZE * sizeof(int));
    random(a, SIZE);
    export_array(a, SIZE);
    cout << "\n--------------\n";

    delOdd1(a, SIZE);
    export_array(a, SIZE);
    return 0;
}