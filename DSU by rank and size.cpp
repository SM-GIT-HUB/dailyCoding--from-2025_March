#include<bits/stdc++.h>
using namespace std;

class DSUrank {
public:
	vector<int> rank, parent;
	
	DSUrank(int n)
	{
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}
	
	int findUltParent(int node)
	{
		if (parent[node] == node) {
			return node;
		}
		
		return parent[node] = findUltParent(parent[node]);
	}
	
	void unionByRank(int u, int v)
	{
		int uParent = findUltParent(u);
		int vParent = findUltParent(v);
		
		if (uParent == vParent) {
			return;
		}
		else if (rank[uParent] > rank[vParent]) {
			parent[vParent] = uParent;
		}
		else if (rank[uParent] < rank[vParent]) {
			parent[uParent] = vParent;
		}
		else
		{
			parent[vParent] = uParent;
			rank[uParent]++;
		}
	}
	
	bool sameComp(int u, int v)
	{
		if (findUltParent(u) == findUltParent(v)) {
			return true;
		}
		
		return false;
	}
};

class DSUsize {
public:
	vector<int> size, parent;
	
	DSUsize(int n)
	{
		size.resize(n + 1, 1);
		parent.resize(n + 1);
		
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}
	
	int findUltParent(int node)
	{
		if (parent[node] == node) {
			return node;
		}
		
		return parent[node] = findUltParent(parent[node]);
	}
	
	void unionBySize(int u, int v)
	{
		int uParent = findUltParent(u);
		int vParent = findUltParent(v);
		
		if (uParent == vParent) {
			return;
		}
		else if (size[uParent] >= size[vParent])
		{
			parent[vParent] = uParent;
			size[uParent] += size[vParent];
		}
		else
		{
			parent[uParent] = vParent;
			size[vParent] += size[uParent];
		}
	}
	
	bool sameComp(int u, int v)
	{
		if (findUltParent(u) == findUltParent(v)) {
			return true;
		}
		
		return false;
	}
};

int main(void)
{
	DSUrank m1(5);
	cout << m1.sameComp(1, 2) << endl;
	m1.unionByRank(1, 2);
	cout << m1.sameComp(1, 2) << endl;
	
	DSUsize m2(5);
	cout << m2.sameComp(1, 2) << endl;
	m2.unionBySize(1, 2);
	cout << m2.sameComp(1, 2) << endl;
}
