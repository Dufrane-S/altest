import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<dot> list = new ArrayList<dot>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            list.add(new dot(y, x));
        }
        list.sort(new Comparator<dot>() {
            @Override
            public int compare(dot o1, dot o2) {
                if (o1.x != o2.x) {
                    return Integer.compare(o1.x, o2.x);
                }
                return Integer.compare(o1.y, o2.y);
            }
        });
        for (dot i : list) {
            System.out.println(i.x + " " + i.y);
        }
    }
}

class dot {
    int y;
    int x;
    public dot(int y, int x) {
        this.y = y;
        this.x = x;
    }
}