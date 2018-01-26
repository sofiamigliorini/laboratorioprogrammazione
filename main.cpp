#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

using namespace std;

int main() {
    string type;
    cout << "Enter type: (int, char, string) " << endl;
    cin >> type;

    MatrixTemplate *m = MatrixFactory::createMatrix(type, 2, 2);

    return 0;
}