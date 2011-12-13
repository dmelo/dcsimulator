#ifndef CNETWORK_H
#define CNETWORK_H

#include"matrix.h"


class CNetwork {
    private:
       Matrix *matrix; 

    public:
        CNetwork(int size);
        ~CNetwork();

        void initBAModel();
};

#endif
