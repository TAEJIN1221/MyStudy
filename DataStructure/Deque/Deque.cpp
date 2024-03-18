// Deque(linked list)
using namespace std;

struct Node {
    int val;
    Node* next, * prev;

    Node(int v, Node* n, Node* p): val(v), next(n), prev(p) { }
};

class Deque {
    int size;
    Node* front, * rear;
public:
    Deque(): front(NULL), rear(NULL), size(0) { }

    void pushFront(int x) {
        Node* newNode = new Node(x, front, NULL);
        if (size == 0)
            rear = newNode;
        else
            front->prev = newNode;
        front = newNode;

        size++;
    }

    void pushBack(int x) {
        Node* newNode = new Node(x, NULL, rear);
        if (size == 0)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;

        size++;
    }

    int popFront() {
        if (size == 0)
            return -1;
        else {
            int result = front->val;
            Node* temp = front;
            if (size == 1)
                front = rear = NULL;
            else {
                front->next->prev = NULL;
                front = front->next;
            }

            delete temp;
            size--;

            return result;
        }
    }

    int popBack() {
         if (size == 0)
            return -1;
        else {
            int result = rear->val;
            Node* temp = rear;
            if (size == 1)
                front = rear = NULL;
            else {
                rear->prev->next = NULL;
                rear = rear->prev;
            }

            delete temp;
            size--;

            return result;
        }
    }

    int getSize() { return size; }

    int isEmpty() { return size == 0; }

    int getFront() {
        return (size ? front->val : -1);
    }

    int getBack() {
        return (size ? rear->val : -1);
    }
};
