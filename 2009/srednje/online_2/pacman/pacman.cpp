#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <cstdlib>
using namespace std;

int n,m,d;
pair <int,int> start, end;
char maze[100][100];
struct qwerty {
    int move[4], prev_move, set_move, row, col;
    bool directed;
} ghost[16];

bool check(int x, int y)
{
    if (x<0 || x>=n) return 0;
    if (y<0 || y>=m) return 0;
    if (maze[x][y]=='x') return 0;
    return 1;
}

/*void printM()
{
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++) cout<<maze[i][j];
        cout<<endl;
    }
}/**/

bool check_move(int id)
{
    if (ghost[id].set_move==1){
        return check(ghost[id].row-1, ghost[id].col);
    }
    else if (ghost[id].set_move==2){
        return check(ghost[id].row, ghost[id].col+1);
    }
    else if (ghost[id].set_move==3){
        return check(ghost[id].row+1, ghost[id].col);
    }
    else if (ghost[id].set_move==4){
        return check(ghost[id].row, ghost[id].col-1);
    }
}

bool move_ghost(int id)
{
    int i;
    if (ghost[id].directed){
        if (ghost[id].set_move==1) ghost[id].row--;
        else if (ghost[id].set_move==2) ghost[id].col++;
        else if (ghost[id].set_move==3) ghost[id].row++;
        else if (ghost[id].set_move==4) ghost[id].col--;
        if (!(check_move(id))){
            ghost[id].directed=false;
            ghost[id].prev_move=ghost[id].set_move;
        }
        else ghost[id].directed=true;
    }
    else {
        bool picked=0;
        for (i=0;i<4;i++){
            if ((ghost[id].prev_move) && abs(ghost[id].move[i]-ghost[id].prev_move)==2) continue;
            ghost[id].set_move=ghost[id].move[i];
            if (check_move(id)){
                picked=1;
                break;
            }
        }
        if(!picked){
            for (i=0;i<4;i++){
                ghost[id].set_move=ghost[id].move[i];
                if (check_move(id)){
                    picked=1;
                    break;
                }
            }
        }
        if (picked){
            maze[ghost[id].row][ghost[id].col]='.';
            if (ghost[id].set_move==1) ghost[id].row--;
            else if (ghost[id].set_move==2) ghost[id].col++;
            else if (ghost[id].set_move==3) ghost[id].row++;
            else if (ghost[id].set_move==4) ghost[id].col--;
            if (!(check_move(id))){
                ghost[id].directed=false;
                ghost[id].prev_move=ghost[id].set_move;
            }
            else ghost[id].directed=true;
        }
    }
}

int bfs()
{
    int i,p,x,y,px,py,sec=0;
    queue<pair <int,int> > q;
    q.push(start); q.push(start);
    //maze[start.first][start.second]='0';
    for (i=0;i<d;i++) maze[ghost[i].row][ghost[i].col]='G';
    //printM();
    //system("PAUSE");
    while (!q.empty()){
        p=q.size()/2;
        for (i=0;i<d;i++) maze[ghost[i].row][ghost[i].col]='.';
        for (i=0;i<d;i++) move_ghost(i);
        for (i=0;i<d;i++) maze[ghost[i].row][ghost[i].col]='G';
        for (i=0;i<p;i++){
            x=q.front().first; y=q.front().second;
            q.pop();
            px=q.front().first; py=q.front().second;
            q.pop();
            if (check(x-1, y) && (x-1!=px) && (maze[x][y]!='G') && (maze[x-1][y]!='G')/**/){
                if (make_pair(x-1, y)==end) return sec+1;
                q.push(make_pair(x-1, y)); q.push(make_pair(x,y));
                //maze[x-1][y]='0'+(sec+1)%10;
            }
            if (check(x+1, y) && (x+1!=px) && (maze[x][y]!='G') && (maze[x+1][y]!='G')/**/){
                if (make_pair(x+1, y)==end) return sec+1;
                q.push(make_pair(x+1, y)); q.push(make_pair(x,y));
                //maze[x+1][y]='0'+(sec+1)%10;
            }
            if (check(x, y-1) && (y-1!=py) && (maze[x][y]!='G') && (maze[x][y-1]!='G')/**/){
                if (make_pair(x, y-1)==end) return sec+1;
                q.push(make_pair(x, y-1)); q.push(make_pair(x,y));
                //maze[x][y-1]='0'+(sec+1)%10;
            }
            if (check(x, y+1) && (y+1!=py) && (maze[x][y]!='G') && (maze[x][y+1]!='G')/**/){
                if (make_pair(x, y+1)==end) return sec+1;
                q.push(make_pair(x, y+1)); q.push(make_pair(x,y));
                //maze[x][y+1]='0'+(sec+1)%10;
            }
        }
        //printM();
        //system("PAUSE");
        sec++;
    }
    return -1;
}

int main()
{
   // ifstream fin("pacman.in");
    int i,j;
    cin>>n>>m;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            cin>>maze[i][j];
    cin>>start.first>>start.second>>end.first>>end.second>>d;
    start.first--; start.second--; end.first--; end.second--;
    for (i=0;i<d;i++){
        cin>>ghost[i].row>>ghost[i].col>>ghost[i].move[0]
        >>ghost[i].move[1]>>ghost[i].move[2]>>ghost[i].move[3];
        ghost[i].prev_move=0;
        ghost[i].directed=false;
        ghost[i].row--;
        ghost[i].col--;
    }
    cout<<bfs()<<endl;
    //system("PAUSE");
    return 0;
}
