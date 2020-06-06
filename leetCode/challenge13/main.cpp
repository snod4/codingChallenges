//Implement a trie with insert, search, and startsWith methods.
//Not the most efficient way, but wanted to learn how to use heap memeory in c++ as well as how structs worked with it. 

#include <iostream>
using namespace std;
class Trie {
    
     private:
    
    
    struct trie{
        string str;
        struct trie * children[26] = {nullptr};
        bool key = false;
    }typedef trie_t;
    
    
public:
    
    trie_t * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new trie_t;
        root->str = "";
        root->key = false;
        // for(int i = 0; i < 26; i++){
        //     root->children[i] = nullptr;
        // }
    }

    
    ~Trie(){
        destoryTrie(root);
        root = nullptr;
    }

    bool isEmpty(trie_t * list[26]){
        for(int i = 0; i < 26; i++){
            if(list[i] != nullptr){
                return false;
            }
        }
        return true;
    }

    void destoryTrie(trie_t * temp){
        if(temp == nullptr){
            return;
        }
        else{
            for(int i = 0; i < 26; i++){
                destoryTrie(temp->children[i]);
            }
            delete temp;
        }
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        trie_t * temp = root;
        string str("");
        for(int i = 0; i < word.length(); i++){
            str.append(temp->str);
            str+=word[i];
            if(temp->children[word[i]-'a'] == NULL){
                trie_t * add = new trie_t;
                add->key = false;
                add->str = str;
                for(int g = 0; g < 26; g++){
                    add->children[g] = nullptr;
                }
                temp->children[word[i]-'a'] = add;
                temp = add;
                str = "";
                if(i == word.length() - 1){
                temp->key = true;
                str = "";
            }
            }
            else if(i == word.length() - 1){
                temp->children[word[i]-'a']->key = true;
                str = "";
            }
            else{
                temp = temp->children[word[i]-'a'];
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie_t * temp = root;
        for(int i = 0; i < word.length(); i++){
            if(temp->children[word[i]-'a'] == nullptr){
                return false;
            }
            temp = temp->children[word[i]-'a'];
        }
        return temp->key;
        }
    
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        trie_t * temp = root;
        for(int i = 0; i < word.length(); i++){
            if(temp->children[word[i]-'a'] == nullptr){
                return false;
            }
            temp = temp->children[word[i]-'a'];
        }
        return true;
        
    }
    
    
   
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 * 
 */

int main(){
    Trie* obj = new Trie();
    cout << obj->root->children[0] << endl;
   obj->insert("apple");
   bool param_2 = obj->search("apple");
   bool param_3 = obj->startsWith("apple");

    cout << param_2 << " " << param_3 << endl;
    delete obj;
    //  obj = nullptr;


//     Trie obj;
//     cout << obj.root->children[0] << endl;
//    obj.insert("apple");
//    bool param_2 = obj.search("apple");
//    bool param_3 = obj.startsWith("apple");
    return 0;
}
