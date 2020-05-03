/**
 * Jared Bentvelsen
 * https://dmoj.ca/problem/crci08p2
 * April 29 2020
 */

#include <iostream>
#include <string>
#include <algorithm>
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
int track[51][3];
int play(char m1, char m2){
    if(m1 == 'S'){
        return m2 == 'S' ? 1 : m2 == 'R' ? 0 : 2;
    }
    if(m1 == 'R'){
        return m2 == 'R' ? 1 : m2 == 'P' ? 0 : 2;
    }
    if(m1 == 'P'){
        return m2 == 'P' ? 1 : m2 == 'S' ? 0 : 2;
    }
    return -1;
}
int getSuit(int i){
    int nR = track[i][ROCK] + 2*track[i][SCISSORS];
    int nP = track[i][PAPER] + 2*track[i][ROCK];
    int nS = track[i][SCISSORS] + 2*track[i][PAPER];
    int s = ROCK;
    int max = nR;
    if(nP > max){
        s = PAPER;
        max = nP;
    }
    if(nS > max){
        s = SCISSORS;
    }
    return s;
}

int main(){
    std::string input,opp;
    int N, R,scr = 0, mx = 0;

    for(int i = 0; i < 51;i++){
        for(int j = 0; j < 3;j++){
            track[i][j] = 0;
        }
    }
    
    
    std::cin >> R >> input >> N;
   
    for(int i = 0; i < N;i++){
        std::cin >> opp;
        for(int j = 0; j < R;j++){
            scr += play(input[j],opp[j]);
            track[j][opp[j] == 'S' ? SCISSORS : opp[j] == 'P' ? PAPER : ROCK]++;
        }
    }
    int suit;
    for(int i = 0; i < R;i++){
        suit = getSuit(i); // The suit to pick
        //std::cout<<suit;
        mx += 2*track[i][suit == PAPER ? ROCK : suit == ROCK ? SCISSORS : PAPER];
        mx += track[i][suit];

    }
    std::cout << scr << "\n";
    std::cout << mx;
    return 0;
}