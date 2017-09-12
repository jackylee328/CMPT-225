#include <iostream>
#include "circle.h"

using namespace std;

const int ARR_SIZE = 3;
Circle c[ARR_SIZE];
static int count = 0;

void collect(){
  int x,y,n;
  double r;
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> x;
    cin >> y;
    cin >> r;
    Circle new = Circle(x,y,r);
    c[i] = new;
    count++;
  }
}

int main(){
  cout << n;
  for (int i=0; i<n; i++){
    c[i].displayCircle();
  }
  for (int j=i; j<ARR_SIZE; j++){
    cout << "This cell is empty."
  }
  return 0;
}
