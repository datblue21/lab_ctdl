#include <iostream>

using namespace std;

int ucln(int a, int b)
{
    if (b == 0)
        return a;
    if (a % b == 0)
        return b;
    return ucln(b, a % b);
}
int bcnn(int a, int b)
{
    int tg = ucln(a, b);
    return a * b / tg;
}
int main()
{
    int a, b;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    cout << "Uoc chung lon nhat: ";
    cout << ucln(a, b) << endl;
    int tg = bcnn(a, b);
    cout << "Boi chung lon nhat: ";
    cout << bcnn(a, b) << endl;
    return 0;
}