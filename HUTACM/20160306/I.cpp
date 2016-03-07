#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

char aa[3], bb[3], cc[3], dd[3];
int a[5], t;
int f[5];

int change(char *a) {
    if (a[0] == 'A')
        return 1;
    if (a[0] == 'J')
        return 11;
    if (a[0] == 'Q')
        return 12;
    if (a[0] == 'K')
        return 13;
    if (a[1] == '\0')
        return a[0] - 48;
    return 10;
}

int dfs(int now, int sum) {
    int tmp;
    tmp = sum + f[now];
    if (now == 4) {
        if (tmp == 24) {
            t = 1;
            return 0;
        }
    } else dfs(now + 1, tmp);
    if (t) return 0;

    if (now != 1) {
        tmp = sum - f[now];
        if (now == 4) {
            if (tmp == 24) {
                t = 1;
                return 0;
            }
        } else dfs(now + 1, tmp);
        if (t) return 0;
    }


    if (now != 1) {
        tmp = sum * f[now];
        if (now == 4) {
            if (tmp == 24) {
                t = 1;
                return 0;
            }
        } else dfs(now + 1, tmp);
        if (t) return 0;
    }

    if (now != 1 && f[now] != 0)
        if (sum % f[now] == 0) {
            tmp = sum / f[now];
            if (now == 4) {
                if (tmp == 24) {
                    t = 1;
                    return 0;
                }
            } else dfs(now + 1, tmp);
        }

    return 0;
}

int check(int sum) {
    int tt;
    tt = f[3] + f[4];
    if (sum + tt == 24) {
        t = 1;
        return 0;
    }
    if (sum - tt == 24) {
        t = 1;
        return 0;
    }
    if (sum * tt == 24) {
        t = 1;
        return 0;
    }
    if (tt != 0)
        if (sum % tt == 0)
            if (sum / tt == 24) {
                t = 1;
                return 0;
            }

    tt = f[3] - f[4];
    if (sum + tt == 24) {
        t = 1;
        return 0;
    }
    if (sum - tt == 24) {
        t = 1;
        return 0;
    }
    if (sum * tt == 24) {
        t = 1;
        return 0;
    }
    if (tt != 0)
        if (sum % tt == 0)
            if (sum / tt == 24) {
                t = 1;
                return 0;
            }

    tt = f[3] * f[4];
    if (sum + tt == 24) {
        t = 1;
        return 0;
    }
    if (sum - tt == 24) {
        t = 1;
        return 0;
    }
    if (sum * tt == 24) {
        t = 1;
        return 0;
    }
    if (tt != 0)
        if (sum % tt == 0)
            if (sum / tt == 24) {
                t = 1;
                return 0;
            }

    if (f[4] == 0) return 0;
    if (f[3] % f[4] != 0) return 0;
    tt = f[3] / f[4];
    if (sum + tt == 24) {
        t = 1;
        return 0;
    }
    if (sum - tt == 24) {
        t = 1;
        return 0;
    }
    if (sum * tt == 24) {
        t = 1;
        return 0;
    }
    if (tt != 0)
        if (sum % tt == 0)
            if (sum / tt == 24) {
                t = 1;
                return 0;
            }

    if (f[4] == 0) return 0;
    return 0;
}

int ddd() {
    check(f[1]+f[2]);
    if (t == 1) return 0;
    check(f[1]-f[2]);
    if (t == 1) return 0;
    check(f[1]*f[2]);
    if (t == 1) return 0;
    if (f[2] != 0)
        if (f[1] % f[2] == 0)
    check(f[1] / f[2]);
    return 0;
}

int main() {
    while (~scanf("%s",aa)) {
        scanf("%s",bb);
        scanf("%s",cc);
        scanf("%s",dd);
        a[1] = change(aa);
        a[2] = change(bb);
        a[3] = change(cc);
        a[4] = change(dd);
        t = 0;
        for (int i = 1;i <= 4 && t == 0; ++i)
            for (int j = 1;j <= 4 && t == 0; ++j)
                if (i != j)
                    for (int k = 1;k <= 4 && t == 0; ++k)
                        if (k != i && k != j) {
                            f[1] = a[i];
                            f[2] = a[j];
                            f[3] = a[k];
                            f[4] = a[10 - i - j - k];
                            dfs(1, 0);
                            ddd();
                        }
        if (t) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
