// Lab 5
// mysayings.cpp
// Grace Milton

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void dispmenu();
void dispall(vector<string>);
void newsaying(vector<string> &sayings);
void subsaying(vector<string>);
void savefile(vector<string> sayings,string);


int main()
{
   vector<string> sayings;
   int choice;
   int run = 1;
   string filename;
   string newfile;

   cout << "enter data file name: "; // Enter name of file you want to use.
   cin >> filename;
   ifstream ifs;
   string strObject;
   ifs.open(filename); // Opens file.

   // Displays error message if file doesn't work.
   if(!ifs) {
      cout << "error opening file " << filename << endl;
      return 1;
   }

   // Reads in file.
   getline(ifs, strObject);
   while(!ifs.eof()) {
      sayings.push_back(strObject);
      getline(ifs, strObject);
   }
  
   while (run)
   {
      dispmenu(); // Displays menu.
      cin >> choice;
      switch(choice) 
      {
         case 1: // Choice 1: Display all sayings
            dispall(sayings);
            break;
         case 2: // Choice 2: Add saying
            cout << "What would you like to add? ";
            newsaying(sayings); 
            cout << "Added!" << endl;
            break;
         case 3: // Choice 3: Find substring
            cout << "What word/substring would you like to find? ";
            subsaying(sayings);
            break;
         case 4: // Choice 4: Save new file
            cout << "What would you like to save the file as? ";
            cin >> newfile;
            savefile(sayings, newfile);
            cout << "Saved!" << endl;
            break;
         case 5: // Choice 5: Quit
            run = 0;
            break;
         default: // Displays error message if invalid input entered for choice
            cout << "ERROR INVALID INPUT" << endl;   
      }
   }

   cout << "Thanks!" << endl; // Ends program with Thanks!

   return 0;
}

// Displays menu and asks for choice
void dispmenu()
{
   cout << endl;
   cout << "1: display all sayings currently in the database." << endl;
   cout << "2: enter a new saying into the database." << endl;
   cout << "3: list sayings that contain a given word." << endl;
   cout << "4: save all sayings into a new text file." << endl;
   cout << "5: quit program" << endl;
   cout << "Enter your choice: ";
}

// Displays all sayings
void dispall(vector<string> sayings)
{
   for (unsigned int i = 0; i < sayings.size(); i++)
   {
       cout << "> " << sayings[i] << endl;
   }
}

// Adds new saying to vector
void newsaying(vector<string> &sayings)
{
   string newstring;
   cin.ignore();
   getline(cin, newstring);
   sayings.push_back(newstring);
}
 
// Finds substring in any saying in vector and displays if found
void subsaying(vector<string> sayings)
{
   string substring;
   cin.ignore();
   getline(cin, substring);
   for (unsigned int i = 0; i < sayings.size(); i++)
   {
      string tempstring = sayings[i];
      if (tempstring.find(substring) != -1)
         cout << "> " << sayings[i] << endl;
   }
}

// Saves vector of sayings (and added sayings) to file named by user
void savefile(vector<string> sayings, string newfile)
{
   ofstream ofs;
   ofs.open(newfile);
   for(unsigned int i = 0; i < sayings.size(); i++)
      ofs << sayings[i] << endl;
   ofs.close();
}
