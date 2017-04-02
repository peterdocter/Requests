//
// Created by Nyloner on 2017/3/27.
//

#ifndef REQUESTS_RESPONSE_H
#define REQUESTS_RESPONSE_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<string, string> Headers;

class Response
{
public:
    Response()
    {
        redirect_url = NULL;
    };

    ~Response()
    {
        if (redirect_url != NULL)
        {
            free(redirect_url);
        }
    };

    string text;
    Headers response_headers;
    string s_response_headers;
    string cookies;
    string url;
    char *redirect_url;
    int curl_code;
    int status;
};

#endif //REQUESTS_RESPONSE_H
