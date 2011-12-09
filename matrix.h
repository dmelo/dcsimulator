#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>

using namespace std;

class Matrix {
    private:
        int total; // total number of links.
        int size; // maximum number of pages.
        set<int> **link; // link to the next page -- points to.
        set<int> **blink; // back link -- is pointed by.

    public:
        Matrix(int size);
        ~Matrix();
        void setLink(int x, int y);
        void unsetLink(int x, int y);
        bool getLink(int x, int y);
        int countLink(int x);
        int countBLink(int x);
        int getRandomByPriotiyBLink();
        int getSize();
};

#endif
