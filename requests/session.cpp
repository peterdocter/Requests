//
// Created by Nyloner on 2017/4/2.
//

#include "session.h"

shared_ptr<Response> Session::get(const string &url, string cookies)
{
    if (cookies == "")
        cookies = session_cookies;
    shared_ptr<Response> res = Requests::get(url, cookies);
    session_cookies = res->cookies;
    return res;
}

shared_ptr<Response> Session::get(const string &url, const Headers &headers, string cookies)
{
    if (cookies == "")
        cookies = session_cookies;
    shared_ptr<Response> res = Requests::get(url, headers, cookies);
    session_cookies = res->cookies;
    return res;
}

shared_ptr<Response> Session::post(const string &url, const PostData &data, string cookies)
{
    if (cookies == "")
        cookies = session_cookies;
    shared_ptr<Response> res = Requests::post(url, data, cookies);
    session_cookies = res->cookies;
    return res;
}

shared_ptr<Response> Session::post(const string &url, const PostData &data, const Headers &headers, string cookies)
{
    if (cookies == "")
        cookies = session_cookies;
    shared_ptr<Response> res = Requests::post(url, data, headers, cookies);
    session_cookies = res->cookies;
    return res;
}

