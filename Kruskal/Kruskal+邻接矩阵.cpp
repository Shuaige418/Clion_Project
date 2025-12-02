#include <stdio.h>
#define inf 0x3f3f3f3f
const int N = 5010, M = 5e5 + 10;
int p[N];
int g[N][N];

struct edge {
    int x, y, w;
} e[M], temp[M];

void swapEdge(edge *a, edge *b) {
    edge t = *a;
    *a = *b;
    *b = t;
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (e[i].w < e[j].w) temp[k++] = e[i++];
        else temp[k++] = e[j++];
    while (i <= mid) temp[k++] = e[i++];
    while (j <= r) temp[k++] = e[j++];
    for (i = l, j = 0; i <= r; ++i, ++j) e[i] = temp[j];
}

void qsort(int l, int r) {
    if (l >= r) return;
    int k = e[l].w, i = l - 1, j = r + 1;
    while (i < j) {
        while (e[++i].w < k);
        while (e[--j].w > k);
        if (i < j) swapEdge(&e[i], &e[j]);
    }
    qsort(l, j);
    qsort(j + 1, r);
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void insert(int x, int y) {
    p[find(x)] = find(y);
}

int jud(int x, int y) {
    return find(x) == find(y);
}

int kruskal(int n, int m) {
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) p[i] = i;
    qsort(0, m - 1);
    for (int i = 0; i < m; ++i) {
        if (!jud(e[i].x, e[i].y)) {
            insert(e[i].x, e[i].y);
            ans += e[i].w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return ans;
}

int initEdge(int n) {
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (g[i][j] != inf) {
                e[idx].x = i;
                e[idx].y = j;
                e[idx].w = g[i][j];
                idx++;
            }
        }
    }
    return idx;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = inf;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = w;
        g[b][a] = w;
    }
    int new_m = initEdge(n);
    printf("%d\n", kruskal(n, new_m));
    return 0;
}

