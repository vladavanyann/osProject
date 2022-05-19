#ifndef  RESPONSE_REPOSITORY
#define  RESPONSE_REPOSITORY
#include <string>
#include <map>
#include "ResponseRepository.h"

class ResponseRepository {
  std::string number;
  std::string info;
  std::string version;
  std::string body;
  std::map<std::string, std::string> headers;
  
  ResponseRepository();

  ResponseRepository(std::string number, std::string info) // version-y default "HTTP/1.0"
    {};
  static void sendResponse(int, const ResponseRepository&);
  static void answer(void *);
  static ResponseRepository generateResponse(
    const std::map<std::pair<std::string, std::string>, Service *> *,
     const RequestRepository &);

};

#endif
