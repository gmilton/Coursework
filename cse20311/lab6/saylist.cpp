// Lab 6
// saylist.cpp
// Grace Milton
// based off R. Bualan's mysayings.cpp solution
#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <fstream>
using namespace std;

void sortlist(list<string> &, string);
int displaymenu(void);
void showallsayings(list<string> &);
void getnewsaying(list<string> &);
void showmatching(list<string> &);
void deletesaying(list<string> &);

int main()
{
   list<string> sayings;
   int choice;
   bool done = false;
   string filename, newfile;
   string strObject;
   ifstream ifs;
   ofstream ofs;

   cout << "Welcome to the Sayings Database! \n";
   cout << "Enter name of startup file: ";
   cin >> filename;
   ifs.open(filename);
   // Makes sure file is valid
   if(!ifs) {
      cout << "error opening file " << filename << endl;
      return 1;
   }

   // Loads the sayings from the startup file alphabetically
   getline(ifs,strObject);
   sayings.push_back(strObject);
   while(!ifs.eof()) {
      getline(ifs, strObject);
      if (strObject.empty()) continue; // Skips empty lines
      sortlist(sayings, strObject);
   }

   while(!done) {
      choice = displaymenu();
      switch (choice) {
         case 1: // Displays all sayings.
            showallsayings(sayings);
            break;
         case 2: // Adds new saying
            getnewsaying(sayings);
            break;
         case 3: // Finds sayings with given substring
            showmatching(sayings);
            break;
         case 4: // Deletes saying
            showallsayings(sayings); 
            deletesaying(sayings);
            break;
         case 5: // Saves current sayings into new file
            cout << "Enter the file name where all sayings will be saved: ";
            cin >> newfile;
            ofs.open(newfile,ofstream::out);
            // Makes sure the file can be created
            if(!ofs) {  
               cout << "error creating file " << newfile << endl;
               return 2;
            }
            // Saves sayings into file
            for (auto it = sayings.begin(); it != sayings.end(); it++) {
               ofs << *it << endl;  
            }
            break;
         case 6: // Quits program
            cout << "Goodbye!\n";
            done = true;
            break;
         default: // Makes sure choice is valid
            cout << "\nunknown choice " << choice << "; try again.\n";
            continue;
      }
   }

   return 0;
}

// Adds saying to list alphabetically
void sortlist(list<string> &say, string strObject)
{
   auto it = say.begin();
   while (strObject.compare(*it) > 0 && it!= say.end()){
      ++it;
   }
   if (it == say.end()) {
      say.push_back(strObject);
   }
   else {
      say.insert(it, strObject);
   }
}

// Displays menu and returns choice
int displaymenu(void)
{
   int choice;
   cout << "\nTasks you can perform:\n";
   cout << " 1: show all sayings.\n";
   cout << " 2: enter a new saying.\n";
   cout << " 3: list sayings that contain a given word.\n";
   cout << " 4: delete a saying.\n";
   cout << " 5: save all sayings in a new text file.\n";
   cout << " 6: quit.\n";

   cout << "Enter your choice: ";
   cin >> choice;

   return choice;
}

// Shows all sayings
void showallsayings(list<string> &say)
{
   int count = 0;

   for (auto it = say.begin(); it != say.end(); it++) {
      count++;
      cout << setw(2) << count << " - " << *it << endl;
   }
}

// Adds new saying in correct alphabetical position
void getnewsaying(list<string> &say)
{
   string newsay;

   cout << "Enter a new saying: ";
   cin.ignore();
   getline(cin, newsay);
   sortlist(say, newsay);
}

// Shows sayings containing given substring/word
void showmatching(list<string> &say) 
{
   string word;
   bool amatch = false;

   cout << "Enter the search word: ";
   cin.ignore();
   getline(cin, word);
   for (auto it = say.begin(); it != say.end(); it++) {
      if ((*it).find(word) != string::npos) {
         cout << "> " << *it << endl;
         amatch = true; // Sets value to true when match found
      }
   }
   // Displays message if no match
   if (!amatch) {
      cout << "there are no matches\n";
   }
}

// Deletes saying of user's choice
void deletesaying(list<string> &say)
{
   int deletesay, maxsay = say.size();
   auto it = say.begin();
   cout << "Which saying would you like to delete? "; 
   cin >> deletesay;
   // Makes sure saying choice is valid
   while (deletesay < 1 || deletesay > maxsay) {
      cout << "Please enter a number from 1-" << maxsay << ": ";
      cin >> deletesay;
   }
   deletesay = deletesay - 1;
   advance(it, deletesay);
   say.remove(*it); 
} 
