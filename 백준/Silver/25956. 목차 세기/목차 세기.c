#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int v[n]; //ex) v[1]은 제목 1 아래의 제목 2의 개수를 의미합니다. 즉 하위제목의 개수를 저장하는 배열입니다.
	int ans[n]; //답 (대입을 이용하니 초기화 하지 않아도 됩니다)
	int stack[n][2]; //스택 (대입을 이용하니 초기화 하지 않아도 됩니다)
	int cnt = 0; //스택의 position indicator
	int before = 0;
	
	for(int i=0; i<n; i++) { //n개 입력
        v[i] = 0; //이건 초기화 해주어야 합니다.
		int tmp;
		scanf("%d", &tmp); //입력
		
		if(!cnt || stack[cnt-1][0] <= tmp) { //스택이 비어있거나, 스택에서 가장 최근 것 보다 값이 같거나 더 클 때
			if(before+1 < tmp) { //입력이 잘못되었는지를 검사
				printf("-1");
				return 0;
			} 
			before = tmp; //갱신
            
            //스택에 집어넣기
			stack[cnt][0] = tmp;
			stack[cnt++][1] = i;
            
            //tmp은 tmp-1의 하위 제목입니다.
			v[tmp-1]++;
            
		} else { //스택에 요소가 있고, 스택에서 가장 최근 것보다 값이 작을 때
			before = tmp; //갱신
            
			while(cnt>0 && tmp <= stack[cnt-1][0]) { //스택보다 tmp의 값이 클 때까지 계속 스택의 요소들을 꺼냅니다.
				--cnt;
                int tmp2 = stack[cnt][0]; //스택에서 꺼낸 값의 값(제목)
				ans[stack[cnt][1]] = v[tmp2]; //답을 출력하는 배열에 스택에서 꺼낸 값의 값(제목)의 바로 아래 하위제목의 개수를 대입
				v[tmp2] = 0; //그런 다음 바로 아래 하위제목의 개수를 0으로 바꿈
			}
            
            //스택에 집어넣기
			stack[cnt][0] = tmp;
			stack[cnt++][1] = i;
            
            //tmp은 tmp-1의 하위 제목입니다
			v[tmp-1]++;
		}
	}
	
	while(cnt--) { //스택에 남은 값 꺼내기
        int tmp2 = stack[cnt][0]; //스택에서 꺼낸 값의 값(제목)
		ans[stack[cnt][1]] = v[tmp2]; //답을 출력하는 배열에 스택에서 꺼낸 값의 값(제목)의 바로 아래 하위제목의 개수를 대입
		v[tmp2] = 0; //그런 다음 바로 아래 하위제목의 개수를 0으로 바꿈
	}
	for(int i=0; i<n; i++) printf("%d\n", ans[i]); //입력받은대로 출력
}