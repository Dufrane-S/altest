import java.util.*;
import java.io.*;

public class Main{
	public static void main(String args[]) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(br.readLine());
		int answer=0;
		while(st.hasMoreTokens()) {
			st.nextToken();
			answer++;
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(Integer.toString(answer));
		bw.flush();
		bw.close();
		
	}
}