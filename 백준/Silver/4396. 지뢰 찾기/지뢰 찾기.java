import java.io.*;
import java.util.*;

public class Main {

    static char[][] box = new char[11][11];
    static String[][] result = new String[11][11];
    static int[] dy = {1, 1, 1, 0, -1, -1, -1, 0};
    static int[] dx = {-1, 0, 1, 1, 1, 0, -1, -1};
    static int n = 0;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                box[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                result[i][j] = s.charAt(j) + "";
            }
        }
        boolean check = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (box[i][j] == '*' && check) {
                    result[i][j] = "*";
                } else if (result[i][j].equals("x") && box[i][j] == '*') {
                    result[i][j] = "*";
                    check = true;
                } else if (result[i][j].equals("x")) {
                    result[i][j] = check(i, j);
                }
            }
        }
        if(check) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(box[i][j] == '*') {
                        result[i][j] = "*";
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bw.write(result[i][j]);
            }
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }

    private static String check(int y, int x) {
        int s = 0;
        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n || box[ny][nx] == '.') continue;
            s++;
        }
        return Integer.toString(s);
    }

}