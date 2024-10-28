import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		LinkedList<Integer> list = new LinkedList();
		for(int i=1;i<=n;i++) {
			list.addLast(i);
		}
		while(list.size()>1) {
			list.removeFirst();
			list.addLast(list.removeFirst());
		}

		System.out.println(list.get(0));
	}
}
