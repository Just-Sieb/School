#include <iostream>
#include "sorted.h"
#include "ItemType.h"

using namespace std;

void printList(SortedType &list);

void MergeLists(SortedType &list1, SortedType &list2, SortedType& list)
{
    list.ResetList();
    list1.ResetList();
    list2.ResetList();
    ItemType item;

    
    for(int count = 0; count < list2.GetLength(); count++)
    {
        item = list2.GetNextItem();
        list.PutItem(item);
    }
    
    for(int count = 0; count < list1.GetLength(); count++)
    {
        item = list1.GetNextItem();
        list.PutItem(item);
    }
}

// for int values
void check(int listValue, int correctValue){
       if (listValue == correctValue)
       {
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

void printList(SortedType &list)
{
    list.ResetList();
    ItemType current;
    
    for (int counter = 0; counter < list.GetLength(); counter++)
    {
        current = list.GetNextItem();
        current.Print();
        
    }
    cout << endl;
}

int main(){
    
    cout << "Starting program" << endl;
    
    SortedType clientList1;
    SortedType clientList2;
    SortedType clientList3;
    SortedType listMergeInFunc1;
    SortedType listMergeInFunc2;
    SortedType listMergeInFunc3;
    ItemType item;
    
    SortedType list1;
    SortedType list2;
    SortedType list3;
    SortedType list4;
    
    cout << "Adding item to the lists: " << endl;

    item.Initialize(1);
    list1.PutItem(item);
    item.Initialize(72);
    list1.PutItem(item);
    item.Initialize(3);
    list1.PutItem(item);
    item.Initialize(33);
    list1.PutItem(item);
    item.Initialize(253);
    list1.PutItem(item);
    item.Initialize(12);
    list1.PutItem(item);
    item.Initialize(67);
    list1.PutItem(item);

    item.Initialize(132);
    list2.PutItem(item);
    item.Initialize(505);
    list2.PutItem(item);
    item.Initialize(34);
    list2.PutItem(item);
    item.Initialize(23);
    list2.PutItem(item);
    item.Initialize(263);
    list2.PutItem(item);
    item.Initialize(7);
    list2.PutItem(item);
    item.Initialize(54);
    list2.PutItem(item);

    item.Initialize(56);
    list3.PutItem(item);
    item.Initialize(1746);
    list3.PutItem(item);
    item.Initialize(92);
    list3.PutItem(item);
    item.Initialize(574);
    list3.PutItem(item);
    item.Initialize(78);
    list3.PutItem(item);
    item.Initialize(14);
    list3.PutItem(item);
    item.Initialize(1000);
    list3.PutItem(item);

    item.Initialize(16);
    list4.PutItem(item);
    item.Initialize(728);
    list4.PutItem(item);
    item.Initialize(5673);
    list4.PutItem(item);
    item.Initialize(333);
    list4.PutItem(item);
    item.Initialize(27);
    list4.PutItem(item);
    item.Initialize(19);
    list4.PutItem(item);
    item.Initialize(693);
    list4.PutItem(item);

    cout << "\nThe initial lists\n";
    printList(list1);
    printList(list2);
    printList(list3);
    printList(list4);


    cout << "\nMerge lists using the client function:\n";
    MergeLists(list1, list2, clientList1);
    MergeLists(list3, list4, clientList2);
    MergeLists(clientList1, clientList2, clientList3);
    
    printList(clientList1);
    printList(clientList2);
    printList(clientList3);


    cout << "\nMerge lists using the functions built into the class\n";

    listMergeInFunc1.MergeLists(list1, list2);
    printList(listMergeInFunc1);

    listMergeInFunc2.MergeLists(list3, list4);
    printList(listMergeInFunc2);

    listMergeInFunc3.MergeLists(listMergeInFunc1, listMergeInFunc2);
    printList(listMergeInFunc3);

    
    cout << "Finished running" << endl;
    
    return 0;
}