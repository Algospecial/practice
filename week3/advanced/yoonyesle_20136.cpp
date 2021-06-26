#include <iostream>
#include <queue>
using namespace std;

void print_queue(priority_queue<pair<int, int>> q){
	while (!q.empty()) {
		printf("%d %d, ", q.top().first, q.top().second); q.pop();
	}
	printf("\n");
}

int main() {
	int n, k, index[500001], cur = 0, cnt = 0;
	bool visit[500001] = {false};
	scanf("%d%d", &n, &k);
	queue<int> next_index[500001];
	for (int i = 0; i < k; ++i) {
		scanf("%d", &index[i]);
		next_index[index[i]].push(i);
	}
	if (n >= k) {
		printf("0"); return 0;
	}
	for (int i = 1; i <= k; ++i)
		next_index[i].push(500001);
	priority_queue<pair<int, int>> q;
	int flag = 0;
	for (; flag < n && cur < k; ++cur) {
		next_index[index[cur]].pop();
		if (!visit[index[cur]])
			++flag;
		visit[index[cur]] = true;
	}
	for (int i = 1; i <= k; ++i)
		if (visit[i])
			q.push({next_index[i].front(), i});
	--cur;
	//print_queue(q); printf("%d\n", cur);
	while (++cur < k) {
		next_index[index[cur]].pop();
		//print_queue(q);
		//printf("%d: %d %d, %d ->%d\n", cur, q.top().second, index[cur], next_index[q.top().second].front(), cnt);
		if (visit[index[cur]]) {
			q.push({next_index[index[cur]].front(), index[cur]});
			continue;
		}
		visit[q.top().second] = false;
		q.pop();
		q.push({next_index[index[cur]].front(), index[cur]});
		visit[index[cur]] = true;
		++cnt;
	}
	//print_queue(q);
	printf("%d", cnt);
	return 0;
}
