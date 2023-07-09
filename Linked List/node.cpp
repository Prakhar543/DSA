class Node{
    public:
    int val;
    Node * next;    
    Node(int val){
        this -> val = val;
        next = NULL;
    }
};

class DoubleNode{
    public:
    int val;
    DoubleNode * next;
    DoubleNode * prev;
    DoubleNode(int val){
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};