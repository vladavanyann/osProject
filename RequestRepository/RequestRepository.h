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
#include <sys/socket.h>

class RequestRepository{

private:
    std::string method;
    std::string url;
    std::string path;
    std::string version;
    std::string body;
    std::string status;
    std::map<std::string, std::string> headers;

public:

    RequestRepository();
    RequestRepository(std::string method, std::string url, std::string path,std::string version, std::string body,std::string status);
    static RequestRepository getRequest(int);


};


#endif
