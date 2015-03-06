#include<iostream>
#include<stdlib.h>
#include "fish_classes.h"
#include "move_fish.h"

//void move_tuna(tuna &t);

void init_minnow(minnow *head, int x, int y, int z);
void new_minnow(minnow *head, int x, int y, int z);

int main(){
  
  srand(time(NULL));
  shark a[2];
  a[0].xcoord=0;
  a[0].ycoord=0;
  a[0].zcoord=0;
  move_shark(a[0]);
  

  minnow *b;
  init_minnow(b, 1, 1, 1);

  //b=new_minnow();

  
  std::cout << "x: " << b.xcoord << " y: " << b.ycoord << " z: " << b.zcoord <<  std::endl; 

  return 0;
}
