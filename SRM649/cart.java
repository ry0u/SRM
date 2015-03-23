import java.util.*;

public class cart{
	public static int calc(int N,int K){
		int[][] res = new int[N+1][K+1];

		for(int i=1;i<=N;i++){
			res[i][0] = i;
		}

		for(int i=0;i<K+1;i++){
			res[1][i] = 1;
		}

		for(int i=1;i <= K;i++){
			for(int j=2;j <= N;j++){
				res[j][i] = j;
				for(int k=1;k<j;k++){
					for(int l=i-1;l >= 0;l--){
						int max = res[k][l];

						if(max < res[j-k][i-1-l]){
							max = res[j-k][i-1-l];
						}
						if(res[j][i] > max + 1){
							res[j][i] = max+1;
						}
					}
				}
			}
		}

		return res[N][K];
	}

	public static void main(String[] args){
		System.out.println(calc(5,2));
	}
}
