
#include "RequestRepository.h"

    RequestRepository::RequestRepository() = default ;
    RequestRepository::RequestRepository(std::string method, std::string url, std::string path,std::string version, std::string body): 
                      method{method},url{url}, path{path}, version{version}, body{body}
    {}
   
RequestRepository RequestRepository::getRequest(int clientSocket) {
  RequestRepository request;
  std::string head;
  std::string body;
 // get head
 // parser (request, head);
  //get body
  request.body = body;
  return request;
}

