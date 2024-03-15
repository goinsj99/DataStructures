#include<iostream>
#include<cmath>
#include<iomanip>
#include "StackCalculator.hpp"

using namespace std;


int main()
{
  // stack to hold the operands
  StackCalculator stack;
  int num = 0;
  string* inparr = new string[50];
  // enter a number
  string number;
  cout << "Enter the operators and operands ('+', '*') in a prefix format" << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, number);

    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. store them in inparr
    */
   if(number == "="){
    break;
   }
   else{
      inparr[num] = number;
      num++;
   }
  }

  /* TODO - If the inparr is empty then print "No operands: Nothing to evaluate"
            else call the evaluate function
  */
   if(num == 0){
    cout << "No operands: Nothing to evaluate" << endl;
  }
  else{
    if(stack.evaluate(inparr, num)){
      stack.evaluate(inparr, num);
      cout << "Result= " << stack.peek()->number << endl;
    }
    // else{
    //   cout << ""
    // }
  }
  /* TODO - Validate the expression
      1. If valid then print the result cout << "Result= "<<result << endl;
      2. Else, print "Invalid expression"*/
  
  return 0;
}
