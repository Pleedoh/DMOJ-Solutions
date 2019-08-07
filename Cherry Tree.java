import java.util.*;
import java.io.*;

public class CherryTree {
	
	static node[] tree = new node[10001];
	static int N,C,K,ans = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in[] = br.readLine().split(" ");
		N = Integer.parseInt(in[0]);
		C = Integer.parseInt(in[1]);
		K = Integer.parseInt(in[2]);
		in = br.readLine().split(" ");
		for(int i = 1; i <= N;i++){
			tree[i] = new node();
			tree[i].cherries = Integer.parseInt(in[i-1]);
		}
		int a,b,k;
		for(int i = 1;i < N;i++){
			in = br.readLine().split(" ");
			a = Integer.parseInt(in[0]);
			b = Integer.parseInt(in[1]);
			k = Integer.parseInt(in[2]);
			tree[a].children.add(new pair(b,k));
			tree[b].weight = k;
		}
		define(1);
		//System.out.println(tree[7].weight);
		System.out.println(ans);
	}//main
	
	static void define(int root){
		int chi;
		//System.out.println(root);
		for(int i = 0;i< tree[root].children.size();i++){
			chi = tree[root].children.get(i).num;
			define(chi);
			tree[root].cherries += tree[chi].cherries;
			tree[root].weight += tree[chi].weight;
		}
		if(tree[root].cherries >= C && tree[root].weight <= K && root != 1) ans++;
		
	}
	static class pair{
		int num;
		int weight;
		pair(int num, int weight){
			this.num = num;
			this.weight = weight;
		}
	}
	static class node{
		int cherries;// the total number of cherries should this become the root
		int weight;//the total weight
		ArrayList<pair> children = new ArrayList<pair>();
		
	}
}