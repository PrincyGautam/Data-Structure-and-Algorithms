#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *rootnode = NULL, *temp = NULL, *t2, *t1;
 
void delete1();
void insert();
void delete();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search1(struct btnode *t,int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
int countLeafNode(struct btnode *t);
void print();
void printlevel(struct btnode *t, int desired, int current);
int height(struct btnode *t);
int io[15];
int po[15];
int x,y;
int flag = 1;
 
void main()
{
    int ch[2];

    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Delete an element from the tree and Preorder Traversal\n");
    printf("default - Exit\n");
    while(1)
    {
        printf("\nEnter menu number : ");
		int i=0;
		
		do{
			scanf("%d", &ch[i++]);
		}while (getchar() != '\n' && i < 3);
		
		ch[i];

        switch (ch[0]){
			
			case 1:  
				insert();
				//printf("Number of leaves : %d", countLeafNode(t));
				//printf("Number of levels : %d", );
				break;
			case 2:    
				delete();
				preorder(root);
				//inorder(root);
				//postorder(root);
				break;
			default :     
				exit(0);
				break;    
        }
    }
}

/* To create a node */
void create()
{
    //int data;
    //printf("Enter data of node to be inserted : ");
    //scanf("%d", &data);
	printf("Inorder: ");
	do{
		scanf("%d", &io[x++]);
	}while(getchar() != '\n');
	
	printf("\nPostorder: ");
	do{
		scanf("%d", &po[y++]);
	}while(getchar() != '\n');
	
	int size = sizeof(io)/sizeof(io[0]);
	
	for (int i=1; i< size; i++){
		temp = (struct btnode *)malloc(1*sizeof(struct btnode));
		temp->value = io[i];
		temp->l = temp->r = NULL;
	}
}
/* To insert a node in the tree */
void insert()
{
    create();
    if(root == NULL) {
		root = temp;
	}
    else{
        search(root);   
	}		
}

/* Function to search the appropriate position to insert the new node */
void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))      /* value more than root node value insert at right */
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))    /* value less than root node value insert at left */
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}
 
/* recursive function to perform inorder traversal of tree */
void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("empty");
        return;
    }
	else{
		if (t->l != NULL)    
			inorder(t->l);
		printf("%d -> ", t->value);
		if (t->r != NULL)    
			inorder(t->r);
	}
}
 
/* To check for the deleted node */
void delete()
{
    int data;
 
    if (root == NULL)
    {
        printf("empty");
        return;
    }
    printf("Enter the data to be deleted : ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);
}
 
/* To find the preorder traversal */
void preorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("empty");
        return;
    }
    printf("%d -> ", t->value);
    if (t->l != NULL)    
        preorder(t->l);
    if (t->r != NULL)    
        preorder(t->r);
}
 
/* To find the postorder traversal */
void postorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("empty");
        return;
    }
    if (t->l != NULL) 
        postorder(t->l);
    if (t->r != NULL) 
        postorder(t->r);
    printf("%d -> ", t->value);
}
 
/* Search for the appropriate position to insert the new node */
void search1(struct btnode *t, ch[1])
{
    if ((ch[1]>t->value))
    {
        t1 = t;
        search1(t->r, ch[1]);
    }
    else if ((ch[1] < t->value))
    {
        t1 = t;
        search1(t->l, ch[1]);
    }
    else if ((ch[1]==t->value))
    {
        delete1(t);
    }
}
 
/* To delete a node */
void delete1(struct btnode *t)
{
    int k;
 
    /* To delete leaf node */
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having one left hand child */
    else if ((t->r == NULL))
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
 
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having right hand child */
    else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t == NULL;
        free(t);
        return;
    }
 
    /* To delete node having two child */
    else if ((t->l != NULL) && (t->r != NULL))  
    {
        t2 = root;
        if (t->r != NULL)
        {
            k = smallest(t->r);
            flag = 1;
        }
        else
        {
            k =largest(t->l);
            flag = 2;
        }
        search1(root, k);
        t->value = k;
    }
 
}
/* To find the smallest element in the right sub tree */
int smallest(struct btnode *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return(smallest(t->l));
    }
    else    
        return (t->value);
}
 
/* To find the largest element in the left sub tree */
int largest(struct btnode *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return(largest(t->r));
    }
    else    
        return(t->value);
}

int countLeafNode(struct btnode *t){
    if(t == NULL)
        return 0;
    /* Check for leaf node */
    if(t->left == NULL && t->right == NULL)
        return 1;
    /* For internal nodes, return the sum of 
    leaf nodes in left and right sub-tree */
    return countLeafNode(t->left) + countLeafNode(t->right);
}

void print()
{
    int h, i;
 
    h = height(t);
    for (i = 0;i < h;i++)
    {
        printf("\nLEVEL %d  :", i);
        printlevel(root, i, 0);
        printf("\n");
    }
}
/*
 *Prints the nodes of a particular level
 */
void printlevel(struct btnode *t, int desired, int current)
{
    if (t)
    {
        if (desired == current)
            printf("%d ", t->value);
        else
        {
            printlevel(t->l, desired, current + 1);
            printlevel(t->r, desired, current + 1);
        }
    }
}
 
/*
 * Height of the binary tree
 */
int height(struct btnode *t)
{
    int lheight, rheight;
    if (t != NULL)
    {
        lheight = height(t->l);
        rheight = height(t->r);
        if (lheight > rheight)
            return(lheight+1);
        else 
            return(rheight+1);
    }
}