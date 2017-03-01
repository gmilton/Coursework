// Lab 7
// state.h
// Grace Milton
// interface for State class

#include <string>
using namespace std;

class State {
  public:
    State();
    State(string, string, string, int, int, int);
    ~State();
    string getAbbr();
    string getName();
    string getCapital();
    int getPopulation();
    int getYear();
    int getReps();
    void setAbbr(string);
    void setName(string);
    void setCapital(string);
    void setPopulation(int);
    void setYear(int);
    void setReps(int);
    void printall();
    void printyear();
	void printpopulation();
	void printdensity();
  private:
    string abbr;
    string name;
    string capital;
    int population;
    int year;
    int reps;
};
