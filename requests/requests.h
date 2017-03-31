//
// Created by Nyloner on 2017/3/27.
//

#ifndef REQUESTS_REQUESTS_H
#define REQUESTS_REQUESTS_H

#include <string>
#include <map>
#include <vector>

#include "response.h"
#include <curl/curl.h>

using namespace std;
typedef map<string, string> Headers;
typedef map<string, string> PostData;

class Requests
{
public:

    shared_ptr<Response> get(const string &url, const Headers &headers);

    shared_ptr<Response> get(const string &url);

    shared_ptr<Response> post(const string &url, const PostData &data);

    shared_ptr<Response> post(const string &url, const PostData &data, const Headers &headers);

private:
    struct curl_slist *headers_to_curl_headers(const Headers &headers);

    string post_data_to_string(const PostData &post_data);

    Headers parser_response_headers(const string &response_headers_str);

    vector<string> string_split(const string &str, const string &sep);
};


#endif //REQUESTS_REQUESTS_H
