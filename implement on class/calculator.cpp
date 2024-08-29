#include<iostream>
using namespace std;
#include<string>


int get_int(string prompt);

int main() {
   int x = get_int("x: ");
   int y = get_int("y: ");
   cout << x + y <<endl;
   return 0;
}

