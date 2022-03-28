#include "HTTP_Server.h"

Poco::Net::HTTPRequestHandler *MyHttpRequestFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request)
{
    if(request.getURI() == "/hello" && request.getMethod() == "GET")
    {
        return new MyHelphandler;
    }
    else
    {
        return new MyErrorHandler;
    }
}
