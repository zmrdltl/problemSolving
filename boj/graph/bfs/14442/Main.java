import java.io.*;
import java.util.*;

public class Main {
    static int n, m, k;
    static int[][] mapInput;
    static int[][][] check;
    static int[] dr = {0, 0, 1, -1};
    static int[] dc = {1, -1, 0, 0};

    static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0, 0});
        check[0][0][0] = 1;

        while (!q.isEmpty()) {
            int[] current = q.poll();
            int r = current[0];
            int c = current[1];
            int breakCnt = current[2];

            if (r == n - 1 && c == m - 1) {
                return check[r][c][breakCnt];
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (0 > nr || nr >= n || 0 > nc || nc >= m) continue;

                if (mapInput[nr][nc] == 0 && check[nr][nc][breakCnt] == 0) {
                    check[nr][nc][breakCnt] = check[r][c][breakCnt] + 1;
                    q.add(new int[]{nr, nc, breakCnt});
                }

                if (mapInput[nr][nc] == 1 && breakCnt < k && check[nr][nc][breakCnt + 1] == 0) {
                    check[nr][nc][breakCnt + 1] = check[r][c][breakCnt] + 1;
                    q.add(new int[]{nr, nc, breakCnt + 1});
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        mapInput = new int[n][];
        check = new int[n][m][k + 1];

        for (int i = 0; i < n; i++) {
            mapInput[i] = br.readLine().chars().map(c -> c - '0').toArray();
        }
        System.out.println(bfs());
    }
}
