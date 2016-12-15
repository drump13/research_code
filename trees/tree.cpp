#include "tree.h"
// using namespace std;

void BipartiteGraph::add_edge(vector<Pair*> edges){
	map<int,int> left_map,right_map;
	int count_left = 0;
	int count_right = 0;
	for(int i = 0;i<edges.size();i++){
		if(left_map.count(edges[i]->left)==0){
			left_map[edges[i]->left] = count_left;
			count_left++;	
		}
		if(!right_map.count(edges[i]->right)==0){
			right_map[edges[i]->right] = count_right;
			count_right++;
		}
	}
	for(int i = 0 ; i < edges.size();i++){
		int u = left_map[edges[i]->left];
		int v = right_map[edges[i]->right];
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int BipartiteGraph::maximum_matching() {
	int res = 0;
	fill(begin(match), end(match), -1);
	for (int v = 0; v < n; ++v) {
		if (match[v] == -1) {
			fill(begin(used), end(used), false);
			if (dfs(v)) res++;
		}
	}
	return res;
}
/*
パターンノードの方が全てマッチングに入ったかどうかチェック
最大マッチングを解いた際，パターン側の全ノードから全てマッピングが存在する時trueを返す
*/
bool BipartiteGraph::is_solved(){
	for(int i = 0 ; i < match.size();i++){
		if(match[i] == -1) return false;
	}
	return true;
}

bool BipartiteGraph::dfs(int v) {
	used[v] = true;
	for (int u : g[v]) {
		int w = match[u];
		if (w == -1 || (!used[w] && dfs(w))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}



/***************************************
以下木クラスの実装
****************************************/

Tree::Tree(Node* node,int label, int id ){
	root = node;
	root->label = label;
	root->id = id;
	root->parent = NULL;

}
/*
コピーコンストラクタ
ノードを渡す事でそのノードを根にした部分木を生成
*/
Tree::Tree(Node* node){
	root = node;
	//todo
}

/*
標準形文字列を渡すとその木を生成する
*/
Tree::Tree(string canonical_form){
	vector<string> sv = split(canonical_form,' ');
	root = new_node(stoi(sv[0]));

	Node* current_node = root;
	for(int i = 1 ; i < sv.size();i++){
		int svi = stoi(sv[i]);
		if(svi == -1){
			current_node = current_node->parent;

		}else{
			Node* node = new_node(svi);
			node->id = i;
			add_node(current_node,node);
			current_node = node;
		}

	}
	
}

Tree::~Tree(){

}


Node* Tree::new_node(int lab){
	Node* newnode;
	newnode = new Node();
	newnode->label = lab;
	newnode->id = 0;
	return newnode;

}

Node *Tree::get_root(){
	return root;
}




/*
親ノードを指定して，そのノードの最も右の子として新たなノードを付ける
*/
void Tree::add_node(Node *parent,Node *node){
	parent->children.push_back(node);
	node->parent = parent;

}

void Tree::reindexing(){
	root->id = 0;
	int current_count= 1;
	for(int i = 0 ; i < root->children.size();i++){
		int c = rec_reind(root->children[i],current_count);
		current_count=c+1;
	}
}
int Tree::rec_reind(Node* current,int count){
	current->id = count;
	int current_count = count;
	for(int i = 0 ; i < current->children.size();i++){
		int c = rec_reind(current->children[i],current_count+1);
		current_count=c;
	}
	
	return current_count;
}
void Tree::print_tree(){
	string result = "";
	result = get_string(root);
	cout << result << endl;
}

string Tree::get_string(Node* node){
	stringstream s;
	s << node->label;
	s << ":";
	s << node->id;
	string result = s.str();
	for(int i = 0;i < node->children.size();i++){
		result = result + " ";
		result = result+get_string(node->children[i]);
	}
	result = result+" -1";
	return result;
}

vector<Node*> Tree::get_subtree_list(Tree* tree){
	vector<Node*> subtree;
	//todo
	return subtree;
}

bool Tree::is_subtree(Tree* tree){
	//todo
	return false;
}


TreeDB::TreeDB(){
}
void TreeDB::add_tree(Tree* tree){
	treedb.push_back(tree);
}

bool TreeDB::is_frequent(Tree* tree,int minimum_sup){
//todo
	vector<Node*> list = get_subtree_list(tree);
	return list.size() >= minimum_sup;
}
vector<Node*> TreeDB::get_subtree_list(Tree* tree){
	vector<Node*> roots;
	for(int i = 0 ; i < treedb.size();i++){
		vector<Node*> sub = (*treedb[i]).get_subtree_list(tree);
		roots.insert(roots.end(), sub.begin(), sub.end());
	}
	return roots;
}


/***************************************
以下RG-Treeクラスの実装
主にSCC-Minerで使われる
****************************************/

RGTree::RGTree(RGNode* rgnode){
	root = rgnode;
}
void RGTree::add_node(RGNode *parent,RGNode *node){

}
void RGTree::print_rgtree(){

}

/***************************************
以下enumeration-treeクラスの実装
主にCM-Tree-Minerで使われる
****************************************/


EnumerationTree::EnumerationTree(){
	tree=NULL;
}
EnumerationTree::EnumerationTree(Tree *ftree){
	tree=ftree;
}
EnumerationTree::~EnumerationTree(){

}
void EnumerationTree::extend(Node *parent,Node *node){}

vector<Tree*> EnumerationTree::get_current_trees(){
	return current_trees;
}


/***************************************
以下静的お便利メソッドの実装
****************************************/


vector<string> split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	return elems;
}

