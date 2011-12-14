#include"matrix.h"
#include"log.h"

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
    return blink[x]->size();
}

int Matrix::getRandomByPriotiyBLink() {
    int r = (rand() + 1) % total, i = 0;
    sprintf(text, "r: %d. total: %d\n", r, total);
    for(; r > 0; i++) {
        r -= this->countBLink(i);
    }

    sprintf(text, "%s%d\n", text, i);
    Log(text, 5);

    return i;
}

int Matrix::getSize() {
    return size;
}

int *Matrix::nodesBCountRelation() {
    int* relation = (int *) calloc(size, sizeof(int));
    for(int i = 0; i < size; i++)
        relation[countBLink(i)]++;

    return relation;
}

void Matrix::exportNodesBCountRelation(FILE *fd) {
    int *relation = nodesBCountRelation();
    for(int i = 0; i < size; i++)
        fprintf(fd, "%d %d\n", i, relation[i]);
}
