class Connection {
    private:
        int inCount;
        int outCount;
    
    public:
        Connection(int out, int in);

        void propagate(double* dataIn, double* dataOut);

};
