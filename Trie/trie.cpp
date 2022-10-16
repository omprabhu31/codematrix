#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for( int i = 0; i < 26; i++ )
            {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie
{
    public:
    TrieNode* root; 

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode * root, string word)
    {
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        } 

        //Assuming the word is in caps 
        int index = word[0]-'A';
        TrieNode *child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            // if absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child,word.substr(1));

    }

    void insertWord(string word)
    {
        insertUtil(root,word);  
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if(word.length() == 0 ){
            return root->isTerminal;
        }

        int index = word[0]-'A';
        TrieNode *child;
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(root, word.substr(1));
    }

    bool searchWord(string word)
    {
        return(searchUtil(root, word));
    }
};


int main(){

    Trie *t = new Trie();
    cout<<"Helooodfa;oisdjflojagiljg"<<endl;
        cout    << "Present or not"<< t->searchWord("abcde");

    t->insertWord("abcd");
    cout    << "Present or not"<< t->searchWord("abcde");
    return 0;
}