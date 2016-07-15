#include <iostream>
using namespace std;

int main() {

    //The two constant values that do no change in the program
    const double SquareFeetPerHour = 100;
    const double CostOfOneGallon = 27;
    const double CoverageOfOneGallon = 350;

    // Initialization of the variable used in the program
    double width = 0.0;
    double height = 0.0;
    double area = 0.0;
    double GallonsNeeded = 0.0;
    double CostOfPaint = 0.0;
    double TotalTime = 0.0;

    // Getting the value of area of the wall
    cout << "Enter the width of the wall in feet: ";
    cin >> width;
    cout << "Enter the height of the wall in feet: ";
    cin >> height;
    
    // Calculate and output area of wall
    area = height * width;
    GallonsNeeded = area / CoverageOfOneGallon;
    // TODO find function to round Gallons needed up
    CostOfPaint = GallonsNeeded * CostOfOneGallon;
    TotalTime = area / SquareFeetPerHour;

    // Outputting all teh results to the console
    cout << "Total area to paint in square feet: "
         << area << endl
         << "Total number of gallons of paint needed: "
         << GallonsNeeded << endl
         << "Total cost of paint in dollars: "
         << CostOfPaint << endl
         << "Total time to paint in hours: "
         << TotalTime;

    return 0;
}
