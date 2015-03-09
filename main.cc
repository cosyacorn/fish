#include<iostream>
#include<cstdlib>
#include "fish_classes.h"
#include "move_fish.h"

//void move_tuna(tuna &t);

void init_fish(fish *head, int species, int x, int y, int z);
fish* new_fish(int species, int x, int y, int z);
void append_fish(fish *head, int species, int x, int y, int z);

int main(){
  
  srand(time(NULL));
  
    
  fish* head_fish;
  head_fish = new fish;
  init_fish(head_fish, 2, 2, 2, 2);

  //append_minnow(head_minnow, 2, 2, 2);
  append_fish(head_fish, 3, 3, 3, 3);
  move_fish(head_fish);

  while(head_fish!=NULL){

    std::cout << "x: " << head_fish->xcoord << " y: " << head_fish->ycoord << " z: " << head_fish->zcoord <<  std::endl; 

  head_fish=head_fish->next;
  }


  return 0;
}
