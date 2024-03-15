/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
#include <iomanip>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	/* TODO */
	JobQueue Qute;
	int input;
	bool newnew = false;
	string input2;
	string mean;
	int counter = 0;
	while(!newnew){
	menu();
	getline(cin, input2);
    input = stoi(input2);

		switch (input)
		{
			case 1:
			
				int newInput;
				
				cout << "Enter the number of jobs to be created:" << endl;
				cin >> newInput;
				for(int i = 1 ; i <= newInput; i++){
						cout << "job" << i  << ":" << endl;
						getline(cin,mean);
						Qute.enqueue(mean);
				}
				break;
			
			case 2:
				int cat;
				cout << "Enter the number of jobs to be dispatched:" << endl;
				cin >> cat;

				if(cat <= Qute.queueSize()){
					for(int i = 1; i <= cat; i++){
						cout << "Dispatched: " << Qute.peek() << endl;
						Qute.dequeue();
					}
				}
				else{
					for(int i = 1; i <= cat; i++){
						cout << "Dispatched: " << Qute.peek() << endl;
						Qute.dequeue();
					}
					cout << "No more jobs to be dispatched from queue" << endl;
				}
				break;
				
			case 3:
				cout << "Number of jobs in the queue:" << Qute.queueSize() << endl;
				newnew = true;
				break;
		}
	}
	return 0;
}
