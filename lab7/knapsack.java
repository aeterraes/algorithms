import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(
                new BufferedReader(
                        new InputStreamReader(System.in)
                )
        );
        int s = in.nextInt();
        int n = in.nextInt();
        int weight[] = new int[n + 1];
        weight[0] = 0;
        for (int i = 1; i <= n; i++) {
            weight[i] = in.nextInt();
        }
        int costs[] = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            costs[i] = weight[i];
        }
        int[][] a = new int[n + 1][s + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= s; j++) {
                if (j >= weight[i]) {
                    a[i][j] = Math.max(a[i - 1][j], a[i - 1][j - weight[i]] + costs[i]);
                } else {
                    a[i][j] = a[i - 1][j];
                }
            }
        }
        System.out.println(a[n][s]);
    }
}