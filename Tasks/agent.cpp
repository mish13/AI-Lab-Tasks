#include<bits/stdc++.h>

using namespace std;

int main()
{
    int row,col;
    cout<<"Give the dimension of the grid"<<endl;
    cin>>col>>row;
    int sx,sy,ex,ey;
    cout<<"Give the starting co-ordinate"<<endl;
    cin>>sx>>sy;
    cout<<"Give the ending co-ordinate"<<endl;
    cin>>ex>>ey;
    int diffx= abs(sx-ex);
    int diffy= abs(sy-ey);
    char fld[row+7][col+7];
    for(int i=1;i<=col;i++)
    {
        for(int j=1;j<=row;j++)
        {
            if(i==sx && j==sy)
            {
                cout<<"S ";
                fld[i][j]='S';
            }
            else if(i==ex && j==ey)
            {
                cout<<"D ";
                fld[i][j]='D';
            }
            else
                cout<<". ",fld[i][j]='.';
        }
        cout<<endl;
    }
    cout<<"Movements are:"<<endl;
    if(sx<ex)
    {

        for(int i=1;i<=diffx;i++)
        {
            if(i!=diffx || diffy!=0)
            {
                sx++;
                fld[sx][sy]='V';
            }

            else
            {
                sx++;
                fld[sx][sy]='V';
            }
        }
    }
    else
    {
        for(int i=1;i<=diffx;i++)
        {
            if(i!=diffx || diffy!=0)
            {
                sx--;
                fld[sx][sy]='^';
            }
            else
            {
                sx--;
                fld[sx][sy]='^';
            }
        }
    }
    if(sy<ey)
    {

        for(int i=1;i<=diffy;i++)
        {
            if(i!=diffy)
            {
                sy++;
                fld[sx][sy]='>';
            }
            else
            {
                sy++;
                fld[sx][sy]='>';
            }
        }
    }
    else
    {
        for(int i=1;i<=diffy;i++)
        {
            if(i!=diffy)
            {
                sy--;
                fld[sx][sy]='<';
            }
            else
            {
                sy--;
                fld[sx][sy]='<';
            }
        }
    }
    for(int i=1;i<=col;i++)
    {
        for(int j=1;j<=row;j++)
        {
            if(i==sx && j==sy)
            {
                cout<<"S ";
            }
            else if(i==ex && j==ey)
            {
                cout<<"D ";
            }
            else
                cout<<fld[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
