#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    
    int b1, b10, b100;
    b1 = B % 10;
    b10 = (B/10) % 10;
    b100 = B / 100;
    
    cout << A*b1 << endl <<
        A*b10 << endl <<
        A*b100 << endl <<
        A*B;
    
    return 0;
}