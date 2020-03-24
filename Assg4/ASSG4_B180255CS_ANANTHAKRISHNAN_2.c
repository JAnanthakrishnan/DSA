#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct node{
	int key;
	int color;
	struct node *parent;
	struct node *left;
	struct node *right;
};
struct node *ROOT;
struct node *NILL;

void left_rotate(struct node *x);
void right_rotate(struct node *x);
void tree_print(struct node *x);
void red_black_insert(int key);
void red_black_insert_fixup(struct node *z);
struct node *tree_search(int key);
struct node *tree_minimum(struct node *x);


void tree_print(struct node *x){
	if(x != NILL){
		tree_print(x->left);
		printf("%d\t", x->key);
		tree_print(x->right);
	}
}

struct node *tree_search(int key){
	struct node *x;

	x = ROOT;
	while(x != NILL && x->key != key){
		if(key < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}

	return x;
}

struct node *tree_minimum(struct node *x){
	while(x->left != NILL){
		x = x->left;
	}
	return x;
}

void red_black_insert(int key){
	struct node *z, *x, *y;
	z = malloc(sizeof(struct node));

	z->key = key;
	z->color = RED;
	z->left = NILL;
	z->right = NILL;

	x = ROOT;
	y = NILL;

	while(x != NILL){
		y = x;
		if(z->key <= x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}

	if(y == NILL){
		ROOT = z;
	}
	else if(z->key <= y->key){
		y->left = z;
	}
	else{
		y->right = z;
	}

	z->parent = y;

	red_black_insert_fixup(z);
}


void red_black_insert_fixup(struct node *z){
	while(z->parent->color == RED){

		/* z's parent is left child of z's grand parent*/
		if(z->parent == z->parent->parent->left){

			/* z's grand parent's right child is RED */
			if(z->parent->parent->right->color == RED){
				z->parent->color = BLACK;
				z->parent->parent->right->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}

			/* z's grand parent's right child is not RED */
			else{
				
				/* z is z's parent's right child */
				if(z == z->parent->right){
					z = z->parent;
					left_rotate(z);
				}

				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(z->parent->parent);
			}
		}

		/* z's parent is z's grand parent's right child */
		else{
			
			/* z's left uncle or z's grand parent's left child is also RED */
			if(z->parent->parent->left->color == RED){
				z->parent->color = BLACK;
				z->parent->parent->left->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}

			/* z's left uncle is not RED */
			else{
				/* z is z's parents left child */
				if(z == z->parent->left){
					z = z->parent;
					right_rotate(z);
				}

				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(z->parent->parent);
			}
		}
	}

	ROOT->color = BLACK;
}


void left_rotate(struct node *x){
	struct node *y;
	
	/* Make y's left child x's right child */
	y = x->right;
	x->right = y->left;
	if(y->left != NILL){
		y->left->parent = x;
	}

	/* Make x's parent y's parent and y, x's parent's child */
	y->parent = x->parent;
	if(y->parent == NILL){
		ROOT = y;
	}
	else if(x == x->parent->left){
		x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}
	
	/* Make x, y's left child & y, x's parent */
	y->left = x;
	x->parent = y;
}



void right_rotate(struct node *x){
	struct node *y;

	/* Make y's right child x's left child */
	y = x->left;
	x->left = y->right;
	if(y->right != NILL){
		y->right->parent = x;
	}

	/* Make x's parent y's parent and y, x's parent's child */
	y->parent = x->parent;
	if(y->parent == NILL){
		ROOT = y;
	}
	else if(x == x->parent->left){
		x->parent->left = y;	
	}
	else{
		x->parent->right = y;
	}

	/* Make y, x's parent and x, y's child */
	y->right = x;
	x->parent = y;
}


void tree_print1(struct node *x){
	if(x != NILL){
        char ch;
        printf("( ");
        {
            if(x->color==0)
            ch = 'R';
            else
            {
                ch = 'B';
            }
        }
        printf("%d %c ", x->key,ch);
		tree_print1(x->left);
		tree_print1(x->right);
        printf(") ");
	}
    else 
    printf("( ) ");
}


int main()
{
    NILL = malloc(sizeof(struct node));
	NILL->color = BLACK;
	ROOT = NILL;
    int data;
    while((scanf("%d",&data)))
    {
        red_black_insert(data);
        tree_print1(ROOT);
        //printtree(ROOT);
        printf("\n");
    }
}


//#include <time.h>

//#define NB_ELEMS 250

/* Drier program to test above function*/
//int main()
//{
//    srandom(time(NULL));
//    struct node *root = NULL;
//
//    clock_t t0 = clock();
//    for (int i = 0; i < NB_ELEMS; ++i)
//		insert(&root, random());
//    clock_t t1 = clock();
//    printf("inorder Traversal Is :\n");
//    inorder(root);
//    printf("\n");
//    float time_taken = (float)(t1 - t0) / CLOCKS_PER_SEC * 1000;
//	printf("insertion took %fms -> %fus/elem\n",
//		time_taken,
//		time_taken / NB_ELEMS * 1000);
//	
//    return 0;
//}