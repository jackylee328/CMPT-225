#include <iostream>

using namespace std;

int sumArray(int* arr, int arrSize){
  int sum = 0;
  for (int i=0; i<arrSize; i++){
    sum += arr[i];
  }
  return sum;
}

int main(){
  int size;
  cin >> size;
  int* arr = new int[size];
  int val;
  for (int i=0; i<size; i++){
    cin >> val;
    arr[i] = val;
  }
  int sum = sumArray(arr, size);
  cout << sum << endl;
  //delete [ ] arr;
  return 0;
}
