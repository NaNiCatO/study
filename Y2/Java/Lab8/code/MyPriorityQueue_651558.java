package Lab8.code;

public class MyPriorityQueue_651558 {
    MyMinHeap heap = new MyMinHeap();
    
    public void enqueue(int d) {
        if(!heap.isFull()){
            heap.insert(d) ;
        }
    }

    public int dequeue() {  
        return (!heap.isEmpty()) ? heap.remove() : -1;
    }

    public int front() {
        return heap.peek();
    }

    public boolean isFull() {
        return heap.isFull();
    }

    public boolean isEmpty() {
        return heap.isEmpty();
    }

    public String toString() {
        return heap.toString();
    }
}
