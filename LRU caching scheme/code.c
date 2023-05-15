#include <stdio.h>
#include <stdlib.h>


typedef struct QNode {
	struct QNode * prev, 
	struct QNode * next;
	int BookID;
} QNode;

typedef struct Queue {
	int total_nodes; 
	int nodes; 
	QNode *head, 
	QNode *tail;
} Queue;


typedef struct Hash {
	int capacity; 
	QNode** sequence; 
} Hash;

QNode* new_Node(int BookID){
	QNode* nd = (QNode*)malloc(sizeof(QNode));
	nd->BookID = BookID;

	
	nd->prev = nd->next;
	nd->next = NULL;

	return nd;
}

int isFull(Queue* queue)
{
	if(queue->total_nodes == queue->nodes){
	return -1;
	}
}
int isEmpty(Queue* queue)
{
	if (queue -> tail == NULL){
		return -2 ;
	}
}

Queue* makeQ(int nodes)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));

	q -> total_nodes = 0;
	q -> head = q->tail;
	q -> tail = NULL;
	q -> nodes = nodes;
	return q;
}

Hash* makeHash(int capacity){
	Hash* hash = (Hash*)malloc(sizeof(Hash));
	hash->capacity = capacity;

	hash->sequence = (QNode**)malloc(hash->capacity * sizeof(QNode*));

	for (int i = 0; i < hash->capacity; ++i){
		hash->sequence[i] = NULL;
	}
	return hash;
}

void enQ(Queue* queue, Hash* hash, int BookID){
	if (isFull(queue)) {
		hash->sequence[queue->tail->BookID] = NULL;
		deQ(queue);
	}
	
	QNode* nd = new_Node(BookID);
	nd->next = queue->head;

	if (isEmpty(queue))
		queue->tail = queue->head = nd;
	else{
		queue->head->prev = nd;
		queue->head = nd;
	}

	hash->sequence[BookID] = nd;
	queue->total_nodes++;
}

void deQ(Queue* queue)
{
	if (isEmpty(queue)){
		return;
	}

	if (queue->head == queue->tail)
		queue->head = NULL;

	QNode* nd = queue->tail;
	queue->tail = queue->tail->prev;

	if (queue->tail)
		queue->tail->next = NULL;

	free(nd);
	queue->total_nodes--;
}

void Put(Queue* queue, Hash* h, int BookID){
	QNode* id = h->sequence[BookID];

	if (id == NULL){
		enQ(queue, h, BookID);
	}

	else if (id != queue->head) {
	
		id->prev->next = id->next;
		if (id->next)
			id->next->prev = id->prev;

		if (id == queue->tail) {
			queue->tail = id->prev;
			queue->tail->next = NULL;
		}

		id->next = queue->head;
		id->prev = NULL;

		id->next->prev = id;
		queue->head = id;
	}
}

struct Node {
int data;
int priority;
struct Node *back;
struct Node *front;
}Node;

void push(struct Node** start,struct Node** end, int data, int position)
{

struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = data;
new_node->priority = position;

if (*start == NULL) {
*start = new_node;
*end = new_node;
new_node->front = NULL;
}
else {

if (position <= (*start)->priority) {
new_node->front = *start;
(*start)->back = new_node->front;
*start = new_node;
}

else if (position > (*end)->priority) {
new_node->front = NULL;
(*end)->front = new_node;
new_node->back = (*end)->front;
*end = new_node;
}
else {

struct Node* ele = (*start)->front;
while (ele->priority > position) 
  {
          ele = ele->front;
  }

(ele->back)->front = new_node;
new_node->front = ele->back;
new_node->back = (ele->back)->front;
ele->back = new_node->front;
}
}
}

int peek(struct Node* first) 
 {
  int leastPrio = first->data; 
  return leastPrio;
 }

char isEmpty(struct Node* first) { 
	if(first == NULL) {
		printf("Empty");
    }

 }
 
int pop(struct Node** start, struct Node** end)
{
	struct Node* ele = *start;
	int leastPrio = ele->data;

	(*start) = (*start)->front;
	free(ele);

	if (*start == NULL)
	*end = NULL;
	return leastPrio;
}


void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d ", node->data);
    last = node;
    node = node->front;
  }
  if (node == NULL)
    printf("\n");
}

int main()
{
	int size=2;
    int a[size]; 

	for(int i=0;i<size;i++){
		scanf("%d",&a[i]);
		//printf("%d ", a[i]);
	// create a queue with m nodes
	Queue* q = makeQ(a[1]);
	
	int sequence[50];
    
    for(int i=0;i<=50;i++){
        scanf("%[^\n]d ", sequence[i]);
    }
	
	Hash* h = makeHash(100);
	
	for(int i=1; i<=sequence[0];i++){
		Put(q, h, sequence[i]);
	}
	struct Node *f = NULL;
	struct Node *l = NULL;
	
	for(int i=1; i<=sequence[0];i++){
		push(&f, &l, sequence[i], i-1);
		displayList(f);
	}
	return 0;
}