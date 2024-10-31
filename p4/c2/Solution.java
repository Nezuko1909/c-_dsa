package p4.c2;

import java.util.*;


/**Linker list class */
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
};

/**My list */
class MyList {
    Node head;

    // constructor -> list empty
    public MyList() {
        this.head = null;
    }

    public void Add(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = newNode; 
        } else {
            Node curr = head;
            while (curr.next != null) {
                curr = curr.next;
            }
            curr.next = newNode;
        }
    }

    public void Insert(int pos, int val) {
        Node newNode = new Node(val);

        // if list empty and pos = 0
        if (pos == 0) {
            newNode.next = head;
            head = newNode;
            return;
        }

        Node curr = head;
        for (int i = 0; i < pos - 1; i++) {
            // Error: Invalid position
            if (curr == null) {
                return;
            }
            curr = curr.next;
        }

        // Insert
        newNode.next = curr.next;
        curr.next = newNode;
    }

    public void Delete(int pos) {
        // List empty
        if (head == null) {
            return;
        }

        if (pos == 0) {
            head = head.next;
            return;
        }

        Node curr = head;
        for (int i = 0; i < pos - 1; i++) {
            // Invalid pos
            if (curr == null || curr.next == null) {
                return;
            }
            curr = curr.next;
        }

        // Delete 
        curr.next = curr.next.next;
    }

    public void PrintList() {
        Node t = head;
        if (t == null) {
            return;
        }

        while (t != null) {
            System.out.print(t.data + " ");
            t = t.next;
        }
        System.out.println();
    }
};


public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in);
        int n;
        n = scanner.nextInt();
        
        MyList ml = new MyList();

        for (int i = 0; i < n; i++) {
            int newVal = scanner.nextInt();
            ml.Add(newVal);
        }
        
        int q;
        q = scanner.nextInt();
        while (q > 0) {
            String req = scanner.next();
            if (req.equals("Insert")) {
                int pos, val;
                pos = scanner.nextInt();
                val = scanner.nextInt();
                ml.Insert(pos, val);
            }
            if (req.equals("Delete")) {
                int pos = scanner.nextInt();
                ml.Delete(pos);
            }
            q--;
        }

        ml.PrintList();
        scanner.close();
    }
}


