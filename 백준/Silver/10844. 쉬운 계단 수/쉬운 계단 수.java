import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[][] list = new int[101][10];
        for (int i = 1; i < 10; i++) {
            list[1][i] = 1;
        }
        for (int i = 2; i < 101; i++) {
            for (int j = 1; j < 9; j++) {
                list[i][j] = (list[i - 1][j - 1] % 1000000000 + list[i - 1][j + 1] % 1000000000) % 1000000000;
            }
            list[i][0] = list[i - 1][1] % 1000000000;
            list[i][9] = list[i - 1][8] % 1000000000;
        }
        int answer = 0;
        for (int k : list[N]) {
            answer += k;
            answer = answer % 1000000000;
        }
        System.out.println(answer);
        
    }
}