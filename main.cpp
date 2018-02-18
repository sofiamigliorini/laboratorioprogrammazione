#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"


using namespace std;

int main() {
    int type, r, c;
    cout << "Enter rows number " << endl;
    cin >> r;
    cout << "Enter columns number " << endl;
    cin >> c;

    MatrixTemplate<int> *intMatrix = new MatrixTemplate<int>(r, c);
    int value;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Enter value " << endl;
            cin >> value;
            intMatrix->setValue(value, i, j);
        }
    }

    cout << "Op: " << endl;
    cout << "1 for determinant" << endl;
    cout << "2 for transpose" << endl;
    cout << "3 for inverse" << endl;
    cin >> type;
    if (type == 1) {
        cout << intMatrix->determinant(intMatrix) << endl;
    }
    if (type == 2) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << intMatrix->transpose()[i * c + j] << endl;
        }
    }
    if (type == 3) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << intMatrix->inverse()[i * c + j] << endl;
        }
    }


    return 0;
}