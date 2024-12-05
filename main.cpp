#include <iostream>
#include <winsock2.h>
#include <cstring>
#include <string>
#include <memory>
#include <fstream>
#include "httplib.h"
#include "interface.h"
#include "../api/client.h"
#include "interface.h"
#include "manager.h"

using namespace std;


string CLIENT_ID ="q5V57T8V";

string  CLIENT_SECRET ="JehqsJovprDmuusZ6doMECnK4lr7DlOItIQe_XPG1WE";

int main() {
    // Create an instance of DeribitOrderManager
    OrderManagerInterface *manager = new DeribitOrderManager(CLIENT_ID, CLIENT_SECRET, "https://www.deribit.com");

    // Call place_order with sample parameters
    manager->place_order("limit", "BTC-USD", "1", "50000");

    // Call cancel_order with a sample order ID
    manager->cancel_order("12345");

    // Call modify_order with a sample order ID and new price
    manager->modify_order("12345", "51000");

    // Call get_orderbook with a sample instrument name
    manager->get_orderbook("BTC-USD");

   delete manager;


    return 0;
}