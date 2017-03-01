#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int nx;
	int ny;
	cout << "Size of table (X axis): ";
	cin >> nx;
	cout << "Size of table (Y axis): ";
	cin >> ny;
	for (int j = 0; j <= ny; j++){
		if (j == 0){
			cout << setw(4) << "*" << setw(4);
		} else {
			cout << setw(4) << j << setw(4);
		}
		for (int i = 1; i <= nx; i++){
			if (i*j == 0){
				cout << i << setw(4);
			} else if (i == nx){
				cout << i*j;
			} else {
				cout << i*j << setw(4);
			}
		}
		cout << endl;
	}
}
