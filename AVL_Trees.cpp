#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *parent;
    node *left;
    node *right;
    int h;
};
node* newNode(int data, node *p)
{
    node *temp=new node();
    temp->parent=p;
    temp->data=data;
    temp->h=-1;
    temp->left=temp->right=NULL;
    return temp;
}
node *root=NULL;//global variable
node* search(int n);//search function prototype declaration
int max(int a,int b)
{
    if(a >b)
    return a;
    else
    return b;
}
int height(node* f)//return height of a node. height of null is -1
{
    if(f==nullptr)
    {
        return -1;
    }
    else
    {
        return f->h;
    }
}
void update_height(node *f)//updates height from f to top till height is same or root is reached 
{
    while(f!=nullptr && f->h!=max(height(f->left),height(f->right))+1)
    {
        f->h=max(height(f->left),height(f->right))+1;
        f=f->parent;
    }
}
void left_rotate(node *f)//left rotate a function
{
    node *temp;
    temp=f->parent;
    if(temp==nullptr)
    {
        root=f->right;/* when no parent node is there to the node f that is root*/
        f->right->parent=temp;//seeting parent of right child to null
        f->parent=f->right;//setting parent of f to the right child of f
        temp=f->right->left;//changing left child of right child of f as the right child
        f->right->left=f;//making f as the left child of the right child of f
        f->right=temp;
    }
    else if(temp->left==f)
    {
        temp->left=f->right;
        f->right->parent=temp;
        f->parent=f->right;
        temp=f->right->left;
        f->right->left=f;
        f->right=temp;
    }
    else
    {
        temp->right=f->right;
        f->right->parent=temp;
        f->parent=f->right;
        temp=f->right->left;
        f->right->left=f;
        f->right=temp;
    }
    f->h=max(height(f->left),height(f->right))+1;//changing height of f since only it will be affected due to rotation
}
void right_rotate(node *f)//opposite of left rotate
{
    node *temp;
    temp=f->parent;
    if(temp==nullptr)
    {
        root=f->left;
        f->left->parent=temp;
        f->parent=f->left;
        temp=f->left->right;
        f->left->right=f;
        f->left=temp;
    }
    else if(temp->left==f)
    {
        temp->left=f->left;
        f->left->parent=temp;
        f->parent=f->left;
        temp=f->left->right;
        f->left->right=f;
        f->left=temp;
    }
    else
    {
        temp->right=f->left;
        f->left->parent=temp;
        f->parent=f->left;
        temp=f->left->right;
        f->left->right=f;
        f->left=temp;
    }
    f->h=max(height(f->left),height(f->right))+1;
}
void rebalance(node *f)
{
    while(f !=nullptr)//till root is reached
    {
        update_height(f);
        if(height(f->right) - height(f->left)>1)//right child heavy case
        {
            if(f->right!=nullptr && height(f->right->right)>=height(f->right->left))
            {
                left_rotate(f);//simple case the heavy tree is in the same line
            }   
            else
            {
                right_rotate(f->right);//complex case heavy tree is zig zag in nature
                left_rotate(f);
            }
        }
        else if(height(f->left) - height(f->right) >1)//left heavy case all cases are same
        {
            if(f->left!=nullptr && height(f->left->left)>=height(f->left->right))
            {
                right_rotate(f);//all commands are opposite to the right heavy case
            }   
            else
            {
                left_rotate(f->left);
                right_rotate(f);
            }
        }
        f=f->parent;
    }
}
void insert()
{
    int n;
    cout<<"Enter elements of tree\n";
    cin>>n;
    node *temp=root;
    if(root==NULL)
    {
        root=newNode(n,nullptr);
        update_height(root);
    }
    else
    {
        while(temp!=NULL)
        {
            if(n<temp->data)
            {
                if(temp->left ==NULL)
                {
                    temp->left=newNode(n,temp);
                    temp=temp->left;
                    update_height(temp);
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->right ==NULL)
                {
                    temp->right=newNode(n,temp);
                    temp=temp->right;
                    update_height(temp);
                    break;
                }
                else
                {
                    temp=temp->right;
                }    
            }
        }
    }
    rebalance(temp);//rebalancing from the bottom

}
int find_min(node *f)
{
    if(f->left==nullptr)
    {
        return f->data;
    }
    return find_min(f->left);
}
int find_max(node *f)
{
    if(f->right==nullptr)
    {
        return f->data;
    }
    return find_max(f->right);
}
void successor(int n)
{
    node *f=search(n);
    if(f->right != nullptr)
    {
        cout<<find_min(f->right)<<" is the successor of "<<n<<endl;
    }
    else if(f->parent != nullptr && f->parent->left==f)
    {
        cout<<f->parent->data<<" is the successor of "<<n<<endl;
    }
    else
    {
        int p=0;
        while(f->parent !=nullptr)
        {
            if(f->parent->left==f)
            {
                f=f->parent;
                p=1;
                break;
            }
            f=f->parent;
        }
        if(p==0)
        {
            cout<<"Successor of "<<n<<" not found "<<endl;
        }
        else
        {
            cout<<f->data<<" is the successor of "<<n<<endl;
        }
    }
}
int successor(node *f)//successor for remove function
{
    if(f->right != nullptr)
    {
        return find_min(f->right);
    }
    else if(f->parent != nullptr && f->parent->left==f)
    {
        return f->parent->data;
    }
    else
    {
        int p=0;
        while(f->parent !=nullptr)
        {
            if(f->parent->left==f)
            {
                f=f->parent;
                p=1;
                break;
            }
            f=f->parent;
        }
        return f->data; 
    }
}
void predecessor(int n)
{
    node *f=search(n);
    if(f->left != nullptr)
    {
        cout<<find_max(f->left)<<" is the predecessor of "<<n<<endl;
    }
    else if(f->parent != nullptr && f->parent->right==f)
    {
        cout<<f->parent->data<<" is the predecessor of "<<n<<endl;
    }
    else
    {
        int p=0;
        while(f->parent !=nullptr)
        {
            if(f->parent->right==f)
            {
                f=f->parent;
                p=1;
                break;
            }
            f=f->parent;
        }
        if(p==0)
        {
            cout<<"Predecessor of "<<n<<" not found "<<endl;
        }
        else
        {
            cout<<f->data<<" is the predecessor of "<<n<<endl;
        }
    }
}
void remove(node *f)
{
    if(f->left==nullptr && f->right==nullptr)//case where node is a leaf
    {
        if(f->parent->left==f)
        {
            f->parent->left=nullptr;
        }
        else if(f->parent->right==f)
        {
            f->parent->right=nullptr;
        }
        update_height(f->parent);
        return;
    }
    else if(f->left==nullptr)//case with only right child
    {
        if(f->parent->left==f)
        {
            f->parent->left=f->right;
        }
        else if(f->parent->right==f)
        {
            f->parent->right=f->right;
        }
        update_height(f->right);
        return;
    }
    else if(f->right==nullptr)//only left child present
    {
        if(f->parent->left==f)
        {
            f->parent->left=f->left;
        }
        else if(f->parent->right==f)
        {
            f->parent->right=f->left;
        }
        update_height(f->left);
        return;
    }
    else//node with two childs
    {
        int n=successor(f);
        node *p=search(n);
        f->data=p->data;
        remove(p);
        return;
    }
}
node* search(int n)
{
    node *f=root;
    int i;
    while(f !=nullptr)
    {
        if(n<f->data)
        {
            f=f->left;
        }
        if(n>f->data)
        {
            f=f->right;
        }
        if(n==f->data)
        {
            return f;
        }
    }
    return nullptr;
}
void inorder(node *f)
{
    if(f==nullptr)
    {
        return;
    }
    inorder(f->left);
    cout<<f->data<<" ";
    inorder(f->right);
}
int main()
{//except insert and delete avl does not affect other bst operations
    int i,n;
    while(true)
    {
        cout<<"Enter choice 1.insert 2.display 3.search 4.find min and max 5.find sucessor 6.find predecessor 7.delete\n";
        cin>>i;
        switch(i)
        {
            case 1:insert();
            break;
            case 2:inorder(root);
            cout<<endl;
            break;
            case 3:
            cout<<"Enter search value \n";
            cin>>n;
            if(search(n)->data==n)
            {
                cout<<n<<" is found";
            }
            else
            {
                cout<<n<<" is not found";
            }
            break;
            case 4:
            cout<<find_min(root)<<" is the minimum"<<endl;
            cout<<find_max(root)<<" is the maximum"<<endl;
            break;
            case 5:
            cout<<"Enter value \n";
            cin>>n;
            successor(n);
            break;
            case 6:
            cout<<"Enter value \n";
            cin>>n;
            predecessor(n);
            break;
            case 7:
            cout<<"Enter value to be deleted\n";
            cin>>n;
            remove(search(n));
            break;
            default:
            exit(0);
        }
    }
}
