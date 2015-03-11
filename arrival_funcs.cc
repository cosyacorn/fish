#include "fish_classes.h"
#include<cstdlib>
#include<iostream>

void append_fish(fish *h, int species, int x, int y, int z);



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


void arrival_tuna_minnows(fish **head, int x, int y, int z){

  fish *cur, *prev, *temp;

  cur=*head;

  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;
  
  while(cur!=NULL && cur->next!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==0){
	temp=cur->next;
	prev->next=cur->next;
	delete cur;
	cur=temp;
      }
      if(cur->type==1){
	cur->eaten++;
      }
    }
    if(cur->type!=0){
      cur=cur->next;
      prev=prev->next;
    }
  }

  if(cur!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type == 0 ){
	prev->next = NULL;
	delete cur;
      }
      if(cur->type==1){
	cur->eaten++;
      }
    }
  }
  if ((*head)->type == 0){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      temp = (*head)->next;
      delete *head;
      *head = temp;
    }
  }
  if ((*head)->type == 1){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      (*head)->eaten++;
    }
  }
}


void arrival_tuna_shark(fish **head, int x, int y, int z){

  fish *cur, *prev, *temp;
  int del_flag;

  cur=*head;
  del_flag=0;

  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;
  
  while(cur!=NULL && cur->next!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==1){
	temp=cur->next;
	prev->next=cur->next;
	delete cur;
	cur=temp;
	del_flag=1;
      }
      if(cur->type==2){
	cur->eaten++;
      }
    }
    if(cur->type!=1){
      cur=cur->next;
      prev=prev->next;
    }
  }

  if(cur!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(del_flag==0){
	if(cur->type == 1){
	  prev->next = NULL;
	  delete cur;
	  del_flag=1;
	}
      }
      if(cur->type==2){
	cur->eaten++;
      }
    }
  }
  if ((*head)->type == 1){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      if(del_flag==0){
	temp = (*head)->next;
	delete *head;
	*head = temp;
	del_flag=1;
      }
    }
  }
  if ((*head)->type == 2){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      (*head)->eaten++;
    }
  }
}

void feeding_frenzy(fish **head, int x, int y, int z){

  fish *cur, *prev, *temp;

  cur=*head;

  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;
  
  while(cur!=NULL && cur->next!=NULL){
    if(cur->xcoord==x || cur->xcoord==(x+1)%5 || cur->xcoord==(x-1+5)%5){
      if(cur->ycoord==y || cur->ycoord==(y+1)%5 || cur->ycoord==(y-1+5)%5){
	if(cur->zcoord==z || cur->zcoord==(z+1)%5 || cur->zcoord==(z-1+5)%5){
	  if(cur->type==0){
	    temp=cur->next;
	    prev->next=cur->next;
	    delete cur;
	    cur=temp;
	    //cur=cur->prev;
	  }
	}
      }
    }
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==2){
	cur->eaten++;
      }
    }
    if(cur->type!=0){
      cur=cur->next;
      prev=prev->next;
    }
  }

  if(cur!=NULL){
    if(cur->xcoord==x || cur->xcoord==(x+1)%5 || cur->xcoord==(x-1+5)%5){
      if(cur->ycoord==y || cur->ycoord==(y+1)%5 || cur->ycoord==(y-1+5)%5){
	if(cur->zcoord==z || cur->zcoord==(z+1)%5 || cur->zcoord==(z-1+5)%5){
	  if(cur->type == 0){
	    prev->next = NULL;
	    delete cur;
	  }
	}
      }
    }
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==2){
	cur->eaten++;
      }
    }
  }
  if ((*head)->type == 0){
    if((*head)->xcoord==x || (*head)->xcoord==(x+1)%5 || (*head)->xcoord==(x-1+5)%5){
      if((*head)->ycoord==y || (*head)->ycoord==(y+1)%5 || (*head)->ycoord==(y-1+5)%5){
	if((*head)->zcoord==z || (*head)->zcoord==(z+1)%5 || (*head)->zcoord==(z-1+5)%5){
	  temp = (*head)->next;
	  delete *head;
	  *head = temp;
	}
      }
    }
  }
  if ((*head)->type == 2){
    if((*head)->xcoord==x && (*head)->ycoord==y && (*head)->zcoord==z){
      (*head)->eaten++;
    }
  }
}
