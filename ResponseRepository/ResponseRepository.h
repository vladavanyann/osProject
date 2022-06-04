#ifndef  RESPONSE_REPOSITORY
#define  RESPONSE_REPOSITORY
#include <string>
#include <map>
#include "ResponseRepository.h"
#include <boost/asio/post.hpp>

class ResponseRepository {
  std::string number;
  std::string info;
  std::string version;
  std::string body;
  std::string statusInfoTxt;
  std::string statusInfoCode;
  std::map<std::string, std::string> headers;
  
  ResponseRepository();

  ResponseRepository(std::string number, std::string info, std::string statusInfoTxt, std::string statusInfoCode) // version-y default "HTTP/1.0"
  {};
  void sendResponse(ResponseRepository& reqObj);
  static void answer(void *);
  

};

#endif
