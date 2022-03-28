#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>
#include <string>
#include <vector>
#include <Poco/XML/Name.h>


using namespace Poco::Util;
using namespace Poco::Net;
class MyHttpRequestFactory : public Poco::Net::HTTPRequestHandlerFactory
{
    virtual Poco::Net::HTTPRequestHandler*  createRequestHandler(const Poco::Net::HTTPServerRequest& request);
};
class MyHelphandler: public Poco::Net::HTTPRequestHandler
{
    virtual void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override
    {
        response.setContentType("text/plain");
        response.setStatus(Poco::Net::HTTPResponse::HTTPStatus::HTTP_OK);
        std::ostream& send_to = response.send();
        send_to << "Hi from poco server!";
    }
};
class MyErrorHandler: public Poco::Net::HTTPRequestHandler
{
    virtual void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override
    {
        response.setContentType("text/plain");
        response.setStatus(Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND);

    }
};
class MyServerApp : public ServerApplication
{
protected:
  int main(const std::vector<std::string> &)
  {
      Poco::UInt16 port = 9999;
      HTTPServerParams* pParams = new HTTPServerParams;
      pParams->setMaxQueued(100);
      pParams->setMaxThreads(16);
      ServerSocket svs(port);
      svs.listen();// set-up a server socket
      MyHttpRequestFactory* fac = new MyHttpRequestFactory();
      HTTPServer srv(fac, svs, pParams);
      // start the HTTPServer
      srv.start();
      waitForTerminationRequest();
      srv.stop();
      return Application::EXIT_OK;
  }
};

#endif // HTTP_SERVER_H

