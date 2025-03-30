import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long [] list = new long[n];
		long [] dp = new long [n];
		
		for(int i=0; i<n; i++) {
			list[i]= Integer.parseInt(br.readLine());
		}
		if(n==1){
		    System.out.println(list[0]);
		    return;
		}else if(n==2){
		    System.out.println(list[0]+list[1]);
		    return;
		}
		dp[0]=list[0];
		dp[1]=list[0]+list[1];
		dp[2]=list[0]+list[2];
		if(dp[2]<list[2]+list[1])dp[2]=list[2]+list[1];
		for(int i=3; i<n; i++) {
			long b =dp[i-2]+list[i];
			long a=list[i]+list[i-1]+dp[i-3];
			if(a>b) {
				dp[i]=a;
			} else {
				dp[i]=b;
			}
		}
        System.out.println(dp[n-1]);
	}
}