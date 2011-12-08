#ifndef CNETWORK_H
#define CNETWORK_H


class CNetwork {
    private:
        set<int> **network;
        int size;

    public:
        CNetwork(int size);
        ~CNetwork();

};

#endif
