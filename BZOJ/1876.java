/**************************************************************
    Problem: 1876
    User: Gunpowder
    Language: Java
    Result: Accepted
    Time:1852 ms
    Memory:16540 kb
****************************************************************/
 
import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger a = scan.nextBigInteger();    
        BigInteger b = scan.nextBigInteger();
        BigInteger c = a.gcd(b);
        System.out.println(c);
    }
}