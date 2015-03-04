#include<iostream>
#include<stdlib.h>
#include "fish_classes.h"
#include "move_fish.h"

int main(){
  
  srand(time(NULL));
  minnow a;
  a.xcoord=1;
  a.ycoord=1;
  a.zcoord=1;
  move_minnow(a);
  
  std::cout << "Hello " << a.xcoord <<  std::endl; 

  return 0;
}
