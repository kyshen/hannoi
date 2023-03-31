#include <cstdio>
#include <stack>

using namespace std;

class Tower {
private:
    int _n; // numbers of hannoi
    int _N; // numbers of times

    void _Hannoi(int n, int from, int to) {
        int mi;
        for (int i = 0; i < 3; i++) {
            if (from != i && to != i) mi = i;
        }
        if (n == 0) return;
        if (n == 1) {
            _move(from, to);
        }
        else {
            _Hannoi(n - 1, from, mi);
            _move(from, to);
            _Hannoi(n - 1, mi, to);
        }
    }

    void _move(int from, int to) {
        towers[to].push(towers[from].top());
        towers[from].pop();
        ++times;
    }

public:
    stack<int> *towers = new stack<int>[3];
    int times;

    Tower(int n = 3) {
        _n = n;
        _N = 2^n - 1;
        times = 0;
        for (int i = _n - 1; 0 <= i; i--) towers[0].push(i);
    }

    void Hannoi() {_Hannoi(_n, 0, 2);}

    void showTowers() {
        stack<int> *twrs = new stack<int>[3];
        printf("Towers[size=%d times=%d]:\n", _n, times);
        for (int i = 0; i < 3; i++) {
            twrs[i] = towers[i];
            printf("[%d]\t", i);
            while (!twrs[i].empty()) {
                printf("%d ", twrs[i].top());
                twrs[i].pop();
            }
            printf("\n");
        }
        printf("\n");
        delete [] twrs;
    }

    ~Tower() { delete [] towers; }
};

int main() {
    int n;
    printf("请输入塔数：");
    scanf("%d", &n);
    if (n <= 0) {
        printf("你这是什么意思?\n");
        return 0;
    }
    Tower T(n);
    T.showTowers();
    T.Hannoi();
    T.showTowers();
}