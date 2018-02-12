//
// Created by Sofia Migliorini on 25/01/18.
//

#ifndef LABORATORIOPROGRAMMAZIONE_MATRIXFACTORY_H
#define LABORATORIOPROGRAMMAZIONE_MATRIXFACTORY_H

#include "MatrixTemplate.h"

class MatrixFactory {
public:
    MatrixFactory() = default;
    virtual ~MatrixFactory() = default;

    template <typename T> MatrixTemplate<T>* createMatrix(int type, int r, int c){
        if (type == 1)
            return new MatrixTemplate<int>(r, c);
        if (type == 2)
            return new MatrixTemplate<float>(r, c);
        if (type == 3)
            return new MatrixTemplate<long>(r, c);
    };

};


#endif //LABORATORIOPROGRAMMAZIONE_MATRIXFACTORY_H
