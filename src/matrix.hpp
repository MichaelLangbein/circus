
class Matrix {
    private:
        int rows;
        int cols;
        double** vals;

    public:
        Matrix (int rows, int cols);
        Matrix (const Matrix& source);
        Matrix& operator= (const Matrix& source);
        ~Matrix();
        void mult(double* dataIn, double* dataOut);
        double get(int r, int c) const;
};
