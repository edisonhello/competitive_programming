import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        while (in.hasNext()) {
            BigInteger a = in.nextBigInteger();
            BigInteger b = in.nextBigInteger();
            System.out.println(a.multiply(b));
        }
    }
}
