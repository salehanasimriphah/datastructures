#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "Before swapping: x = " << x << ", y = " << y << endl;

    int *a = &x;
    int *b = &y;
    int temp = *a;
    *a = *b;
    *b = temp;

    cout << "After swapping: x = " << x << ", y = " << y << endl;

    return 0;
}

