//65011558 Suvijuk Samitimata
package code;

public class BST {
    TreeNode root;
    
    public BST() { root = null; }
    
    public TreeNode getRoot() {
        return root;
    }
    
    public void insert(int d) {
        if (root == null) {
            root = new TreeNode(d);
        } else {
            TreeNode cur = root;
            while (cur != null) {
                if (d < cur.data) {
                    if (cur.left != null)
                        cur = cur.left;
                    else {
                        /* your code 1*/
                        cur.left = new TreeNode(d);
                        cur.left.parent = cur;
                        return;
                    }
                } else { //! (d < p.data)
                    if (cur.right != null)
                        /* your code 2*/
                        cur = cur.right;
                    else {
                        cur.right = new TreeNode(d);
                        cur.right.parent = cur;
                        return;
                    }
                }
            } //while
        }
    } //insert by iteration


    public void printPreOrder() {
        printPreOrderRecurse(root);
    }

    
    private void printPreOrderRecurse(TreeNode node) {
        if(node==null) return;
        System.out.print(node.data+" ");
        printPreOrderRecurse(node.left);
        printPreOrderRecurse(node.right);
    }   


    public void printInOrder() {
        printInOrderRecurse(root);
    }

    private void printInOrderRecurse(TreeNode node) {
        if(node==null) return;
        printInOrderRecurse(node.left);
        System.out.print(node.data+" ");
        printInOrderRecurse(node.right);
    }   


    public void printPostOrder() {
        printPostOrderRecurse(root);
    }
    
    private void printPostOrderRecurse(TreeNode node) {
        if(node==null) return;
        printPostOrderRecurse(node.left);
        printPostOrderRecurse(node.right);
        System.out.print(node.data+" ");
    }  


    public TreeNode search(int d) {
        TreeNode result = searchRecurse(d, root);
        return result;
    }

    public TreeNode searchRecurse(int d, TreeNode n) {
        if (n == null) return null;
        if (d == n.data) return n;
        /* your code 7*/
        if (d < n.data){
            return searchRecurse(d, n.left);
        }
        return searchRecurse(d, n.right);
    }

    public TreeNode searchIter(int key) {
        if (root.data == key)
            return root;
        TreeNode current = root;
        while (current != null) {
            if (key < current.data) {
                if (current.left != null)
                    current = current.left;
            } else {
                if (current.right != null)
                    current = current.right;
            }
            if (current.data == key)
                return current;
            
            /* your code 8 */
            if(current.left == null && current.left == null){
                return null;
            }
        } //while
        return null;
    }

    public int height() {
        return root == null ? 0 : height(root);
    }
          
    public int height(TreeNode node) {
        if (node == null)
            return 0;
        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public TreeNode findMaxFrom(TreeNode subtreeHead) {
        /* your code 10 */
        TreeNode current = subtreeHead;
        while(current.right != null){
            current = current.right;
        }
        return current;
    }


    public void delete(int d, TreeNode current) {
        if (current == null) return; //not found
        if (d < current.data)
            delete(d, current.left);
        else if (d > current.data)
            delete(d, current.right);
        else { //found ... time to delete
            if (current.left == null || current.right == null) { // 0 or 1 child
                TreeNode q = (current.left == null) ? current.right : current.left;
                if (current.parent.left == current)
                    current.parent.left = q; //this node is left child
                else
                    current.parent.right = q;
                
                if (q != null) q.parent = current.parent;
            }else { // two children
                TreeNode q = findMaxFrom(current.left);
                /* your code 11 */
                delete(q.data, current.left);
                if(current.parent.left==current)
                    current.parent.left = q;
                else
                    current.parent.right = q;
                q.left = current.left;
                q.right = current.right;
            }// two children
        } //found
    }
}
