package main

import "fmt"

func main() {
    var n int64
    var ans, m, t, i int64
    var a [200]int64
    fmt.Scanf("%v\n",&n)
    for i = 1; i <= n; i++ {
        fmt.Scanf("%v",&a[i])
    }

    t = 1
    ans = 1
    for a[t] == 0 {
        t = t + 1
        if t == n+2 {
            ans = 0
            break
        }
    }
    m = 0;
    for i = t; i <= n; i++ {
        if a[i]==1 {
            ans = ans * (m + 1)
            m = 0
        } else {
            m = m + 1
        }
    }
    fmt.Println(ans) 
}