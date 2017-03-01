// Authors: Matthew D'Alonzo,Grace Milton, and Roann Yanes
// Program: cards.h

class Cards {
	public:
		Cards();
		~Cards();
		void setSuit(int);
		void setKind(char);
		int getSuit();
		char getKind();
		void drawCard();

	private:
		int suit;
		char kind;

