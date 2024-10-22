import java.util.*;
import java.io.*;
public class Main{
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=1;i<=9;i++) {
			//System.out.println(n + " * "+i+" = "+n*i);
			//bw.write(n + " * "+i+" = "+n*i);
			//bw.newLine();
			StringBuilder sb = new StringBuilder();
			sb.append(n);
			sb.append(" * ");
			sb.append(i);
			sb.append(" = ");
			sb.append(n*i);
			bw.write(sb.toString());
			bw.newLine();
		}
		bw.flush();
		bw.close();
	}
}