//
// Created by Nyloner on 2017/4/2.
//

#include "../requests/requests.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string url = "http://nyloner.cn";
    Headers headers;
    headers["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36";
    headers["Accept"] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";

    Requests requests;
    shared_ptr<Response> res = requests.get(url, headers);
    if (res->curl_code == 0)
    {
        cout << res->s_response_headers << endl;
        cout << res->status << endl;
        cout << res->text << endl;
    }
    return 0;
}