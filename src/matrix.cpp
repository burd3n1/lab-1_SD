#include <iostream>
#include "matrix.hpp"


Matrix::Matrix(int n) : rows(n), cols(n) {
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = 0.0;
    }
    for (int i = 0; i < n; ++i) {
        set(i, i, 1.0);
    }
}

Matrix::Matrix(int m, int n, double fillValue) : rows(m), cols(n) {
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = fillValue;
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = other.data[i];
    }
}

Matrix::~Matrix() {
    delete[] data;
}

double Matrix::get(int i, int j) const {
    return data[i * cols + j];
}

void Matrix::set(int i, int j, double value) {
    data[i * cols + j] = value;
}


int Matrix::getHeight() const {
    return rows;
}

int Matrix::getWidth() const {
    return cols;
}

void Matrix::negate() {
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = -data[i];
    }
}

void Matrix::addInPlace(const Matrix &other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Error");
    }
    for (int i = 0; i < rows * cols; ++i) {
        data[i] += other.data[i];
    }
}


Matrix Matrix::multiply(const Matrix &other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Error");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < cols; ++k) {
                sum += get(i, k) * other.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}