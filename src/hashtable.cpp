#include "../include/hashtable.h"
#include "../include/node.h"

using namespace std;

HashTable::HashTable(int s)
{
    table = new list<Node*>[s];
    size = s;
}

int HashTable::HashFunction(int a, int b, int c, int d)
{
    int sum = a + b + c + d;
    int index = sum % size;
    return index;
}

Node* HashTable::Contains(Puzzle currboard)
{
    //Puzzle currboard = currnode->GetPuzzle();

    int a = currboard.getTile(0, 1);
    int b = currboard.getTile(1, 0);
    int c = currboard.getTile(1, 2);
    int d = currboard.getTile(2, 1);
    int index = HashFunction(a, b, c, d);
    //printf("%i",index);
    if (table[index].empty())
    {
        //printf("empty\n");
        return nullptr;
    }
    list<Node*>::iterator listCheck;
    for (listCheck = table[index].begin(); listCheck != table[index].end(); listCheck++)
    {
        //if (currboard.getBoard() == listCheck->getBoard())

        if (currboard.getBoard() == (*listCheck)->GetPuzzle().getBoard())
        {
            return *listCheck;
        }
    }
    //printf("not found\n");
    return nullptr;
}

void HashTable::Insert(Node* currNode)
{
    Puzzle currBoard = currNode->GetPuzzle();

    int a = currBoard.getTile(0, 1);
    int b = currBoard.getTile(1, 0);
    int c = currBoard.getTile(1, 2);
    int d = currBoard.getTile(2, 1);
    int index = HashFunction(a, b, c, d);
    table[index].push_front(currNode);
}



/*
#include "../include/hashtable.h"

using namespace std;

HashTable::HashTable(int s)
{
    table = new list<Puzzle>[s];
    size = s;
}

int HashTable::HashFunction(int a, int b, int c, int d)
{
    int sum = a + b + c + d;
    int index = sum % size;
    return index;
}

bool HashTable::Contains(Puzzle currboard)
{
    int a = currboard.getTile(0, 1);
    int b = currboard.getTile(1, 0);
    int c = currboard.getTile(1, 2);
    int d = currboard.getTile(2, 1);
    int index = HashFunction(a, b, c, d);
    if (table[index].empty())
    {
        return false;
    }
    list<Puzzle>::iterator listCheck;
    for (listCheck = table[index].begin(); listCheck != table[index].end(); listCheck++)
    {
        if (currboard.getBoard() == listCheck->getBoard())
        {
            return true;
        }
    }
    return false;
}

void HashTable::Insert(Puzzle currBoard)
{
    int a = currBoard.getTile(0, 1);
    int b = currBoard.getTile(1, 0);
    int c = currBoard.getTile(1, 2);
    int d = currBoard.getTile(2, 1);
    int index = HashFunction(a, b, c, d);
    table[index].push_front(currBoard);
}
*/