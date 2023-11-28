package Lab3.pack3_ArrayLinkedList.code;

public class MyLinkedList_651558 {
    public class Node {
        int data;
        Node next;
        public Node(int d) {
            data = d;
        }

        private int size(){
            int max = 0;
            Node p = head;
            while(p!=null) {
                p = p.next;
                max++;
            }
            return max;
        }

    }
    Node head = null;

    public String toString() {
        StringBuffer sb = new StringBuffer("head ");
        Node p = head;
        while(p!=null) {
            sb.append("--> [");
            sb.append(p.data);
            sb.append("] ");
            p = p.next;
        }
        sb.append("-> null");
        return new String(sb);
    }

    public int getAt(int i) {
        Node p = head;
        while(i>0) {
            p = p.next;
            i--;
        }
        return p.data;
    }

    public void setAt(int d, int i) {
        Node p = head;
        while(i>0) {
            p = p.next;
            i--;
        }
        p.data = d;
    }

    public void add(int d) {
        Node p = new Node(d);
        p.next = head;
        head = p;
    }

    public void insert(int d) {
        Node q = new Node(d);
        Node p = head;
        if(p == null || p.data >= q.data){
            add(d);
        }
        else{
            while(p.next != null){
                if(p.next.data >= q.data){
                    break;
                }
                p = p.next;
            }
            if(p.next != null) q.next = p.next;
            p.next = q;
        }
    }

    public void delete(int d) {
        Node p = head;
        if(p.data == d){
            head = p.next;
        }
        else{
            while(p != null){
                if(p.next == null || p.next.data == d){
                    break;
                }
                p = p.next;
            }
            if(p.next != null) p.next = p.next.next;
        }
    }

    public int find(int d) {
        int index = 0;
        Node p = head;
        while(p!=null) {
            if(p.data==d) return index;
            index++;
            p = p.next;
        }
        return -1;
    }

    public void add(int [] d){
        for (int i = 0; i < d.length; i++) {
            Node p = new Node(d[(d.length-1)-i]);
            p.next = head;
            head = p;
        }
    }

    public void insert(int [] d){
        int max_index = d.length ;
        for (int i = 0; i < max_index; i++) {
            insert(d[i]);
        }
    }
    
    public void q1_rotate_clockwise(int k){
        Node p = head;
        Node temp = head;
        int max_size = head.size();
        if(k <= 5){
            for (int j = 0; j < max_size-1; j++){
                p = p.next;
            }
            for (int i = 0; i < k; i++) {
                p.next = temp;
                temp = temp.next;
                p = p.next;
                head = temp;
            }
        p.next = null;
        }
    }

    public void q2_reverse(){
        Node p = head;
        Node temp = head;
        int max_size = head.size();
        for (int j = 0; j < max_size-1; j++){
            p = p.next;
        }
        for (int i = 0; i < max_size-1; i++){
            head = temp.next;
            if(i == 0){
                temp.next = null;
            } else{
                temp.next = p.next;
            }
            p.next = temp;
            temp = head;
        }
    }

    public void q3_remove_dup(){
        int temp;
        int max_size = head.size();
        Node p = head;
        for (int i = 0; i < max_size-1; i++){
            p = head;
            temp = p.data;
            for (int j = 0; j < max_size-1; j++){
                p = p.next;
                if(temp == p.data){
                    delete(temp);
                    max_size = head.size();
                }
            }
        }
    }

    public void q4_increment_digits(){
            Node p = head;
            while(p!=null) {
                p.data++;
                if(p.data > 9){
                    p.data = 0;
                }
                p = p.next;
            }
    }
    
    public boolean q5_isPalindrome(){
        Node f = head;
        Node b ;
        int max_size = head.size();
        boolean result = true;
        for(int i = 0; i < ((max_size-1)/2); i++){
            b = head;
            for(int j = 0; j < ((max_size-1)-i); j++){
                b = b.next;
            }
            if(f.data != b.data){
                result = false;
                break;
            }
            f = f.next;
        }
        return result;
    }
}


