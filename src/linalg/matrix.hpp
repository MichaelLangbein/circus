#include "vector.hpp"

class Matrix {
    private:
        int rows;
        int cols;
        double** vals;

    public:
        Matrix (int rows, int cols);
        Matrix (const Matrix& source);
        Matrix& operator= (const Matrix& source);
        Matrix operator+ (const Matrix& other);
        Matrix operator* (const Matrix& other);
        Vector operator* (const Vector& vec);
        ~Matrix();
        int getRows() const;
        int getCols() const;
        double get(int r, int c) const;
        void set(int r, int c, double val);
};
