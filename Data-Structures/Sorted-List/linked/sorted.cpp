#include "sorted.h"

SortedType::SortedType()
{
    length = 0;
    listData = NULL;
}

bool SortedType::IsFull() const
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

int SortedType::GetLength() const
{
    return length;
}

void SortedType::MakeEmpty()
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

ItemType SortedType::GetItem(ItemType item, bool& found)
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
            case LESS    : moreToSearch = false;
                           break;

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

void SortedType::PutItem(ItemType item)
{
    NodeType* newNode;
    NodeType* predLoc;
    NodeType* location;
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);

    while(moreToSearch)
    {
        switch(item.ComparedTo(location->info))
        {
            case GREATER : predLoc = location;
                           location = location->next;
                           moreToSearch = (location != NULL);
                           //std::cout << "We are in greater\n";
                           break;

            case EQUAL   : predLoc = location;
                           location = location->next;
                           moreToSearch = false;
                           break;

            case LESS    : moreToSearch = false;
                           break;

        }
    }

    newNode = new NodeType;
    newNode->info = item;

    if(predLoc == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

void SortedType::DeleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;
    if(item.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while(item.ComparedTo((location->next)->info) != EQUAL)
        {
            location = location->next;
        }
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void SortedType::ResetList()
{
    currentPos = NULL;
}

ItemType SortedType::GetNextItem()
{
    ItemType item;
    if(currentPos == NULL)
        currentPos = listData;

    item = currentPos->info;
    //item.Print();
    currentPos = currentPos->next;
    return item;
}

SortedType::~SortedType()
{
    this->MakeEmpty();
}

void SortedType::MergeLists(SortedType &list1, SortedType &list2)
{
    list1.ResetList();
    list2.ResetList();
    this->MakeEmpty();

    ItemType list1Item;
    ItemType list2Item;

    NodeType* newNode;

    int list1Counter = 0;
    int list1Length = list1.GetLength();
    int loopLength = list1.GetLength() + list2.GetLength();

    list1Item = list1.GetNextItem();
    list2Item = list2.GetNextItem();

    for(int count = 0; count < loopLength; count++)
    {
        newNode = new NodeType;
        newNode->next = NULL;


        //std::cout << "We are at " << count << std::endl;

        if((list1Item.ComparedTo(list2Item) == LESS) && list1Counter < list1Length )
        {
            //std::cout << "We are at item 1 less" << std::endl;
            if(listData == NULL)
            {
                newNode->info = list1Item;
                listData = newNode;
            }
            else
            {
                newNode->info = list1Item;
                currentPos->next = newNode;
            }
            list1Item = list1.GetNextItem();
            list1Counter++;
        }
        else
        {
            //std::cout << "We are at item 2 less" << std::endl;
            if(listData == NULL)
            {
                newNode->info = list2Item;
                listData = newNode;
            }
            else
            {
                //std::cout << "We are in else" << std::endl;
                newNode->info = list2Item;
                currentPos->next = newNode;
            }
            list2Item = list2.GetNextItem();
        }
        //std::cout << "We are outside if statements" << std::endl;
        if(count == 0)
        {
            currentPos = newNode;
        }
        else
        {
            currentPos->next = newNode;
            currentPos = currentPos->next;
        }
        length++;
        //std::cout << "We are at end of the loop" << std::endl;
    }
}