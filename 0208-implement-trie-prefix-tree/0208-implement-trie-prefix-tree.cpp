class TrieNode{
public:
    TrieNode* children[26];
    bool leaf = false;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }

};


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {

        TrieNode* temp = root;

        for(char c: word){
            if(!temp->children[c-'a']){
                temp->children[c-'a'] = new TrieNode();
            }
            temp = temp->children[c-'a'];
        }
            temp->leaf = true;
    }
    
    bool search(string word) {

        TrieNode* temp = root;
        for(char c: word){
            if(!temp->children[c-'a']){
                return false;
            }
            temp = temp->children[c-'a'];
        }

        return temp->leaf;
        
    }
    
    bool startsWith(string prefix) {

        
        TrieNode* temp = root;
        for(char c: prefix){
            if(!temp->children[c-'a']){
                return false;
            }
            temp = temp->children[c-'a'];
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
 */