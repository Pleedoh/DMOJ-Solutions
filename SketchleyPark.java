import java.io.*;
import java.util.*;
public class SketchleyPark {
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String msg = br.readLine();//HAILHYDRA -> 9 letters long
		int ke = Integer.parseInt(br.readLine());
		HashMap<Integer,String> pmgs = new HashMap<Integer,String>();
		String t;
		int o = 0;
		boolean hail = false;
		for(int i = 0; i < msg.length()-8;i++){
			t = msg.substring(i,i+9);
			if(t.charAt(0) == t.charAt(4) && t.charAt(1) == t.charAt(8)){
				Set<Character> u = new HashSet<Character>();
				if(t.charAt(0) != t.charAt(2) && t.charAt(1) != t.charAt(2))u.add(t.charAt(2));
				if(t.charAt(0) != t.charAt(3) && t.charAt(1) != t.charAt(3))u.add(t.charAt(3));
				if(t.charAt(0) != t.charAt(5) && t.charAt(1) != t.charAt(5))u.add(t.charAt(5));
				if(t.charAt(0) != t.charAt(6) && t.charAt(1) != t.charAt(6))u.add(t.charAt(6));
				if(t.charAt(0) != t.charAt(7) && t.charAt(1) != t.charAt(7))u.add(t.charAt(7));
				if(u.size() == 5){
					pmgs.put(o,t);
					o++;
				}
			}
		}
		if(pmgs.size() > 0){
		String key = "";
		char[] hydra = new char[9];
		check:
 		for(int i = 0; i < ke; i++){
			key = br.readLine();
			hydra[0] = key.charAt(7);//H
			hydra[1] = key.charAt(0);//A
			hydra[2] = key.charAt(8);//I
			hydra[3] = key.charAt(11);//L
			hydra[4] = hydra[0];//H
			hydra[5] = key.charAt(24);//Y
			hydra[6] = key.charAt(3);//D
			hydra[7] = key.charAt(17);//R
			hydra[8] = hydra[1];//A
			t = new String(hydra);
			for(int j = 0; j < pmgs.size();j++){
				if(pmgs.get(j).equals(t)){
					hail = true;
					break check;
			}
			}
		}
		if(hail){
			char[] res = new char[msg.length()];
			for(int i = 0; i < msg.length();i++){
				res[i] =(char)(key.indexOf(msg.charAt(i)) + 65);
			}
			System.out.println(res);
		}
		else System.out.println("KeyNotFoundError");
		}
		else System.out.println("KeyNotFoundError");
	}

}