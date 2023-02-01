#include<cstdio>
#include<iostream>
//#include<malloc.h>
using namespace std;

template <class T>
class Node {
    public:
        T* val;
        Node* next;
        Node(){};
        Node(T val){
            //T *p = (T *)malloc(sizeof(T));
            T* p = new T(val);
            *p = val;
            this->val = p;
            this->next = NULL;
        }
        ~Node(){
            delete val;
            delete next;
        }

        void Add(T val){
            this->next = new Node(val);
        }
};

template <class T>
class ListNode{
    public:
        int length;
        Node<T>* node;
        ListNode(){};
        ListNode(T val){
            this->node = new Node<T>(val);
            length = 1;
        }
        ~ListNode(){
            delete length;
            delete node;
        }
        void Push(T val){
            int i = length;
                Node<T>* temp = node;
            while(--i){
                temp = temp->next;
            }
            temp->Add(val);
            length++;
        }
        void Poll(){
            this->node = this->node = this->node->next;
            length--;
        }

        T Peak(){
            return *(T *)this->node->val;
        }

        int Size(){
            return this->length;
        }

        bool IsEmpty(){
            if(this->node == NULL){
                return true;
            }else{
                return false;
            }
        }
        void Information(){
            Node<T>* temp = this->node;
            int i = 0;
            while(temp != NULL){
                cout << "第" << i << "个链表节点的值：";
                cout << *(T *)temp->val << endl;
                temp = temp->next;
                i++;
            }
        }
};
int main(){

    ListNode<string>* q = new ListNode<string>("asfd");
    q->Push("afdas");
    q->Push("asdfasf");
    q->Push("sdf");
    q->Push("sdf");
    q->Push("xfv");

    /*ListNode<int>* q = new ListNode<int>(-1);
    q->Push(2);
    q->Push(6);
    q->Push(3);
    q->Push(9);
    q->Push(4);*/

    /*head->Push(2);
    ListNode* temp = head;
    temp = temp->next;
    temp->Push(3);
    temp = temp->next;
    temp->Push(1);
    temp = temp->next;
    temp->Push(9);
    temp = temp->next;
    temp->Push(8);*/

    /*ListNode* pre = new ListNode(2);
    head->next = pre;
    ListNode* cur = new ListNode(4);

    pre->next = cur;
    pre = cur;

    cur = new ListNode(-5);

    pre->next = cur;
    pre = cur;*/


    q->Information();


    cout << "队列头的值：" << q->Peak() << endl;
    cout << "队列长度：" << q->Size() << endl;
    cout << "是否为空队列" << q->IsEmpty() << endl;

    cout << "--------------------" << endl;
    q->Poll();
    q->Poll();
    q->Poll();
    q->Information();
    /*temp = q->node;
    i = 0;
    while(temp != NULL){
        cout << "第" << i << "个链表节点的值：";
        cout << temp->GetVulue() << endl;
        temp = temp->next;
        i++;
    }*/
    cout << "队列头的值：" << q->Peak() << endl;
    cout << "队列长度：" << q->Size() << endl;
    cout << "是否为空队列" << q->IsEmpty() << endl;


    cout << "--------------------" << endl;
    q->Poll();
    q->Poll();
    q->Poll();
    q->Information();
    cout << "是否为空队列" << q->IsEmpty() << endl;
    return 0;
}
