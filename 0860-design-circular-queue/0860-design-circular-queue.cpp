class MyCircularQueue {
public:
    vector<int> q;
    int cap;
    int index = 0;
    MyCircularQueue(int k) {
        q.resize(k);
        cap = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[index++] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        for(int i = 0; i < q.size() - 1; i++) q[i] = q[i+1];
        index--;
        return true; 
    }
    
    int Front() {
        if(isEmpty()) return - 1;
        return q[0];
    }
    
    int Rear() {
        if(isEmpty()) return - 1;
        return q[index-1];
    }
    
    bool isEmpty() {
        return index==0;
    }
    
    bool isFull() {
        return index>=cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */