package main

import "fmt"

func main() {
    var n int
    var m int
    var a int
    fmt.Scanf("%d%d%d\n",&n, &m, &a)
    nn := (n + a - 1) / a;
    mm := (m + a - 1) / a;
    ans := int64(nn) * int64(mm)
    fmt.Println(ans) 
}