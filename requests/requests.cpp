//
// Created by Nyloner on 2017/3/27.
//

#include "requests.h"

static size_t OnWriteData(void *buffer, size_t size, size_t nmemb, void *lpVoid)
{
    std::string *str = dynamic_cast<std::string *>((std::string *) lpVoid);
    if (NULL == str || NULL == buffer)
    {
        return 0;
    }
    char *pData = (char *) buffer;
    str->append(pData, size * nmemb);
    return nmemb;
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

string Requests::post_data_to_string(const PostData &post_data)
{
    string post_str;
    auto map_it = post_data.begin();
    while (map_it != post_data.end())
    {
        post_str += map_it->first + "=" + map_it->second + "&";
        map_it++;
    }
    return post_str;
}

vector<string> Requests::string_split(const string &str, const string &sep)
{
    vector<string> result;
    unsigned long pos = 0;
    while (pos < str.length())
    {
        unsigned long index = str.find(sep, pos);
        if()
    }
}

Headers Requests::parser_response_headers(const string &response_headers_str)
{
    Headers response_headers;
}

shared_ptr<Response> Requests::get(const string &url, const Headers &headers)
{
    struct curl_slist *curl_headers = headers_to_curl_headers(headers);
    CURL *curl = curl_easy_init();
    shared_ptr<Response> res = make_shared<Response>();
    if (curl == NULL)
    {
        res->curl_code = -1;
        return res;
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_headers);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &res->text);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, (void *) &res->response_headers);
    res->curl_code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(curl_headers);
    return res;
}

shared_ptr<Response> Requests::get(const string &url)
{
    CURL *curl = curl_easy_init();
    shared_ptr<Response> res = make_shared<Response>();
    if (curl == NULL)
    {
        res->curl_code = -1;
        return res;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &res->text);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, (void *) &res->response_headers);
    res->curl_code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return res;
}

shared_ptr<Response> Requests::post(const string &url, const PostData &data)
{
    CURL *curl = curl_easy_init();
    shared_ptr<Response> res = make_shared<Response>();
    string post_str = post_data_to_string(data);
    if (curl == NULL)
    {
        res->curl_code = -1;
        return res;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_str.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &res->text);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, (void *) &res->response_headers);
    res->curl_code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return res;
}

shared_ptr<Response> Requests::post(const string &url, const PostData &data, const Headers &headers)
{
    struct curl_slist *curl_headers = headers_to_curl_headers(headers);
    CURL *curl = curl_easy_init();
    shared_ptr<Response> res = make_shared<Response>();
    string post_str = post_data_to_string(data);
    if (curl == NULL)
    {
        res->curl_code = -1;
        return res;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_str.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &res->text);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, (void *) &res->response_headers);
    res->curl_code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(curl_headers);
    return res;
}
