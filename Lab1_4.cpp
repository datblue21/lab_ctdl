#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void input(int *a, int n)
{
    srand(time(NULL));
    cout << "number 's elements: " << endl;
    for (int i = 0; i < n; i++)
        a[i] = rand();
}
void export_(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}
int main()
{
    int n, *a;
    cout << "number element" << endl;
    cin >> n;
    a = new int(n);
    input(a, n);
    export_(a, n);
    return 0;
}
