#include <iostream>
#include "StackCalculator.hpp"


using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }
  return true;
}

StackCalculator::StackCalculator()
{
  //TODO:
  stackHead = nullptr;
}

StackCalculator::~StackCalculator()
{
  //TODO:
  while(!isEmpty()){
        pop();
    }
}

bool StackCalculator::isEmpty()
{
	//TODO:
  return(stackHead == nullptr);   //!
}

void StackCalculator::push(float number)
{
  //TODO:
  Operand* temp = new Operand;
  temp->number = number;
  temp->next = nullptr;
  temp->next = stackHead;
  stackHead = temp;
}

void StackCalculator::pop()
{
	//TODO:
    if(!isEmpty()){
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
    else{
        cout << "Stack empty, cannot pop a job." << endl;
    }
}

Operand* StackCalculator::peek()
{
	//TODO:
   if(isEmpty()){
        cout<< "Stack Empty, cannot peek." << endl;
        return nullptr;
    }
    else{
        return stackHead;
    }
    //return nullptr;// remove this line if you want
}

bool StackCalculator:: evaluate(string* s, int size)
{
    /*TODO: 1.scan the array from the end
            2.Use isNumber function to check if the input is an operand
            3.push all operands to the stack
            4.If operator take two element of from the stack,
              compute and put the result back in stack
            5.Handle the boundery cases as required.
            6.Read the writeup for more details
    */
  // char plus = '+';
  // char star = '*';
  int snicker = size -1;
  while(snicker >= 0){
    if(isNumber(s[snicker])){
      push(stof(s[snicker]));
      snicker--;
    }
    else if(s[snicker] == "+" || s[snicker] == "*")
    {   
      float value = 0;
        if(isEmpty())
        {
          cout << "err: not enough operands" << endl;
          return false;
          break;
        }
        else
        {
          float temp = peek()->number;
          pop();
          float temp2 = peek()->number;
          pop();
            if(s[snicker] == "+")
            {
              value = temp + temp2;
              push(value);
              snicker--;
            }
            else{
              value = temp * temp2;
              push(value);
              snicker--;
            }
        } 
      return true;
      break;
    }
    else{
      cout << "err: invalid operation" << endl;
      return false;
      break;
    }
  }
	return true;
}
