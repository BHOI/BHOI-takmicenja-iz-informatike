#include <cstdio>
#include <cstring>              // za memset
#include <queue>

using namespace std;

#define MAX 255

int  R, S;
char dvoriste[MAX][MAX];

int  v[MAX][MAX];                    // visited
int  ukupno_koza=0, ukupno_vukova=0; // rjesenja

void flood_fill( int x, int y )
{
   int vukova=0, koza=0;

   queue<int> qx, qy;
   qx.push( x ); qy.push( y );
   v[x][y] = 1;

   while ( !qx.empty() ) {
      int x = qx.front(); qx.pop();
      int y = qy.front(); qy.pop();

      if      ( dvoriste[x][y] == 'z' ) ++vukova;
      else if ( dvoriste[x][y] == 'p' ) ++koza;

      for ( int smjer=0; smjer<4; ++smjer ) {
         static const int dx[] = { 1, 0, -1, 0 };
         static const int dy[] = { 0, 1, 0, -1 };
         int nx = x+dx[smjer], ny = y+dy[smjer];

         if ( nx<0 || nx>=R || ny<0 || ny>=S || dvoriste[nx][ny] == '#' || v[nx][ny] )
            continue;

         qx.push( nx ); qy.push( ny );
         v[nx][ny] = 1;
      }
   }

   if ( vukova >= koza ) ukupno_vukova += vukova;
   else                  ukupno_koza += koza;
}

int main()
{
   //freopen("pilici.in", "r", stdin);
   //freopen("pilici.out", "w", stdout);

   scanf( "%d%d", &R, &S );
   for ( int i=0; i<R; ++i )
      scanf( "%s", dvoriste[i] );


   memset( v, 0, sizeof( v ) );
   for ( int i=0; i<R; ++i )
      for ( int j=0; j<S; ++j )
         if ( !v[i][j] )
            flood_fill( i, j );

   printf( "%d %d\n", ukupno_koza, ukupno_vukova );

 //  fclose(stdin);
 //  fclose(stdout);

   return 0;
}
