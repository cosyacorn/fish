#include "fish_classes.h"
#include<cstdlib>
#include<iostream>

//Function to initalise the head node in our linked list of fish
void init_fish(fish *head, int species, int x, int y, int z){

  head->type=species;

  head->xcoord=x;
  head->ycoord=y;
  head->zcoord=z;

  head->age=0;
  head->eaten=0;

  head->next=NULL;
  //head->prev=NULL;
}


//Function for creating a new fish (of class fish)
fish* new_fish(int species, int x, int y, int z){

  fish *f=new fish;

  //set up the various entries in the fish class

  f->next=NULL;
  //f->prev=NULL;

  f->type=species;

  f->xcoord=x;
  f->ycoord=y;
  f->zcoord=z;

  f->age=0;
  f->eaten=0;

  return f;
  
}

//Function to add elements to the linked list.
//want all the minnows to be grouped together at the start of the list.
//Then the tuna, then the sharks

void append_fish(fish *h, int species, int x, int y, int z){
  while(h->next != NULL){
    //minnows first
    if(species==0 && (h->next)->type==1)
      break;
    //then tuna
    if(species==1 && (h->next)->type==2)
      break;
    h=h->next;
  }
  fish *f = new_fish(species, x, y, z);
  f->next=h->next;
  h->next=f;
  //f->prev=h;
}


//Function to print out all the fish in the linked list
void print_fish(fish *head){

  while(head!=NULL){
    std::cout << "type " << head->type << " x: " << head->xcoord << " y: " << head->ycoord << " z: " << head->zcoord <<  std::endl; 

    head=head->next;
  }
}

//function to count the population of each species
void count_fish(fish * head, int &n_min, int &n_tuna, int &n_shark){

  int min, tuna, shark;

  min=tuna=shark=0;

  while(head!=NULL){
    if(head->type==0)
      min++;
    if(head->type==1)
      tuna++;
    if(head->type==2)
      shark++;
    head=head->next;
  }
  n_min=min;
  n_tuna=tuna;
  n_shark=shark;
}
