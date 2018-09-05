#include<stdio.h>
#include<stdlib.h>
#define MAX_Q_SIZE 500

struct node 
{
  int data;
  struct node *left;
  struct node *right;
};

struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);
 
void Levelorder(struct node* root)
{
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;
 
    while (temp_node)
    {
        printf("%d ", temp_node->data);
 
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
 
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);
 
        temp_node = deQueue(queue, &front);
    }
}
 
struct node** createQueue(int *front, int *rear)
{
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);
 
    *front = *rear = 0;
    return queue;
}
 
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);

} 
void Preorder(struct node* node)
{ //rLR
	if(node==NULL)
		return;
	printf("%d ",node->data);
	Preorder(node->left);
	Preorder(node->right);
} 
 
void Inorder(struct node* node)
{ //LrR
	if(node==NULL)
		return;
	Inorder(node->left);
	printf("%d ",node->data);
	Inorder(node->right);
} 

void Postorder(struct node* node)
{ //LRr
	if(node==NULL)
		return;
	Postorder(node->left);
	Postorder(node->right);
	printf("%d ",node->data);
} 


int main()
{
	struct node *root = newNode(1);  
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);

	printf("Preorder Traversal of Tree is:\n");
	Preorder(root);

	printf("\nInorder Traversal of Tree is:\n");
	Inorder(root);

	printf("\nPreorder Traversal of Tree is:\n");
	Postorder(root);


	printf("\nLevel order Traversal of Tree is:\n");
	Levelorder(root);

	getchar();
	return 0;
}
