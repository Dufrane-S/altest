import java.io.*;
import java.util.*;

public class Main {

    static Deque<Integer> list = new LinkedList<>();
    static int n;
    static int m;
    static int count = 0;
    static boolean check = false;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[] dp = new int[12];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i < 12; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        if (dp[n] < m) {
            System.out.println(-1);
        } else {
            dfs(0);

        }
    }

    static void dfs(int now) {
        if (check) return;

        if (now > n) return;
        if (now == n) {
            count++;
            if (count == m) {
                check = true;
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < list.size() - 1; i++) {
                    int tmp = list.pollFirst();
                    sb.append(tmp);
                    sb.append('+');
                    list.add(tmp);
                }
                int tmp = list.pollFirst();
                list.add(tmp);
                sb.append(tmp);
                System.out.println(sb);
            }
            return;
        }
        list.add(1);
        dfs(now + 1);
        list.pollLast();
        list.add(2);
        dfs(now + 2);
        list.pollLast();
        list.add(3);
        dfs(now + 3);
        list.pollLast();
    }

}
