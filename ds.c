#include<stdlib.h>
#include<stdio.h>
typedef struct node{
		int value;
		struct rep * repptr;
		struct node * next;
		}node;

//structure to represnt header node of linked representation of set
typedef struct rep { node * head;
		node * tail;
		}rep;

//structure to store key and set representative
typedef struct nodaddr { int key;
		node * obj_node_ptr;
		struct nodaddr * next;
		} nodaddr;
	
	nodaddr * ndr=0;	//list to store key an object node pointer

//function to create a set for an object
void makeset(int a)
	{
	//create a object node pointer
	nodaddr * t=(nodaddr *)malloc(sizeof(nodaddr));
	
	//create a new set
	rep * newset=(rep *)malloc(sizeof(rep));
	node * n=(node *)malloc(sizeof(node));
	
	//fill values
	n->value=a;
	n->repptr=newset;
	n->next=0;

	//initialize head and tail
	newset->head=newset->tail=n;

	//to store object node pointer and key
	t->obj_node_ptr=n;
	t->key=a;
	t->next=ndr;
	ndr=t;
	}

//function to return pointer of the representative of node containing x
rep * find(int x)
{
	nodaddr *t=ndr;
	while(t->key !=x && t!=0)
	  t=t->next;
	return t->obj_node_ptr->repptr;
}
// to find union of two sets corresponding to objects 
void unionset(int key1,int key2)
{
	rep * set1,* set2;

	node * t1;
	set1=find(key1);
	set2=find(key2);
	
	//changing the header pointers of sets2
	t1=set2->head;
	while(t1!=0)
	{
		t1->repptr=set1;
		t1=t1->next;
	}
	
	//set tail of set1 to tail of set2
	set1->tail->next=set2->head;
	set1->tail=set2->tail;
}



	void main()
	 {
	makeset(10);
	makeset(20);
	makeset(30);
	makeset(40);
	makeset(50);
	printf("find(10)=%p",find(10));
	printf("\nfind(20)=%p",find(20));
	printf("\nfind(30)=%p",find(30));
	printf("\nfind(40)=%p",find(40));
	unionset(10,20);
	printf("\nafter union of 10 & 20 find (20)=%p",find(20));
	unionset(30,40);
	printf("\nafter union of 30 & 40 find (40)=%p",find(40));
	unionset(20,40);
	printf("\nafter union of  set containing 20 and 40 find(40)=%p",find(40));
	
	
	}


/*
find(10)=0x9a5030
find(20)=0x9a5090
find(30)=0x9a50f0
find(40)=0x9a5150
after union of 10 & 20 find (20)=0x9a5030
after union of 30 & 40 find (40)=0x9a50f0
after union of  set containing 20 and 40 find(40)=0x9a5030 

*/


