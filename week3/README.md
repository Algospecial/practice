# Week3 - Priority Queue, Dijkstra

## 1. date
- basic : 6/22 08:00 ~ 11:50
- advance: 6/25 08:00 ~ 11:00

## 2. what we tried
### basic   
1. [1715/카드 정렬하기](https://www.acmicpc.net/problem/1715) - G4
2. [1445/일요일 아침의 데이트](https://www.acmicpc.net/problem/1445) - G2
3. [13308/주유소](https://www.acmicpc.net/problem/13308) - G1

### advance   
1. [1854/K번째 최단경로 찾기](https://www.acmicpc.net/problem/1854) - P5   
2. [20136/멀티탭 스케줄링 2](https://www.acmicpc.net/problem/20136) - P5

## 3. etc
<details>
<summary>김도은</summary>
<div markdown="1">       

1. [1445] 일요일 아침의 데이트 
	* 우선순위 큐에서 확인한 것을 pop하지 않아 틀림
	* 쓰레기 주변 지역에 수를 부여할 때 아무것도 없는 지역에만 부여해야 하는데 조건을 잘못 설정함

</div>
</details>
<details>
<summary>윤예슬</summary>
<div markdown="1">       
1. [20136] 멀티탭 스케줄링 2 
	* 이미 멀티탭에 있는 경우 큐에 있는 원소를 수정하는 대신 정보가 갱신된 새로운 원소를 push 해주도록 하였으나 멀티탭에 자리가 아직 남은 경우 같은 전자제품을 여러 개 꼽게 됨. 따라서 먼저 전자제품 n개를 멀티탭에 꼽아두고 시작.


</div>
</details>

<details>
<summary>채정아</summary>
<div markdown="1">       

1. [13308] 주유소 
	* 각 도시 별 주유소 금액 중 최소를 우선순위 큐에 넣지 않고 이미 지나온 도시 번호를 넣어서 틀렸음
2. [1854] k번째 최단경로 찾기   
	* 거리를 저장하는 큐를 우선순위 큐로 하지 않고 k번째 원소에 접근해 답을 찾으려 해서 틀렸음  
</div>
</details>
