#include<iostream>
using namespace std;

#define MAX 100

//definition of a Deque structure
class Deque{
  private :
    int arr[MAX];
    int front;
    int back;
    int size;
  public :
    Deque(int size){
      front = -1;
      back = 0;
      this -> size = size; 
    }

  bool full(){
    return (front == 0 and back == size-1) or front == back+1 ;
  }

  bool empty(){
    return front == -1;
  }

  void insert_front(int key){
    if(full()){
      cout << "Overflow" << endl;
      return;
    }
    if(front == -1 ){
      front = 0;
      back = 0;
    }
    else if(front == 0){
      front = size - 1;
    }
    else front -= 1;

    arr[front] = key;
  }

  void insert_back(int key){
    if(full()){
      cout << "Overflow!" << endl;
      return;
    }
    else if(front == -1){
      front = 0;
      back = 0;
    }
    else if (back == size -1){
      back = 0 ;
    }
    else back += 1;

    arr[back] = key;
  }

  void delete_front(){
    if(empty()){
      cout << "Deque is empty, no elements to delete" << endl;
      return;
    }
    //Deque with only one element
    else if (front == back){
      front = -1;
      back = -1;
    }
    else if (front == size -1) front = 0;
    else front += 1;
  }

  void delete_back(){
    if(empty()){
      cout << "Deque is empty, no elements to delete" << endl;
      return;
    }
    else if (front == back){
      front = -1;
      back = -1;
    }
    else if(back == 0) back = size - 1;
    else back -= 1;
  }

  int give_front(){
    if (empty()){
      cout << "Array is empty !" << endl ;
      return -1 ;
    }
    return arr[front];
  }

  int give_back(){
    if (empty()){
      cout << "Array is empty !" << endl ;
      return -1;
    }
    return arr[back];
  }
};

int main()
{
    Deque dq(5);
    cout << "Insert element at rear end  : 5 \n";
    dq.insert_back(5);

    cout << "insert element at rear end : 10 \n";
    dq.insert_back(10);

    cout << "get rear element " << " "
         << dq.give_back() << endl;

    dq.delete_back();
    cout << "After delete rear element new rear"
         << " become " << dq.give_back() << endl;

    cout << "inserting element at front end \n";
    dq.insert_front(15);

    cout << "get front element " << " "
         << dq.give_front() << endl;

    dq.delete_front();

    cout << "After delete front element new "
       << "front become " << dq.give_front() << endl;
    return 0;
}
