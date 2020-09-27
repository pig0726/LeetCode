class Node {
public:
    string name;
    bool dead;
    vector<Node*> children;
    Node(string name) {
        this->name = name;
        this->dead = false;
    }
};

class ThroneInheritance {
public:
    Node* root;
    unordered_map<string, Node*> umap;

    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        umap[root->name] = root;
    }
    
    void birth(string parentName, string childName) {
        Node* parent = umap[parentName];
        Node* child = new Node(childName);
        umap[child->name] = child;
        parent->children.push_back(child);
    }
    
    void death(string name) {
        Node* node = umap[name];
        node->dead = true;    
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ord;
        dfs(root, ord);
        return ord;
    }

    void dfs(Node* node, vector<string>& ord) {
        if (!node->dead) ord.push_back(node->name);
        for (auto child : node->children) {
            dfs(child, ord);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

