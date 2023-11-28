package Lab3.pack3_ArrayLinkedList.code;

public class MyArrayBasic {
    protected int MAX_SIZE = 5;
    protected int data[] = new int[MAX_SIZE];
    protected int size = 0;

    public MyArrayBasic(int ...a) {
        if(a != null){
            //while(MAX_SIZE < a.length){
            //    expands();
            //}
            for(int i : a){
                add(i);
            }
        }
    }

    public void add(int d) {
        if(isFull()) expands();
        data[size++] = d;
    }

    public void insert(int d, int index) {
        for(int i=size; i>index; i--) {
        data[i] = data[i-1];
        }
        data[index] = d;
        size++;
    }

    public int find(int d) {
        int index=-1;
        for(int i=0; i<size; i++) {
            if(data[i]==d) {
                index = i;
                break;
            }
        }
        return index;
    }

    public int binarySearch(int d) {
        int a = 0, b = size-1;
        while(a <= b) {
            int m = (a+b)/2;
            if(data[m] == d) return m;
            if(d<data[m]) b = m-1;
            else a = m + 1; // d>data[m]
        }
        return -1;
    }

    public void delete(int index) {
        if(index < size){
        for(int i=index; i<size-1; i++) {
            data[i] = data[i+1];
        }
        size--;
        }
    }

    public boolean isFull() {
        return size==MAX_SIZE;
    }

    public boolean isEmpty() {
        return size==0;
    }

    void expands() { // version B
        MAX_SIZE = 2*MAX_SIZE;
        int newData[] = new int[MAX_SIZE];
        System.arraycopy(data,0,newData,0,size);
        data = newData;
        //System.gc();
    }
}
