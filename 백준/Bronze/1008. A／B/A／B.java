import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		double n = Integer.parseInt(st.nextToken());
		double m = Integer.parseInt(st.nextToken());
		System.out.println(n/m);
	}
}