#include<iostream>
#include<cstdlib>
#include "fish_classes.h"
#include "move_fish.h"


void init_fish(fish *head, int species, int x, int y, int z);
fish* new_fish(int species, int x, int y, int z);
void append_fish(fish *head, int species, int x, int y, int z);
void print_fish(fish *head);
void delete_fish(fish **head_ref, fish *del);
void arrival_minnows(fish *head, int x, int y, int z);
void arrival_tuna(fish *head, int x, int y, int z);
void delete_forward(fish *fishy, int species, int x, int y, int z);
void delete_backward(fish *fishy, int species, int x, int y, int z);
void arrival_tuna_minnows(fish *head, int x, int y, int z);

int main(){
  
  srand(time(NULL));
  
    
  fish* head_fish;
  head_fish = new fish;
  init_fish(head_fish, 0, 2, 2, 2);
  //append_fish(head_fish, 0, 0, 0, 0);
  //append_fish(head_fish, 0, 2, 2, 2);
  append_fish(head_fish, 1, 2, 2, 2);
  //append_fish(head_fish, 0, 2, 2, 2);
  

  print_fish(head_fish);
  
  arrival_tuna_minnows(head_fish, 2, 2, 2);
  //delete_fish(&head_fish, head_fish);
  std::cout<<std::endl;
  print_fish(head_fish);

  


  return 0;
}
