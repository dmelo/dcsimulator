#include"matrix.h";

Matrix::Matrix(int size) {
    this->size = size;
    m = (set<bool> **) malloc(size * sizeof(set<bool> *));

    for(int i = 0; i < size; i++)
        m[i] = new set<bool>;
}

Matrix::~Matrix() {
    for(int i = 0; i < size; i++)
        free(m[i]);
    free(m);
}

void Matrix::set(int x, int y) {
    int big = x > y ? x : y;
    int small = x < y ? x : y;

    m[small]->insert(big);
}

void Matrix::unset(int x, int y) {
    int big = x > y ? x : y;
    int small = x < y ? x : y;

    m[small]->erase(big);
}

bool Matrix::get(int x, int y) {
    int big = x > y ? x : y;
    int small = x < y ? x : y;

    return m[small]->find(big) == m[small]->end() ? false : true;
}
