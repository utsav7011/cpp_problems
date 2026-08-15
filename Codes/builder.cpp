#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class HTTPRequest {
  string URL;
  string method;
  map<string, string> header;
  map<string, string> queryParams;
  string body;
  int timeout;

  HTTPRequest() : timeout(30), method("GET") {}

public:
  friend class HTTPRequestBuilder;

  HTTPRequest(string url, string method = "GET",
              map<string, string> headers = {},
              map<string, string> query = {},
              string body = "",
              int timeout = 30)
      : URL(url), method(method), header(headers), queryParams(query), body(body), timeout(timeout) {}

  // method to execute the HTTP Request;
  void execute() {
    // dummy execution method that prints all the parameters only
    cout << "URL: " << URL << endl;
    cout << "Method: " << method << endl;
    cout << "Timeout: " << timeout << " seconds" << endl;

    cout << "Headers:" << endl;
    for (const auto &h : header) {
      cout << "  " << h.first << ": " << h.second << endl;
    }

    cout << "Query Params:" << endl;
    for (const auto &q : queryParams) {
      cout << "  " << q.first << "=" << q.second << endl;
    }

    cout << "Body: " << body << endl;
  }
};

// single responsibility of the builder class is to get the object
class HTTPRequestBuilder {
  string URL;
  string method;
  map<string, string> header;
  map<string, string> queryParams;
  string body;
  int timeout;

public:
  HTTPRequestBuilder() : method("GET"), timeout(30) {}

  HTTPRequestBuilder &withURL(const string &url) {
    URL = url;
    return *this;
  }

  HTTPRequestBuilder &withMethod(const string &m) {
    method = m;
    return *this;
  }

  HTTPRequestBuilder &withHeader(const string &key, const string &value) {
    header[key] = value;
    return *this;
  }

  HTTPRequestBuilder &withQueryParam(const string &key, const string &value) {
    queryParams[key] = value;
    return *this;
  }

  HTTPRequestBuilder &withBody(const string &b) {
    body = b;
    return *this;
  }

  HTTPRequestBuilder &withTimeout(int t) {
    timeout = t;
    return *this;
  }

  HTTPRequest build() {
    return HTTPRequest(URL, method, header, queryParams, body, timeout);
  }
};

int main() {
  HTTPRequest req = HTTPRequestBuilder()
                        .withURL("https://example.com/api")
                        .withMethod("POST")
                        .withHeader("Content-Type", "application/json")
                        .withQueryParam("page", "1")
                        .withQueryParam("limit", "10")
                        .withBody("{\"name\":\"Alice\"}")
                        .withTimeout(60)
                        .build();

  req.execute();

  return 0;
}