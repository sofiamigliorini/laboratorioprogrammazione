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
                m[i * columns + j] = 0;
        }
    };

    virtual ~MatrixTemplate() {
        delete[] m;
    };


    int getRows() const {
        return rows;
    }

    void setRows(int rows) {
        MatrixTemplate::rows = rows;
    }

    int getColumns() const {
        return columns;
    }

    void setColumns(int columns) {
        MatrixTemplate::columns = columns;
    }

    virtual bool setValue(T value, int x, int y) {
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

    MatrixTemplate &getRow(int x) throw(std::runtime_error) {
        if (x >= 0 && x < rows) {
            MatrixTemplate row(1, this->columns);
            for (int j = 0; j < columns; j++)
                row.m[j] = this->m[x * columns + j];
            return row;
        } else
            throw std::runtime_error("invalid coordinate");
    };

    MatrixTemplate &getColumn(int y) throw(std::runtime_error) {
        if (y >= 0 && y < columns) {
            MatrixTemplate column(this->rows, 1);
            for (int i = 0; i < rows; i++)
                column.m[i] = this->m[i * columns + y];
            return column;
        } else
            throw std::runtime_error("invalid coordinate");
    };

    MatrixTemplate &operator=(const MatrixTemplate &M1) throw(std::runtime_error) {
        if (M1.rows != this->rows || M1.columns != this->columns)
            throw std::runtime_error("wrong matrix dimension");
        else
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    this->m[i * columns + j] = M1.m[i * columns + j];
            }
        return *this;
    };

    bool operator==(const MatrixTemplate &M1) {
        if (M1.rows != this->rows || M1.columns != this->columns)
            return false;
        else
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    if (M1.m[i * columns + j] != this->m[i * columns + j])
                        return false;
            }
        return true;
    };

    MatrixTemplate &operator+(const MatrixTemplate &M1) throw(std::runtime_error) {
        if (M1.rows != this->rows || M1.columns != this->columns)
            throw std::runtime_error("wrong matrix dimension");
        else {
            MatrixTemplate M2(M1.rows, M1.columns);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    M2.m[i * columns + j] = this->m[i * columns + j] + M1.m[i * columns + j];
            }
            return M2;
        }
    };

    MatrixTemplate &operator-(const MatrixTemplate &M1) throw(std::runtime_error) {
        if (M1.rows != this->rows || M1.columns != this->columns)
            throw std::runtime_error("wrong matrix dimension");
        else {
            MatrixTemplate M2(M1.rows, M1.columns);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++)
                    M2.m[i * columns + j] = this->m[i * columns + j] - M1.m[i * columns + j];
            }
            return M2;
        }
    };

    MatrixTemplate &operator*(const MatrixTemplate &M1) throw(std::runtime_error) {
        if (this->columns != M1.rows)
            throw std::runtime_error("wrong matrix dimension");
        else {
            MatrixTemplate M2(this->rows, M1.columns);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < M1.columns; j++) {
                    for (int k = 0; k < columns; k++)
                        M2.m[i * j] += this->m[i * columns + k] * M1.m[k * M1.columns + j];
                }
            }
            return M2;
        }
    };

    MatrixTemplate &transpose() {
        MatrixTemplate M2(this->columns, this->rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                M2.m[j * this->rows + i] = m[i * this->columns + j];
        }
        return M2;
    };

    float determinant(const MatrixTemplate &M1) throw(std::runtime_error) {
        if (M1.rows != M1.columns)
            throw std::runtime_error("matrix not squared");
        else {
            int det = 0;
            if (M1.rows == 1)
                det = M1.m[0];
            if (M1.rows == 2)
                det = M1.m[0] * M1.m[3] - M1.m[2] * M1.m[1];
            else {
                for (int r = 0; r < M1.rows; r++) {
                    MatrixTemplate subM(M1.rows - 1, M1.columns - 1);
                    for (int i = 0; i < M1.rows - 1; i++) {
                        for (int j = 0; j < M1.columns - 1; j++) {
                            int subRow = (i < r ? i : i + 1);
                            int subCol = j + 1;
                            subM.m[i * (M1.columns - 1) + j] = M1.m[subRow * M1.columns + subCol];
                        }
                    }
                    if (r % 2 == 0)
                        det += M1.m[r * M1.columns + 0] * determinant(subM);
                    else
                        det -= M1.m[r * M1.columns + 0] * determinant(subM);
                }
            }
            return det;
        }
    };

    MatrixTemplate &inverse() throw(std::runtime_error) {
        if (rows != columns)
            throw std::runtime_error("matrix not squared");
        else {
            float det = determinant(*this);
            if (det == 0)
                throw std::runtime_error("matrix not inversible");
            else {
                MatrixTemplate M2(this->rows, this->columns);
                MatrixTemplate subM(rows - 1, columns - 1);
                for (int r = 0; r < rows; r++) {
                    for (int c = 0; c < columns; c++) {
                        for (int i = 0; i < rows - 1; i++) {
                            for (int j = 0; j < columns - 1; j++) {
                                int subRow = (i < r ? i : i + 1);
                                int subCol = (j < r ? j : j + 1);
                                subM.m[i * subM.columns + j] = this->m[subRow * columns + subCol];
                            }
                        }
                        if ((r + c) % 2 == 0)
                            M2.m[r * columns + c] = 1 / det * determinant(subM);
                        else
                            M2.m[r * columns + c] = -1 / det * determinant(subM);
                    }

                }
                return M2.transpose();
            }
        }
    };

private:
    T *m;
    int rows;
    int columns;

};


#endif //LABORATORIOPROGRAMMAZIONE_MATRIX_H
