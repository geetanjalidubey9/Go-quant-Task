#include <bits/stdc++.h>

#include "client.h"
#include "interface.h"
using namespace std;

class DeribitOrderManager : public OrderManagerInterface

{

private:
    string apiKey;
    string apiSecret;
    ApiClient apiClient;

public:
    DeribitOrderManager(string &key, string &secret, string baseUrl)
        : apiKey(key), apiSecret(secret), apiClient(baseUrl) {}

 void place_order(string type, string instrument_name, string quantity, string price) override {
    string endpoint = "/api/v2/private/order/";
    string data = "type=" + type + "&instrument_name=" + instrument_name + "&quantity=" + quantity + "&price=" + price + "&side=buy";
    
    string response = apiClient.post_request(endpoint, data);
    cout << "Place order response: " << response << endl;
}

    void cancel_order(string order_id) override

    {
        string endpoint = "/api/v2/private/cancel_order/";
        string data = "order_id="+order_id; 

        string response = apiClient.post_request(endpoint, data);
        cout << "Cancel order response: " << response << endl;
    }

 
    void modify_order(string order_id, string price) override
    {
        string endpoint = "/api/v2/private/modify_order/";
         string data = "order_id=" + order_id + "&price=" + price;

   
        string response = apiClient.post_request(endpoint, data);
        cout << "Modify order response: " << response << endl;
    }


  void get_orderbook(string instrument_name) {
    string endpoint = "/api/v2/public/get_orderbook/";
    string data = "instrument_name=" + instrument_name;

    string response = apiClient.post_request(endpoint, data);
    cout << "Orderbook response: " << response << endl;
}


    void view_current_positions()
    {
        string endpoint = "/api/v2/private/get_account_summary/";
        string data = "";

    
        string response = apiClient.post_request(endpoint, data);
        cout << "Current positions response: " << response << endl;
    }

};
