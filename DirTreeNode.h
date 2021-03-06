#ifndef DIR_TREE_NODE_H
#define DIR_TREE_NODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class DirTreeNode {
private:
	char* name;
	int type;
	unsigned long long size;
	unsigned time;
	DirTreeNode *next;
	DirTreeNode *firstChild;
	bool forced; // whether this node was created implicitly - if yes, it can be overwritten without affecting its children
	static DirTreeNode *lastInserted; // pointer to last inserted node
public:
	bool do_not_list_as_dir; // treat this file as regular file even when it has backslash at the end
	DirTreeNode(const char* fName, const unsigned long long fSize, const unsigned fTime, const int fType);
	~DirTreeNode();
	void setNext(DirTreeNode *next);
	void setForced(bool bln);
	DirTreeNode* getNext();
	char* getName();
	bool insert(char* fName, const unsigned long long fSize, const unsigned fTime, const int fType);
	bool remove(const char* fName);
	void writeOut(FILE* fout, char* curPath);
	void finalize(); // makes this node and all its children explicit, i.e. forced = false
	static void setDoNotListAsDirForLastInserted() {
		if (lastInserted != NULL) lastInserted->do_not_list_as_dir = true;
	}
};

#endif
