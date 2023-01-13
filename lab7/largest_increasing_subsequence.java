import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(
                new BufferedReader(
                        new InputStreamReader(System.in)
                )
        );
        PrintWriter out = new PrintWriter(
                new OutputStreamWriter(
                        System.out)
        );
        int n = in.nextInt();
        int a[] = new int[n];
        int prev[] = new int[n];
        int d[] = new int[n];
        ArrayList<Integer> way = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            prev[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            d[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    if (d[j] + 1 > d[i]) {
                        d[i] = d[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        int len = d[0];
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] > len) {
                len = d[i];
                pos = i;
            }
        }
        while (pos != -1) {
            way.add(a[pos]);
            pos = prev[pos];
        }
        out.println(len);
        for (int i = way.size() - 1; i > 0; i--) {
            out.print(way.get(i) + " ");
        }
        out.print(way.get(0));
        out.flush();
    }
}