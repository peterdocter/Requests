//
// Created by Nyloner on 2017/3/27.
//

#ifndef REQUESTS_REQUESTS_H
#define REQUESTS_REQUESTS_H

#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "response.h"
#include <curl/curl.h>

using namespace std;
typedef map<string, string> Headers;
typedef map<string, string> PostData;

class Requests
{
public:

    virtual ~Requests();

    virtual shared_ptr<Response> get(const string &url, const Headers &headers, string cookies = "");

    virtual shared_ptr<Response> get(const string &url, string cookies = "");

    virtual shared_ptr<Response> post(const string &url, const PostData &data, string cookies = "");

    virtual shared_ptr<Response>
    post(const string &url, const PostData &data, const Headers &headers, string cookies = "");

private:
    struct curl_slist *headers_to_curl_headers(const Headers &headers);

    string post_data_to_string(const PostData &post_data);

    Headers parser_response_headers(const string &response_headers_str);

};


#endif //REQUESTS_REQUESTS_H
