#include<iostream>
#include<cstdlib>
#include "fish_classes.h"
#include "move_fish.h"


void init_fish(fish *head, int species, int x, int y, int z);
fish* new_fish(int species, int x, int y, int z);
void append_fish(fish *head, int species, int x, int y, int z);
void print_fish(fish *head);
void choose_arrival_func(fish **head, int x, int y, int z);

int main(){
  
  srand(time(NULL));
  srand48(time(NULL));
  
    
  fish* head_fish;
  head_fish = new fish;
  init_fish(head_fish, 2, 2, 2, 2);
  head_fish->eaten=1;
  //append_fish(head_fish, 2, 0, 0, 0);
  append_fish(head_fish, 2, 2, 2, 2);
  append_fish(head_fish, 2, 2, 2, 2);
  (head_fish->next)->eaten=1;
  //append_fish(head_fish, 2, 2, 2, 2);
  

  print_fish(head_fish);
  
  
  choose_arrival_func(&head_fish, 2, 2, 2);
  std::cout<<std::endl;
  print_fish(head_fish);

  //std::cout<<head_fish->eaten<<std::endl;
  


  return 0;
}
