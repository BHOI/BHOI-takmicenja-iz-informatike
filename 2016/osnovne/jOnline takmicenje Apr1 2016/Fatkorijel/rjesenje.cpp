#include<string>
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class bignum
{
    public:
        vector < int > cipher;
        bignum () {}
        bignum ( const string &arg )
        {
            for ( int i ( 0 ); i < arg.size(); i ++ )
            {
                cipher.push_back ( arg [ i ] - '0' );
            }
        }
        bignum ( int a )
        {
            while ( true )
            {
                if ( a < 10 )
                {
                    cipher.push_back ( a );
                    break;
                }
                cipher.push_back ( a % 10 );
                a /= 10;
            }
            reverse ( cipher.begin(), cipher.end() );
        }
        bignum operator + ( const bignum &alternative )
        {
            bignum result;
            bignum replica = alternative;
            for ( int i ( 0 ); i < cipher.size(); i ++ ) result.cipher.push_back ( cipher [ i ] );
            reverse ( result.cipher.begin(), result.cipher.end() );
            reverse ( replica.cipher.begin(), replica.cipher.end() );

            int len = max ( result.cipher.size(), replica.cipher.size() );
            for ( int i ( result.cipher.size() ); i < len; i ++ ) result.cipher.push_back ( 0 );
            for ( int i ( replica.cipher.size() ); i < len; i ++ ) replica.cipher.push_back ( 0 );

            int carry = 0;
            for ( int i ( 0 ); i < len; i ++ )
            {
                result.cipher [ i ] += replica.cipher [ i ] + carry;
                carry = result.cipher [ i ] / 10;
                result.cipher [ i ] %= 10;
            }
            if ( carry > 0 )
            {
                result.cipher.push_back ( carry );
            }
            reverse ( result.cipher.begin(), result.cipher.end() );
            return result;
        }

        bignum operator * ( const bignum &alternative )
        {
            bignum result ( "0" );
            bignum row ( "0" );
            int zeros ( 0 );
            int transfer;
            for ( int i ( alternative.cipher.size() - 1 ); i > -1; i -- )
            {
                row.clear();
                transfer = 0;
                for ( int k ( 0 ); k < zeros; k ++ ) row.cipher.push_back ( 0 );
                for ( int j ( cipher.size() - 1 ); j > -1; j -- )
                {
                    row.cipher.push_back ( ( alternative.cipher [ i ] * cipher [ j ] ) + transfer );
                    transfer = row.cipher [ row.cipher.size() - 1 ] / 10;
                    row.cipher [ row.cipher.size() - 1 ] %= 10;
                }
                if ( transfer > 0 ) row.cipher.push_back ( transfer );
                reverse ( row.cipher.begin(), row.cipher.end() );
                result = result + row;
                zeros ++;
            }
            if ( result.cipher [ 0 ] == 0 )
            {
                reverse ( result.cipher.begin(), result.cipher.end() );
                while ( true )
                {
                    if ( result.cipher [ result.cipher.size() - 1 ] != 0 || result.cipher.size() == 1 ) break;
                    result.cipher.pop_back();
                }
                reverse ( result.cipher.begin(), result.cipher.end() );
            }
            return result;
        }
        bignum operator - ( const bignum &as )
        {
            bignum rs;
            bignum a ( as );
            rs.clear();
            for ( int i ( 0 ); i < cipher.size(); i ++ ) rs.cipher.push_back ( cipher [ i ] );
            reverse ( a.cipher.begin(), a.cipher.end() );
            reverse ( rs.cipher.begin(), rs.cipher.end() );
            for ( int i ( 0 ); i < a.cipher.size(); i ++ )
            {
                //cout << rs.cipher [ i ] << " " << a.cipher [ i ] << endl;
                if ( rs.cipher [ i ] < a.cipher [ i ] )
                {
                    rs.cipher [ i + 1 ] --;
                    rs.cipher [ i ] += 10;
                    rs.cipher [ i ] -= a.cipher [ i ];
                }
                else
                {
                    rs.cipher [ i ] -= a.cipher [ i ];
                }
            }
            //eliminisati ostatak
            //int i = a.cipher.size() - 1;
            for ( int i ( a.cipher.size() - 1 ); i < cipher.size() - 1; i ++ )
            {
                if ( rs.cipher [ i ] == -1 )
                {
                    rs.cipher [ i ] += 10;
                    rs.cipher [ i + 1 ] --;
                }
            }

            while ( true )
            {
                if ( rs.cipher [ rs.cipher.size() - 1 ] != 0 ) break;
                rs.cipher.pop_back();
            }
            //obrisati nule
            reverse ( rs.cipher.begin(), rs.cipher.end() );
            //okrenuti
            return rs;
        }
        bignum operator / ( const bignum &a )
        {

        }

        bool operator == ( const bignum &a ){
            if(a.cipher.size()!=cipher.size())return false;
            for(int i=0;i<cipher.size();i++){
                if(cipher[i]!=a.cipher[i])return false;
            }
            return true;
        }

        void print ()
        {            for ( int i ( cipher.size()-1 ); i>=0 ;i -- )
            {
                cout << cipher [ i ];
            }
            cout << endl;
        }
        void clear ()
        {
            cipher.clear();
        }
        bool operator < ( const bignum &a ) const
        {
            if ( cipher.size () > a.cipher.size() ) return false;
            if ( cipher.size () < a.cipher.size() ) return true;
            for ( int i ( 0 ); i < cipher.size(); i ++ )
            {
                if ( cipher [ i ] < a.cipher [ i ] ) return true;
                if ( cipher [ i ] > a.cipher [ i ] ) return false;
            }
        }
};

int main()
{
    string a;
    cin>>a;
    bignum bigA(a);
    bignum bigI(1);
    bignum bigR(1);
    while(true){
        bigR=bigR*bigI;
        if(bigI==bigA)break;
        bigI=bigI+1;
    }
    bigR.print();
    return 0;
}
