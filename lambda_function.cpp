#include <iostream>
using namespace std;
//  g++ lambda_function.cpp -o lambda_function
int main() {
    [](int a, int b) {
        cout << a + b << endl;
    }(3, 4);
    return 0;
}