//
// Created by Nyloner on 2017/4/2.
//

#ifndef REQUESTS_SESSION_H
#define REQUESTS_SESSION_H

#include "requests.h"

class Session : public Requests
{
public:
    shared_ptr<Response> get(const string &url, const Headers &headers, string cookies = "");

    shared_ptr<Response> get(const string &url, string cookies = "");

    shared_ptr<Response> post(const string &url, const PostData &data, string cookies = "");

    shared_ptr<Response>
    post(const string &url, const PostData &data, const Headers &headers, string cookies = "");

    void clear_cookies()
    {
        session_cookies = "";
    };

private:
    string session_cookies;
};


#endif //REQUESTS_SESSION_H
