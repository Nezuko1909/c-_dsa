class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
    boolean checkBST(Node root) {
        return checkBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    boolean checkBST(Node node, int minValue, int maxValue) {
        if (node == null) {
            return true;
        }

        if (node.data <= minValue || node.data >= maxValue) {
            return false;
        }

        return checkBST(node.left, minValue, node.data) && checkBST(node.right, node.data, maxValue);
    }
}
