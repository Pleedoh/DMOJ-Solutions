import java.io.*;
import java.util.*;
public class ApplesToOranges {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in[] = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]);
		int M = Integer.parseInt(in[1]);
		HashMap<String,fruit> market = new HashMap<String,fruit>();
		String nextName;
		double r = 0;
		while(N-->0){
			nextName = br.readLine();
			market.put(nextName,new fruit(nextName));
		}
		while(M-->0){
			in = br.readLine().split(" ");
			market.get(in[0]).adj.add(new pair(in[1],Double.parseDouble(in[2])));
		}
		market.get("APPLES").mxP = 1.0;
		Queue<String> todo = new LinkedList<String>();
		todo.add("APPLES");
		String source;
		boolean yeet = false;
		bfs:
		while(!todo.isEmpty()){
			//t is current fruit & amount of which
			source = todo.poll();
			for(int i = 0; i < market.get(source).adj.size();i++){
				nextName = market.get(source).adj.get(i).name;//Next fruit
				r = market.get(source).adj.get(i).rate*market.get(source).mxP;//The resulting rate to be pushed in
				if (r > market.get(nextName).mxP) {//Only explore the edge if this method of getting to that fruit is better than what we already have
					market.get(nextName).mxP = r;
					if(nextName.equals("APPLES") && r-1 > 1e-6){
						yeet = true;
						break bfs;
					}
					todo.add(nextName);
				}
			}
		}
		System.out.println(yeet ? "YA" : "NAW");
	}//Main
	static class fruit{
		String name;
		double mxP = 0;
		ArrayList<pair> adj = new ArrayList<pair>(); 
		fruit(String name){
			this.name = name;
		}
	}
	static class pair{
		String name;
		double rate;
		pair(String a,double b){
			this.name = a;
			this.rate = b;
		}
	}

}