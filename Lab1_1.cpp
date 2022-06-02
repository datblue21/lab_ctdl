#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void export_array(int *x, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(x + i) << ' ';
    }
    cout << endl;
}
void ran_dom(int arr[], int &n)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand();
    }
}

void del_odd(int *p, int &n)
{

    int b[100];
    for (int i = 0; i < n; i++)
    {
        b[i] = *(p + i);
    }
    int lth = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] % 2 == 0)
        {

            *(p + lth) = b[i];
            lth++;
        }
    }
    n = lth;
    // export_array(p, n);
}

int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    int *x;
    // x = (int *)calloc(n, sizeof(int));
    x = (int *)malloc(n * sizeof(int));
    ran_dom(x, n);
    export_array(x, n);
    del_odd(x, n);
    export_array(x, n);
    return 0;
}