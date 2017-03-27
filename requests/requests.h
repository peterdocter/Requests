//
// Created by Nyloner on 2017/3/27.
//

#ifndef REQUESTS_REQUESTS_H
#define REQUESTS_REQUESTS_H

#include <string>
#include <map>

#include "response.h"
#include <curl/curl.h>

using namespace std;
typedef map<string, string> Headers;
typedef map<string, string> PostData;

class Requests
{
public:
    Requests();

    ~Requests();

    Response get(const string &url, const Headers &headers, int timeout = 30);

    Response get(const string &url, int timeout = 30);

    Response post(const string &url, const PostData &data, int timeout = 30);

    Response post(const string &url, const PostData &data, const Headers &headers, int timeout = 30);

private:
    struct curl_slist *headers_to_curl_headers(const Headers &headers);

    CURL *curl;
};


#endif //REQUESTS_REQUESTS_H
