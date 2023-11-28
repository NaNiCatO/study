package Lab3.pack3_ArrayLinkedList.code;

public class MyArray_651558 extends MyArrayBasic{
    protected int data[];
    protected int size = 0;

    public MyArray_651558(){
        MAX_SIZE = 100_000;
        data = new int[MAX_SIZE];
    }

    public MyArray_651558(int max) {
        MAX_SIZE = max;
        data = new int[MAX_SIZE];
    }

    public boolean isFull(){
        if(size >= MAX_SIZE) return true;
        return false;
    }

    public boolean isEmpty(){
        if(size == 0) return true;
        return false;
    }

    public int[] expandByK(int k){
        MAX_SIZE = 2*MAX_SIZE;
        int newData[] = new int[MAX_SIZE];
        System.arraycopy(data,0,newData,0,size);
        data = newData;
        return newData;
        //System.gc();
    }

    int[] expand(){
        return expandByK(2);
    }
    
    @Override
    public void add(int d) {
        if (isFull()){
            data = expand();
        }
        data[size] = d;
        size++;
    }
}
