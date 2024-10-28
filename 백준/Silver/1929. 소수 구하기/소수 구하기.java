import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws Exception {

		boolean [] list = new boolean[1000001];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=2;i<=m;i++) {
			if(!list[i]) {
				for(int j=2;j*i<=m;j++) {
					list[i*j]=true;
				}
			}
		}
		list[1]=true;
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i=n;i<=m;i++) {
			
			if(!list[i]) {bw.write(Integer.toString(i));bw.write('\n');}
		}
		bw.flush();
		bw.close();
	}

}
