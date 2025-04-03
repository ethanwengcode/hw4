#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
bool equalPathsHelper(Node* n, int currDepth, int& expectedDepth){
  if(n == NULL){
    return true; 
  }

  // leaf node
  if(n->left == NULL && n->right == NULL){
    if(expectedDepth != -1) {
      return currDepth == expectedDepth; // check if this branch's depth is as expected
    }
    else { // found the first leaf node
      expectedDepth = currDepth;
      return true;
    }
  }

  // recursive calls
  bool checkLeft = equalPathsHelper(n->left, currDepth +1, expectedDepth);
  bool checkRight = equalPathsHelper(n->right, currDepth +1, expectedDepth);
  return checkLeft && checkRight;
}

bool equalPaths(Node * root)
{
    // Add your code below
    // use -1 to indicate that no leaf node was visited yet
    int expectedDepth = -1;
    return equalPathsHelper(root, 0, expectedDepth);
}

