/* File Name: WICPS.cpp
 *
 * Authors: Andy Wu, Jacky Lee
 *
 * Creation Date: May 24th, 2017
 */

#include <iostream>
#include "Patient.h"
#include "List.h"
#include <unistd.h>

using namespace std;

static bool is_finished = 0;

// Description: print a welcome message when the program first executes
void welcome(){
    cout << "==============================================" << endl;
    cout << "      Welcome to Andy and Jacky's clinic      " << endl;
    cout << "==============================================" << endl;
    cout << "( Í¡Â° ÍœÊ– Í¡Â°)      ( Í¡Â° ÍœÊ– Í¡Â°)      ( Í¡Â° ÍœÊ– Í¡Â°)" << endl;
}

// Description: display all options available to the users
void print_menu(){
    // set a delay of 1.5 seconds to increase readability
    // users can finish reading the previous message before this one prints
    sleep(1.5);
    cout << "=========================" << endl;
    cout << "Choose from 6 options:   " << endl;
    cout << "   1. Add Patient.       " << endl;
    cout << "   2. Remove Patient.    " << endl;
    cout << "   3. Search Patient.    " << endl;
    cout << "   4. Modify Patient.    " << endl;
    cout << "   5. Print Patient List." << endl;
    cout << "   6. Exit the program.  " << endl;
    cout << "=========================" << endl;
    cout << "Your Choice: ";
}

// Description: check if the received care card is valid
// returns 4 if valid, otherwise it is invalid.
int checkForInvalidCareCardNumber(string careCard){
    string zero = "0";
    string allZero = "0000000000";
    // check if the string contains characters which are not numbers
    // return 1 if a non-number is detected
    for(unsigned int i = 0; i < careCard.length(); i++){
        if(careCard.at(i) < 47 || careCard.at(i) > 57){
            return 1;
        }
    }
    // return 0 if a 0 is received
    if(careCard == zero){
        return 0;
    }
    // return 2 if "0000000000" is received
    if(careCard == allZero){
        return 2;
    }
    // return 3 if length of string is not equal to 10
    if(careCard.length() != 10){
        return 3;
    }
    // return 4 if the care card number is valid!
    return 4;
}

// Description: adds a patient by asking the user to input a care card number
// a patient is added only if the care card number is valid,
// our list is not full, and patient does not already exist
void addPatient(List &aList){
    string careCard;
    // ask user for an input
    cout << "Please enter a care card number. Enter 0 to go back" << endl;
    // receive and store the input as careCard
    getline(cin, careCard);
    // check if careCard is valid
    int status = checkForInvalidCareCardNumber(careCard);
    while(status != 4){
        // back to menu if 0 is received
        if(status == 0){
            cout << "Going back to menu... c:" << endl;
            return;
        }
        // oops! input is not accepted because a non-number is received
        else if(status == 1){
            cout << "You cannot have a carecard that has a invalid digit! Please Try again or enter 0 to back. â˜œ(`oÂ´)" << endl;
            getline(cin, careCard);
            status = checkForInvalidCareCardNumber(careCard);
        }
        // "0000000000" is not accepted either
        else if(status == 2){
            cout << "You cannot have a care card that contains all 0s! Please Try again or enter 0 to back. â˜œ(`oÂ´)" << endl;
            getline(cin, careCard);
            status = checkForInvalidCareCardNumber(careCard);
        }
        // input is not 10 digits, not accepted
        else if(status == 3){
            cout << "You cannot have a care card that is more or less than 10 digits! Please Try again or enter 0 to back. â˜œ(`oÂ´)" << endl;
            getline(cin, careCard);
            status = checkForInvalidCareCardNumber(careCard);
        }
    }
    // care card number is valid, we will now try to add the patient
    Patient newPatient = Patient(careCard);
    // make sure the patient does not already exist
    if (aList.search(newPatient) == NULL){
        // we also want to make sure that the list is not full
        bool successful = aList.insert(newPatient);
        if (successful){
            cout << "Patient has been added. â•­( ï½¥ã…‚ï½¥)Ùˆ" << endl;
        }
        else{
            cout << "Patient list is full. (Â´Â°Ï‰Â°`)" << endl;
        }
    }
    else{
        cout << "Patient already exists. (Â´Â°Ï‰Â°`)" << endl;
    }
}

// Description: check if list is empty
bool checkIfListIsEmpty(List &aList){
    // return true if number of elements is equal to 0
    int numberOfElements = aList.getElementCount();
    if(numberOfElements == 0){
        return true;
    }
    // return false otherwise
    return false;
}

// Description: remove all patients from our list
void removeAllPatient(List &aList){
    aList.removeAll();
}

// Description: remove a patient from the list by asking the user to input a care card number
void removePatient(List &aList){
    //Checks if list is empty
    if(checkIfListIsEmpty(aList)){
        cout << "List is empty! (O__O)" << endl;
        return;
    }
    string careCard;
    // ask user for an input
    cout << "Please enter a care card number. Enter 0 to go back! Enter 1 to remove all!" << endl;
    getline(cin, careCard);
    // back to menu if a 0 if received
    if(careCard == "0"){
        cout << "Going back to menu... c:" << endl;
        return;
    }
    // remove all patients
    else if(careCard == "1"){
        cout << "Removing all patients... :c" << endl;
        removeAllPatient(aList);
        return;
    }
    // remove a patient with the received care card
    Patient aTemp = Patient(careCard);
    bool tryToRemove = aList.remove(aTemp);
    // successful!
    if(tryToRemove == true){
        cout << "Patient has been removed successfully! â•­( ï½¥ã…‚ï½¥)Ùˆ" << endl;
    }
    // could not find the patient, unsuccessful
    else{
        cout << "You cannot delete a patient that doesn't exist! (Â´Â°Ï‰Â°`)" << endl;
    }
}

