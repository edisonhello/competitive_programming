import java.io.*;
import java.util.*;
import java.math.*;

public class Cryptopangrams {
// public class Solution {
    public static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int Ts = in.nextInt();
        for (int ts = 1; ts <= Ts; ++ts) {
            System.out.print("Case #" + ts + ": ");
            int x = in.nextInt();
            int n = in.nextInt();
            BigInteger c[] = new BigInteger[n + 9]; // original sequence
            for (int i = 1; i <= n; ++i) c[i] = in.nextBigInteger();
            BigInteger uc[] = new BigInteger[n + 9]; // uniqued sequence
            int uci = 1;
            uc[1] = c[1];
            for (int i = 2; i <= n; ++i) if (c[i].compareTo(c[i - 1]) != 0) {
                uci += 1;
                uc[uci] = c[i];
            }

            /* System.out.print("uci = " + uci + " : ");
            for (int i = 1; i <= uci; ++i) System.out.print(uc[i] + " ");
            System.out.println(""); */

            BigInteger pp[] = new BigInteger[n + 9]; // gcd sequence
            int ppi = 0;
            for (int i = 2; i <= uci; ++i) {
                ppi += 1;
                pp[ppi] = uc[i].gcd(uc[i - 1]);
            }

            /* System.out.print("ppi = " + ppi + " : ");
            for (int i = 1; i <= ppi; ++i) System.out.print(pp[i] + " ");
            System.out.println(""); */

            BigInteger spp[] = new BigInteger[n + 9]; // prime sequence
            int sppi = ppi;
            for (int i = 1; i <= ppi; ++i) spp[i] = pp[i];
            sppi += 1; spp[sppi] = uc[1].divide(pp[1]);
            sppi += 1; spp[sppi] = uc[uci].divide(pp[ppi]);

            /* System.out.print("sppi = " + sppi + " : ");
            for (int i = 1; i <= sppi; ++i) System.out.print(spp[i] + " ");
            System.out.println(""); */


            for (int i = 1; i < sppi; ++i) {
                for (int j = sppi - 1; j >= i; --j) {
                    if (spp[j].compareTo(spp[j + 1]) == 1) {
                        BigInteger tmp = spp[j];
                        spp[j] = spp[j + 1];
                        spp[j + 1] = tmp;
                    }
                }
            }

            /* System.out.print("sppi = " + sppi + " : ");
            for (int i = 1; i <= sppi; ++i) System.out.print(spp[i] + " ");
            System.out.println(""); */


            BigInteger uspp[] = new BigInteger[n + 9]; // uniqued prime sequence
            int usppi = 1;
            uspp[1] = spp[1];
            for (int i = 2; i <= sppi; ++i) if (spp[i].compareTo(spp[i - 1]) != 0) {
                usppi += 1;
                uspp[usppi] = spp[i];
            }

            /* System.out.print("usppi = " + usppi + " : ");
            for (int i = 1; i <= usppi; ++i) System.out.print(uspp[i] + " ");
            System.out.println(""); */

            
            if (usppi != 26) {
                System.out.println("usppi = " + usppi);
            }
            
            BigInteger cur = uc[1].divide(pp[1]);
            for (int i = 1; i <= usppi; ++i) {
                if (uspp[i].compareTo(cur) == 0) {
                    System.out.print((char)(i - 1 + 'A'));
                }
            }
            for (int i = 1; i <= n; ++i) {
                cur = c[i].divide(cur);
                for (int j = 1; j <= usppi; ++j) {
                    if (uspp[j].compareTo(cur) == 0) {
                        System.out.print((char)(j - 1 + 'A'));
                    }
                }
            }
            System.out.println("");
        }
    }
}
