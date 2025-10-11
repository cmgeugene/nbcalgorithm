#include <iostream>

using namespace std;

int main()
{
    int A, B;
    double C;
    cin >> A >> B;
    C = (double)A/B;
    cout << fixed;
    cout.precision(15);
    cout << C;
    return 0;
}