#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;


struct studentData{
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};
void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length){

    students[length].studentName = studentName;
    students[length].recitation = recitation;
    students[length].homework = homework;
    students[length].exam = exam;
    students[length].quiz = quiz;
    students[length].average = (float)(homework + recitation + quiz + exam)/4;
}

char calcLetter(double average){
    char grade;
    if(average >= 90){
        grade = 'A';
        return grade;               //bunch of edge cases for grades
    }
    if(average < 90 && average >= 80){
        grade = 'B';
        return grade;
    }
    if(average < 80 && average >= 70){
        grade = 'C';
        return grade;
    }
    if(average < 70 && average >= 60){
        grade = 'D';
        return grade;
    }
    else{
        grade = 'F';
        return grade;
    }
    
}
void printList(const studentData students[], int length){
    for(int i = 0; i < length; i++){
        cout << students[i].studentName << " earned " << students[i].average << " which is a(n) " << calcLetter(students[i].average) << endl;     //printing
    }
}
int main(int argc, const char *argv[])
{
    ifstream myFile;
    myFile.open(argv[1]);

    string line, studentName;
    string homework;
    string recitation;
    string quiz;
    string exam;
    double average;
    int temp;
    int tempHw;
    int tempRec;
    int tempQuiz;
    int tempExam;

    int count = 0;
    
    int x = sizeof(myFile);
    studentData studentArr[x];

    if (myFile.is_open()){
        while(getline(myFile,line)){        //if files open use split function to get lines
            stringstream ss(line);
            getline(ss, studentName, ',');
            getline(ss, homework,',');
            getline(ss, recitation, ',');
            getline(ss, quiz, ',');
            getline(ss, exam, '\n');

            
            tempHw = stoi(homework);
            tempRec = stoi(recitation);
            tempQuiz = stoi(quiz);
            tempExam = stoi(exam);
            addStudentData(studentArr,studentName,tempHw,tempRec,tempQuiz,tempExam,count);
            count++;
        }
    }
    printList(studentArr, count);
    myFile.close(); 

    ofstream write;
    write.open(argv[2]);            //writing to file
    string lowBound = argv[3];
    string upBound = argv[4];
    studentData tempArr[x];

    for(int i = 0; i < count; i++){
        if(calcLetter(studentArr[i].average) <= lowBound[0] && calcLetter(studentArr[i].average) >= upBound[0])
        {                                                                               //if students are within user given bounds, write
            tempArr[i] = studentArr[i];
            write << tempArr[i].studentName << "," << tempArr[i].average << ","<< calcLetter(tempArr[i].average) << endl;
        }
    }

    write.close();
    return 0;
}