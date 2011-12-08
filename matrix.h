#ifndef MATRIX_H
#define MATRIX_H

#include<set>

using namespace std;

class Matrix {
    private:
        set<int> **m;
        int size;

    public:
        Matrix(int size);
        ~Matrix();

        void set(int x, int y);
        void unset(int x, int y);
        bool get(int x, int y);

};

#endif
