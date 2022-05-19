#include "ResponseRepository.h"
#include "../RequestRepository/RequestRepository.h"

 ResponseRepository::ResponseRepository() = default;

 ResponseRepository::ResponseRepository(std::string number, std::string info)
      : number{number}, info{info},version{"HTTP/1.0"}
       {}

void ResponseRepository::sendResponse(int clientSocket,const ResponseRepository& response) {
  std::string responseString;
  responseString += response.version + ' ';
  responseString += response.number + ' ';
  responseString += response.info + '\n';
  for (const auto &header : response.headers) {
    responseString += header.first + ": " + header.second + '\n';
  }
  responseString += '\n' + response.body + '\n';
  ssize_t sending =
      send(clientSocket, responseString.c_str(), responseString.size(), 0);
  handle(sending, static_cast<ssize_t>(-1),
         "Couldn't send a message on a socket!");
}



void ResponseRepository::answer(void *data) {}

