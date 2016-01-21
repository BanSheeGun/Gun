package main

import "fmt"

func main() {
    var a, b, c, x, y, z int
    fmt.Scanf("%d%d%d\n",&a,&b,&c);
    fmt.Scanf("%d%d%d\n",&x,&y,&z);
    aa := a - x
    if (aa > 0) {
        aa /= 2
    }
    bb := b - y
    if (bb > 0) {
        bb /= 2
    }
    cc := c - z
    if (cc > 0) {
        cc /= 2
    }

    ans := aa + bb + cc

    if ans >= 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}