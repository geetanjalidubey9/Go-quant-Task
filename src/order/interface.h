#include <bits/stdc++.h>
using namespace std;

class OrderManagerInterface
{
    virtual void place_order(string type ,string instrument_name,string quantity,string price) = 0;
    virtual void cancel_order(string order_id) = 0;
    virtual void modify_order(string order_id, string price) = 0;
    virtual void get_orderbook(string instrument_name0)=0;
    virtual  void view_current_positions()=0;
};


#endif

