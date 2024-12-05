#include "httplib.h"
#include <string>
using namespace std;

class ApiClient
{
public:
    ApiClient(const string &baseUrl) : baseUrl(baseUrl), cli(baseUrl) {}


    string get_request(const string &endpoint)
    {
        auto res = cli.Get(endpoint.c_str());

        if (res && res->status == 200)
        {
            return res->body; 
        }
        else
        {
            return "Error: " + to_string(res ? res->status : 0);
        }
    }

    string post_request(const string &endpoint, const string &data)
    {
        httplib::Headers headers;
        headers.insert({"Content-Type", "application/x-www-form-urlencoded"});

        auto res = cli.Post(endpoint.c_str(), headers, data, "application/x-www-form-urlencoded");

        if (res && res->status == 200)
        {
            return res->body; // Return response body if the request was successful
        }
        else
        {
            return "Error: " + to_string(res ? res->status : 0);
        }
    }

    // Function to send PATCH request
    string patch_request(const string &endpoint, const string &data)
    {
        httplib::Headers headers;
        headers.insert({"Content-Type", "application/x-www-form-urlencoded"});

        auto res = cli.Patch(endpoint.c_str(), headers, data, "application/x-www-form-urlencoded");

        if (res && res->status == 200)
        {
            return res->body; // Return response body if the request was successful
        }
        else
        {
            return "Error: " + to_string(res ? res->status : 0);
        }
    }

    // Function to send DELETE request
    string delete_request(const string &endpoint)
    {
        auto res = cli.Delete(endpoint.c_str());

        if (res && res->status == 200)
        {
            return res->body; // Return response body if the request was successful
        }
        else
        {
            return "Error: " + to_string(res ? res->status : 0);
        }
    }

private:
    string baseUrl;
    httplib::Client cli; // The client is now a member variable
};
