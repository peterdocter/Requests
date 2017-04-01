//
// Created by Nyloner on 2017/3/31.
//

#include "test.h"

int test_get()
{
    string url = "http://www.nyloner.cn";
    Requests requests;
    shared_ptr<Response> res = requests.get(url);
    cout << res->status << endl;
    cout << res->text << endl;
    cout << res->s_response_headers << endl;
    return 0;
}


int test_get_headers()
{
    string url = "http://www.nyloner.cn";
    Requests requests;
    Headers headers;
    headers["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36";
    headers["Accept"] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";
    shared_ptr<Response> res = requests.get(url, headers);
    cout << res->text << endl;
    return 0;
}

int test_post()
{
    PostData post_data;
    post_data["username"] = "13583681280";
    post_data["password"] = "123456";
    Requests requests;
    shared_ptr<Response> res = requests.post("http://www.3j1688.com/member/index.html", post_data);
    cout << res->s_response_headers << endl;
    cout << res->status << endl;
    //cout << res->text << endl;
    cout << res->url << endl;
    return 0;
}