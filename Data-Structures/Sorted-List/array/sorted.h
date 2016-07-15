#pragma once
#include "ItemType.h"

class SortedType
{
    public:
        SortedType();
        SortedType(int max);
        void MakeEmpty();
        bool IsFull() const;
        int GetLength() const;
        ItemType GetItem(ItemType item, bool &found);
        void PutItem(ItemType item);
        void DeleteItem(ItemType item);
        void ResetList();
        ItemType GetNextItem();
        void MergeLists(SortedType &list1, SortedType &list2);

    private:
        int length;
        int maxList;
        ItemType info[30];
        int currentPos;
};
