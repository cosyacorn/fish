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
       if(head->eaten!=0){
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
     if(head->type==2){
       if(head->eaten!=0){
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
      if(cur->type==1 && del_flag==0){
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
    cur=cur->next;
    prev=prev->next;  
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
  int del_flag;

  cur=*head;
  del_flag=0;

  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;
  
  while(cur!=NULL && cur->next!=NULL){
    del_flag=0;
    if(cur->xcoord==x || cur->xcoord==(x+1)%5 || cur->xcoord==(x-1+5)%5){
      if(cur->ycoord==y || cur->ycoord==(y+1)%5 || cur->ycoord==(y-1+5)%5){
	if(cur->zcoord==z || cur->zcoord==(z+1)%5 || cur->zcoord==(z-1+5)%5){
	  if(cur->type==0){
	    temp=cur->next;
	    prev->next=cur->next;
	    delete cur;
	    del_flag=1;
	    cur=temp;
	  }
	}
      }
    }
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==2){
	cur->eaten++;
      }
    }
    if(cur->type!=0 || del_flag==0){
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


void not_eaten_five_moves(fish **head){

  fish *cur, *prev, *temp;
  int del_flag;
  
  cur=*head;

  if(cur==NULL) return;

  prev=cur;
  cur=cur->next;

  while(cur!=NULL && cur->next!=NULL){
    del_flag=0;
    if(cur->age>=5 && cur->eaten==0){
      if(cur->type==1 ||cur->type==2){
	temp=cur->next;
	prev->next=cur->next;
	delete cur;
	cur=temp;
	del_flag=1;
      }
    }
    if(del_flag==0)
      cur=cur->next;
  }
  
  if(cur!=NULL){
    if(cur->age>=5 && cur->eaten==0){
      if(cur->type == 1 || cur->type==2){
	prev->next = NULL;
	delete cur;	 
      }
    }
  }
  if((*head)->age>=5 && (*head)->eaten==0){
    if((*head)->type==1 || (*head)->type==2){
      temp = (*head)->next;
      delete *head;
      *head = temp;
    }
  }
}





void choose_arrival_func(fish **head, int x, int y, int z){

  int minnows, fed_tuna, fed_sharks, tuna, shark, tuna_minnows, tuna_shark, frenzy;
  int opt[6], tot, i;
  double prob[6], r;
  fish *cur;

  not_eaten_five_moves(head);

  cur=*head;

  minnows=fed_tuna=fed_sharks=tuna=shark=tuna_minnows=tuna_shark=frenzy=0;
  for(i=0;i<6;i++)
    opt[i]=0;
  tot=0;

  while(cur!=NULL){
    if(cur->xcoord==x && cur->ycoord==y && cur->zcoord==z){
      if(cur->type==0)
	minnows++;
      if(cur->type==1){
	tuna++;
	  if(cur->eaten!=0){
	    fed_tuna++;
	  }
      }
      if(cur->type==2){
	shark++;
	if(cur->eaten!=0){
	  fed_sharks++;
	}
      }
      if(tuna>=1 && shark>0)
	tuna_shark++;
    }
    cur=cur->next;
  }
  if(tuna==1 && minnows>=1)
    tuna_minnows++;
  if(shark==1 && minnows!=0)
    frenzy++;

  if(minnows>=2)
    opt[0]=1;
  if(fed_tuna>=2)
    opt[1]=1;
  if(fed_sharks>=2)
    opt[2]=1;
  if(tuna_minnows!=0)
    opt[3]=1;
  if(tuna_shark!=0)
    opt[4]=1;
  if(frenzy>=1)
    opt[5]=1;


  for(i=0;i<6;i++)
    tot+=opt[i];


  prob[0]=((double)opt[0])/((double)tot);

  for(i=1;i<6;i++)
    prob[i]=prob[i-1]+((double)opt[i])/((double)tot);


  r=drand48();
  
  if(r<prob[0])
    arrival_minnows(*head, x, y, y);

  else if(r>=prob[0] && r<prob[1])
    arrival_tuna(*head, x, y, z);

  else if(r>=prob[1] && r<prob[2])
    arrival_shark(*head, x, y, z);

  else if(r>=prob[2] && r<prob[3])
    arrival_tuna_minnows(head, x, y, z);

  else if(r>=prob[3] && r<prob[4])
    arrival_tuna_shark(head, x, y, z);

  else if(r>=prob[4] && r<prob[5])
    feeding_frenzy(head, x, y, z);
}

