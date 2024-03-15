#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Helper function: Create new node using provided args
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  //write your code
    this->root = nullptr;

}
void deleteTree(MovieNode* node){
  if(node == nullptr){ 
    return;
  }
  deleteTree(node->left);
  deleteTree(node->right);
  delete(node);
}
MovieTree::~MovieTree() {
  //write your code
    deleteTree(root);
}

void printHelp(MovieNode* m){
  if(m == nullptr){
    return;
  }
  printHelp(m->left);
  cout << "Movie: " << m->title << " " << "(" << m->rating << ")" << endl;
  printHelp(m->right);
}
void MovieTree::printMovieInventory() {
  if(root == NULL){
    cout << "Tree is Empty. Cannot print" << endl;
  }
  else{
    printHelp(root);
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode* newMovie = new MovieNode();
  newMovie-> ranking = ranking;
  newMovie-> title = title;
  newMovie-> year = year;
  newMovie-> rating = rating;
  if(root == 0)
  {
    root = newMovie;
    return;
  }
  else 
  { 
    MovieNode* currNode = root;
    if((currNode->title).compare(title) > 0)
    { 
      if(currNode->left != 0)
      { 
        currNode =  currNode->left;
      }
      else 
      { 
        currNode->left = newMovie;
        return;
      }
    }
    else 
    { 
      if(currNode->right != 0) {
         currNode = currNode->right;
      }
      else 
      {
        currNode->right = newMovie;
        return;
      }
    }
  }
}

MovieNode* findHelp(MovieNode* m, string title){
  if(m == 0){
    return nullptr;
  }
  else{
    if((m->title).compare(title) > 0)
    {
      return findHelp(m->left, title);
    }
    else if((m->title).compare(title) == 0
    {
      return m;
    }
    else if((m->title).compare(title) < 0)
    {
      return findHelp(m->right, title);
    }
  }
  return 0;
}

void MovieTree::findMovie(string title){
  //write your code
  MovieNode* find = findHelp(root, title);
  if(find != 0){
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << find->ranking << endl;
    cout << "Title  :" << find->title << endl;
    cout << "Year   :" << find->year << endl;
    cout << "rating :" << find->rating << endl;
  }
  else{
    cout << "Movie not found." << endl;
  }
}
void queryHelp(MovieNode* m, float rating, int year){
  if(m == nullptr){ 
    return;
  }
  
  if((m->rating >= rating) && (m->year > year)){
    cout << m->title << "(" << m->year << ") " << m->rating << endl;
  }
  queryHelp(m->left,rating,year);
  queryHelp(m->right,rating,year);
}
void MovieTree::queryMovies(float rating, int year) {
  if(root == nullptr){
    cout << "Tree is Empty. Cannot query movies" << endl;
  }
  else{
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    queryHelp(root,rating, year);
  }
}
void avgHelp(MovieNode* m, float &more, float &counter){
  if(m == nullptr){ 
    return;
  }
  float curr = m->rating;
  more = more + curr;
  counter++;
  avgHelp(m->left,more,counter);
  avgHelp(m->right,more,counter);
}
void MovieTree::averageRating() {
  if(root == nullptr){
    cout << "Average rating:0.0" << endl;
  }
  else{
    float counter;
    float more;
    avgHelp(root,more,counter);
    float ave = more/counter;
    cout << "Average rating:" << ave << endl;
  }
}
void printLevelHelp(MovieNode* m, int level,int counter){
  if(m == nullptr){
    return;
  }
  if(counter == level){
  cout << "Movie: " << m->title << " " << "(" << m->rating << ")" << endl;  }
  else{
    printLevelHelp(m->left,level-1,counter);
    printLevelHelp(m->right,level-1,counter);
  }
}
void MovieTree::printLevelNodes(int level){
  int counter = 0;
  printLevelHelp(root,level,counter);
}




