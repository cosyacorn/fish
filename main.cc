#include<iostream>
#include<cstdlib>
#include "fish_classes.h"
#include "move_fish.h"


void init_fish(fish *head, int species, int x, int y, int z);
fish* new_fish(int species, int x, int y, int z);
void append_fish(fish *head, int species, int x, int y, int z);
void arrival_minnows(fish *head, int x, int y, int z);
void arrival_tuna(fish *head, int x, int y, int z);


int main(){
  
  srand(time(NULL));
  
    
  fish* head_fish;
  head_fish = new fish;
  init_fish(head_fish, 0, 2, 2, 2);
  append_fish(head_fish, 0, 2, 3, 2);
  append_fish(head_fish, 0, 2, 2, 2);
  //move_fish(head_fish);
  //arrival
  arrival_minnows(head_fish, 2, 2, 2);

  while(head_fish!=NULL){

    std::cout << "x: " << head_fish->xcoord << " y: " << head_fish->ycoord << " z: " << head_fish->zcoord <<  std::endl; 

  head_fish=head_fish->next;
  }


  return 0;
}
