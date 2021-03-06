#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
}

bool UnsortedType::IsFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

int UnsortedType::GetLength() const
{
    return length;
}

void UnsortedType::MakeEmpty()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(location->info))
        {
            case LESS    : 
            case GREATER : location = location->next;
                           moreToSearch = (location != NULL);
                           break;
            case EQUAL   : found = true;
                           item = location->info;
                           break;
        }
    }
    return item;
}

void UnsortedType::PutItem(ItemType item)
{
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;

    length++;
}

void UnsortedType::DeleteItem(ItemType item)
{
    NodeType* location =listData;
    NodeType* tempLocation;

    if (item.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while (item.ComparedTo((location->next)->info) != EQUAL)
            location = location->next;

        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

void UnsortedType::ResetList()
{
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    return currentPos->info;
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