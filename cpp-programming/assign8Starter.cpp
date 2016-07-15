#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Item {
    public:
        void SetName(string nm)
            { name = nm; };
        void SetQuantity(int qnty)
            { quantity = qnty; };
        virtual void Print()
            { cout << name << " " << quantity << endl; };
        virtual ~Item()
            { return; };
    protected:
        string name;
        int    quantity;
};

class Produce : public Item { // Derived from Item class
    public:
        void SetExpiration(string expir)
            { expiration = expir; };
        void Print()
            { cout << name << " x" << quantity
              << " (Expires: " << expiration << ")"
              << endl;
            };
    private:
        string expiration;
};

// Print all items in the inventory
void PrintInventory(vector<Item*> inventory);

// Dialogue to create a new item, then add that item to the inventory
vector<Item*> AddItemToInventory(vector<Item*> inventory);

// Dialogue to update the quantity of an item, then update that item in the inventory
vector<Item*> UpdateItemQtyInInventory(vector<Item*> inventory);

// Dialogue to remove a specific item, then remove that specific item from the inventory
vector<Item*> RemoveItemFromInventory(vector<Item*> inventory);

int main() {
    vector<Item*> inventory;
    string usrInptOptn = "default";
    
    while (true) {
        // Get user choice
        cout << "\nEnter (p)rint, (a)dd, (u)pdate, (r)emove, or (q)uit: ";
        getline(cin, usrInptOptn);

        // Process user choice
        if (usrInptOptn.size() == 0) {
            continue;
        } else if (usrInptOptn.at(0) == 'p') {
            PrintInventory(inventory);
        } else if (usrInptOptn.at(0) == 'a') {
            inventory = AddItemToInventory(inventory);
        } else if (usrInptOptn.at(0) == 'u') {
            inventory = UpdateItemQtyInInventory(inventory);
        } else if (usrInptOptn.at(0) == 'r') {
            inventory = RemoveItemFromInventory(inventory);
        } else if (usrInptOptn.at(0) == 'q') {
            cout << "\nGood bye." << endl;
            break;
        }
    }

    return 0;
}

void PrintInventory(vector<Item*> inventory) {
    unsigned int i = 0;
    if (inventory.size() == 0) {
        cout << "No items to print." << endl;
    } else {
        for (i=0; i<inventory.size(); ++i) {
            cout << i << " - ";
            inventory.at(i)->Print();
        }
    }
    return;
}

vector<Item*> AddItemToInventory(vector<Item*> inventory) {
    Produce* prdc;
    string usrInptName = "";
    string usrInptQntyStr = "";
    istringstream inSS;
    int usrInptQnty = 0;
    string usrInptExpr = "";
    
    cout << "Enter name of new produce: ";
    getline(cin, usrInptName);
    
    cout << "Enter quantity: ";
    getline(cin, usrInptQntyStr);
    inSS.str(usrInptQntyStr);
    inSS >> usrInptQnty;
    inSS.clear();
    
    cout << "Enter expiration date: ";
    getline(cin, usrInptExpr);
    
    prdc = new Produce;
    prdc->SetName(usrInptName);
    prdc->SetQuantity(usrInptQnty);
    prdc->SetExpiration(usrInptExpr);
    
    inventory.push_back(prdc);
    
    return inventory;
}

vector<Item*> UpdateItemQtyInInventory(vector<Item*> inventory) {
    string usrIndexChoiceStr = "";
    unsigned int usrIndexChoice = 0;
    istringstream inSS;
    string usrInptQntyStr = "";
    int usrInptQnty = 0;
    
    if (inventory.size() == 0) {
        cout << "No items to update." << endl;
    } else {
        PrintInventory(inventory);
        
        do {
            cout << "Update which item #: ";
            getline(cin, usrIndexChoiceStr);
            inSS.str(usrIndexChoiceStr);
            inSS >> usrIndexChoice;
            inSS.clear();
        } while ( !(usrIndexChoice < inventory.size()) );
        
        cout << "Enter new quantity: ";
        getline(cin, usrInptQntyStr);
        inSS.str(usrInptQntyStr);
        inSS >> usrInptQnty;
        inSS.clear();
        
        inventory.at(usrIndexChoice)->SetQuantity(usrInptQnty);
    }
    
    return inventory;
}

vector<Item*> RemoveItemFromInventory(vector<Item*> inventory) {
    istringstream inSS;
    string usrIndexChoiceStr = "";
    unsigned int usrIndexChoice = 0;
    string usrInptQntyStr = "";
    
    if (inventory.size() == 0) {
        cout << "No items to remove." << endl;
    } else {
        PrintInventory(inventory);
        
        do {
            cout << "Remove which item #: ";
            getline(cin, usrIndexChoiceStr);
            inSS.str(usrIndexChoiceStr);
            inSS >> usrIndexChoice;
            inSS.clear();
        } while ( !(usrIndexChoice < inventory.size()) );
        
        inventory.erase( inventory.begin() + usrIndexChoice );
    }
    
    return inventory;
}
