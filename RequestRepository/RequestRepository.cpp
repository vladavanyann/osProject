
#include "RequestRepository.h"


RequestRepository::RequestRepository(std::string method, std::string url, std::string path,std::string version, std::string body):
                                     method{},url{}, path{}, version{}, body{}
    {}
RequestRepository::RequestRepository(std::string method, std::string url, std::string path,std::string version, std::string body): method{method},url{url}, path{path}, version{version}, body{body}
    {}

 std::string RequestRepository::getMethod(){
   return method;
 }
 std::string RequestRepository::getPath(){
   return path;
 }
std::map<std::string, std::string> RequestRepository::getHeaders(){
  return headers;
}

   
RequestRepository RequestRepository::getRequest(int socketFD){
    ssize_t receivedBytes = -1;
    std::string request;
    while (receivedBytes != 0) {
        char* message = new char[10000];
        receivedBytes = recv(socketFD, (void *) message, 10000, 0);
        if (receivedBytes < 0) { 
            close(socketFD);
            std::cerr << errno << std::endl;
            *this = RequestRepository{};
            return;
        }
        request += message;
    }
    
    return *this;
}

void parse(RequestRepository& reqObj,const std::string& req, ssize_t receivedBytes){
    int index = 0;
    std::string method = reqObj.getMethod();
    std::string path = reqObj.getPath();
    std::map<std::string, std::string> headers = reqObj.getHeaders();
    while (method[method.size() - 1] != ' ' && index < receivedBytes){
        method.push_back(req[index]);
        ++index;
    }
    while (path[path.size() - 1] != ' ' && index < receivedBytes){
        path.push_back(req[index]);
        ++index;
    }

    while (index < receivedBytes){
        std::string key;
        std::string value;
        if (req[index] == '\n'){
            ++index;
            break;
        }
        while (index < receivedBytes && req[index] != ':')
        {
                key.push_back(req[index]);
                ++index;
        }
        while (index < receivedBytes && req[index] != '\n')
        {
                value.push_back(req[index]);
                ++index;
        }
        headers.insert({key, value});
    }
   // 
   // set body ........
   //

}

//RequestRepository RequestRepository::getRequest(int clientSocket) {
  /*RequestRepository request;
  std::string head;
  std::string body;
 // get head
 // parser (request, head);
  //get body
  request.body = body;
  return request;

*/

//}

