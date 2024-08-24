

#include <iostream>
using namespace std;

float Addition(float x, float y) {
    return x + y;
}
float Subtraction(float x, float y) {
    return x - y;
}
float Multiplication(float x, float y) {
    return x * y;
}
float Division(float x, float y) {
    return x / y;
}

int main(int argc, char* argv[])
{
    // Code B
// User type to simplify the declaration
    typedef float (*lpfnOperation)(float, float);
    // CVector of pointer to functions
    lpfnOperation vpf[4] = { &::Addition, &::Subtraction,
    &::Multiplication, &::Division };
    float a, b, c; int opt;
    // enter the operands
    cout << "Ingresa a y b" << endl;
    cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    cout << "Ingresa la opcion 1 Add, 2 Sub, 3 Mult, 4 Div:" << endl;
    cin >> opt;
    // The next line replaces the switch and replaces the whole switch
    c = (*vpf[opt])(a, b);
    cout << c << endl;

}

