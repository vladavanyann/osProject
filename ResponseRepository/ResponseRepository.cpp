#include "ResponseRepository.h"
#include "../RequestRepository/RequestRepository.h"

 ResponseRepository() = default;

  ResponseRepository(std::string number, std::string info)
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

ResponseRepository ResponseRepository::generateResponse(
    const std::map<std::pair<std::string, std::string>, Service *>
        *functionality,
    const http::Request &clientRequest) {
  std::pair<std::string, std::string> requestType =
      std::make_pair(clientRequest.method, clientRequest.path);
  auto finding = functionality->find(requestType);
  if (finding == functionality->end()) {
    throw RESPONSE_404;
  }
  auto clientService = finding->second;
  http::Response clientResponse = clientService->doService(clientRequest);
  return clientResponse;
}

void ResponseRepository::answer(void *data) {
  auto translationUnit = reinterpret_cast<Translator *>(data);
  try {
    try {
      while (true) {
        RequestRepository clientRequest = getRequest(translationUnit->clientSocket);
        ResponseRepository clientResponse =
            generateResponse(translationUnit->functionality, clientRequest);
        sendResponse(translationUnit->clientSocket, clientResponse);
      }
    } catch (const http::Response &ex) {
      sendResponse(translationUnit->clientSocket, ex);
      int closing = close(translationUnit->clientSocket);
      handle(closing, -1, "Couldn't close file descriptor");
      delete translationUnit;
    } catch (const std::exception &ex) {
      sendResponse(translationUnit->clientSocket, RESPONSE_500);
      int closing = close(translationUnit->clientSocket);
      handle(closing, -1, "Couldn't close file descriptor");
      delete translationUnit;
      std::cout << ex.what() << std::endl;
    }
  } catch (const std::exception &ex) {
    std::cout << ex.what();
  }
}

