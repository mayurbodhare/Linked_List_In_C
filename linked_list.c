#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//defining the structure
struct node{
	int data;
	struct node *next;
};
// START is global Variable
struct node *START=NULL;
// createNode will allocate memory
struct node* createNode(){
	struct node *n;
	n=(struct node*) malloc(sizeof(struct node));
	return n;
}

void traverseList(void);

struct node* getDataInNode(){
	struct node *temp;
	temp = createNode();
	printf("enter the No.: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	return temp;
}
void insertAtLastNode(){
	struct node *temp,*t;
	temp=getDataInNode();
	if(START==NULL)
		START=temp;
	else{
		t=START;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
}

void insertAtFirstNode(){
	struct node *temp,*t;
	temp=getDataInNode();
	if(START==NULL)
		START=temp;
	else{
		temp->next=START;
		START=temp;
	}
}

void insertAtMiddlePosition(){
	struct node *new,*temp,*temprv;
	int pos,count=1;
	new=getDataInNode();
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	if(START==NULL){
		START=new;
	}
	else{
		temp=START;
		while(temp->next!=NULL && count<pos){
			++count;
			temprv=temp;
			temp=temp->next;
		}
		if(count==pos){
			new->next=temp;
			temprv->next=new;
		}
		else
			printf("\nlist is small than postion!!!");
	}
	
}

void insertAtMiddleAfterPerticularNode(){
	struct node *new,*temp;
	int n;
	new=getDataInNode();
	printf("\nEnter the element after which you want to insert: ");
	scanf("%d",&n);
	if(START==NULL){
		START=new;
	}
	else{
		temp=START;
		while(temp->next!=NULL && temp->data!=n){
			temp=temp->next;
		}
		if(temp->data==n){
			new->next=temp->next;
			temp->next=new;
		}
	}
}

void deleteFirstNode(){
	struct node *r;
	
	if(START==NULL)
		printf("\nList is empty!!!");
	else{
		r=START;
		START=START->next;
		free(r);
		traverseList();
	}
}

void deleteLastNode(){
	struct node *tmp,*tmpprv;
	if(START==NULL)
		printf("\nList is empty!!!");
	else{
		tmp=START;
		while(tmp->next!=NULL){
			tmpprv=tmp;
			tmp=tmp->next;
		}
		tmpprv->next=NULL;
		free(tmp);
		traverseList();
	}
}

void deleteMiddleNodePosition(){
	struct node *temp,*temprv;
	int pos,count=1;
	
	if(START==NULL)
		printf("\nList is empty!!!");
	else{
		printf("enter the postion: ");
		scanf("%d",&pos);
		if(pos==1){
			deleteFirstNode();
		}
		else{
			temp=START;
			while(temp->next!=NULL && count<pos){
				count++;
				temprv=temp;
				temp=temp->next;
			}
			if(count==pos){
				temprv->next=temp->next;
				free(temp);
				traverseList();
			}
			else
				printf("\nlist is small than postion!!!");
			}
	}
	
	
}

void reverseList(){
	struct node *curr,*prv,*next;
	curr=START;
	prv=NULL;
	while(curr!=NULL){
		next = (*curr).next;
		(*curr).next=prv;
		prv=curr;
		curr=next;
	}
	START=prv;
}

void reverseListRecursion(struct node *ptr){
	if(ptr->next==NULL){
		 START=ptr;
		 return;		
	}
	reverseListRecursion(ptr->next);
	struct node *q=ptr->next;
	q->next=ptr;
	ptr->next=NULL;
}

void traverseList(){
	struct node *t;
	if(START==NULL)
		printf("\nList is empty!!!");
	else{
		t=START;
		while(t!=NULL){
			printf(" %d ",t->data);
			t=t->next;
		}
	}
}

void traverseListRecursion(struct node *ptr){
	if(ptr==NULL) return;
	printf(" %d ",(*ptr).data);
	traverseListRecursion((*ptr).next);
}

void reverseTraverseListRecursion(struct node *ptr){
	if(ptr==NULL) return;
	reverseTraverseListRecursion((*ptr).next);
	printf(" %d ",(*ptr).data);
}

int menu(){
	int ch;
	printf("\n1.insert");
	printf("\n2.delete");
	printf("\n3.travese");
	printf("\n4.insert at first");
	printf("\n5.delete at last");
	printf("\n6.insert at middle (position)");
	printf("\n7.delete at middle (position)");
	printf("\n8.insert after perticular element");
	printf("\n9.reverse List (iterative)");
	printf("\n10.traverse using Recursion");
	printf("\n11.traverse Reverse using Recursion");
	printf("\n12.reverse list using Recursion");
	printf("\n13.exit");
	printf("\n");
	scanf("%d",&ch);
	return (ch);
}

int main(){
	while(1){
		//clrscr();
		switch(menu()){
			
			case 1:
				insertAtLastNode();
				break;
			case 2:
				deleteFirstNode();
				break;
			case 3:
				traverseList();
				break;
			case 4:
				insertAtFirstNode();
				break;
			case 5:
				deleteLastNode();
				break;
			case 6:
				insertAtMiddlePosition();
				break;
			case 7:
				deleteMiddleNodePosition();
				break;
			case 8:
				insertAtMiddleAfterPerticularNode();
				break;
			case 9:
				reverseList();
				break;
			case 10:
				traverseListRecursion(START);
				break;
			case 11:
				reverseTraverseListRecursion(START);
				break;
			case 12:
				reverseListRecursion(START);
				break;
			case 13:
				exit(0);
			default:
				printf("Invalid entry");
		}
	}
}
