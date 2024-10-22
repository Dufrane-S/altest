import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		
		long n = Long.parseLong(s);
		n--;
		
		s = br.readLine();
		StringTokenizer st = new StringTokenizer(s, " ");
		List<Long> road = new ArrayList<>(); 
		while(st.hasMoreTokens()) {
			road.add(Long.parseLong(st.nextToken()));
		}
		
		
		s = br.readLine();
		st = new StringTokenizer(s, " ");
		List<Long> gas = new ArrayList<>(); 
		while(st.hasMoreTokens()) {
			gas.add(Long.parseLong(st.nextToken()));
		}
		long gprice = 1000000001;
		long total = 0;
		long dis = 0;
		for (int i = 0; i < n; i++) {
			if (gas.get(i) < gprice) {
				gprice = gas.get(i);
				total += gprice * road.get(i);
			}
			else {
				total += gprice * road.get(i);
			}
		}
		System.out.println(total);
	}
}