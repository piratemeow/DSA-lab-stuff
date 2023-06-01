#include <bits/stdc++.h>
using namespace std;


class node{

public:

	int data = 0;
	int level = 0;
	node* par = NULL;
	node* left = NULL;
	node* right = NULL;

	node()
	{

	}

	node (int ele)
	{
		this->data = ele;
	}

	
	void insert(node* root, int ele)
	{
		
		//cout<<root->data<<" ";

		// if (root == NULL)
		// {
		// 	root = new node ();
		// 	root->data = ele;
		// 	return;
		// }

		if (ele <= root->data )
		{
			if (root->left==NULL)
			{
				node* n = new node();

				n->data = ele;
				root->left = n;

				return;
			}

			else
			insert(root->left,ele);

		}

		else
		{
			if (root->right==NULL)
			{
				node* n = new node();

				n->data = ele;
				root->right = n;

				return;
			}
			else
			insert(root->right,ele);
		}
	}

	node* insert_loop(node* root,int ele)
	{
		node* cur = new node();

		if (root == NULL)
		{
			cur ->data = ele;
			root = cur;
			return root;
		}

		else
		{
			cur = root;
			while (1)
			{

				if (ele<=cur->data)
				{
					if (cur->left==NULL)
					{
						node* n = new node();
						n->data = ele;
						cur->left = n;
						break;
					}
					else
					cur = cur->left;
				}

				else
				{
					if (cur->right==NULL)
					{
						node* n = new node();
						n->data = ele;
						cur->right = n;
						break;
					}
					else
					cur = cur->right;
				}
			}
		}

		return root;
	}


	node* search(node* root, int ele)
	{
		if (root == NULL)
		{
			return NULL;
		}

		else
		{
			node* cur = new node();

			cur = root;

			while (1)
			{
				if (cur == NULL)
					return NULL;

				else if (cur->data == ele)
				{
					return cur;
				}

				else if (ele < cur->data)
				{
					cur = cur->left;
				}

				else
				{
					cur = cur->right;
				}
			}

		}
	}


	node* dele (node* root, int ele)
	{



		if (root==NULL)
		{
			cout<<"The BST is empty\n";
			return root;
		}

		else if (search(root,ele)==NULL)
		{
			cout<<"No such data\n";
			return root;
		}



		else
		{
			

			node* temp = root;
			node* cur = root;
			//cur = temp = root;
			while (1)
			{
				

				if (root->data == ele)
				{
					if (root->left == NULL && root->right == NULL)
					{
						return NULL;
					}
					else if (root->right==NULL)
					{
						return root->left;
					}
					else if (root->left == NULL)
						return root->right;
					else
					{

						node* n = root->right;

						while (n->left!=NULL)
						{
							n=n->left;
						}

						n->left = root->left;

						return root->right;
					}
				}
				else if (cur->data == ele)
				{
					if (cur->left == NULL && cur->right == NULL)
					{
					
						if (temp->left!=NULL && temp->left->data == cur->data)
						{
							temp->left = NULL;
							temp->right = NULL;

						}
						else
						{
							temp->left = NULL;
							temp->right = NULL;

						}
						free (cur);
						//cout<<cur->data<<endl;

					}
					else if (cur->left==NULL)
					{
						if (temp->left!=NULL && temp->left->data == cur->data)
						{
							temp->left = cur->right;

						}
						else
						{
							temp->right = cur->right;

						}

						free(cur);
					}

					else if (cur->right == NULL)
					{
						if (temp->left!=NULL && temp->left->data == cur->data)
						{
							temp->left = cur->left;

						}
						else
						{
							temp->right = cur->left;

						}

						free(cur);

					}

					else
					{
						
						node* n = cur->right;

						while (n->left!=NULL)
						{
							n=n->left;
						}

						n->left = cur->left;

						if (temp->left!=NULL && temp->left->data == cur->data)
						{
							temp->left = cur->right;

						}
						else
						{
							temp->right = cur->right;

						}


						free(cur);

					}


					break;
				}

				else if (ele < cur->data)
				{
					temp = cur;
					cur = cur->left;
				}
				else if (ele > cur->data)
				{
					temp = cur;
					cur = cur->right;
				}
			}
			

			
		}

		return root;
	}

	void preorder(node* root)
	{
		if (root == NULL)
			return;
		cout<<root->data<<" ";

		inorder(root->left);
		inorder(root->right);
	}

	void inorder(node* root)
	{
		if (root == NULL)
			return;

		inorder(root->left);

		cout<<root->data<<" ";

		inorder(root->right);
	}

	void postorder(node* root)
	{
		if (root == NULL)
			return;

		inorder(root->left);
		inorder(root->right);

		cout<<root->data<<" ";
	}



};

int main ()
{
	int n;

	cin>>n;

	node* r = new node();

	node* root = NULL;
	node* root1 = NULL;

	while (n--)
	{
		int x ;
		cin>>x;
		if (root==NULL)          /* while using the recursive insert  function we manually have tto
								  consider for the root which is null for the first insertion so we 
								  dont use the function for the first insertion
								*/
		{
			root = new node();
			root->data = x;
			continue;
		}

		r->insert(root,x); 

		root1 = r->insert_loop(root1,x); /* If the bst is empty then the root value is null
										  in that case we have to create a memory space for the root. 
										  that can be easily done but that place has to be returned by
										  the function to get stored. Hence the return type of the function is node*
										  */				
	}


	r->inorder(root);
	cout<<endl;


	node* x = r->search(root,5);

	

	//cout<<x->->data<<endl;
	if (x==NULL)
	{
		cout<<"No data\n";
	}

	else
	{
		cout<<x->data<<endl;
	}


	root = r->dele(root,2);
	x = r->search(root,5);

	
	if (x==NULL)
	{
		cout<<"No data\n";
	}

	else
	{
		cout<<x->data<<endl;
	}

	r->inorder(root);


}
