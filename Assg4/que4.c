// C++ program for implementation of 
// Binomial Heap and Operations on it 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//using namespace std; 

typedef struct node 
{ 
	int val, degree; 
	struct node *parent, *child, *sibling; 
}Node; 

// Making root global to avoid one extra 
// parameter in all functions. 
Node *root = NULL; 

// link two heaps by making h1 a child 
// of h2. 
int binomialLink(Node *h1, Node *h2) 
{ 
	h1->parent = h2; 
	h1->sibling = h2->child; 
	h2->child = h1; 
	h2->degree = h2->degree + 1; 
} 

// create a Node 
Node *createNode(int n) 
{ 
	Node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->val = n; 
	new_node->parent = NULL; 
	new_node->sibling = NULL; 
	new_node->child = NULL; 
	new_node->degree = 0; 
	return new_node; 
} 

// This function merge two Binomial Trees 
Node *mergeBHeaps(Node *h1, Node *h2) 
{ 
	if (h1 == NULL) 
		return h2; 
	if (h2 == NULL) 
		return h1; 

	// define a Node 
	Node *res = NULL; 

	// check degree of both Node i.e. 
	// which is greater or smaller 
	if (h1->degree <= h2->degree) 
		res = h1; 

	else if (h1->degree > h2->degree) 
		res = h2; 

	// traverse till if any of heap gets empty 
	while (h1 != NULL && h2 != NULL) 
	{ 
		// if degree of h1 is smaller, increment h1 
		if (h1->degree < h2->degree) 
			h1 = h1->sibling; 

		// Link h1 with h2 in case of equal degree 
		else if (h1->degree == h2->degree) 
		{ 
			Node *sib = h1->sibling; 
			h1->sibling = h2; 
			h1 = sib; 
		} 

		// if h2 is greater 
		else
		{ 
			Node *sib = h2->sibling; 
			h2->sibling = h1; 
			h2 = sib; 
		} 
	} 
	return res; 
} 

// This function perform union operation on two 
// binomial heap i.e. h1 & h2 
Node *unionBHeaps(Node *h1, Node *h2) 
{ 
	if (h1 == NULL && h2 == NULL) 
	return NULL; 

	Node *res = mergeBHeaps(h1, h2); 

	// Traverse the merged list and set 
	// values according to the degree of 
	// Nodes 
	Node *prev = NULL, *curr = res, 
		*next = curr->sibling; 
	while (next != NULL) 
	{ 
		if ((curr->degree != next->degree) || 
				((next->sibling != NULL) && 
				(next->sibling)->degree == 
				curr->degree)) 
		{ 
			prev = curr; 
			curr = next; 
		} 

		else
		{ 
			if (curr->val <= next->val) 
			{ 
				curr->sibling = next->sibling; 
				binomialLink(next, curr); 
			} 
			else
			{ 
				if (prev == NULL) 
					res = next; 
				else
					prev->sibling = next; 
				binomialLink(curr, next); 
				curr = next; 
			} 
		} 
		next = curr->sibling; 
	} 
	return res; 
} 

// Function to insert a Node 
void binomialHeapInsert(int x) 
{ 
	// Create a new node and do union of 
	// this node with root 
    //struct node * temp = createNode(x);
	root = unionBHeaps(root, createNode(x)); 
    //return temp;
} 

// Function to display the Nodes 
void display(Node *h) 
{ 
	while (h) 
	{ 
		printf("%d ",h->val);
		display(h->child); 
		h = h->sibling; 
	} 
} 

// Function to reverse a list 
// using recursion. 
int revertList(Node *h) 
{ 
	if (h->sibling != NULL) 
	{ 
		revertList(h->sibling); 
		(h->sibling)->sibling = h; 
	} 
	else
		root = h; 
} 

