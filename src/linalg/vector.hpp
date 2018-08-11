class Vector {
    private: 
        int size;
        double* vals;
    
    public:
        Vector(int size);
        Vector(const Vector& source); // copy constructor
        Vector& operator=(const Vector& source); // assignment operator
        Vector operator+(const Vector& other);
        double operator*(const Vector& other);
        Vector operator*(double scalar);
        ~Vector();
        int getSize() const;
        void set(int pos, double val);
        double get(int pos) const;
};
