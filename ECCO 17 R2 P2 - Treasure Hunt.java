import java.io.*;

import java.util.*;

public class TreasureHunt {
	static tile[][] grid;// [row][col]
	static int N;
	static int keys;
	static int tr;
	static List<pair> pD;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int T = 0; T < 10; T++) {
			N = Integer.parseInt(br.readLine());
			String line;
			grid = new tile[N][N];
			pair s = new pair(-1, -1);
			keys = 0;
			tr = 0;
			pD = new ArrayList<pair>();
			for (int i = 0; i < N; i++) {
				line = br.readLine();
				for (int j = 0; j < N; j++) {
					grid[i][j] = new tile(line.charAt(j));
					if (line.charAt(j) == 'S') {
						s = new pair(i, j);
						grid[i][j].vis = true;
					}
					if (line.charAt(j) == '#')
						grid[i][j].vis = true;
				}
			} // in
			bfs(s);
			int i = 0;
			while (i < pD.size()) {
				s = pD.get(i);
				if (keys >= grid[s.first][s.second].doorVal) {
					bfs(s);
					pD.remove(i);
					i = 0;
				} 
				else i++;
					
			} // leftover doors
			System.out.println(tr);
		} // TC

	}// MAIN

	static void bfs(pair s) {
		Queue<pair> todo = new LinkedList<pair>();
		todo.add(s);
		grid[s.first][s.second].vis = true;
		while (!todo.isEmpty()) {
			s = todo.poll();
			if (grid[s.first][s.second].type == 'T')
				tr++;
			if (valid(s.first - 1, s.second)) {// up
				if (!grid[s.first - 1][s.second].vis) {
					if (grid[s.first - 1][s.second].type == 'K')
						keys++;
					if (grid[s.first - 1][s.second].doorVal <= keys) {
						todo.add(new pair(s.first - 1, s.second));
					} else {
						pD.add( new pair(s.first - 1, s.second));
						
					}

					grid[s.first - 1][s.second].vis = true;
				}
			}
			if (valid(s.first + 1, s.second)) {// down
				if (!grid[s.first + 1][s.second].vis) {
					if (grid[s.first + 1][s.second].type == 'K')
						keys++;
					if (grid[s.first + 1][s.second].doorVal <= keys) {
						todo.add(new pair(s.first + 1, s.second));
					} else {
						pD.add( new pair(s.first + 1, s.second));
						
					}

					grid[s.first + 1][s.second].vis = true;
				}
			}
			if (valid(s.first, s.second - 1)) {// left
				if (!grid[s.first][s.second - 1].vis) {
					if (grid[s.first][s.second - 1].type == 'K')
						keys++;
					if (grid[s.first][s.second - 1].doorVal <= keys) {
						todo.add(new pair(s.first, s.second - 1));
					} else {
						pD.add(new pair(s.first, s.second - 1));
						
					}

					grid[s.first][s.second - 1].vis = true;
				}
			}
			if (valid(s.first, s.second + 1)) {// right
				if (!grid[s.first][s.second + 1].vis) {
					if (grid[s.first][s.second + 1].type == 'K')
						keys++;
					if (grid[s.first][s.second + 1].doorVal <= keys) {
						todo.add(new pair(s.first, s.second + 1));
					} else {
						pD.add( new pair(s.first, s.second + 1));
						
					}
					grid[s.first][s.second + 1].vis = true;
				}
			}
		} // bfs while
	}

	static boolean valid(int r, int c) {
		if (r < 0 || c < 0)
			return false;
		if (r >= N || c >= N)
			return false;
		return true;
	}

	static class pair {
		int first, second;

		pair(int f, int s) {
			this.first = f;
			this.second = s;
		}
	}

	static class tile {
		boolean vis = false;
		char type = 'x';
		int doorVal = 0;

		tile(char c) {
			this.type = c;
			if (c - 48 > 0 && c - 48 < 10)
				this.doorVal = c - 48;
		}
	}

}// EOF