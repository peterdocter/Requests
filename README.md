### Requests

基于libcurl实现的requests库

#### 1.GET
```c++
#include "requests/requests.h"

int main()
{
    string url = "http://nyloner.cn";

    Headers headers;
    headers["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36";
    headers["Accept"] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";

    Requests requests;
    shared_ptr<Response> res = requests.get(url, headers);

    cout << res->text << endl;

    return 0;
}
```

#### 2.POST
```c++
#include "requests/requests.h"

int main()
{
    string url = "http://www.kfc.com.cn/kfccda/ashx/GetStoreList.ashx?op=cname";
    Headers headers;
    headers["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36";
    headers["Accept"] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";

    PostData post_data;
    post_data["cname"] = "北京";
    post_data["pid"] = "";
    post_data["pageIndex"] = "1";
    post_data["pageSize"] = "100";

    Requests requests;
    shared_ptr<Response> res = requests.post(url, post_data, headers);

    cout << res->text << endl;

    return 0;
}
```

#### 3.Cookies
```c++
#include "requests/requests.h"

int main()
{
    string cookies = "sessionid=dr3uzv8gnl2p11ns43k651rbrlkxyu";
    string url = "http://nyloner.cn/home";

    Requests requests;
    shared_ptr<Response> res = requests.get(url,cookies);

    cout << res->text << endl;

    return 0;
}
```

#### 4.Session
```c++
#include "requests/requests.h"
#include "requests/session.h"

int main()
{
    Session session;

    PostData post_data;
    post_data["username"] = "username";
    post_data["password"] = "password";
    post_data["verifycode"] = "verifycode";

    session.post("http://nyloner.cn/login/", post_data);
    shared_ptr<Response> res = session.get("http://nyloner.cn/user/");

    cout << res->text << endl;

    return 0;
}
```
