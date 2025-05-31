int Povrsina(int V, int S, char **M)
{
    int crte = 0, tacke = 0;
    bool unutra;
    for(int i = 0; i < V; ++i)
    {
        unutra = false;
        for(int j = 0; j < S; ++j)
        {
            if(M[i][j] == '.')
            {
                if(unutra)
                    ++tacke;
            }
            else if(M[i][j] == '\\' || M[i][j] == '/')
            {
                ++crte;
                unutra = !unutra;
            }
        }
    }
    return tacke + crte / 2;
}

