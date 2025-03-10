import java.util.*;
import java.io.*;
public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n= Integer.parseInt(br.readLine());
		int [] array = new int [n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++){
		    array[i]=Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		long answer = 0;
		for(int k : array){
		    k-=b;
		    answer++;
		    if(k<=0){
		        continue;
		    }else if(k%c==0){
		        answer+=k/c;
		    }else{
		        answer+=(k/c+1); 
		    }
		}
		System.out.println(answer);
	}
}
