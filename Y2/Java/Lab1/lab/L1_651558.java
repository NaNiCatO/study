import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;


public class L1_651558 {
    public static void main(String[] args) {
    q1();
    q2();
    q3();
    q4();
    q5();
    }
/* q1() – q5() */
    
    static void q1() { 
        System.out.println("-q1----");
        List<String> listA = new ArrayList<>(Arrays.asList("lilly","tulip","daisy"));
        List<String> listB = Arrays.asList("pomeranian", "terrier", "jack", "beagle");
        /* your code 1 */
        listA.addAll(listB);

        System.out.println(listA); System.out.println(listB);
    }

    static void q2() { 
        System.out.println("\n\n-q2----");
        ArrayList<String> listA = new ArrayList<>(
        Arrays.asList("pomeranian", "terrier", "jack", "beagle"));
        List<String> listB = Arrays.asList("lilly","tulip","daisy");
        ArrayList<String> q1List = null;
        /* your code 2 */
        q1List = new ArrayList<>(listA) ;
        q1List.addAll(listB);

        System.out.println(listA);
        System.out.println(listB);
        System.out.println(q1List);
    }

    static void q3() {
        System.out.println("\n\n-q3----");
        ArrayList<Dog> q3List = new ArrayList<>();
        q3List.add(new Dog("jack")); q3List.add(new Dog("terrier"));
        System.out.println("snapshot 1 " + q3List);
        add(q3List, new Dog("pomeranian"));
        System.out.println("snapshot 2 " + q3List);
        add(q3List,new Dog("jack"));
        System.out.println("snapshot 3 " + q3List);
        add(q3List,new Dog("beagle"));
        System.out.println(q3List);
        }
    private static void add( ArrayList<Dog> list, Dog d ) {
        /* your code 3 */
        boolean is_new = true; 
        for (Dog i : list) {
            if(i.equals(d)){
                is_new = false;
            }
        }
        if(is_new){
            list.add(d);
        }
    }

    static void q4() {
    System.out.println("\n\n-q4----");
    ArrayList<String> listA = new ArrayList<>(Arrays.asList("jack","pomeranian", "terrier", "jack", "beagle"));
    ArrayList<String> listB = removeDuplicates(listA);
    listA = removeDuplicates(listA);
    System.out.println(listA);
    System.out.println(listB);
    }
    private static ArrayList<String> removeDuplicates(List<String> list) {
        /* your code 4.1 */
        HashSet<String> nondup = new HashSet<>(list);
        return new ArrayList<>(nondup) /* your code 4.2 */;
    }

    static void q5() { 
        System.out.println("\n\n-q5----");
        List<String> listA = Arrays.asList("pomeranian", "terrier", "jack", "beagle",
        "pomeranian" , "beagle",
        "jack", "beagle");
        HashMap<String,Integer> q5map = new HashMap<>();
        String key;
        for (int i = 0; i < listA.size(); i++) {
            key = listA.get(i);
            q5map.put(key, ((q5map.get(key) == null) ? 1 : q5map.get(key)+1/* your code 5 */));
        }
        System.out.println(q5map);
        }
}



