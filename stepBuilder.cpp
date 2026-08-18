#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class HTTPREquest {
  string url;
  string method;
  map<string, string> headers;
  map<string, string> queryParams;
  string body;
  int timeout;

public:
  HTTPREquest() : url("https://localhost"), method("GET"), body(""), timeout(30) {}

  friend class HTTPREequestBuilder;

  void execute() const {
    cout << "URL: " << url << endl;
    cout << "Method: " << method << endl;
    cout << "Timeout: " << timeout << " seconds" << endl;

    cout << "Headers:" << endl;
    for (const auto &h : headers) {
      cout << "  " << h.first << ": " << h.second << endl;
    }

    cout << "Query Params:" << endl;
    for (const auto &q : queryParams) {
      cout << "  " << q.first << "=" << q.second << endl;
    }

    cout << "Body: " << body << endl;
  }
};

// abstract class with withURL method which returns the reference of next paramsStep Class
class URLStep {
public:
  virtual ~URLStep() = default;
  virtual class ParamsStep &withURL(const string &url) = 0;
};

// abstract class with Params method which returns the reference of next BodyStep
class ParamsStep {
public:
  virtual ~ParamsStep() = default;
  virtual class ParamsStep &withParam(const string &key, const string &value) = 0;
  virtual class ParamsStep &withParams(const map<string, string> &params) = 0;
  virtual class BodyStep &withBody(const string &body) = 0;
};

// abstract class with body step which returns the reference of next Optional Class
class BodyStep {
public:
  virtual ~BodyStep() = default;
  virtual class OptionalStep &withMethod(const string &method) = 0;
};

// class with optional URL params step which returns the reference of next BuildStep class
class OptionalStep {
public:
  virtual ~OptionalStep() = default;
  virtual class OptionalStep &withMethod(const string &method) = 0;
  virtual class OptionalStep &withHeader(const string &key, const string &value) = 0;
  virtual class OptionalStep &withTimeout(int timeout) = 0;
  virtual HTTPREquest build() = 0;
};

// abstract class with build method which returns the object of HTTP request to client
class BuildStep {
public:
  virtual ~BuildStep() = default;
  virtual HTTPREquest build() = 0;
};

class HTTPREequestBuilder : public URLStep,
                           public ParamsStep,
                           public BodyStep,
                           public OptionalStep,
                           public BuildStep {
  HTTPREquest request;

public:
  HTTPREequestBuilder() = default;

  static URLStep &startBuilding() {
    static HTTPREequestBuilder builder;
    return builder;
  }

  ParamsStep &withURL(const string &url) override {
    request.url = url.empty() ? "https://localhost" : url;
    return *this;
  }

  ParamsStep &withParam(const string &key, const string &value) override {
    request.queryParams[key] = value;
    return *this;
  }

  ParamsStep &withParams(const map<string, string> &params) override {
    request.queryParams = params;
    return *this;
  }

  BodyStep &withBody(const string &body) override {
    request.body = body;
    return *this;
  }

  OptionalStep &withMethod(const string &method) override {
    request.method = method.empty() ? "GET" : method;
    return *this;
  }

  OptionalStep &withHeader(const string &key, const string &value) override {
    request.headers[key] = value;
    return *this;
  }

  OptionalStep &withTimeout(int timeout) override {
    request.timeout = timeout <= 0 ? 30 : timeout;
    return *this;
  }

  HTTPREquest build() override {
    if (request.url.empty()) request.url = "https://localhost";
    if (request.method.empty()) request.method = "GET";
    if (request.timeout <= 0) request.timeout = 30;
    return request;
  }
};

int main() {
  HTTPREquest req = HTTPREequestBuilder::startBuilding()
                        .withURL("https://example.com/api")
                        .withParam("page", "1")
                        .withParam("limit", "10")
                        .withBody("{\"name\":\"Alice\"}")
                        .withMethod("POST")
                        .withHeader("Content-Type", "application/json")
                        .withTimeout(60)
                        .build();

  req.execute();
  return 0;
}