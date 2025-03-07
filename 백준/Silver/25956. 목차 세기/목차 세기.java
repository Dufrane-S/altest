import java.io.*;
import java.util.*;

public class Main {
    // 스택에 저장할 항목 클래스
    static class StackItem {
        int level;  // 제목 수준
        int index;  // 해당 제목의 인덱스

        StackItem(int level, int index) {
            this.level = level;
            this.index = index;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        int[] v = new int[n+1];       // 하위 제목 개수 저장 배열
        int[] answers = new int[n]; // 결과 배열
        Deque<StackItem> stack = new ArrayDeque<>(); // ArrayDeque를 스택으로 사용 (성능상 이점)
        int before = 0;
        
        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(br.readLine());  // 입력
            
            if (stack.isEmpty() || stack.peek().level <= tmp) {  // 스택이 비었거나, 스택 최상단 값보다 입력 값이 크거나 같을 때
                if (before + 1 < tmp) {  // 입력값 검증
                    System.out.println("-1");
                    return;
                }
                before = tmp;  // 이전 값 갱신
                
                // 스택에 추가
                stack.push(new StackItem(tmp, i));
                
                // tmp는 tmp-1의 하위 제목
                if (tmp > 0) {
                    v[tmp - 1]++;
                }
            } else {  // 스택이 비어있지 않고, 스택 최상단 값보다 입력 값이 작을 때
                before = tmp;  // 이전 값 갱신
                
                // 스택 최상단 값이 tmp보다 크거나 같을 동안 스택에서 요소 제거
                while (!stack.isEmpty() && tmp <= stack.peek().level) {
                    StackItem item = stack.pop();
                    answers[item.index] = v[item.level]; // 결과 배열에 저장
                    v[item.level] = 0;  // 하위제목 개수 초기화
                }
                
                // 스택에 추가
                stack.push(new StackItem(tmp, i));
                
                // tmp는 tmp-1의 하위 제목
                if (tmp > 0) {
                    v[tmp - 1]++;
                }
            }
        }
        
        // 남은 스택 요소 처리
        while (!stack.isEmpty()) {
            StackItem item = stack.pop();
            answers[item.index] = v[item.level];
            v[item.level] = 0;
        }
        
        // 결과 출력
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(answers[i]).append("\n");
        }
        System.out.print(sb);
    }
}
