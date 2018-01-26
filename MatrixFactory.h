//
// Created by Sofia Migliorini on 25/01/18.
//

#ifndef LABORATORIOPROGRAMMAZIONE_MATRIXFACTORY_H
#define LABORATORIOPROGRAMMAZIONE_MATRIXFACTORY_H

#include <string>
#include "MatrixTemplate.h"


class MatrixFactory {
public:
    static MatrixTemplate *createMatrix(const std::string& type, int r, int c){
        if(type=="int")
            new MatrixTemplate<int>(r,c);
        else if(type=="char")
            new MatrixTemplate<char>(r,c);
        else if(type=="string")
            new MatrixTemplate<std::string>(r,c);
    };

};


#endif //LABORATORIOPROGRAMMAZIONE_MATRIXFACTORY_H
