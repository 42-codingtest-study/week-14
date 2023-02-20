import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ4883 {
    static int count;
    static int sum;
    static int retryFlag;

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line;
        int tastCase = 0;

        while(Integer.parseInt((line=br.readLine()))!= 0) {
            tastCase++;
            int n = Integer.parseInt(line);
            int[][] dp = new int[n][3];
            for(int i=0; i<n; i++) {
                st = new StringTokenizer(br.readLine());
                dp[i][0] = Integer.parseInt(st.nextToken());
                dp[i][1] = Integer.parseInt(st.nextToken());
                dp[i][2] = Integer.parseInt(st.nextToken());
            }
            for(int i = 1; i<n; i++) {
                if(i == 1) {
                    for(int j = 0; j<3; j++) {
                        if(j == 0) dp[i][0] += dp[i-1][1];
                        else {
                            dp[i][j] += Math.min(dp[i][j-1],
                                Math.min(dp[i-1][1], dp[i-1][1]+dp[i-1][2]));
                        }
                    }
                }else {
                    dp[i][0] += Math.min(dp[i-1][0], dp[i-1][1]);
                    dp[i][1] += Math.min(Math.min(dp[i][0], dp[i-1][0]),
                        Math.min(dp[i-1][1], dp[i-1][2]));
                    dp[i][2] += Math.min(dp[i][1],Math.min(dp[i-1][1], dp[i-1][2]));
                }
            }
            System.out.println(tastCase + ". " + dp[n-1][1]);
        }
    }

    public static void main(String[] args) throws IOException{
        new BOJ4883().solution();
    }
}