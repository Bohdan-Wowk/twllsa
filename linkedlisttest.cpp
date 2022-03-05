#include <iostream>

int main();
class Node{
    public:
    Node(int const val);
    ~Node();
    void setnext(Node * const p_newnode);
    void setvalue(int const newval);
    Node * getnext() const;
    int getval() const;
    bool operator<( Node const &other );
    bool operator==( Node const &other );
    bool operator>(Node const &other );
    private:
    Node * p_nextnode;
    int value;
};

class List{
    public:
    List();
    ~List();
    void print();
    void deleteel(Node *&p_prevel);
    void construct();
    void swapel(Node*&prevel);
    void swaphead();
    void sorthigh();
    int countelements();
    Node * getp_head();
    void setp_head(Node * head);

    private:
    Node * p_head;
};

Node * List::getp_head(){
    return p_head;
}
void List::setp_head(Node*head){
    p_head = head;
}
List::List(){

}
List::~List(){

}
int List::countelements(){
    int i{0};
    Node *p_traverse{p_head};   
    while(p_traverse != nullptr){
    p_traverse = p_traverse->getnext();
    i++;
    }
    delete p_traverse;
    return i;
}
Node::Node(int const val){
value = val;
p_nextnode = nullptr;
}

Node::~Node(){
p_nextnode = nullptr;
delete p_nextnode;
}
bool Node::operator<( Node const &other){
    if(this->getval() < other.getval()){
        return true;
    }
    return false;
}
bool Node::operator==( Node const &other){
    if(this->getval() == other.getval()){
        return true;
    }
    return false;
}
bool Node::operator>( Node const &other){
    if(this->getval() > other.getval()){
        return true;
    }
    return false;

}
void Node::setnext(Node * const p_newnode){
p_nextnode = p_newnode;
}

void Node::setvalue(int const newval){
value = newval;
}

Node * Node::getnext() const{
    return p_nextnode;
}
int Node::getval() const{
    return value;
}
void List::construct(){
    Node *p_construct{p_head};
    p_construct->setnext(new Node(2));
    p_construct = p_construct->getnext();
    p_construct->setnext(new Node(3));
    p_construct = p_construct->getnext();
    p_construct->setnext(new Node(4));
    p_construct = p_construct->getnext();
    p_construct->setnext(new Node(5));
    p_construct = p_construct->getnext();
    p_construct->setnext(new Node(6));
    p_construct = p_construct->getnext();
    p_construct->setnext(new Node(7));
    p_construct = p_construct->getnext();
    p_construct->setnext(new Node(8));
    p_construct = nullptr;
}
void List::print(){
    Node *p_traverse{p_head};   
    while(p_traverse != nullptr){
    std::cout << p_traverse->getval() << std::endl;
    p_traverse = p_traverse->getnext();
    }
    std::cout << "end of sequence" << std::endl;
    delete p_traverse;  
}
void List::deleteel(Node *&p_prevel){
    Node *p_tobedel{p_prevel->getnext()};
    Node *p_replacement{p_tobedel->getnext()};
    p_tobedel->setnext(nullptr);
    p_tobedel->~Node(); 
    p_prevel->setnext(p_replacement);
}
void List::swapel(Node*&prevel){
    Node * firstel = prevel->getnext();
    Node * secondel = firstel->getnext();
    Node * finalel = secondel->getnext();
    Node * prevelstore = firstel;
    Node * finalelstore = finalel;

    prevel->setnext(secondel);
    secondel->setnext(prevelstore);
    firstel->setnext(finalelstore);

    firstel = nullptr;
    secondel = nullptr;
    finalel = nullptr;
    prevelstore = nullptr;
    finalelstore = nullptr;
    delete firstel;
    delete secondel;
    delete finalel;
    delete prevelstore;
    delete finalelstore;
}
void List::swaphead(){
    Node * p_hold{p_head};
    Node * p_next{p_head->getnext()};
    Node * p_after{p_next->getnext()};
    p_head = p_next;
    p_next->setnext(p_hold);
    p_hold->setnext(p_after);
    p_hold = nullptr;
    p_next = nullptr;
    p_after = nullptr;
    delete p_hold;
    delete p_next;
    delete p_after;
}
void List::sorthigh(){
    Node * p_traverse{p_head};
    int count = this->countelements();
    for(int i=0; i<count; i++){
    while(p_traverse != nullptr){
        if(p_traverse < p_traverse->getnext()){
            if(p_traverse == p_head){
                p_traverse = p_traverse->getnext();
                this->swaphead();
            }
            else{
                swapel(p_traverse);
                p_traverse = p_traverse->getnext();
            }
        }
        else{
            p_traverse = p_traverse->getnext();
        }
    }
    p_traverse = p_head;   
    }
}


int main(){
    List Newlist;
    Newlist.setp_head(new Node(1));
    Newlist.construct();
    Newlist.print();
    Newlist.sorthigh();
    Newlist.print();
    return 0;
}