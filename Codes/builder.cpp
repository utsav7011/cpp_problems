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

  HTTPRequest() : URL("https://localhost"), method("GET"), body(""), timeout(30) {}

  public:
  friend class HTTPRequestBuilder;

  HTTPRequest(string url = "https://localhost",
              string method = "GET",
              map<string, string> headers = {},
              map<string, string> query = {},
              string body = "",
              int timeout = 30)
      : URL(url.empty() ? "https://localhost" : url),
        method(method.empty() ? "GET" : method),
        header(headers),
        queryParams(query),
        body(body),
        timeout(timeout <= 0 ? 30 : timeout) {}

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
  HTTPRequestBuilder() : URL("https://localhost"), method("GET"), body(""), timeout(30) {}

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
    if (URL.empty()) URL = "https://localhost";
    if (method.empty()) method = "GET";
    if (timeout <= 0) timeout = 30;

    return HTTPRequest(URL, method, header, queryParams, body, timeout);
  }
};

class HTTPBuilderDirector {
public:
  static HTTPRequest buildDefaultRequest() {
    return HTTPRequestBuilder()
        .withURL("https://localhost")
        .withMethod("GET")
        .withHeader("Accept", "application/json")
        .withTimeout(30)
        .build();
  }

  static HTTPRequest buildRequestWithDefaults(const string &url = "https://localhost",
                                             const string &method = "GET",
                                             const string &body = "",
                                             int timeout = 30) {
    return HTTPRequestBuilder()
        .withURL(url)
        .withMethod(method)
        .withBody(body)
        .withTimeout(timeout)
        .build();
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

  HTTPRequest defaultReq = HTTPRequestBuilder()
                              .withHeader("Accept", "application/json")
                              .build();

  HTTPRequest directorReq = HTTPBuilderDirector::buildDefaultRequest();

  cout << "--- Full Request ---" << endl;
  req.execute();

  cout << "\n--- Default Request ---" << endl;
  defaultReq.execute();

  cout << "\n--- Director Default Request ---" << endl;
  directorReq.execute();

  return 0;
}