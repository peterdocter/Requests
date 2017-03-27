//
// Created by Nyloner on 2017/3/27.
//

#include "requests.h"

Requests::Requests()
{
    curl = curl_easy_init();
}

struct curl_slist *Requests::headers_to_curl_headers(const Headers &headers)
{
    struct curl_slist *curl_headers = NULL;
    auto map_it = headers.begin();
    while (map_it != headers.end())
    {
        string line = map_it->first + ": " + map_it->second;
        curl_headers = curl_slist_append(curl_headers, line.c_str());
        ++map_it;
    }
    return curl_headers;
}

Response Requests::get(const string &url, const Headers &headers, int timeout = 30)
{
    struct curl_slist *curl_headers = headers_to_curl_headers(headers);

    curl_slist_free_all(curl_headers);
}

Response Requests::get(const string &url, int timeout = 30)
{

}

Response Requests::post(const string &url, const PostData &data, int timeout = 30)
{

}

Response Requests::post(const string &url, const PostData &data, const Headers &headers, int timeout = 30)
{
    struct curl_slist *curl_headers = headers_to_curl_headers(headers);

    curl_slist_free_all(curl_headers);
}

Requests::~Requests()
{
    curl_easy_cleanup(curl);
}