#ifndef EMPLOYEETREE_H
#define EMPLOYEETREE_H
#include "EmployeeInfo.h"
#include <iostream>
using namespace std;

// class EmployeeTree similar to class IntBinarayTree
class EmployeeTree {
private:
    struct TreeNode {
        EmployeeInfo value;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

    // Private member functions
    void insert(TreeNode*&, TreeNode*&);
    void destroySubTree(TreeNode*);
    void deleteNode(EmployeeInfo, TreeNode*&);
    void makeDeletion(TreeNode*&);
    void displayInOrder(TreeNode*) const;
    void displayPreOrder(TreeNode*) const;
    void displayPostOrder(TreeNode*) const;
    


public:
    // Constructor
    EmployeeTree() {
        root = NULL;
    }

    // Destructor
    ~EmployeeTree() {
        destroySubTree(root);
    }

    // Binary tree operations
    void insertNode(EmployeeInfo);
    bool searchNode(int);
    void remove(EmployeeInfo);
    void displayPreOrder() const {
        displayPreOrder(root);
    }
        void displayInOrder() const {
        displayInOrder(root);
    }
    void displayPostOrder() const {
        displayPostOrder(root);
    }
    int size();
    int countNodes(TreeNode*);
};
//function to add to the BST
//insert accept a TreeNode and a pointer to a node.
//Thunction inserts the node to the tree pointed by the TreeNode pointer.
//This  function is called recursively
void EmployeeTree::insert(TreeNode*&nodePtr, TreeNode*&newNode) {
    // if nodePtr is null, then assign the reference of new node to nodePtr
    if (nodePtr == NULL) {
        nodePtr = newNode;
    }
    // if the new node value is less than the nodePtr than insert it in the left subtree
    else if (newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode);
    }// otherwise in the right subtree
    else {
        insert(nodePtr->right, newNode);
    }
}

//destroy dubTreeTree is called by destructor. It deletes all nodes in teh tree
void EmployeeTree::destroySubTree(TreeNode* nodePtr) {
    // if nodePre is not NULL
    if (nodePtr) {
        // if leftsubtree is not empty, then destroy left subtree
        if (nodePtr->left) {
            destroySubTree(nodePtr->left);
        }
        // if the right subtree is not empty then destroy the right subtree
        if (nodePtr->right) {
            destroySubTree(nodePtr->right);
        }
        // finally delete the nodePtr
        delete nodePtr;
    }
}

//deleteNode deletes the elemnts with value of item.
void EmployeeTree::deleteNode(EmployeeInfo item, TreeNode*& nodePtr) {
    // if item to delete is less than the nodePtr, then delete from the left subtree
    if (item < nodePtr->value) {
        deleteNode(item, nodePtr->left);
    }
    // if item to delete is greater than the nodePtr, then delete from the right subtree
    else if (item > nodePtr->value) {
        deleteNode(item, nodePtr->right);
    }
    // otherwise delete the nodePtr
    else {
        makeDeletion(nodePtr);
    }
}

//make deletion takes a reference to a pointer to the node that is to be deleted
//the node is removed and the branches of the tree below the node are reattached
void EmployeeTree::makeDeletion(TreeNode*& nodePtr) {
    TreeNode* tempNodePtr;

    // if the node to delete is empty, then we cannot delete it
    if (nodePtr == NULL) {
        cout << "Cannot delete empty node.\n";
    }
    // if right subtree is empty
    else if (nodePtr->right == NULL) {
        // takr the reference of the nodePtr
        tempNodePtr = nodePtr;
        // make the nuw nodePtr as left subtree
        nodePtr = nodePtr->left;
        // delete the reference of the old nodePtr
        delete tempNodePtr;
    }
    // same steps for the the case left subtree is empty
    else if (nodePtr->left == NULL) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    // if its the nodePtr that has to be deleted
    else {
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

// displayInOrder function displays the values in subtree pointed by nodePtr, via inorder transversal
void EmployeeTree::displayInOrder(TreeNode* nodePtr) const {
    // nodePtr is not NULL
    if (nodePtr) {
        // first print the left subtree then node value and then the right subtree
        displayInOrder(nodePtr->left);
        cout << nodePtr->value.getEmpID() << " " << nodePtr->value.getLastName() 
            << " " << nodePtr->value.getFirstName() << " " << nodePtr->value.getYearsOfService() <<endl;
        displayInOrder(nodePtr->right);
    }
}
//displayPreOrder function displays the values in subtree pointed by nodePtr, via preorder transversal
void EmployeeTree::displayPreOrder(TreeNode* nodePtr) const {
    // nodePtr is not NULL
    if (nodePtr) {
        // first print the node value, then left subtree after that then the right subtree
        cout << nodePtr->value.getEmpID() << " " << nodePtr->value.getLastName()
            << " " << nodePtr->value.getFirstName() << " " << nodePtr->value.getYearsOfService() << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}
//displayPostOrder function displays the values in subtree pointed by nodePtr, via postorder transversal
void EmployeeTree::displayPostOrder(TreeNode* nodePtr) const {
    // nodePtr is not NULL
    if (nodePtr) {
        // first print the left subtree then the right subtree and after that the node value
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value.getEmpID() << " " << nodePtr->value.getLastName()
            << " " << nodePtr->value.getFirstName() << " " << nodePtr->value.getYearsOfService() << endl;
    }
}
// this function will find the nuber of element in the tree
int EmployeeTree::size() 
{
    return countNodes(root);
}
// this function will count the number of element in the BST and retur to size() function
int EmployeeTree::countNodes(TreeNode* root) {
    //TreeNode* root;
    if (root == NULL)
        return 0;
    else
        return countNodes(root->left) + countNodes(root->right) + 1;

}
//insertNode creates a new node to hold item as its value and asses to the insert function
void EmployeeTree::insertNode(EmployeeInfo item) {
    // creating a new node and then calling the private member function insert to add to the EmployeeTee
    TreeNode* newNode;

    newNode = new TreeNode;
    newNode->value = item;
    newNode->left = newNode->right = NULL;

    insert(root, newNode);
}

//Search node determines if the value is present in the tree. If so, the function returns true. Otherwise, it returns false
bool EmployeeTree::searchNode(int empID) {
    TreeNode* nodePtr = root;
    // starting with root loop through the entire tree
    while (nodePtr) {
        // if the empID is matched, print out the name of the employee and return true
        if (nodePtr->value.getEmpID() == empID) {
            cout << nodePtr->value.getEmpID() << " " << nodePtr->value.getLastName()
                << " " << nodePtr->value.getFirstName() << " " << nodePtr->value.getYearsOfService() << endl;
            return true;
        }
        // if empID is less than the empID of node than it must be in the left subtree
        else if (empID < nodePtr->value.getEmpID()) {
            nodePtr = nodePtr->left;
        }
        // otherwise it's in the right subtree 
        else {
            nodePtr = nodePtr->right;
        }
    }
    // if by now node has not been found that means there is no node with the given id, so return false
    cout << "Not found" << endl;
    return false;
}

//remove calls delete the deleteNode to the node whose value member is the same as item
void EmployeeTree::remove(EmployeeInfo item) {
    // calling the private function deleteNode 
    deleteNode(item, root);
}


#endif