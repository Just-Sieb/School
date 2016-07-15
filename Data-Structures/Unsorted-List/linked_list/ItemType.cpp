#include <fstream>
#include <iostream>
#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else
        return EQUAL;
}

void ItemType::Initialize(int number)
{
    value = number;
}

void ItemType::Print() const
{
    std::cout << value << " ";
}