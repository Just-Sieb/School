#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
}

bool UnsortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}

int UnsortedType::GetLength() const
{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool &found)
{
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LESS    :
            case GREATER : location++;
                           moreToSearch = (location < length);
                           break;
            case EQUAL   : found = true;
                           item = info[location];
                           break;
        }
    }
    return item;
}

void UnsortedType::MakeEmpty()
{
    length = 0;
    return;
}

void UnsortedType::PutItem(ItemType item)
{
    info[length] = item;
    length++;
    return;
}

void UnsortedType::DeleteItem(ItemType item)
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL)
        location++;
        
    info[location] = info[length - 1];
    length--;
    return;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
    return;
}

ItemType UnsortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

void UnsortedType::SplitLists(UnsortedType list, ItemType item, UnsortedType &list1, UnsortedType &list2)
{
    //Empties the lists we are putting the items in
    list1.MakeEmpty();
    list2.MakeEmpty();
    ItemType tempItem;
    
    list.ResetList();
    
    if (list.GetLength() > 0)
    {
        bool foundSplit = false;
        for(int counter = 0; counter < list.GetLength(); counter++)
        {
            if (!foundSplit)
            {
                tempItem = list.GetNextItem();
                list1.PutItem(tempItem);
                if (tempItem.ComparedTo(item) == EQUAL){
                    foundSplit = true;
                }
            }
            else
            {
                list2.PutItem(list.GetNextItem());
            }
            
        }
    }
    return;
}