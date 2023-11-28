package Lab3.pack3_ArrayLinkedList;

//import Java.Lab3.pack3_ArrayLinkedList.code.MyArrayBasic;
import Lab3.pack3_ArrayLinkedList.code.MyArray_651558;


public class L3_ArrayTesterPackX {
    public static void main(String[] args) {
    System.out.println("-demo4-----");
    myArray_demo4();
    System.out.println("-task2-----");
    task2();
    }

    static private void myArray_demo4() {
        MyArray_651558 demo = new MyArray_651558(5);
        demo.delete(0);
        demo.add(3);
        demo.add(7);
        demo.add(5);
        demo.add(4);
        demo.add(6);
        demo.add(1);
        System.out.println(demo);
    }

    static private void task2() {
        for (int N = 200_000; N <= 10 * 200_000; N += 200_000) {
            long start = System.currentTimeMillis();
            MyArray_651558 mArray = new MyArray_651558(N);
            for (int n = 1; n <N; n++){
                mArray.add((int)(Math.random()*1000));
            }
                long time = (System.currentTimeMillis() - start);
                System.out.println(N + "\t\t" + time);
        }
        System.out.println("with expansion");
        for (int N = 200_000; N <= 10 * 200_000; N += 200_000) {
            long start = System.currentTimeMillis();
            MyArray_651558 mArray = new MyArray_651558();
            for (int n = 1; n <N; n++){
                mArray.add((int)(Math.random()*1000));
            }
                long time = (System.currentTimeMillis() - start);
                System.out.println(N + "\t\t" + time);
        }
    }
}
