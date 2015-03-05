#include<iostream>
#include<stdlib.h>
#include "fish_classes.h"
#include "move_fish.h"

//void move_tuna(tuna &t);

int main(){
  
  srand(time(NULL));
  shark a[2];
  a[0].xcoord=0;
  a[0].ycoord=0;
  a[0].zcoord=0;
  move_shark(a[0]);
  
  std::cout << "x: " << a[0].xcoord << " y: " << a[0].ycoord << " z: " << a[0].zcoord <<  std::endl; 

  return 0;
}
