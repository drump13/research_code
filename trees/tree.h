#include "misc.h"
struct Node{
	int label;
	int id;
	struct Node *parent;
	vector<Node *> children;
};
struct RGNode{
	int label;
	int id;
	struct RGNode *parent;
	vector<RGNode*> children;
	vector<Node*> occurence_list; 
};

struct Pair{
	int left;
	int right;
};


class BipartiteGraph{
public:
	int n;
    vector<vector<int>> g;
    vector<int> match;
	BipartiteGraph(int n_) : n(n_), g(n_), match(n_), used(n_) {}
	int maximum_matching(void);
	void add_edge(vector<Pair*> edges);
	bool is_solved();
    
private:
	vector<int> used;
    bool dfs(int v);

};	
/*
Treeクラス，ルートのみ保持する．
*/
class Tree{
public:

	Tree(Node* root,int label, int id);
	Tree(Node* root);
	Tree(string canical_form);
	Node* new_node(int lab);

	virtual ~Tree();
	Node* new_node();
	Node* get_root();
	void add_node(Node *parent,Node *node);
	void print_tree();
	void reindexing();
	vector<Node*> get_subtree_list(Tree* tree);
	bool is_subtree(Tree* tree);

private:
	Node *root;
private:
	string get_string(Node* node);
	bool is_exist_mbipart();
	int rec_reind(Node* current,int count);
};

/***
Treeクラスのvectorを持つクラス
パターンに対する頻度を返すメソッドやパターンマッチングを行うメソッドを持つ
***/
class TreeDB{
public:
	TreeDB();
	void add_tree(Tree* tree);
	bool is_frequent(Tree* tree,int minimum_sup);
	vector<Node*> get_subtree_list(Tree* tree);


private:	
	vector<Tree*> treedb;
};

/*
RGTreeクラス
通常のノードとは違い，Occurencelistを持つノードによって作られる木
*/
class RGTree{
public:
	RGTree(RGNode* rgnode);
	void add_node(RGNode *parent,RGNode *node);
	void print_rgtree();
private:
	RGNode *root;
};

/*
CMTreeMinerに用いられる．
*/
class EnumerationTree{
public:
	EnumerationTree();
	EnumerationTree(Tree* tree);
	virtual ~EnumerationTree();
	void extend(Node *parent,Node *node);
	vector<Tree*> get_current_trees();	
private:
	Tree* tree;
	vector<Tree*> current_trees;


};

vector<string> split(const string &s, char delim);
