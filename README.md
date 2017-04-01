### Requests

基于libcurl实现的requests库

#### 1.GET
```c++
string url = "http://www.nyloner.cn";
Requests requests;
Headers headers;
headers["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36";
headers["Accept"] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";
shared_ptr<Response> res = requests.get(url, headers);
cout << res->text << endl;
```

#### 2.POST
```c++
PostData post_data;
post_data["username"] = "username";
post_data["password"] = "passwd";

Headers headers;
headers["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36";
headers["Accept"] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";

Requests requests;
string url = "http://www.nyloner.cn";
shared_ptr<Response> res = requests.post(url, post_data);
cout << res->text << endl;
```