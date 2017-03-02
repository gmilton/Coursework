// Grace Milton
// CSE 20312 Lab 02 Part 2
// centralcity.cpp
//
// Main driver for CCCitizen class and its derived classes
 	
/*	Instantiates six characters from TV show "The Flash", 
 	sets their attributes using either the constructor or additional functions, 
 	then prints using either function, base pointer, or derived pointer	*/

#include <iostream>
#include <string>
using namespace std;
#include "cccitizen.h"
#include "metahuman.h"
#include "human.h"

int main() {

   // Instantiate 6 Characters
   Metahuman Barry("Allen", "Barry", 1);
   Human Joe("West", "Joe", 2, "Detective, Central City Police Department", "Team Flash");
   Metahuman Cisco("Ramon", "Cisco", 3);
   Human Harry("Wells", "Harrison", 4);
   Metahuman Wells("Thawne", "Eobard", 5);
   Human Iris("West", "Iris", 8);


   // Set Barry's attributes
   Barry.setAlias("The Flash");
   Barry.setPowers("Superspeed (Zoom!)");
   Barry.setMorals("Adorably Good");
   
   // Set Cisco's attributes
   Cisco.setAlias("Vibe");
   Cisco.setPowers("Vibing (don't know too much about yet)");
   Cisco.setMorals("Good as you can get");

   // Set Harry's attributes
   Harry.setJob("Scientist, S.T.A.R. Labs (Earth-2)");
   Harry.setAffiliation("Team Flash? His Daughter? TBD");
  
   // Set Wells' attributes
   Wells.setAlias("Harrison Wells, Reverse Flash");
   Wells.setPowers("Superspeed (Zoom!)");
   Wells.setMorals("Bad to the bone");

   // Set Iris' attributes
   Iris.setJob("Investigative Journalist, Central City Picture News");
   Iris.setAffiliation("Team Flash");

   Barry.print();
   Joe.print();

   // Print Cisco using base_ptr
   CCCitizen * base_ptr = &Cisco;
   base_ptr->print();

   Harry.print();

   // Print Wells using derived_ptr
   Metahuman * derived_ptr = &Wells;
   derived_ptr->print();   

   // Print Iris using base_ptr
   base_ptr = &Iris;
   base_ptr->print();

   return 0;

}
