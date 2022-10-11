#include <iostream>
#include <string>
#include "Tic.h"

using namespace std;

Table::Table(int h_c, int w_c, int a[5][5])
{
    this->h=h_c;
    this->w=w_c;
    for(int i = 0 ; i < this->w; i++)
    {
        for(int j = 0 ; j < this->h; j++)
        {
            this->a[i][j]=a[i][j];
            
        }
    }
}


void Table::set_a(int a[5][5])
{
    for(int i = 0 ; i < w; i++)
    {
        for(int j = 0 ; j < h; j++)
        {
            this->a[i][j]=a[i][j];
        }
    }
}

void Table::set_h(int value)
{
    this->h=value;
}

void Table::get_a()
{
    for(int i = 0 ; i < w; i++)
    {
        for(int j = 0 ; j < h; j++)
        {
            cout<<this->a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Table::get_h()
{
    return this->h;
}

int Table::get_w()
{
    return this->w;
}


void Table::set_w(int value)
{
    this->w=value;
}

void Table::create()
{
    for(int i = 0 ; i < w; i++)
    {
        for(int j = 0 ; j < h; j++)
        {
            if(i%2!=0)
                this->a[i][j]=2;
            else if (j%2!=0)
                this->a[i][j]=1;          
        }
    }
}

void Table::conv()
{
    cout<<endl;
    for(int i = 0 ; i < w; i++)
    {
        for(int j = 0 ; j < h; j++)
        {   
            switch (a[i][j])
            {
            case 0:
                cout<<" ";
                break;
            case 1:
                cout<<"|";
                break;
            case 2:
                cout<<"-";
                break;
            case 3:
                cout<<"X";
                break;
            case 4:
                cout<<"O";
                break;
            
            default:
                break;
            }         
        }
        cout<<endl;
    }
}

void Table::print()
{
    this->get_a();
}

//---------------------------------------------------

int Table::check_win()
{
    int x_flag=0;
    int o_flag=0;
    int x_win_flag=0;
    int o_win_flag=0;
    //check line
    for(int i = 0 ; i < w && x_win_flag==0 && o_win_flag==0; i+=2)
    {
        for(int j = 0 ; j < h && x_win_flag==0 && o_win_flag==0; j+=2)
        {
            if(this->a[i][j]==3)
                x_flag++;
            if(this->a[i][j]==4)
                o_flag++;     
        }
        if(x_flag==3)
            x_win_flag=1;
        if( o_flag==3)
            o_win_flag=2;
        x_flag=0;
        o_flag=0;
    }
    cout<<x_flag<<" "<<o_flag<<"______________________________________"<<x_win_flag<<" "<<o_win_flag<<endl;
    //check col
    for(int j = 0 ; j < w && x_win_flag==0 && o_win_flag==0; j+=2)
    {
        for(int i = 0 ; i < 5 && x_win_flag==0 && o_win_flag==0; i+=2)
        {
            if(this->a[i][j]==3)
                x_flag++;
            if(this->a[i][j]==4)
                o_flag++;     
        }
        if(x_flag==3)
            x_win_flag=1;
        if( o_flag==3)
            o_win_flag=2;
        x_flag=0;
        o_flag=0;
    }
    //check  p_diag
    for(int i=0; i < 5 && x_win_flag==0 && o_win_flag==0;i+=2)
    {
        if(this->a[i][i]==3)
            x_flag++;
        if(this->a[i][i]==4)
            o_flag++;     
    }
     if(x_flag==3)
        x_win_flag=1;
    if( o_flag==3)
        o_win_flag=2;
    x_flag=0;
    o_flag=0;
    //check s_diag
    for(int i=4; i >= 0 && x_win_flag==0 && o_win_flag==0;i-=2)
    {
        for(int j=4; j >= 0 && x_win_flag==0 && o_win_flag==0;j-=2)
        {
            if(this->a[i][j]==3)
                x_flag++;
            if(this->a[i][j]==4)
                o_flag++;
        }
        if(x_flag==3)
            x_win_flag=1;
        if( o_flag==3)
            o_win_flag=2;
        x_flag=0;
        o_flag=0;
    
    } 
    cout<<x_flag<<" "<<o_flag<<"______________________________________"<<x_win_flag<<" "<<o_win_flag<<endl;
    
    if(x_win_flag==1)
        return x_win_flag;
    else if (o_win_flag==2)
    {
        return o_win_flag;
    }
    else
        return 0;
}

void Table::update_a(int x,int y, int value)
{   
    this->a[x][y]=value;
    
}