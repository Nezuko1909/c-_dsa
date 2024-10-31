package p4.c3;

import java.util.Scanner;

class ArrList {
    int arr[];
    int size;
    ArrList(int size) {
        this.size = size;
        this.arr = new int[size];
    }
}

public class Solution {
    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);
        int LineCount = scanner.nextInt();
        ArrList[] MyList = new ArrList[LineCount];

        for (int i = 0; i < LineCount; i++) {
            int size = scanner.nextInt();
            if (size == 0) {
                continue;
            }

            ArrList newArr = new ArrList(size);
            for (int j = 0; j < newArr.size; j++) { 
                newArr.arr[j] = scanner.nextInt();
            }
            MyList[i] = newArr;
        }
        
        int req = scanner.nextInt();
        while(req > 0) {
            int line = scanner.nextInt();
            int x = scanner.nextInt();
            line--;
            x--;

            if (line < 0 || line >= LineCount || MyList[line] == null) {
                System.out.println("ERROR!");
            }
            else if (x < 0 || x >= MyList[line].size) {
                System.out.println("ERROR!");
            } else {
                System.out.println(MyList[line].arr[x]);
            }

            req--;
        }
        scanner.close();
    }
}

/*Example test case:
5
5 41 77 74 22 44
1 12
4 37 34 36 52
0
3 20 22 33
5
1 3
3 4
3 1
4 3
5 5

Expected Output:
74
52
37
ERROR!
ERROR!

 */