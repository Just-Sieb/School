#include <iostream>
using namespace std;

int main() {
    
    int TrunkHeight = 0;
    int TrunkHeightCounter = 0;
    int TrunkWidth = 0;
    int LeavesWidth = 0;
    int LeavesWidthOnRow = 0;
    int SpacesWidthOnRow = 0;
    int LeavesHeight = 0;

    bool IsEven = true;
    int gap = 0;
    int GabCounter = 0;
    
    do {
        IsEven = true;
        count << "Enter trunk height: ";
        cin >> TrunkHeight;
        if ((TrunkHeight % 2) == 1){
            IsEven = false;
        else {
            cout << "Please enter an odd number":
        }
        }
    } while (IsEven)
    
    do {
        IsEven = true;
        count << "Enter trunk width: ";
        cin >> TrunkWidth;
        if ((TrunkWidth % 2) == 1){
            IsEven = false;
        else {
            cout << "Please enter an odd number":
        }
        }
    } while (IsEven)
    
    do {
        IsEven = true;
        count << "Enter leaves width: ";
        cin >> LeavesWidth;
        if ((LeavesWidth % 2) == 1){
            IsEven = false;
        }
        else {
            cout << "Please enter an odd number":
        }
    } while (IsEven)

    // Draw leaves
    LeavesHeight = (LeavesWidth + 1) / 2
    for (int HeightCounter = 1, HeightCounter <= LeavesHeight, HeightCounter++){
        LeavesWidthOnRow = (2 * HeightCounter) - 1;
        SpacesWidthOnRow = (LeavesWidth - LeavesWidthOnRow) / 2;
        for (int SpaceCounter = 1, SpaceCounter <= SpacesWidthOnRow, SpaceCounter++){
            cout << " ";
        }
        for (int LeavesCounter = 1, LeavesCounter <= LeavesWidthOnRow, LeavesCounter++){
            cout << "*";
        }
    }

    // Draw trunk
    gap = (LeavesWidth - TrunkWidth) / 2;
    
    for (int HeightCounter = 1, counter <= TrunkHeight, counter++) {
        for (int SpaceCounter = 1, SpaceCounter <= gap, SpaceCounter++) {
            count << " ";
        }
        for (int TrunkCounter = 1, TrunkCounter <= TrunkWidth, TrunkCounter++) {
            count << "*";
        }
        cout << endl;
    }

    return 0;
}
