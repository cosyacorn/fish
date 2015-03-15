#include<iostream>
#include<cstdlib>
#include "fish_classes.h"
#include "move_fish.h"


void init_fish(fish *head, int species, int x, int y, int z);
fish* new_fish(int species, int x, int y, int z);
void append_fish(fish *head, int species, int x, int y, int z);
void print_fish(fish *head);
void choose_arrival_func(fish **head, int x, int y, int z);
void move_fish(fish *f);
void update(fish **head, int num_minnows, int num_tuna, int num_sharks);
void count_fish(fish * head, int &n_min, int &n_tuna, int &n_shark);


int main(){

  srand(time(NULL));
  srand48(time(NULL));
  
    
  fish* head;
  int n_minnows, n_tuna, n_sharks, i,j;
  int min_flag, tuna_flag, shark_flag;

  head = new fish;

  n_minnows=3000;
  n_tuna=300;
  n_sharks=5;
  min_flag=tuna_flag=shark_flag=0;

  if(n_minnows!=0){
    init_fish(head, 0, rand()%5, rand()%5, rand()%5);
    min_flag=1;
  }
  else if(n_tuna!=0){
    init_fish(head, 1, rand()%5, rand()%5, rand()%5);
    tuna_flag=1;
  }
  else if(n_sharks!=0){
    init_fish(head, 2, rand()%5, rand()%5, rand()%5);
    shark_flag=1;
  }
  else{
    std::cout<<"Error: No fish in initial conditions"<<std::endl;
    return 1;
  }

  for(i=0;i<(n_minnows-min_flag);i++)
    append_fish(head, 0, rand()%5, rand()%5, rand()%5);

  for(i=0;i<(n_tuna-tuna_flag);i++)
    append_fish(head, 1, rand()%5, rand()%5, rand()%5);

  for(i=0;i<(n_sharks-shark_flag);i++)
    append_fish(head, 2, rand()%5, rand()%5, rand()%5);

  //append_fish(head, 0, 0, 1, 3);

  //print_fish(head);
  count_fish(head, n_minnows, n_tuna, n_sharks);
  std::cout<<"minnows: "<<n_minnows<<" tuna: "<<n_tuna<<" sharks: "<<n_sharks<<std::endl;
  

  for(j=0;j<1000;j++){
    for(i=0;i<125;i++){
      update(&head, n_minnows, n_tuna, n_sharks);
    }
    count_fish(head, n_minnows, n_tuna, n_sharks);
    std::cout<<"minnows: "<<n_minnows<<" tuna: "<<n_tuna<<" sharks: "<<n_sharks<<std::endl;
  }

  //std::cout<<std::endl;
  //print_fish(head);

  //std::cout<<head_fish->eaten<<std::endl;
  


  return 0;
}
