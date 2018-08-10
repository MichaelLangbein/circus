class Layer {
    private:
        int size;

    public:
        Layer(int size);

        void evaluate(double* dataIn, double* dataOut);

};
