### Requests

基于libcurl实现的requests库

#### 1.GET
```c++
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
```

#### 2.POST
```c++
string url = "http://www.kfc.com.cn/kfccda/ashx/GetStoreList.ashx?op=cname";
Headers headers;
headers["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36";
headers["Accept"]="text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";

PostData post_data;
post_data["cname"] = "北京";
post_data["pid"] = "";
post_data["pageIndex"] = "1";
post_data["pageSize"] = "100";

Requests requests;
shared_ptr<Response> res = requests.post(url, post_data, headers);
if (res->curl_code == 0)
{
    cout << res->s_response_headers << endl;
    cout << res->status << endl;
    cout << res->text << endl;
}
```

#### 3.Cookies
```c++
string cookies ="cookies";
string url="http://nyloner.cn";

Requests requests;
shared_ptr<Response> res = requests.get(url,cookies);
if (res->curl_code == 0)
{
    cout << res->cookies << endl;
    cout << res->s_response_headers << endl;
    cout << res->text << endl;
}
```

#### 4.Session
```c++
Session session;

PostData post_data;
post_data["username"]="username";
post_data["password"]="password";
post_data["verifycode"]="verifycode";

session.post("http://nyloner.cn/login/",post_data);
shared_ptr<Response> res=session.get("http://nyloner.cn/user/");
if (res->curl_code == 0)
{
    cout << res->cookies << endl;
    cout << res->s_response_headers << endl;
    cout << res->text << endl;
}
```
