#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node1 {
    int data;
    int color;
    struct node1 * left;
    struct node1 * right;
};
struct node1* newnode1(int data,char ch)
{
    struct node1 * temp = (struct node1 *)malloc(sizeof(struct node1));
    temp->data = data;
    if(ch=='B')
    temp->color = 1;
    if(ch=='R')
    temp->color = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int blackheight(struct node1 * root)
{
    if(root==NULL)
        return 1;
    int leftblackheight = blackheight(root->left);
    if(leftblackheight==0)
        return leftblackheight;
    int rightblackheight = blackheight(root->right);
    if(rightblackheight==0)
        return rightblackheight;
    if(leftblackheight!=rightblackheight)
        return 0;
    else 
        return leftblackheight+root->color;
}
struct node1 * insert(struct node1 * root)
{
    scanf(" (");
    int val;
    if(scanf("%d",&val))
    {
        char ch;
        scanf(" ");
        scanf("%c",&ch);
        root = newnode1(val,ch);
        scanf("(");
        root->left = insert(root->left);
        scanf("(");
        root->right = insert(root->right);
    }
    scanf(" )");
    return root;
}

void tree_print1(struct node1 *x,int * flag){
	if(x != NULL){
        char ch;
       // printf("( ");
            if(x->color==0)
            ch = 'R';
            else
            {
                ch = 'B';
            }
        if(blackheight(x->left)!=blackheight(x->right))
        {
            *flag = 0;
        }
        if(x->left!=NULL)
        {
            if(x->color==0&&x->left->color==0)
            {
                *flag = 0;
            }
        }
        if(x->right!=NULL)
        {
            if(x->color==0&&x->right->color==0)
            {
                *flag =  0;
            }
        }
		tree_print1(x->left,flag);
		tree_print1(x->right,flag);
       // printf(") ");
	}
}

int is_bst(struct node1 * root,int * prev,int * flag2)
{
    if(root!=NULL)
    {
        is_bst(root->left,prev,flag2);
       // printf("%d %d\n",root->data,*prev);
        if(root->data<*prev)
        *flag2 = 0;
        *prev = root->data;
        is_bst(root->right,prev,flag2);
    }
}

int main()
{
    int flag = 1;
    int flag2 = 1;
    int prev = INT_MIN;
    struct node1 * root = NULL;
    root = insert(root);
    tree_print1(root,&flag);
    is_bst(root,&prev,&flag2);
    int res = flag*flag2;
    printf("%d\n",res);

    
}