import java.io.*;
import java.util.*;
public class Golf {
	static int[] clubs = new int[32];
	static int strokes[] = new int [5281];
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int D = Integer.parseInt(br.readLine());
		int C = Integer.parseInt(br.readLine());
		for(int c = 0; c < C;c++){
			clubs[c] = Integer.parseInt(br.readLine());
			strokes[clubs[c]] = 1;
		}
		int minStrokes = 999999;
		int bestDist = -1;
		for(int i = 1; i <= D;i++){
			minStrokes = 999999;
			bestDist = -1;
			if(strokes[i] > 0) continue;
			for(int j = 0; j < C;j++){
					if(i - clubs[j] >= 1){
						if(strokes[i-clubs[j]] != 999999){
							if(strokes[i-clubs[j]] < minStrokes){
								minStrokes = strokes[i-clubs[j]];
								bestDist = i-clubs[j];
							}
						}
					}

			}
				if(bestDist == -1){
					strokes[i] = 999999;
				}
				else strokes[i] = strokes[bestDist]+1;
			//System.out.println("Distance = " + i + " |||  best dist = " + bestDist + " ||| strokes to get to " + i + " = " + strokes[i]);
		}
		System.out.println(strokes[D] == 999999 ? "Roberta acknowledges defeat." : "Roberta wins in " + strokes[D] + (strokes[D] == 1 ? " stroke." : " strokes."));
		
		
	}

}