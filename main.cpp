#include <iostream>
#include "HTTP_Server.h"
#include <Poco/Util/ServerApplication.h>
using namespace std;
using namespace Poco::Net;
using namespace Poco::Util;
int main(int argc, char** argv)
{
    MyServerApp app;
    return app.run(argc, argv);
}
