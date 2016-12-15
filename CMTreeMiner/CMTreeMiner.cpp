#include <iostream>
#include "CMTreeMiner.h"
#include "../trees/tree.h"

int main(){
	Tree* tree = new Tree("0 3 3 -1 3 -1 -1 4");
	tree->print_tree();
	TreeDB treeDB = new TreeDB();
	EnumerationTree et = new EnumerationTree();

	return 0;		
}
/********************
CMTreeMinerによって頻出飽和(制約なし)のリストを返す
*********************/
vector<Tree*> CMTreeMiner(EnumerationTree et){

}

vector<Node*> get_occurence_list(Tree*){

}

