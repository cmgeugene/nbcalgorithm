#include <iostream>
#include <string>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    
    string _B;
    _B = to_string(B);
    
    int b1, b10, b100;
    b1 = _B[2] -'0';
    b10 = _B[1] -'0';
    b100 = _B[0] -'0';
    
    cout << A*b1 << endl <<
        A*b10 << endl <<
        A*b100 << endl <<
        A*B;
    
    return 0;
}