#include "sorted.h"
#include "ItemType.h"

SortedType::SortedType()
{
    //maxList == 30;
    length = 0;
    //info = new ItemType[maxList];
}

SortedType::SortedType(int max)
{
    //maxList == max;
    length = 0;
    //info = new ItemType[maxList];
}

void SortedType::MakeEmpty()
{
    length = 0;
}

bool SortedType::IsFull() const
{
    return (length == maxList);
}

int SortedType::GetLength() const
{
    return length;
}

ItemType SortedType::GetItem(ItemType item, bool& found)
{
    int midpoint;
    int first = 0;
    int last = length - 1;

    bool moreToSearch = first <= last;
    found = false;

    while(moreToSearch && !found)
    {
        midpoint = (first + last) / 2;
        switch(item.ComparedTo(info[midpoint]))
        {
            case LESS    : last = midpoint - 1;
                           moreToSearch = first <= last;
                           break;

            case GREATER : first = midpoint + 1;
                           moreToSearch = first <= last;
                           break;

            case EQUAL   : found = true;
                           item = info[midpoint];
                           break;
        }
    }
    return item;
} 

void SortedType::DeleteItem(ItemType item)
{
    int location = 0;

    while(item.ComparedTo(info[location]))
        location++;

    for(int index = location + 1; index < length; index++)
        info[index - 1] = info[index];

    length--;
}

void SortedType::PutItem(ItemType item)
{
    bool moreToSearch;
    int location = 0;

    moreToSearch = (location < length);

    while(moreToSearch)
    {
        switch(item.ComparedTo(info[location]))
        {
            case LESS    : moreToSearch = false;
                           break;

            case GREATER : location++;
                           moreToSearch = (location < length);
                           break;

            case EQUAL   : std::cout << "The two items are equal - this should not happen\n";
                           return;
                           break;
        }
    }
    for(int index = length; index > location; index--)
        info[index] = info[index - 1];
    info[location] = item;
    length++;
}

/*void SortedType::PutItem(ItemType item)
{
    int locationToInsert = 0;
    int midpoint = 0;
    int first = 0;
    int last = length - 1;
    bool moreToSearch = (first < last);
    int whileCount = 0;

    while(moreToSearch)
    {
        midpoint = (first + last) / 2;
        switch(item.ComparedTo(info[midpoint]))
        {
            case LESS    : last = midpoint - 1;
                           //std::cout << "In LESS.\n";
                           moreToSearch = (first < last);
                           if(!moreToSearch)
                               locationToInsert = midpoint - 1;
                           break;

            case GREATER : first = midpoint + 1;
                           //std::cout << "In Greater.\n";
                           moreToSearch = (first < last);
                           if(!moreToSearch)
                               locationToInsert = midpoint + 1;
                           break;

            case EQUAL   : //std::cout << "The two items are equal - this should not be\n";
                           break;
        }
    }
    //std::cout << "We are now preparing the array to insert item.";
    for(int index = length; index > locationToInsert; index--)
    {
        info[index] = info[index - 1];
    }
    info[locationToInsert] = item;
    length++;
}*/

void SortedType::ResetList()
{
    currentPos = -1;
}

ItemType SortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

void SortedType::MergeLists(SortedType &list1, SortedType &list2)
{
    list1.ResetList();
    list2.ResetList();
    this->MakeEmpty();
    
    ItemType list1Item = list1.GetNextItem();
    ItemType list2Item = list2.GetNextItem();

    int list1Counter = 0;
    int list1Length = list1.GetLength();
    int loopLength = list1.GetLength() + list2.GetLength();

    for(int count = 0; count < loopLength; count++)
    {
        if((list1Item.ComparedTo(list2Item) == LESS) && list1Counter < list1Length)
        {
            info[count] = list1Item;
            list1Item = list1.GetNextItem();
            list1Counter++;
        }
        else
        {
            info[count] = list2Item;
            list2Item = list2.GetNextItem();
        }
        length++;
    }
}