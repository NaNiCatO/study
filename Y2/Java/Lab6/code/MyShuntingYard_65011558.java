package Lab6.code;

import java.util.StringTokenizer;

public class MyShuntingYard_65011558 {
    private static int order(String c) {
        return switch (c) {
            case "+", "-" -> 1;
            case "*", "/" -> 2;
            default -> 0;
        };
    }


    public static String infixToPostfix(String infixString) {
        MyQueueL_651558 queue = new MyQueueL_651558();
        MyStackL_651558 stack = new MyStackL_651558();
        String resultPostfixString = "";
        StringTokenizer st = new StringTokenizer(infixString);
        while (st.hasMoreTokens()) {
            String t = st.nextToken();
            if (MyRPN_651558.isNumeric(t))
                queue.enqueue(t);
            else if (t.equals("(")) {
                stack.push(t);
            } else if (t.equals(")")) {
                while (!stack.top().equals("(")){
                    queue.enqueue(stack.pop());
                }
                stack.pop(); //discard "("
            } else {
                if(!stack.isEmpty()) { // double lovely bug
                    /* your code */
                    while(!stack.isEmpty() && order(stack.top()) >= order(t) ){
                        queue.enqueue(stack.pop());
                    }
                }
                /* your code */
                stack.push(t);
            }
            System.out.println("current q = " + queue.dumpToString());
        }
        /* your code */
        while(!stack.isEmpty()){
            queue.enqueue(stack.pop());
        }
        System.out.println("current q = " + queue.dumpToString());
        resultPostfixString = queue.dumpToString();
        return resultPostfixString; //"happy coding";
    }
}
