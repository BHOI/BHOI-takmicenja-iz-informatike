#include <cstdio>
#include <cmath>
#include <cstring>

int main(int argc,char *argv[])
{
	FILE *in=fopen(argv[3],"r");
	int R,C,W,his_score;
	char s[5000];
	if(fscanf(in,"%d %d %d",&R,&C,&W)==3)
	{
	    fscanf(in," %s",s);
        if(strcmp(s,"---Pocetak---$$NemaSanseRealno")){printf("%lf\n",0.0);fprintf(stderr,"Zabranjeno korištenje standardnog ulaza i izlaza!\n");fclose(in);return 0;}
        fscanf(in,"%d",&his_score);
        if(his_score==-1)
        {
            fprintf(stderr,"Nije pravilno i/ili brod nije nađen.\n");
            printf("%lf\n",0.00);
            fclose(in);
            return 0;
        }
	    fscanf(in," %s",s);
        if(strcmp(s,"---Kraj---$$")){printf("%lf\n",0.0);fprintf(stderr,"Zabranjeno korištenje standardnog ulaza i izlaza!\n");fclose(in);return 0;}
		int score=R*(C/W);
		score+=W-1;
		if(C%W)score++;
		if(his_score<score)
        {
            fprintf(stderr,"Nije pravilno i/ili brod nije nađen.\n");
            printf("%lf\n",0.00);
            fclose(in);
            return 0;
        }
		double gotovo=exp(((double)his_score-score)/score*log(0.5)/log(exp(1.)));
		printf("%lf\n",gotovo);
		fprintf(stderr,"%.2lf\n",gotovo*100);
	}
	else
	{
		fprintf(stderr,"Nije pravilno i/ili brod nije nadjen\n");
		printf("%lf\n",0.00);
	}
	fclose(in);
	return 0;
}
