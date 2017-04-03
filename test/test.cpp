//
// Created by Nyloner on 2017/3/31.
//

#include "test.h"

int test_get()
{
    string url = "http://www.nyloner.cn/home";
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
    post_data["username"] = "username";
    post_data["password"] = "passwd";
    Requests requests;
    shared_ptr<Response> res = requests.post("http://www.3j1688.com/member/index.html", post_data);
    cout << res->s_response_headers << endl;
    cout << res->status << endl;
    cout << res->cookies << endl;
    cout << res->url << endl;
    return 0;
}

int test_post_cookies()
{
    string cookies = "Hm_lvt_780f12646b56ec5caa7e64e2d303666b=1491010933; Hm_lpvt_780f12646b56ec5caa7e64e2d303666b=1491010933; ASP.NET_SessionId=mx1t3sl3j2hizhekjift24bk; SERVERID=s1";
    PostData data;
    data["majorNo"] = "07";
    data["year"] = "2016";
    data["schoolNo"] = "1109";
    data["batchNo"] = "2";
    data["subjectName"] = "理工类";

    Requests requests;
    shared_ptr<Response> res = requests.post("http://zyfz.cqzk.com.cn/WillAssistance/SearchStudentInfo/", data,
                                             cookies);
    if (res->curl_code == 0)
    {
        cout << res->cookies << endl;
        cout << res->s_response_headers << endl;
        cout << res->text << endl;
    }

    return 0;
}

int test_session()
{
    Session session;
    PostData post_data;
    post_data["username"] = "username";
    post_data["password"] = "password";
    session.post("http://www.3j1688.com/member/index.html", post_data);
    shared_ptr<Response> res = session.get("http://www.3j1688.com/member/index.html");
    res = session.get("http://www.3j1688.com/myCenter/index.html");
    cout << res->cookies << endl;
    cout << res->s_response_headers << endl;
    cout << res->text << endl;
    return 0;
}
