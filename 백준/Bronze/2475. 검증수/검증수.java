import java.util.*;
import java.io.*;
public class Main{
	public static void main(String args[]) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sum=0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			int a = Integer.parseInt(st.nextToken());
			sum += a * a;
		}
		System.out.println(sum%10);
	}
}