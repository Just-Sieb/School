#pragma once
#include "ItemType.h"

struct NodeType
{
    ItemType info;
    NodeType* next;
};

class SortedType
{
    public:
        SortedType();
        ~SortedType();

        bool IsFull() const;
        int GetLength() const;
        void MakeEmpty();
        ItemType GetItem(ItemType item, bool& found);
        void PutItem(ItemType item);
        void DeleteItem(ItemType item);
        void ResetList();
        ItemType GetNextItem();
        void MergeLists(SortedType &list1, SortedType &list2);

    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
};

