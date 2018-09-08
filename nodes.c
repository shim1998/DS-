#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);

}

struct node* insert(struct node* node,int data){
	if(node==NULL)
		node=newNode(data);
	if(data>node->data)
		node->right=insert(node->right,data);
	if(data<node->data)
		node->left=insert(node->left,data);		
	return node;
}

struct node** createqueue(int *front, int *rear){
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)*500);

    *front = *rear = 0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node){
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct node *deQueue(struct node **queue, int *front){
    (*front)++; 
    return queue[*front-1];
}

int counthalfnodes(struct node *node){
	if(!node)
		return 0;
	int rear, front,count=0;
	struct node **queue = createqueue(&front, &rear);
	enQueue(queue,&rear,node);
	struct node* temp=deQueue(queue,&front);
	while(temp){
		if((!temp->left && temp->right)|| (temp->left && !temp->right))
			count++;
		if(temp->left != NULL)
			enQueue(queue,&rear,temp->left);
		if(temp->right != NULL)
			enQueue(queue,&rear,temp->right);
		temp=deQueue(queue,&front);	
	}
	return count;
}

int countleafnodes(struct node *node){
	if(!node)
		return 0;
	int rear, front,count=0;
	struct node **queue = createqueue(&front, &rear);
	enQueue(queue,&rear,node);
	struct node* temp=deQueue(queue,&front);
	while(temp){
		if(!temp->left && !temp->right)
			count++;
		if(temp->left != NULL)
			enQueue(queue,&rear,temp->left);
		if(temp->right != NULL)
			enQueue(queue,&rear,temp->right);
		temp=deQueue(queue,&front);	
	}
	return count;
}

int countfullnodes(struct node *node){
	if(!node)
		return 0;
	int rear, front,count=0;
	struct node **queue = createqueue(&front, &rear);
	enQueue(queue,&rear,node);
	struct node* temp=deQueue(queue,&front);
	while(temp){
		if(temp->left && temp->right)
			count++;		
		if(temp->left != NULL)
			enQueue(queue,&rear,temp->left);
		if(temp->right != NULL)
			enQueue(queue,&rear,temp->right);
		temp=deQueue(queue,&front);	
	}
	return count;
}

int main()
{
	int data,n;
	struct node *root=NULL;  
	//root->left         = newNode(2);
	//root->right        = newNode(3);
	//root->left->left   = newNode(4);
	//root->right->left  = newNode(5);
	//root->right->right = newNode(6);
	printf("\nEnter number of elements: ");
	scanf("%d",&n);
	printf("\nEnter elements:\n"); 
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		root=insert(root,data);
	}
	printf("Number of halfnodes are %d\n",counthalfnodes(root));
	printf("Number of leafnodes are %d\n",countleafnodes(root));
	printf("Number of fullnodes are %d\n",countfullnodes(root));
	return 0;
}
