#pragma once
#include "ItemType.h"

struct NodeType
{
    ItemType info;
    NodeType* next;
};

class UnsortedType
{
    public:
        UnsortedType();
        void MakeEmpty();
        bool IsFull() const;
        int GetLength() const;
        ItemType GetItem(ItemType item, bool &found);
        void PutItem(ItemType item);
        void DeleteItem(ItemType item);
        void ResetList();
        ItemType GetNextItem();
        void SplitLists(UnsortedType list, ItemType item, UnsortedType &list1, UnsortedType &list2);
    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
};