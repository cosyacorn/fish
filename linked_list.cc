#include "fish_classes.h"
#include<cstdlib>
#include<iostream>


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

fish* new_fish(int species, int x, int y, int z){

  fish *f=new fish;

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

void append_fish(fish *h, int species, int x, int y, int z){
  while(h->next != NULL){
    h=h->next;
  }
  fish *f = new_fish(species, x, y, z);
  h->next=f;
  //f->prev=h;
}


void print_fish(fish *head){

  while(head!=NULL){
    std::cout << "type " << head->type << " x: " << head->xcoord << " y: " << head->ycoord << " z: " << head->zcoord <<  std::endl; 

    head=head->next;
  }
}
