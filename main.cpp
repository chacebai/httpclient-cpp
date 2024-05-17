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
