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

int Levelorder(struct node* root1,struct node* root2)
{
    int rear1, front1,rear2, front2,flag=1;
    struct node **queue1 = createqueue(&front1, &rear1);
    struct node *temp_node1 = root1;
    struct node **queue2 = createqueue(&front2, &rear2);
    struct node *temp_node2 = root2;
 
    while(temp_node1 || temp_node2)
    {
        if(temp_node1->data!=temp_node2->data)
		flag=0;
        if (temp_node1->left)
		enQueue(queue1, &rear1, temp_node1->left);
        if (temp_node1->right)
		enQueue(queue1, &rear1, temp_node1->right);
        if (temp_node2->left)
		enQueue(queue2, &rear2, temp_node2->left);
        if (temp_node2->right)
		enQueue(queue2, &rear2, temp_node2->right);
        temp_node1 = deQueue(queue1, &front1);
	temp_node2 = deQueue(queue2, &front2);
    }
	return flag;
}

int main()
{
	int data,n1,n2;
	struct node *root1=NULL;
	struct node *root2=NULL;  
	//root->left         = newNode(2);
	//root->right        = newNode(3);
	//root->left->left   = newNode(4);
	//root->right->left  = newNode(5);
	//root->right->right = newNode(6);
	printf("\nEnter number of elements for tree 1: ");
	scanf("%d",&n1);
	printf("\nEnter elements(tree 1):\n"); 
	for(int i=0;i<n1;i++){
		scanf("%d",&data);
		root1=insert(root1,data);
	}
	printf("\nEnter number of elements for tree 2: ");
	scanf("%d",&n2);
	printf("\nEnter elements(tree 2):\n"); 
	for(int i=0;i<n2;i++){
		scanf("%d",&data);
		root2=insert(root2,data);
	}
	if(n1==n2){
		if(Levelorder(root1,root2))
			printf("Identical trees\n");
		else
			printf("Non-Identical trees\n");
	}	
	else
		printf("Non-Identical trees\n");
	return 0;
}
