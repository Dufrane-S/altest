import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String s = br.readLine();
		char[] list = new char[s.length()];
		for (int i = 0; i < s.length(); i++) {
			list[i] = s.charAt(i);
		}
		for (int i = 1; i < n; i++) {

			s = br.readLine();
			for (int j = 0; j < s.length(); j++) {
				if(list[j]!=s.charAt(j)) {
					list[j]='?';
				}
			}
		}
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i=0;i<s.length();i++) {
			bw.write(list[i]);
		}
		bw.flush();
		bw.close();
	}
}