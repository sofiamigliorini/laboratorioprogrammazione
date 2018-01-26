//
// Created by Sofia Migliorini on 25/01/18.
//

#include "MatrixTemplate.h"

template <typename T>
bool MatrixTemplate<T>::setValue(T value, int x, int y){
    if(x>0 && x<rows+1 && y>0 && y<columns+1){
        m[x*columns+y]=value;
        return true;
    }

    else
        return false;

}

template <typename T>
const T& MatrixTemplate<T>::getValue(int x, int y){
    if(x>0 && x<rows+1 && y>0 && y<columns+1)
        return m[x*columns+y];
    else
        throw std::runtime_error("invalid coordinates");
}

template <typename T>
MatrixTemplate<T>& MatrixTemplate<T>::operator=(const MatrixTemplate& M1) {
    if (M1.rows!=this->rows || M1.columns!=this->columns)
        throw std::runtime_error("wrong matrix dimension");
    else
        for(int i=1; i<rows+1; i++){
            for(int j=1; j<columns+1; j++)
                this->m[i*columns+j]=M1.m[i*columns+j];
        }
    return *this;
}

template <typename T>
bool MatrixTemplate<T>::operator==(const MatrixTemplate &M1) {
    if (M1.rows!=this->rows || M1.columns!=this->columns)
        return false;
    else
        for (int i = 1; i < rows+1; i++) {
            for(int j=1; j<columns+1; j++)
                if(M1.m[i*columns+j]!=this->m[i*columns+j])
                    return false;
        }
    return true;
}

template <typename T>
MatrixTemplate& MatrixTemplate<T>::operator+(const MatrixTemplate &M1) {
    if (M1.rows!=this->rows || M1.columns!=this->columns)
        throw std::runtime_error("wrong matrix dimension");
    else{
        MatrixTemplate M2(M1.rows, M1.columns);
        for(int i=1; i<rows+1; i++){
            for(int j=1; j<columns+1; j++)
                M2.m[i*columns+j]= this->m[i*columns+j]+M1.m[i*columns+j];
        }
        return M2;
    }

}

template <typename T>
MatrixTemplate& MatrixTemplate<T>::operator-(const MatrixTemplate &M1) {
    if (M1.rows!=this->rows || M1.columns!=this->columns)
        throw std::runtime_error("wrong matrix dimension");
    else{
        MatrixTemplate M2(M1.rows, M1.columns);
        for(int i=1; i<rows+1; i++){
            for(int j=1; j<columns+1; j++)
                M2.m[i*columns+j]= this->m[i*columns+j]-M1.m[i*columns+j];
        }
        return M2;
    }

}

template <typename T>
MatrixTemplate& MatrixTemplate::operator*(const MatrixTemplate &M1) {
    if (this->columns!=M1.rows)
        throw std::runtime_error("wrong matrix dimension");
    else{
        MatrixTemplate M2(this->rows, M1.columns);
        for(int i=1; i<rows+1; i++){
            for(int j=1; j<columns+1; j++)
                M2.m[i*j]=
        }
    }
}