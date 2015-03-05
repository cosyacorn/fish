#include<iostream>
#include<stdlib.h>
#include "fish_classes.h"
#include "move_fish.h"

//void move_tuna(tuna &t);

int main(){
  
  srand(time(NULL));
  tuna a;
  a.xcoord=0;
  a.ycoord=0;
  a.zcoord=0;
  move_tuna(a);
  
  std::cout << "x: " << a.xcoord << " y: " << a.ycoord << " z: " << a.zcoord <<  std::endl; 

  return 0;
}
