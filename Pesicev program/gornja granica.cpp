#include<iostream>
const int N=100;
long long granica[N][N];
bool znamo[N][N];
void print(int a){
    for(int i=0;i<a;i++)
        printf(" ");
}
int main()
{
    for(int i=0;i<N;i++){
        granica[1][i]=granica[i][1]=1;
        granica[2][i]=granica[i][2]=i;
        znamo[1][i]=znamo[i][1]=znamo[2][i]=znamo[i][2]=1;
    }
    int gr3[7]={6,9,14,18,23,28,36};
    for(int i=3;i<10;i++)
        granica[3][i]=granica[i][3]=gr3[i-3],znamo[3][i]=znamo[i][3]=1;
    granica[4][4]=18;
    znamo[4][4]=1;
    granica[4][5]=granica[5][4]=25;
    znamo[4][5]=znamo[5][4]=1;
	for(int i=3;i<N;i++)
        for(int j=3;j<N;j++)
            if(!znamo[i][j]){
                granica[i][j]=granica[i-1][j]+granica[i][j-1];
                if(znamo[i-1][j]&&znamo[i][j-1]&&granica[i-1][j]%2==0&&granica[i][j-1]%2==0)
                    granica[i][j]--;
            }
    int redova,duzina=14;
    printf("Unesi broj redova:\n");
    scanf("%i",&redova);
    int maxDuzina=redova*duzina+4*(redova-1);
    for(int i=0;i<redova;i++){
        int a=2,b=a+i;
        //printf("\\[");
        print((maxDuzina-(i+1)*duzina-4*i)/2);
        for(int j=0;j<=i;j++){
            printf("R(%2i,%2i)",a,b);
            if(znamo[a][b])
                printf(" =");
            else
                printf("<=");
                //printf("\\leq ");
            printf("%4lld",granica[a][b]);
            print(4);
            a++;
            b--;
            //if(j!=i)
            //printf("\\hspace{0.3cm}");
        }
        printf("\n\n");
        //printf("\\]\n");
    }
    while(true){
        printf("Unesti brojeve a i b za koje hoces da znas gornju granicu R(a,b).\n");
        int a,b;
        scanf("%i %i",&a,&b);
        printf("R(%i,%i)",a,b);
        if(!znamo[a][b])
            printf("<");
        printf("=%lld\n",granica[a][b]);
    }
    return 0;
}
