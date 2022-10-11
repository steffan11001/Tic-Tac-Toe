#include <iostream>
#include "Tic.h"

using namespace std;

int position[2];

void position_decode(int value)
{
    
    switch (value)
    {
    case 7:
        position[0]=0;
        position[1]=0;
        break;
    case 8:
        position[0]=0;
        position[1]=2;
        break;
    case 9:
        position[0]=0;
        position[1]=4;
        break;
    case 4:
        position[0]=2;
        position[1]=0;
        break;
    case 5:
        position[0]=2;
        position[1]=2;
        break;
    case 6:
        position[0]=2;
        position[1]=4;
        break;
    case 1:
        position[0]=4;
        position[1]=0;
        break;
    case 2:
        position[0]=4;
        position[1]=2;
        break;
    case 3:
        position[0]=4;
        position[1]=4;
        break;
    default:
        break;
    }
    
}
int main()
{
    // vector<vector<string>> a={
    //     {" ", "|", " ", "|", " "},
    //     {"_", "_", "_", "_", "_",},
    //     {" ", "|", " ", "|", " "},
    //     {"_", "_", "_", "_", "_",},
    //     {" ", "|", " ", "|", " "}
    // };
    int a[5][5]={{0}, {0}, {0}, {0}, {0}};
    Table table(5,5,a);
    
    int count=1;
    table.create();
    table.conv();
    int simbol=0;
    int value;
    while( count <= 9 && table.check_win()==0)
    {   
        if(count%2!=0)//first move put X
        {
            cout<<"unde vrei sa pui x, alege o casuta goala specificand pozitia: ";
            cin>>value;
            simbol=3;
        }
        else{
            cout<<"unde vrei sa pui O, alege o casuta goala specificand pozitia: ";
            cin>>value;
            simbol=4;
        }
        position_decode(value);
        
        table.update_a(position[0], position[1],simbol);
        table.conv();
        if(count==9 && table.check_win()==0)
        {
            // cout<<endl<<count<<" "<< table.check_win()<<endl;
            cout<<"Draw"<<endl;
        }
        if(table.check_win()==1)
        {

            cout<<endl<<count<<" check_win= "<< table.check_win()<<endl;
            cout<<"X Win!"<<endl;
        }
        if(table.check_win()==2)
        {
            // cout<<endl<<count<<" "<< table.check_win()<<endl;
            cout<<"O Win!"<<endl;
        }
        count++;
    }
    

    
    //table.print();
    return 0;
}