#include <iostream>
#include <cmath>
int main();
//class definitions
class Node{
    public:
    Node(int val);
    ~Node();
    void set_p_next(Node * p_n);
    void set_p_prev(Node * p_p);
    void set_val(int val);
    void set_index(int in);
    Node * get_p_next();
    Node * get_p_prev();
    int get_val();
    int get_index();

    private:
    Node * p_next;
    Node * p_prev;
    int value;
    std::size_t index;
};
class TWLL{
    public:
    TWLL(int a[], std::size_t size);
    ~TWLL();
    void set_p_head(Node * p_h);
    void set_p_tail(Node * p_t);
    Node * get_p_head();
    Node * get_p_tail();
    std::size_t get_length();
    void print();
    void swap(Node * a, Node * b);
    void insert(Node *a, Node *b, bool after);
    void deletel(Node *a);
    void randomize();
    bool ascending();
    void aftermerge(TWLL &a);
    int * split(std::size_t pt);
    int * arrayize();
    void index();
    void bogosrt();
    void bubblesrt();
    void insertsrt();
    void alternate();
    void quicksrt();
    
    private:
    Node * p_head;
    Node * p_tail;
    std::size_t length;
};
//Node member functions
Node::Node(int val){
    p_next = nullptr;
    p_prev = nullptr;
    value = val;
    index = -1;
}
Node::~Node(){
    p_next = nullptr;
    p_prev = nullptr;
    value = 0;
}
void Node::set_p_next(Node * p_n){
    p_next = p_n;
}
void Node::set_p_prev(Node * p_p){
    p_prev = p_p;
}
void Node::set_val(int val){
    value = val;
}
void Node::set_index(int in){
    index = in;
}
Node * Node::get_p_next(){
    return p_next;
}
Node * Node::get_p_prev(){
    return p_prev;
}
int Node::get_val(){
    return value;
}
int Node::get_index(){
    return index;
}
//default list member functions
TWLL::TWLL(int a[], std::size_t size){
    p_head = new Node(a[0]);
    Node * p_count{p_head};
    Node * p_count2{nullptr};
    for(std::size_t i=1; i<size; i++){
        p_count2 = new Node(a[i]);
        p_count->set_p_next(p_count2);
        p_count2->set_p_prev(p_count);
        p_count->set_index(i);
        p_count = p_count2;
    }
    if(size == 1){
        p_tail = p_head;
    }
    else{
        p_tail = p_count2;
    }
    length = size;
}
TWLL::~TWLL(){
    while(p_head != nullptr){
        Node * p_tr{p_head};
        p_head = p_head->get_p_next();
        delete p_tr;
    }
}
void TWLL::set_p_head(Node * p_h){
p_head = p_h;
}
void TWLL::set_p_tail(Node * p_t){
p_tail = p_t;
}
Node * TWLL::get_p_head(){
    return p_head;
}
Node * TWLL::get_p_tail(){
    return p_tail;
}
std::size_t TWLL::get_length(){
    return length;
}
void TWLL::print(){
    Node * p_traverse{p_head};
    for(int i=0; i<length; i++){
        std::cout << p_traverse->get_val() << " ";
        p_traverse = p_traverse->get_p_next();
    }
    std::cout << std::endl << "end of sequence" << std::endl;
    p_traverse = nullptr;
}
//tools
void TWLL::swap(Node * a, Node * b){
    if(a == b){
    }
    else{
        Node * holdbprev{b->get_p_prev()};
        Node * holdbnext{b->get_p_next()};
        Node * holdaprev{a->get_p_prev()};
        Node * holdanext{a->get_p_next()};
        if(a->get_p_next() == b){
            b->set_p_prev(holdaprev);
            b->set_p_next(a);
            a->set_p_prev(b);
            a->set_p_next(holdbnext);
            if(a != p_head){
                holdaprev->set_p_next(b);
            }
            if(b != p_tail){
                holdbnext->set_p_prev(a);   
            }
        }
        else if(b->get_p_next() == a){
            b->set_p_prev(a);
            b->set_p_next(holdanext);
            a->set_p_prev(holdbprev);
            a->set_p_next(b);
            if(b != p_head){
                holdbprev->set_p_next(a);
            }
            if(a != p_tail){
                holdanext->set_p_prev(b);
            }
        }
        else{
            b->set_p_prev(holdaprev);
            b->set_p_next(holdanext);
            a->set_p_prev(holdbprev);
            a->set_p_next(holdbnext);
            if(a != p_head){
                holdaprev->set_p_next(b);
            }
            if(b != p_head){
                holdbprev->set_p_next(a);
            }
            if(a != p_tail){
                holdanext->set_p_prev(b);
            }
            if(b != p_tail){
                holdbnext->set_p_prev(a);   
            }
        }
        if(a == p_head){
            p_head = b;
        }
        else if(b == p_head){
            p_head = a;
        }
        if(a == p_tail){
            p_tail = b;
        }
        else if(b == p_tail){
            p_tail = a;
        }
    }
}
void TWLL::insert(Node *a, Node *b, bool after){
    //inserting A before or after B, if after is true then it's after
    if(a == b){
    }
    else{
        Node * holdbprev{b->get_p_prev()};
        Node * holdbnext{b->get_p_next()};
        Node * holdaprev{a->get_p_prev()};
        Node * holdanext{a->get_p_next()};
        if(after){
            if(a->get_p_next() == b){
                swap(a,b);
            }
            else if(b->get_p_next() == a){
            }
            else{
                b->set_p_next(a);
                a->set_p_prev(b);
                a->set_p_next(holdbnext);
                if(a != p_head){
                    holdaprev->set_p_next(holdanext);
                }
                if(a != p_tail){
                    holdanext->set_p_prev(holdaprev);
                }
                if(b != p_tail){
                    holdbnext->set_p_prev(a);   
                }
                if(a == p_head){
                    p_head = holdanext;
                }
                if(a == p_tail){
                    p_tail = holdaprev;
                }
                else if(b == p_tail){
                    p_tail = a;
                }
            }
        }
        else{
            if(b->get_p_next() == a){
                swap(a,b);
            }
            else if(a->get_p_next() == b){
            }
            else{
                b->set_p_prev(a);
                a->set_p_prev(holdbprev);
                a->set_p_next(b);
                if(b != p_head){
                    holdbprev->set_p_next(a);
                }
                 if(a != p_head){
                    holdaprev->set_p_next(holdanext);
                }
                if(a != p_tail){
                    holdanext->set_p_prev(holdaprev);
                }
                if(b == p_head){
                    p_head = a;
                }
                else if(a == p_head){
                    p_head = holdanext;
                }
                if(a == p_tail){
                    p_tail = holdaprev;
                }
            }
        }
    }
}
void TWLL::randomize(){
    for(int i=0; i<(length*2); i++){
    int r1 = (rand() % length)+1;
    int r2 = (rand() % length)+1;
    Node * t1{p_head};
    Node * t2{p_head};
    for(int i=1; i<r1; i++){
        t1 = t1->get_p_next();
    }
    for(int i=1; i<r2; i++){
        t2 = t2->get_p_next();
    }
    this->swap(t1,t2);
    }
    this->index();
}
bool TWLL::ascending(){
    Node * t1{p_head->get_p_next()};
    while(t1 != nullptr){
        if(t1->get_val() < (t1->get_p_prev())->get_val()){
            return false;
        }
        t1 = t1->get_p_next();
    }
    return true;
}
void TWLL::deletel(Node *a){
Node * holdprev{a->get_p_prev()};
Node * holdnext{a->get_p_next()};
if(p_head == a){
    p_head = holdnext;
    delete a;
    holdnext->set_p_prev(nullptr);
    length --;
}
else if(a == p_tail){
    p_tail = holdprev;
    delete a;
    holdprev->set_p_next(nullptr);
    length --;
}
else{
    holdprev->set_p_next(holdnext);
    holdnext->set_p_prev(holdprev);
    delete a;
    length --;
}

}
void TWLL::aftermerge(TWLL &a){
    p_tail->set_p_next(a.get_p_head());
    (a.get_p_head())->set_p_prev(p_tail);
    p_tail = a.get_p_tail();
    length += a.get_length();
}
int * TWLL::split(std::size_t pt){
    Node * p_tr{p_tail};
    int * a = new int [length-pt];
    for(std::size_t i{length-pt}; i > 0; i--){
        a[i-1] = p_tail->get_val();
        p_tr = p_tail;
        p_tail = p_tail->get_p_prev();
        delete p_tr;
    }
    length = pt;
    return a;
}
int * TWLL::arrayize(){
    Node * p_tr{p_head};
    int * a = new int [length/2];
    for(int i{0}; i < length; i++){
        a[i] = p_head->get_val();
        p_tr = p_head;
        p_head = p_head->get_p_next();
        delete p_tr;
    }  
    return a;
}
void TWLL::index(){
    Node*p_tr{p_head};
    for(int i{1}; i <=length; i++){
        p_tr->set_index(i);
        p_tr = p_tr->get_p_next();
    }
}
//algorithms baybe
void TWLL::bogosrt(){
    bool solved{false};
    if(this->ascending()){
        solved = true;
    }
    while(!solved){
        this->randomize();
        if(this->ascending()){
            solved = true;
        }
    }
    this->index();
}
void TWLL::bubblesrt(){
    bool solved{false};
    if(this->ascending()){
        solved = true;
    }
    Node * t1{p_head};
    while(!solved){
        t1 = p_head;
        while(t1->get_p_next() != nullptr){
            if(t1->get_val() > (t1->get_p_next())->get_val()){
                this->swap(t1, t1->get_p_next());
            }
            if(t1 != p_tail){
            t1 = t1->get_p_next();
            }
        }
        if(this->ascending()){
            solved = true;
        }
    }
    this->index();
}
void TWLL::insertsrt(){
    Node * p_ci{p_head};
    Node * p_rev{p_ci};
    bool smallerthan{false};
    bool solved{false};
    while(p_ci != nullptr){
        p_rev = p_ci;
        smallerthan = false;
        while(!smallerthan){
            p_rev = p_rev->get_p_prev();
            if(p_rev == nullptr){
                insert(p_ci, p_head, 0);
                smallerthan = true;
            }
            else if (p_rev->get_val() <= p_ci->get_val()){
                insert(p_ci, p_rev, 1);
                smallerthan = true;
            }
        }
        p_ci = p_ci->get_p_next();
    }
    this->index();
}
void TWLL::alternate(){
    Node * p_t{p_head};
    if(length % 2 == 0){
        while(p_t != nullptr){
            swap(p_t, p_t->get_p_next());
            p_t = p_t->get_p_next();
        }
    }
    else{
        while(p_t != p_tail){
            swap(p_t, p_t->get_p_next());
            p_t = p_t->get_p_next();
        }
        std::cout << "the number " << p_t->get_val() << " has been removed." << std::endl;
        deletel(p_t);     
    }
    this->index();
}
void TWLL::quicksrt(){
    Node * p_tr{p_head};
    Node * p_h{p_tr};
    Node * p_hh{p_head};
    for(std::size_t i{0}; i < length/2; i++){
        p_hh = p_hh->get_p_next();
    }
    for(std::size_t i{0}; i < length; i++){
        p_h = p_tr->get_p_next();
        if(p_tr->get_val() < p_hh->get_val()){
            this->insert(p_tr,p_hh,0);
        }
        p_tr = p_h;
    }
    this->print();
    this->index();
    std::cout << p_hh->get_index();
    int * a = this->split(p_hh->get_index());
    TWLL list(a, p_hh->get_index()-1);
    if(this->ascending()){
        if(list.ascending()){
            this->aftermerge(list);
        }
        else{
            this->aftermerge(list);
        }
    }
    else{
        if(list.ascending()){
            this->aftermerge(list);
        }
        else{
            this->aftermerge(list); 
        }
    }
    p_tr = nullptr;
    p_h = nullptr;
    p_hh = nullptr;
}


int main(){
    std::size_t sz{5};
    int a[sz]{};
    for(int i=1; i<=sz; i++){
        a[i-1] = i;
    }
    TWLL list{a,sz};
    list.quicksrt();
    list.print();
    return 0;
}