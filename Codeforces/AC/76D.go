package main

import(
    "fmt"
)

func main(){
    var a uint64
    var b uint64
    fmt.Scanf("%d\n", &a)
    fmt.Scanf("%d\n", &b)
    if (a-b) % 2 == 1 {
        fmt.Println("-1")
    } else {
        fmt.Printf("%d %d\n", (a-b)/2, a-(a-b)/2)
    }
}
