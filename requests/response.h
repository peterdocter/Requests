//
// Created by Nyloner on 2017/3/27.
//

#ifndef REQUESTS_RESPONSE_H
#define REQUESTS_RESPONSE_H

#include <iostream>
#include <string>

using namespace std;


class Response
{
public:
    string text;
    string response_headers;
    int curl_code;
    int status;
};


#endif //REQUESTS_RESPONSE_H