// Description: find a patient with the given care card number
// print the patient's detailed if successful
void searchPatient(List &aList){
    // check if list is empty
    if(checkIfListIsEmpty(aList)){
        cout << "List is empty! (O__O)" << endl;
        return;
    }
    string careCard;
    // ask users for an input
    cout << "Please enter a care card number. Enter 0 to go back" << endl;
    getline(cin, careCard);
    // back to menu
    if(careCard == "0"){
        cout << "Going back to menu... c:" << endl;
        return;
    }
    // try to find the patient
    Patient aTemp = Patient(careCard);
    Patient *p = aList.search(aTemp);
    // patient not found if NULL is received
    if(p == NULL){
        cout << "Patient not found. (Â´Â°Ï‰Â°`)" << endl;
    }
    // found him! now print his/her details
    else{
        cout << "Patient found! Here are his/her details... âœ§*ã€‚ãƒ¾(ï½¡>ï¹<ï½¡)ï¾‰ï¾žâœ§*ã€‚" << endl;
        p->printPatient();
    }
}

// Description: modify a patient's details
void modifyPatient(List &aList){
    // check if list is empty
    if(checkIfListIsEmpty(aList)){
        cout << "List is empty! (O__O)" << endl;
        return;
    }
    bool goBack = 0;
    string one = "1";
    string requestedCareCard;
    // ask user for an input
    cout << "Please enter the care card number of the patient you are looking for, or hit 1 to go back... " << endl;
    getline(cin, requestedCareCard);
    // back to menu
    if(requestedCareCard == one){
        cout << "Going back to menu... c:" << endl;
        return;
    }
    // find the patient to modify
    Patient aTemp = Patient(requestedCareCard);
    Patient *p = aList.search(aTemp);
    while (p == NULL){
    // patient not found, we can either go back to menu, or try again
        cout << "Patient not found... Please try again or hit 1 to go back. â”Œ(â–€Ä¹Ì¯ â–€-Í  )â”" << endl;
        getline(cin, requestedCareCard);
        // back to menu
        if(requestedCareCard == one){
            cout << "Going back to menu... c:" << endl;
            return;
        }
        // try again!
        aTemp = Patient(requestedCareCard);
        p = aList.search(aTemp);
    }
    // patient is found, print his/her current details
    cout << "Patient found! Here are his/her details... âœ§*ã€‚ãƒ¾(ï½¡>ï¹<ï½¡)ï¾‰ï¾žâœ§*ã€‚" << endl;
    p->printPatient();
    // ask the user what to modify
    while (goBack == 0){
        cout << "What part do you want to modify?" << endl;
        cout << "   1. Name                      " << endl;
        cout << "   2. Address                   " << endl;
        cout << "   3. Phone                     " << endl;
        cout << "   4. Email                     " << endl;
        cout << "   5. Go back                   " << endl;
        cout << "   Your choice: ";
        string userChoice;
        string userInput;
        getline(cin, userChoice);
        // modify his/her name if 1 is received
        if(userChoice == "1"){
            cout << "Please Enter the name of the patient. á˜³á—’.á—•á˜°" << endl;
            getline(cin, userInput);
            p->setName(userInput);
        }
        // modify his/her address if 2 is received
        else if(userChoice == "2"){
            cout << "Please Enter the address of the patient. á˜³á—’.á—•á˜°" << endl;
            getline(cin, userInput);
            p->setAddress(userInput);
        }
        // modify his/her phone number if 3 is received
        else if(userChoice == "3"){
            cout << "Please Enter the phone number of the patient. á˜³á—’.á—•á˜°" << endl;
            getline(cin, userInput);
            p->setPhone(userInput);
        }
        // modify his/her email if 4 is received
        else if(userChoice == "4"){
            cout << "Please Enter the email of the patient. á˜³á—’.á—•á˜°" << endl;
            getline(cin, userInput);
            p->setEmail(userInput);
        }
        // back to menu is 5 is received
        else if(userChoice == "5"){
            cout << "Going back to menu... c:" << endl;
            goBack = 1;
        }
        // an invalid input is received, oh no!
        else{
            cout << "Invalid Input. â˜œ(`oÂ´)" << endl;
        }
    }
}

// Description: print details of all patients currently in the list
void printPatientList(List &aList){
    // list is currently empty, nothing to display
    if(checkIfListIsEmpty(aList)){
        cout << "No Patients Exist on the list at this time! (Ê˜è¨€Ê˜â•¬)" << endl;
    }
    // list is not empty, print all patients
    else{
        aList.printList();
    }
}

// Description: a function to exit the program
void exit(){
    is_finished = 1;
}

int main(){
    // display a welcome message
    welcome();
    // create our list
    List plist;
    string userChoice;
    // execute until the user is finished
    while(!is_finished){
        // display the menu of options
        print_menu();
        // receive the user's input
        getline(cin, userChoice);
        // add a patient if 1 is received
        if(userChoice == "1"){
            addPatient(plist);
        }
        // remove a patient/all patients if 2 is received
        else if(userChoice == "2"){
            removePatient(plist);
        }
        // search of a patient if 3 is received
        else if(userChoice == "3"){
            searchPatient(plist);
        }
        // modify patient's details if 4 is received
        else if(userChoice == "4"){
            modifyPatient(plist);
        }
        // print all patients in the list if 5 is received
        else if(userChoice == "5"){
            printPatientList(plist);
        }
        // exit the program if 6 is received
        else if(userChoice == "6"){
            exit();
        }
        // oh no! looks like our user entered an invalid input
        else{
            cout << "Invalid Input. â˜œ(`oÂ´)" << endl;
        }
    }
}
