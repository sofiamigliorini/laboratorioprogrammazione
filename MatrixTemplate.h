//
// Created by Sofia Migliorini on 25/01/18.
//

#ifndef LABORATORIOPROGRAMMAZIONE_MATRIX_H
#define LABORATORIOPROGRAMMAZIONE_MATRIX_H

#include <stdexcept>

template <typename T>
class MatrixTemplate {

public:
    MatrixTemplate(int r,int c): rows(r), columns(c) {
        m = new T[r * c];
        for (int i = 1; i < r + 1; i++) {
            for (int j = 1; j < c + 1; j++)
                m[i * c + j] = 0;
        }
    };
    ~MatrixTemplate(){
        delete [] m;
    };

    bool setValue(T value, int x, int y);
    const T& getValue(int x, int y) throw(std::runtime_error);
    MatrixTemplate& operator = (const MatrixTemplate& M1) throw(std::runtime_error);
    bool operator == (const MatrixTemplate& M1);
    MatrixTemplate& operator + (const MatrixTemplate& M1) throw(std::runtime_error);
    MatrixTemplate& operator - (const MatrixTemplate& M1) throw(std::runtime_error);
    MatrixTemplate& operator * (const MatrixTemplate& M1) throw(std::runtime_error);

private:
    T *m;
    int rows;
    int columns;

};


#endif //LABORATORIOPROGRAMMAZIONE_MATRIX_H
