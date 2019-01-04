import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class B {
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        long b = in.nextLong();
        int ans = 0;
        for (long i = 1; i * i <= b; ++i) {
            if (b % i == 0) {
                ++ans;
                if (i * i != b) ++ans;
            }
        }
        System.out.println(ans);
    }
}
