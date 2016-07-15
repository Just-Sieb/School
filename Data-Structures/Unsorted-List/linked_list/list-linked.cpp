#include <iostream>
#include "UnsortedType.h"
#include "ItemType.h"

using namespace std;

// for int values
void check(int listValue, int correctValue){
       if (listValue == correctValue){
            cout << "Passed: " 
                 << listValue 
                 << " - "
                 << correctValue
                 << endl;
       }
       else
            cout << "ERROR: The following values did not pass the test, " 
                 << listValue 
                 << " - "
                 << correctValue
                 << endl;
}

// for boolean values
void check(bool listValue, bool correctValue){
       if (listValue == correctValue){
            cout << "Passed: " 
                 << listValue 
                 << " - "
                 << correctValue
                 << endl;
       }
       else
            cout << "ERROR: The following values did not pass the test, " 
                 << listValue 
                 << " - "
                 << correctValue
                 << endl;
}

void printList(UnsortedType list)
{
    list.ResetList();
    ItemType current;
    
    for (int counter = 0; counter < list.GetLength(); counter++)
    {
        current = list.GetNextItem();
        current.Print();
    }
    cout << endl;
    return;
    
}

int main(){
    
    cout << "Starting program" << endl;
    
    UnsortedType list;
    ItemType item;
    
    cout << "List Length: " << list.GetLength() << endl;
    
    cout << "Adding item to the list: " << endl;

    item.Initialize(5);
    list.PutItem(item);
    item.Initialize(7);
    list.PutItem(item);
    item.Initialize(6);
    list.PutItem(item);
    item.Initialize(9);
    list.PutItem(item);
    
    printList(list);
    item.Initialize(1);
    list.PutItem(item);
    
    printList(list);
    
    bool found;
    
    cout << "Verifying contents: " << endl;

    item.Initialize(4);
    list.GetItem(item, found);
    check(found, false);
    item.Initialize(5);
    list.GetItem(item, found);
    check(found, true);
    item.Initialize(9);
    list.GetItem(item, found);
    check(found, true);
    item.Initialize(10);
    list.GetItem(item, found);
    check(found, false); 

    cout << "Adding more items" << endl;
    
    item.Initialize(23);
    list.PutItem(item);
    item.Initialize(2);
    list.PutItem(item);
    item.Initialize(67);
    list.PutItem(item);
    item.Initialize(13);
    list.PutItem(item);
    item.Initialize(145);
    list.PutItem(item);
    
    cout << "Split list test: " << endl;

    printList(list);

    UnsortedType list1, list2;
    item.Initialize(23);
    list.SplitLists(list, item, list1, list2);
    printList(list1);
    printList(list2);
    
    cout << "Finished running" << endl;
    
    return 0;
}
