#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int addToArrayAsc(float sortedArray[],int numElements,float numValue)
{
    
    float temp;
    sortedArray[numElements] = numValue;
    numElements++;
    for(int i = 0; i < numElements -1; i++){
        for(int j = 0; j < numElements - i -1; j++)
        {
            if(sortedArray[j] > sortedArray[j+1]){
                temp = sortedArray[j];                      //bubblesort function returns number of elements, using int j to swap
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1]= (temp * 1.0 );
            }
        }
    }
   

    return numElements;
}

int main(int argc, char *argv[])
{
float numValue = 0;
int numElements = 0; 
int count = 0;
float newValue;
string line;
float sortedArray[100];
ifstream myFile;
myFile.open(argv[1]);
if(myFile.is_open())
{
    while(getline(myFile,line))         //reading file
    {
        numValue = stof(line);                         
        addToArrayAsc(sortedArray,count,numValue);
        
        for (int i = 0; i < count; i++){                //printed array 
            cout << sortedArray[i] << ",";
        } 
    cout << sortedArray[count];
    cout << endl;                       //iterating count for size purposes
    count++;
    }
}
else{
    cout << "Failed to open the file." << endl;     // couldnt open file 
}
myFile.close();
}