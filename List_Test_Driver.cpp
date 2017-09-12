/*
 * List Test Driver
 *
 * Author:
 * Date:
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "ListADT.h"

using namespace std;



int main() {

  // Variables declaration
  //ListADT* members = new ListADT();

  ListADT members;

  cout << "Testing...Testing...1..2..3! Is this mic on?" << endl;

  Profile Tyrone = Profile("Tyrone");
  members.insert(1,Tyrone);
  Profile Jyrone = Profile("Jyrone");
  members.insert(2,Jyrone);
  int x = members.getPosition(Tyrone);
  cout << x << endl;
  cout << members << endl;
  return 0;
}
