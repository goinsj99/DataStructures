#include <iostream>
#include "JobQueue.hpp"
using namespace std;

JobQueue::JobQueue()
{
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
}
bool JobQueue::isEmpty()
{
    if(counter == 0){
        return true;
    }
    else{
        return false;
    }
}

bool JobQueue::isFull()
{
    if(counter == SIZE){
        return true;
    }
    else{
        return false;
    }
}

void JobQueue::enqueue(string job)
{
    if(counter == SIZE){
    cout << "Queue full, cannot add new job" << endl;
    }
    else if(queueEnd == SIZE-1 && queueFront != 0){
        queueEnd = 0;
        queue[queueEnd] = job;
        counter++;
    }
    else if(counter == 0 && queueFront != 0){
        queue[queueFront] = job;
        counter++;
    }
    else if(queueFront == queueEnd && counter == 0){
        queue[0] = job;         
        counter++;
    }
    else{
        queueEnd++;
        queue[queueEnd+1] = job;
        counter++;
    }
}

void JobQueue::dequeue()
{
    if(isEmpty()){
        cout << "Queue empty, cannot dequeue a job" << endl;
    }
    else if(queueFront+1 == SIZE){
        queueFront = (queueFront+1)%SIZE;
        counter--;
    }
    else if(queueFront == queueEnd){
        counter = 0;
    }
    else{
        queueFront = queueFront+1;
        counter--;
    }
}


string JobQueue::peek()
{
    if(counter == 0){
        cout << "Queue empty, cannot peek" << endl;
    }
    else{
        int inFront = getQueueFront();
        return queue[inFront];
    }
}

int JobQueue::queueSize()
{
    return counter;
}