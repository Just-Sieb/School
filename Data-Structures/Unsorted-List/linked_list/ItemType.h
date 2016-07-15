#pragma once
#include <fstream>

enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
    public:
        ItemType();
        RelationType ComparedTo(ItemType item) const;
        void Print() const;
        void Initialize(int number);
    private:
        int value;
};