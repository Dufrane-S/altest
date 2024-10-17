import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		
		//int box[][]=new int [n][n];
		ArrayList<Integer>[] box = new ArrayList[n];
		for(int i=0;i<n;i++) {
			box[i]= new ArrayList<Integer>();
		}
		Boolean done[]=new Boolean [n];
		for(int i=0;i<n;i++) {
			done[i]=false;
		}
		for(int i=0;i<m;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			box[a].add(b);
			box[b].add(a);
		}

		Queue<Integer>q = new LinkedList<>();
		done[0]=true;
		q.add(0);
		int answer=-1;
		while(!q.isEmpty()) {
			int now = q.poll();
			answer++;
			for(int i:box[now]) {
				if(done[i]==false) {
					q.add(i);
					done[i]=true;
				}
			}
			
		}
		System.out.println(answer);
	}
}
