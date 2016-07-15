#pragma once
#include <fstream>
#include <iostream>

enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
    public:
        ItemType();
        RelationType ComparedTo(ItemType) const;        
        void Print() const;
        void Initialize(int number);
    private:
        int value;
};
