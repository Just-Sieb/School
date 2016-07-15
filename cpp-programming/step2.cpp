#include <iostream>
#include <string>
using namespace std;

int main() {
   string tweet;
   
   cout << "Enter abbreviation from tweet: ";
   getline(cin, tweet);
   
   tweet.resize(160)
   
   // Output decoded abbreviation from tweet
   if (tweet == "LOL") {
      cout << "LOL = laughing out loud" << endl;
   }
   else if (tweet == "IRL") {
      cout << "IRL = in real life" << endl;
   }
   else if (tweet == "AFK") {
      cout << "AFK = away from keyboard" << endl;
   }
   else if (tweet == "NVM") {
      cout << "NVM = never ming" << endl;
   }
   else if (tweet == "BFF") {
      cout << "BFF = best friends forever" << endl;
   }
   else if (tweet == "FTW") {
      cout << "FTW = for the win" << endl;
   }
   else if (tweet == "IIRC") {
      cout << "IIRC = if I recall correctly" << endl;
   }
   else if (tweet == "TTYL") {
      cout << "TTYL = talk to you later" << endl;
   }
   else if (tweet == "IMHO") {
      cout << "IMHO = in my humble opinion" << endl;
   }
   else {
      cout << "Sorry, don't know that one." << endl;
   }
   
   return 0;
}