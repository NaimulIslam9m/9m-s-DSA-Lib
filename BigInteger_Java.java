import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    static FastReader in = new FastReader();
    public static void main(String[] args) {
        BigInteger a, b;
        a = new BigInteger(in.next());
        b = new BigInteger(in.next());

        System.out.println("Add: " + a.add(b));
        System.out.println("Sub: " + a.subtract(b));
        System.out.println("Mul: " + a.multiply(b));
        System.out.println("Div: " + a.divide(b));
        System.out.println("Mod: " + a.mod(b)); // b must be positive (b > 0)
        System.out.println("Mod: " + a.remainder(b));
        System.out.println("Abs: " + a.abs());
        System.out.println("");

        if (a.compareTo(b) > 0) // a >= b
            System.out.println("greter");
        if (a.compareTo(b) < 0) // a <= b
            System.out.println("lesser");
        if (a.compareTo(b) == 0)
            System.out.println("equal");
        System.out.println("");

        for (BigInteger i = BigInteger.ONE; i.compareTo(new BigInteger("20")) <= 0; i = i.add(BigInteger.ONE))
            System.out.print(i + " ");
        System.out.println("\n");

        System.out.println("GCD: " + a.gcd(b));
        // param value is 1 - 1/2. Execution time is proportiont to the param value
        System.out.println("IsProbablePrime: " + a.isProbablePrime(8 / 10));
        System.out.println("");

        /**
         * * In BigDecimal everythin is same as BigInteger
         * * except for division
         */
        BigDecimal x, y;
        x = new BigDecimal(in.next());
        y = new BigDecimal(in.next());

        System.out.println("Div: " + x.divide(y));
        // System.out.println("Div: " + x.divide(y, 5, RoundingMode.HALF_UP)); // x >= y
        System.out.println("");
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        // single string
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        // full line
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}