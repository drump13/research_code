#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

Node* new_node(short id,short label){
	Node* newnode;
	newnode = new Node();
	newnode->label = label;
	newnode->id = id;
	return newnode;

}

int main(){
	Tree* tree = new Tree("0 3 3 -1 3 -1 -1 4");
	tree->print_tree();
	tree->reindexing();
	tree->print_tree();
	return 0;		
}

