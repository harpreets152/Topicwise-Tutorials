#include <bits/stdc++.h>
using namespace std;
struct trienode{
	trienode *child[26];
	bool eow;
};
trienode *newnode(){
	trienode *temp=new trienode;
	for(int i=0;i<26;i++) temp->child[i]=NULL;
	temp->eow=0;
	return temp;
}
void insert(trienode *root,string s){
	trienode *curr=root;
	for(int i=0;i<s.length();i++){
		int index=s[i]-'a';
		if(!curr->child[index])
			curr->child[index]=newnode();
		curr=curr->child[index];
	}
	curr->eow=1;
}
bool search(trienode *root,string s){
	trienode *curr=root;
	for(int i=0;i<s.length();i++){
		int index=s[i]-'a';
		if(!curr->child[index]) return false;
		curr=curr->child[index];
	}
	if (curr && curr->eow) return true;
	return false;
}
int main() {
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		trienode *root=newnode();
		while(n--){
			string s;
			cin>>s;
			insert(root,s);
		}
		int q;cin>>q;
		while(q--){
			string s;
			cin>>s;
			cout<<search(root,s)<<endl;
		}
	}
	return 0;
}
