// Lab 8
// lifeboard.h
// Grace Milton

#include <string>
using namespace std;

// Sets size of boards
const int size1 = 40;
const int size2 = 40;

class Lifeboard {
   public:
      Lifeboard();
      ~Lifeboard();
      void initialize(); // Makes entire board empty
      void display(); // Displays board
      void add(int, int); // Makes cell live
      void remove(int, int); // Makes cell dead
      void advance(); // Advances board to next step according to rules of game
      void continuous(Lifeboard &); // Plays game continuously
   private:
      char currBoard[size1][size2];
      char tempBoard[size1][size2];
};
