// Lab 6
// letterfreq.cpp
// Grace Milton
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
   string filename;
   int freq[26];
   ifstream ifs;
   char character;
   float spaces = 0, alphas = 0, sumCharacters = 0, spacepercent;
   
   cout << "Enter name of startup file: ";
   cin >> filename;
   ifs.open(filename);
   if(!ifs) {  // Makes sure file is valid
      cout << "error opening file " << filename << endl;
      return 1;
   }

   for (int i = 0; i < 26; i++) { // Initializes frequency array to 0
      freq[i] = 0;
   }
   
   character = ifs.get(); // Gets first character
   while(!ifs.eof()) { // Goes through whole file      
      if (isspace(character)) { // Counts spaces
         spaces++;
      }
      if (isalpha(character)) { // Counts letters
         character = tolower(character);
         freq[character-97]++;
         alphas++;
      }
      character = ifs.get();
      sumCharacters++; // Counts total number of characters
   }
   
   // Displays list of frequency of each letter
   char letter = 'a';
   for (int i = 0; i < 26; i++) {
      cout << letter << ":" << setw(8) << freq[i] << endl;
      letter++;
   }
   cout << endl;

   cout << "there were " << fixed << setprecision(0) << alphas << " letters" << endl;
   cout << "there were " << sumCharacters << " total characters" << endl;
   cout << "there were " << spaces << " white space characters" << endl;

   spacepercent = 100.*spaces/sumCharacters; // Calculates space percentage
   
   cout << "space percentage: " << setprecision(1) << spacepercent << "%" << endl;

   return 0;
}
