import java.io.*;
import java.util.*;

public class Main {

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		String s = br.readLine();
		st = new StringTokenizer(br.readLine());
		int[] check = new int[4];
		int[] count = new int[4];
		for (int i = 0; i < 4; i++) {
			count[i] = Integer.parseInt(st.nextToken());
		}
		Deque<Character> dq = new ArrayDeque<>();
		int answer = 0;
		for (int i = 0; i < s.length(); i++) {
			char next = s.charAt(i);
			if (next == 'A') {
				check[0]++;
			} else if (next == 'C') {
				check[1]++;
			} else if (next == 'G') {
				check[2]++;
			} else if (next == 'T') {
				check[3]++;
			}
			dq.addLast(next);
			if (dq.size() > m) {
				char del = dq.pollFirst();
				if (del == 'A') {
					check[0]--;
				} else if (del == 'C') {
					check[1]--;
				} else if (del == 'G') {
					check[2]--;
				} else if (del == 'T') {
					check[3]--;
				}
			}
			if(dq.size()==m && check[0]>=count[0] && check[1]>=count[1] && check[2]>=count[2]&& check[3]>=count[3]) {
				answer++;
			}
		}
		System.out.println(answer);
	}
}