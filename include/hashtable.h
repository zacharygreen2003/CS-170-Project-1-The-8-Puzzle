#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "puzzle.h"
#include <list>
#include <cstdlib>

using namespace std;

class HashTable
{
    private:
        int size;
        list<Puzzle> *table;
        int HashFunction(int,int,int,int);
    
    public:
        HashTable(int);
        bool Contains(Puzzle);
        void Insert(Puzzle);
};

#endif