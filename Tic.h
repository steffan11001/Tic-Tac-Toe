#pragma once
#include <vector>
class Table{
    private:
    int h;
    int w;
    int a[5][5];
    public:
    Table(int h_c, int w_c,int a[5][5]);
    void create();
    void conv();
    void set_h(int value);
    void set_w(int value);
    void set_a(int a[5][5]);
    int get_h();
    int get_w();
    void get_a();
    void print();
    void update_a(int x,int y, int value);
    int check_win();
};



