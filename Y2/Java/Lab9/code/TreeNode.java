package code;



public class TreeNode {
    int data;
    TreeNode left, right, parent;
    
    public TreeNode(int d) {
        data = d;
    }
    
    @Override
    public String toString() {
        /* your code 6*/
        // There are 4 cases no child,
        if (left != null && right != null){
            //and both children
            return  left.data + "<-" + data + "->" + right.data;
        }else if (left != null){
            // left-child-only
            return  left.data + "<-" + data + "->null";
        }else if (right != null){
            // right-child-only
            return  "null<-" + data + "->" + right.data;
        }else{
            // no child
            return "null<-" + data + "->null";
        }
    }   
}