// Function to extract minimum value 
Node *extractMinBHeap(Node *h) 
{ 
	if (h == NULL) 
	return NULL; 

	Node *min_node_prev = NULL; 
	Node *min_node = h; 

	// Find minimum value 
	int min = h->val; 
	Node *curr = h; 
	while (curr->sibling != NULL) 
	{ 
		if ((curr->sibling)->val < min) 
		{ 
			min = (curr->sibling)->val; 
			min_node_prev = curr; 
			min_node = curr->sibling; 
		} 
		curr = curr->sibling; 
	} 

	// If there is a single Node 
	if (min_node_prev == NULL && 
		min_node->sibling == NULL) 
		h = NULL; 

	else if (min_node_prev == NULL) 
		h = min_node->sibling; 

	// Remove min node from list 
	else
		min_node_prev->sibling = min_node->sibling; 

	// Set root (which is global) as children 
	// list of min node 
	if (min_node->child != NULL) 
	{ 
		revertList(min_node->child); 
		(min_node->child)->sibling = NULL; 
	} 

	// Do union of root h and children 
	return unionBHeaps(h, root); 
} 

// Function to search for an element 
Node *findNode(Node *h, int val) 
{ 
	if (h == NULL) 
	return NULL; 

	// check if key is equal to the root's data 
	if (h->val == val) 
		return h; 

	// Recur for child 
	Node *res = findNode(h->child, val); 
	if (res != NULL) 
	return res; 

	return findNode(h->sibling, val); 
} 

// Function to decrease the value of old_val 
// to new_val 
void decreaseKeyBHeap(Node *H, int old_val, 
							int new_val) 
{ 
	// First check element present or not 
	Node *node = findNode(H, old_val); 

	// return if Node is not present 
	if (node == NULL) 
		return; 

	// Reduce the value to the minimum 
	node->val = new_val; 
	Node *parent = node->parent; 

	// Update the heap according to reduced value 
	while (parent != NULL && node->val < parent->val) 
	{ 
		int temp = node->val;
        node->val = parent->val;
        parent->val = temp;
		node = parent; 
		parent = parent->parent; 
	} 
} 

// Function to delete an element 
Node *binomialHeapDelete(Node *h, int val) 
{ 
	// Check if heap is empty or not 
	if (h == NULL) 
		return NULL; 

	// Reduce the value of element to minimum 
	decreaseKeyBHeap(h, val, INT_MIN); 

	// Delete the minimum element from heap 
	return extractMinBHeap(h); 
} 

int findMinBHeap(Node *h) 
{ 
	if (h == NULL) 
	return INT_MIN; 

	Node *min_node_prev = NULL; 
	Node *min_node = h; 

	// Find minimum value 
	int min = h->val; 
	Node *curr = h; 
	while (curr->sibling != NULL) 
	{ 
		if ((curr->sibling)->val < min) 
		{ 
			min = (curr->sibling)->val; 
			min_node_prev = curr; 
			min_node = curr->sibling; 
		} 
		curr = curr->sibling; 
	} 
    return min_node->val;
}

// Driver code 
int main() 
{ 
    int n;
    int count = 0;
    scanf("%d",&n);
    int arr[n];
    for(int k=0;k<n;k++)
    {
        arr[k]=0;
    }
    char str[20];
    int val;
    int index;
    while(1)
    {
        scanf("%s",str);
        if(!strcmp(str,"insr"))
        {
            scanf("%d",&index);
            scanf("%d",&val);
            if(arr[index]==0)
            {
                printf("%d",val);
                arr[index] = val;
                binomialHeapInsert(val);
            }
            else
            {
                printf("%d\n",-1);
            }
        }
        if(!strcmp(str,"extr"))
        {
            //struct node * temp = extractMinBHeap(root);
            struct node * temp = extractMinBHeap(root);
            printf("%d",temp->val);
            //for(int j=0;j<100;j++)
            //{
            //    if(arr[j]==temp)
            //    {
            //        arr[j]=NULL;
            //        break;
            //    }
            //}
        }
        if(!strcmp(str,"decr"))
        {
            scanf("%d",&index);
            scanf("%d",&val);
            int old = arr[index];
            arr[index] = val;
            decreaseKeyBHeap(root,old,val);
        }
    }
    

	
} 
