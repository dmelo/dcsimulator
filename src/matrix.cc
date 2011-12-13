#include"matrix.h"

Matrix::Matrix(int size) {
    this->size = size;
    total = 0;
    this->link = (set<int> **) malloc(size * 4);
    blink = (set<int> **) malloc(size * sizeof(set<int> *));

    for(int i = 0; i < size; i++) {
        link[i] = new set<int>();
        blink[i] = new set<int>;
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < size; i++) {
        delete link[i];
        delete blink[i];
    }
    free(link);
    free(blink);
}

void Matrix::setLink(int x, int y) {
    if(link[x]->find(y) == link[x]->end()) {
        total++;
        link[x]->insert(y);
        blink[y]->insert(x);
    }
}

void Matrix::unsetLink(int x, int y) {
    if(link[x]->find(y) != link[x]->end()) {
        total--;
        link[x]->erase(y);
        blink[y]->erase(x);
    }
}

bool Matrix::getLink(int x, int y) {
    return link[x]->find(y) == link[x]->end() ? false : true;
}

int Matrix::countLink(int x) {
    return link[x]->size();
}

int Matrix::countBLink(int x) {
    printf("countBLink(%d): %d -- ", x, blink[x]->size());
    for(set<int>::iterator it = blink[x]->begin(); it != blink[x]->end(); it++)
        printf(" %d", *it);
    printf("\n");
    return blink[x]->size();
}

int Matrix::getRandomByPriotiyBLink() {
    int r = (rand() + 1) % total, i = 0;
    printf("r: %d. total: %d\n", r, total);
    for(; r > 0; i++) {
        r -= this->countBLink(i);
    }

    printf("%d\n\n", i);

    return i;
}

int Matrix::getSize() {
    return size;
}
