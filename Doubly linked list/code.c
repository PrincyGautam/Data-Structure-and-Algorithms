#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_LIMIT 20
struct Node  {
	char data[30];
	struct Node* next;
	struct Node* prev;
};
struct Node* tail;
struct Node* head; 


struct Node* GetNewNode(char *x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->data,x);
	//newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insert_at_tail(char *x) {
	struct Node* temp = tail;
	struct Node* newNode = GetNewNode(x);
	if(tail == NULL) {
		tail = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; 
	temp->next = newNode;
	newNode->prev = temp;
}


void Print(struct Node* tail) {
	struct Node* temp = tail;

	    while(temp!=NULL){
        if(temp->prev==NULL){
            printf("None ");
        }
        else{
            printf("%c" ,temp->prev->data);
            printf(" ");
        }
        if(temp==NULL){
            printf("None ");
        }
        else{
            printf("%c" ,temp->data);
        }
        if(temp->next==NULL){
            printf("None ");
        }
        else{
            printf("%c",temp->next->data);
        }
        
        temp = temp->next;
    }
	printf("\n");
}

void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return;

	while(temp->next != NULL) {
		temp = temp->next;
	}

	while(temp != NULL) {
		printf("%c ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {

	head = NULL;  
	tail =NULL;
	char s;
	scanf("%c ", &s);
	while(s!='E'){
		
	    char str[MAX_LIMIT];
        //fgets(str, MAX_LIMIT, stdin);
		
        if(s =='V'){
			scanf("%s", &str);
			insert_at_tail(str);
            Print(tail);
        }
        else if(s =='B'){
			int d;
			scanf("%d ", &d);
            while(tail->prev!=NULL && d>0){
                tail= tail->prev;
				d--;
			}
            if(d==0){
				Print(tail);
			}
			else{
				printf("%d back not possible",d);
				Print(tail);
			}
            
        }
        else if(s =='F'){
			int w;
			scanf("%d ", &w);
            while(tail->next!=NULL && w>0){
				tail= tail->next;
				w--;
            }
            if(w==0){
				Print(tail);
				printf("\n");
			}
            
            else{
				printf("%d forward not possible",w);
				Print(tail);
			}
            
        }
        else if(s =='D'){
			int a;
            scanf("%d ", &a);
			if(a>0){
				while(tail->next!=NULL && a>0){
					tail = tail->next;
					a--;
				}
				if (a==0){
					if(tail->next==NULL){
						tail->prev->next=NULL;
					}
					else{
						tail->next->prev = tail->prev;
						tail->prev->next= tail->next;
					}
				}
				else{
					printf("None");
				}
			}
		
			
			
            
            else{
				a= abs(a);
				while(tail->prev!=NULL && a>0){
					tail= tail->prev;
					a--;
				}
				if (a==0){
					if(tail->prev==NULL){
						tail->next->prev=NULL;
					}
					else{
						tail->prev->next = tail->next;
						tail->next->prev= tail->prev;
					}
				}
				else{
					printf("None");
				}
			
				printf("\n");
            
			}
		}
        else if(s =='Q'){
            int r;
			scanf("%d ", &r);
			if (r > 0){
				while(tail->next!=NULL && r>0){
					tail= tail->next;
					r--;
				}
				if (r==0){
					printf("%s ", tail->data);
				}
				else{
					printf("None");
				}
			}
			else{
				r=abs(r);
				while(tail->prev!=NULL && r>0){
					tail = tail->prev;
					r--;
				}
				if (r==0){
					printf("%s ", tail->data);
				}
				else{
					printf("None");
				}
				
			}
        }
		scanf("%c ", &s);
	}
}