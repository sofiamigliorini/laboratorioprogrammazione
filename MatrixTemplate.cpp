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
MatrixTemplate& MatrixTemplate<T>::operator*(const MatrixTemplate &M1) {
    if (this->columns!=M1.rows)
        throw std::runtime_error("wrong matrix dimension");
    else{
        MatrixTemplate M2(this->rows, M1.columns);
        for(int i=1; i<rows+1; i++){
            for(int j=1; j<M1.columns+1; j++){
                for(int k=1; k<columns+1; k++)
                    M2.m[i*j]+= this->m[i*columns+k]*M1.m[k*M1.columns+j];
            }
        }
        return M2;
    }
}

template <typename T>
MatrixTemplate& MatrixTemplate<T>::transpose() {
    MatrixTemplate M2(columns, rows);
    for(int i=1; i<rows+1; i++){
        for(int j=1; j < columns + 1; j++)
            M2.m[j*rows+i]=m[i*columns+j];
    }
    return M2;
}

template <typename T>
int MatrixTemplate<T>::determinant(const MatrixTemplate& M1) {
    if (M1.rows != M1.columns)
        throw std::runtime_error("matrix not squared");
    else{
        int det=0;
        if (M1.rows==1)
            det = M1.m[0];
        if (M1.rows==2)
            det = M1.m[0]*M1.m[3]-M1.m[2]*M1.m[1];
        else{
            for(int r=1; r<M1.rows+1; r++){
                MatrixTemplate subM (M1.rows, M1.columns);
                for(int i=1; i<M1.rows; i++){
                    for(int j=1; j<M1.columns; j++) {
                        int subRow = (i < r ? i : i + 1);
                        int subCol = j+1;
                        subM.m[i*(M1.columns-1)+j] = M1.m[subRow*M1.columns+subCol];
                    }
                }
                if (r%2==0)
                    det += M1.m[r*M1.columns+0]*determinant(subM);
                else
                    det -= M1.m[r*M1.columns+0]*determinant(subM);
            }
        }
        return det;
    }

}

template <typename T>
MatrixTemplate& MatrixTemplate<T>::inverse() {
    if (rows != columns)
        throw std::runtime_error("matrix not squared");
    else{
        if (determinant(*this)==0)
            throw std::runtime_error("matrix not inversible");
        else{
            MatrixTemplate M2(this->rows, this->columns);
            for (int r=1; r<rows+1; r++){
                MatrixTemplate subM(rows-1, columns-1);
                for(int i=1; i<rows+1; i++){
                    for(int j=1; j<columns+1; j++){
                        int subRow = (i < r ? i : i + 1);
                        int subCol = (j < r ? j : j + 1);
                        subM.m[i*subM.columns+j] = this->m[subRow*columns+subCol];
                        M2.m[i*columns+j]=1/determinant(*this)*determinant(subM);
                    }
                }

            }
            return M2;
        }
    }
}

