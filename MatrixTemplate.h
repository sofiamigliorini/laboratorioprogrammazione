//
// Created by Sofia Migliorini on 25/01/18.
//

#ifndef LABORATORIOPROGRAMMAZIONE_MATRIX_H
#define LABORATORIOPROGRAMMAZIONE_MATRIX_H

#include <stdexcept>

template<typename T>
class MatrixTemplate {

public:
    explicit MatrixTemplate(int r = 2, int c = 2) : rows(r), columns(c) {
        m = new T[r * c];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                m[i * columns + j] = 0; //initialize zero matrix
        }
    };

    MatrixTemplate(const MatrixTemplate &original) {
        rows = original.rows;
        columns = original.columns;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                m[i * columns + j] = original.m[i * original.columns + j];
        }

    }

    virtual ~MatrixTemplate() {
        delete[] m;
    };


    int getRows() const {
        return rows;
    }

    void setRows(int r) {
        rows = r;
    }

    int getColumns() const {
        return columns;
    }

    void setColumns(int c) {
        columns = c;
    }

    bool setValue(T value, int x, int y) {
        if (x >= 0 && x < rows && y >= 0 && y < columns) {
            m[x * columns + y] = value;
            return true;
        } else
            return false;
    };

    const T &getValue(int x, int y) throw(std::runtime_error) {
        if (x >= 0 && x < rows && y >= 0 && y < columns)
            return m[x * columns + y];
        else
            throw std::runtime_error("invalid coordinates");
    };

    T *getRow(int x) throw(std::runtime_error) {
        if (x >= 0 && x < rows) {
            m2 = new T[1 * columns];
            for (int j = 0; j < columns; j++)
                m2[j] = m[x * columns + j];
            return m2;
        } else
            throw std::runtime_error("invalid coordinate");
    };

    T *getColumn(int y) throw(std::runtime_error) {
        if (y >= 0 && y < columns) {
            m2 = new T[rows * 1];
            for (int i = 0; i < rows; i++)
                m2[i] = m[i * columns + y];
            return m2;
        } else
            throw std::runtime_error("invalid coordinate");
    };

    T *operator=(MatrixTemplate *M1) throw(std::runtime_error) {
        if (M1->rows != this->rows || M1->columns != this->columns)
            throw std::runtime_error("wrong matrix dimension");
        else
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    this->m[i * columns + j] = M1->m[i * columns + j];
            }
        return this;
    };

    bool operator==(MatrixTemplate *M1) {
        if (M1->rows != this->rows || M1->columns != this->columns)
            return false;
        else
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    if (M1->m[i * columns + j] != this->m[i * columns + j])
                        return false;
            }
        return true;
    };

    T *sum(MatrixTemplate *M1) throw(std::runtime_error) {
        if (M1->rows != this->rows || M1->columns != this->columns)
            throw std::runtime_error("wrong matrix dimension");
        else {
            m2 = new T[rows * columns];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    m2[i * columns + j] = this->m[i * columns + j] + M1->m[i * columns + j];
            }
            return m2;
        }
    };

    T *sub(MatrixTemplate *M1) throw(std::runtime_error) {
        if (M1->rows != this->rows || M1->columns != this->columns)
            throw std::runtime_error("wrong matrix dimension");
        else {
            m2 = new T[rows * columns];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    m2[i * columns + j] = this->m[i * columns + j] - M1->m[i * columns + j];
            }
            return m2;
        }
    };

    T *mul(MatrixTemplate *M1) throw(std::runtime_error) {
        if (this->columns != M1->rows)
            throw std::runtime_error("wrong matrix dimension");
        else {
            m2 = new T[rows * M1->columns];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < M1->columns; j++) {
                    m2[i * M1->columns + j] = 0;
                    for (int k = 0; k < columns; k++)
                        m2[i * M1->columns + j] += this->m[i * columns + k] * M1->m[k * M1->columns + j];
                }
            }
            return m2;
        }
    };

    T *transpose() {
        m2 = new T[columns * rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                m2[j * this->rows + i] = m[i * this->columns + j];
        }
        return m2;
    };

    int determinant(MatrixTemplate *M1) throw(std::runtime_error) {
        if (M1->rows != M1->columns)
            throw std::runtime_error("matrix not squared");
        else {
            int det = 0;
            if (M1->rows == 1)
                det = M1->m[0];
            if (M1->rows == 2)
                det = M1->m[0] * M1->m[3] - M1->m[2] * M1->m[1];
            else {
                MatrixTemplate<T> *subM;
                for (int r = 0; r < M1->rows; r++) {
                    subM = new MatrixTemplate<T>(M1->rows - 1, M1->columns - 1);
                    for (int i = 0; i < M1->rows - 1; i++) {
                        for (int j = 0; j < M1->columns - 1; j++) {
                            int subRow = (i < r ? i : i + 1);
                            int subCol = j + 1;
                            subM->m[i * (M1->columns - 1) + j] = M1->m[subRow * M1->columns + subCol];
                        }
                    }
                    if (r % 2 == 0)
                        det += M1->m[r * M1->columns + 0] * determinant(subM);
                    else
                        det -= M1->m[r * M1->columns + 0] * determinant(subM);
                }
            }
            return det;
        }
    };

    T *inverse() throw(std::runtime_error) {
        if (rows != columns)
            throw std::runtime_error("matrix not squared");
        else {
            if (determinant(this) == 0)
                throw std::runtime_error("matrix not inversible");
            else {
                this->m2 = new T[this->rows * this->columns];
                for (int r = 0; r < rows; r++) {
                    MatrixTemplate<T> *subM = new MatrixTemplate<T>(rows - 1, columns - 1);
                    for (int c = 0; c < columns; c++) {
                        for (int i = 0; i < rows - 1; i++) {
                            for (int j = 0; j < columns - 1; j++) {
                                int subRow = (i < r ? i : i + 1);
                                int subCol = (j < c ? j : j + 1);
                                subM->m[i * (columns - 1) + j] = this->m[subRow * columns + subCol];
                            }
                        }
                        if ((r + c) % 2 == 0)
                            this->m2[r * columns + c] = 1 / determinant(this) * determinant(subM);
                        else
                            this->m2[r * columns + c] = -1 / determinant(this) * determinant(subM);
                    }

                }
                T *tmp = new T[columns * rows];
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++)
                        tmp[j * this->rows + i] = m2[i * this->columns + j];
                }
                return tmp;
            }
        }
    };

private:
    T *m2;
    T *m;
    int rows;
    int columns;

};


#endif //LABORATORIOPROGRAMMAZIONE_MATRIX_H
