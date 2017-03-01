#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

cout << "A plot of y = 10*(2+cos(x/2)+sin(2*x)) from x = 0 to 20.0" << 
endl;
float x;
float y;
float max;
float min;
float xmax;
float xmin;
cout << setw(4) << "X" << setw(9) << "Y" << endl;
for (x = 0; x <= 20.2; x = x + 0.2){
	y = 10*(2+cosf(x/2)+sinf(2*x));
	if (x < 9.8) {
		cout << setprecision(2) << fixed << " " << x << 
		setw(8) << setprecision(2) << fixed << y << setw(3);
	} else {
		cout << setprecision(2) << fixed << x << setw(8) << 
		setprecision(2) << fixed << y << setw(3);
	}
	if(x==0){
		max = y;
		xmax = 0;
	} else if (y > max){
		max = y;
		xmax = x;
	}
	if (x == 0){
		min = y;
		xmin = x;
	} else if (y < min) {
		min = y;
		xmin = x;
	}
	y = y+0.5;
	for(int i = 0; i < y; i++){
	cout << "#";
	}
	cout << endl;
}
cout << endl << "The maximum of " << setprecision(2) << fixed << max << 
" was at x=" << setprecision(2) << fixed << xmax << endl;
cout << "The minimum of " << setprecision(2) << fixed << min << 
" was at x= " << setprecision(2) << fixed << xmin << endl;

}
