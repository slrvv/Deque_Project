#include<iostream>
using namespace std;

//structure for node of a list
struct Node{
  int data;
  Node *prev, *next;
  static Node*getnode(int data){
    Node* newNode = new Node;
    newNode -> data = data;
    newNode ->prev = newNode -> next = nullptr;
  }
};

class Deque{
  private :
    Node* front;
    Node* back;
    int size;

  public:
    Deque(){
      front = back = nullptr;
      size = 0;
    }

    bool empty(){
      return front == nullptr ;
    }

    int Size(){
      return size;
    }

    void insert_front(int data){
      Node* newNode = Node::getnode(data);
      if(newNode == nullptr){
        cout << "Overflow" << endl;
        return;
      }
      else if( front == nullptr){
        front = back = newNode;
      }
      else{
        newNode -> next = front;
        front -> prev = newNode;
        front = newNode;
      }
      size++;
    }

    void insert_back(int data){
      Node* newNode = Node::getnode(data);
      if(newNode == nullptr){
        cout << "Overflow" << endl;
        return;
      }
      else if( back == nullptr){
        front = back = newNode;
      }
      else{
        newNode -> prev = back;
        back -> next = newNode;
        back = newNode;

      }
      size++;
    }

    void delete_front(){
      Node* temp = front;
      front = front->next;
      if(empty()){
        cout << "Empty deque, no elements to delete"<< endl;
        return;
      }
      else if( front == nullptr) back = nullptr;
      else{
        front -> prev = nullptr;
      }
      delete temp;
      size--;
    }

    void delete_back(){
      Node* temp = back;
      back = back-> prev;
      if(empty()){
        cout << "Empty deque, no elements to delete"<< endl;
        return;
      }
      else if(back == nullptr) front = nullptr;
      else{
        back -> next = nullptr;
      }
      delete temp;
      size--;
    }

    int get_front(){
      if(empty()) return -1;
      return front -> data;
    }

    int get_back(){
      if(empty()) return -1;
      return back -> data;
    }

    void erase(){
      back = nullptr;
      while(front!= nullptr){
        Node* temp = front;
        front = front->next;
        free(temp);
      }
      size = 0;
    }

};

int main()
{
    Deque dq;
    cout << "Insert element '5' at rear end\n";
    dq.insert_back(5);

    cout << "Insert element '10' at rear end\n";
    dq.insert_back(10);

    cout << "Rear end element: "
        << dq.get_back() << endl;

    dq.delete_back();
    cout << "After deleting rear element new rear"
        << " is: " << dq.get_back() << endl;

    cout << "Inserting element '15' at front end \n";
    dq.insert_front(15);

    cout << "Front end element: "
        << dq.get_front() << endl;

    cout << "Number of elements in Deque: "
        << dq.Size() << endl;

    dq.delete_front();
    cout << "After deleting front element new "
        << "front is: " << dq.get_front() << endl;

    return 0;
}
