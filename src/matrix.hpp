
class Matrix {
    private:
        int rows;
        int cols;
        double** vals;

    public:
        Matrix(int rows, int cols);
        ~Matrix();
        void leftMult(double* dataIn, double* dataOut);
};
