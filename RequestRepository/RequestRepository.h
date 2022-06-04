#ifndef  REQUEST_REPOSITORY
#define  REQUEST_REPOSITORY
#include <string>
#include <map>
#include "ResponseRepository.h"
#include "../Enum/Method.h"
#include <algorithm>
#include <arpa/inet.h>
#include <cstring>
#include <exception>
#include <memory>
#include <netdb.h>
#include <sstream>
#include <iostream>

class RequestRepository{

private:
    std::map<std::string, std::string> headers;
    std::string method;
    std::string url;
    std::string path;
    std::string version;
    std::string body;
    //std::string status;
    

public:

    RequestRepository();
    RequestRepository(std::string method, std::string url, std::string path,std::string version, std::string body);
    std::string getMethod();
    std::string RequestRepository::getPath();
    std::map<std::string, std::string> getHeaders();
    RequestRepository getRequest(int socketFD);
    void parse(const std::string& req, ssize_t receivedBytes);

    

};


#endif
