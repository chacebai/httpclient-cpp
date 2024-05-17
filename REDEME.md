# HTTP client for C++
[![MIT license](https://img.shields.io/badge/license-MIT-blue.svg)](http://opensource.org/licenses/MIT)


## About
This is a simple HTTP client for C++. It wraps libcurl for HTTP requests and meant to be a portable
and easy-to-use API to perform HTTP related operations.

Compilation has been tested with:
- GCC 5.4.0 (GNU/Linux Ubuntu 16.04 LTS)
- Microsoft Visual Studio 2015 (Windows 10)

Underlying libraries:
- [libcurl](http://curl.haxx.se/libcurl/)

Windows Users : vcpkg (Microsoft C++ Library Manager) can be used to easily install libcurl and generate the Visual Studio solution with CMake. With vcpkg, no need to manually copy the DLL in the output directory, vcpkg handles all that ! Look at "Building under Windows via Visual Studio" section, for instructions.

require for centos
```bash
sudo yum install curl-devel -y
```

For example:
```c++
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "HTTPClient.h"

using namespace std;

int main()
{
    CHTTPClient HTTPClient([](const std::string &strLogMsg)
                           { std::cout << strLogMsg << std::endl; });
    HTTPClient.InitSession();
    std::string strWebPage;
    long lWebPageCode = 0;
    long lResultHTTPCode = 0;
    // HTTPClient.SetProxy("http://192.168.100.1:8080");
    // CHTTPClient::PostFormInfo UploadInfo;
    // UploadInfo.AddFormContent("params", "qq5MgqmIaq2SeJr/wdCni0nHc7NglWa17wCD0qvyxFvCE1OG3j1EKtP3mJrTnTnwH4MZjR5H5Y5yzPBdVcpRZvQL+5bF7lXXpiUdNHXXCFT8A5DGQiqVoaDxY62c9pFDNqMg93nG/uimVilC5RSB/SHA22FRhFLYIemByp8fb+U=");
    // HTTPClient.UploadForm("http://101.227.110.117:29002/advisor/user/h5/customer/syncUpdateParams",
    //                     UploadInfo,
    // lResultHTTPCode);
    CHTTPClient::HeadersMap RequestHeaders;
    CHTTPClient::HttpResponse ServerResponse;
    std::string strPostData = "params=qq5MgqmIaq2SeJr/wdCni0nHc7NglWa17wCD0qvyxFvCE1OG3j1EKtP3mJrTnTnwH4MZjR5H5Y5yzPBdVcpRZvQL+5bF7lXXpiUdNHXXCFT8A5DGQiqVoaDxY62c9pFDNqMg93nG/uimVilC5RSB/SHA22FRhFLYIemByp8fb+U=";
    // std::string strPostData = "params=" + HTTPClient.url_encode("qq5MgqmIaq2SeJr/wdCni0nHc7NglWa17wCD0qvyxFvCE1OG3j1EKtP3mJrTnTnwH4MZjR5H5Y5yzPBdVcpRZvQL+5bF7lXXpiUdNHXXCFT8A5DGQiqVoaDxY62c9pFDNqMg93nG/uimVilC5RSB/SHA22FRhFLYIemByp8fb+U=");
    HTTPClient.Post("http://101.227.110.117:29002/advisor/user/h5/customer/syncUpdateParams", RequestHeaders, strPostData, ServerResponse);
    cout << "iCode: " << ServerResponse.iCode << endl;
    cout << "strBody: " << ServerResponse.strBody << endl;
    HTTPClient.CleanupSession();
    return 0;
}
```

source: [https://github.com/embeddedmz/httpclient-cpp](https://github.com/embeddedmz/httpclient-cpp)

