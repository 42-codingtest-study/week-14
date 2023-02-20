import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 5000 자리 이하의 암호가 주어진다 -> DFS 불가
 * 해결: 처음부터 하나씩 문자를 체크하며 경우를 따진다 -> DP
 * dp[i]: input 의 i-1번째 문자까지의 암호 해석한 경우의 수
 * dp[i] = dp[i-2] + dp[i-1]
 *
 * 잘못된 경우
 * 1. 아무것도 입력되지 않은 경우
 * 2. 시작이 0인 경우
 *
 * i 번째에 0이 온 경우
 * 1. i-1 가 1 또는 2인 경우 -> o
 * 2. i-1 가 1 또는 2가 아닌 경우 -> x
 *
 * i-1 번째에 0이 온 경우
 * 1. dp[i] = dp[i - 1];
 *
 * i+1 번째에 0이 온 경우
 * 1. i ~ i+1 두자리 숫자가 26를 넘는지 확인
 *
 * 1. dp[i]는 dp[i-1]이 아닌 dp[i-2]가 와야한다
 */

public class BOJ2011 {

    public void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int input_length = input.length();
        int[] dp = new int[input_length];

        if (input.length() == 0 || input.charAt(0) == '0') {
            System.out.println(0);
            return ;
        }
        dp[0] = 1;
        for (int i = 1; i < input_length; i++) {
            if (input.charAt(i) == '0') {
                if (input.charAt(i - 1) == '1' || input.charAt(i - 1) == '2') {
                    dp[i] = dp[i - 1] % 1000000;
                }
            } else {
                if (input.charAt(i - 1) == '0') {
                    dp[i] = dp[i - 1] % 1000000;
                } else if (i + 1 < input_length && input.charAt(i + 1) == '0') {
                    int num = Integer.parseInt(input.substring(i, i + 2));
                    if (num <= 26) {
                        dp[i] = dp[i - 1] % 1000000;
                    }
                } else {
                    int num = Integer.parseInt(input.substring(i - 1, i + 1));
                    if (num <= 26) {
                        if (i - 2 >= 0)
                            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
                        else
                            dp[i] = (dp[i - 1] + 1) % 1000000;
                    } else {
                        dp[i] = dp[i - 1] % 1000000;
                    }
                }
            }
        }
        System.out.println(dp[input_length-1]);
    }

    public static void main(String[] args) throws IOException {
        new BOJ2011().solution();
    }
}
