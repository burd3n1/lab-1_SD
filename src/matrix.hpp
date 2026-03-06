#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
    private:
    int rows;
    int cols;
    double* data;

    public:

    Matrix(int n);

    Matrix(int rows, int cols, double fillValue = 0.0);

    Matrix(const Matrix& other);


    ~Matrix();

    double get(int i, int j) const;

    void set(int i, int j, double value);

    int getHeight() const;
    int getWidth() const;

    void negate();
    void addInPlace(const Matrix &other);
    Matrix multiply(const Matrix &other) const;


};
#endif //MATRIX_HPP