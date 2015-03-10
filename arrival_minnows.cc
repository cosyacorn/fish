#include "fish_classes.h"
#include<cstdlib>
#include<iostream>

void append_fish(fish *h, int species, int x, int y, int z);
void delete_backward(fish **fishy, int species, int x, int y, int z);
void delete_fish(fish **head_ref, fish *del);


void arrival_minnows(fish *head, int x, int y, int z){
 
  int num_minnows;
 
  num_minnows=0;

  while(head!=NULL){
    if(head->type==0){
      if(head->xcoord==x && head->ycoord==y && head->zcoord==z)
	num_minnows++;
      if(num_minnows>=2){
	append_fish(head, 0, x, y, z);
	append_fish(head, 0, x, y, z);
	break;
      }
    }
    head=head->next;
  }
}


void arrival_tuna(fish *head, int x, int y, int z){

  int num_fed_tuna;

  num_fed_tuna=0;

   while(head!=NULL){
     if(head->type==1){
       if(head->eaten==1){
	 if(head->xcoord==x && head->ycoord==y && head->zcoord==z)
	   num_fed_tuna++;
	 if(num_fed_tuna>=2){
	   append_fish(head, 1, x, y, z);
	   break;
	 }
       }
     }
     head=head->next;
   }
}


void arrival_shark(fish *head, int x, int y, int z){

  int num_fed_shark;

  num_fed_shark=0;

   while(head!=NULL){
     if(head->type==1){
       if(head->eaten==1){
	 if(head->xcoord==x && head->ycoord==y && head->zcoord==z)
	   num_fed_shark++;
	 if(num_fed_shark>=2){
	   append_fish(head, 2, x, y, z);
	   break;
	 }
       }
     }
     head=head->next;
   }
}

int is_tuna_minnow(fish *head, int x, int y, int z){
   
  int minnow, tuna, ans;
 
  minnow=0;
  tuna=0;
  ans=0;

  while(head!=NULL){
    if(head->xcoord==x && head->ycoord==y && head->zcoord==z){
      if(head->type==0)
	minnow++;
      if(head->type==1)
	tuna++;
    }
    if(minnow!=0 && tuna !=0){
      ans=1;
      break;
    }
    head=head->next;
  }
  std::cout << ans << std::endl;
  return ans;
}

void arrival_tuna_minnows(fish *head, int x, int y, int z){

  int del;
  del = is_tuna_minnow(head, x, y, z);

  if(del!=0){
    while(head!=NULL){
      std::cout << del << std::endl;
      if(head->type==0){
	delete_fish(&head, head);
	head=head->prev;
      }
      head=head->next;
    }
  }
}
