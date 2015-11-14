#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>

#include <iostream>
#include <sstream>

class HelloFastCGI : virtual public fastcgi::Component, virtual public fastcgi::Handler
{
    public:
        HelloFastCGI(fastcgi::ComponentContext *context) :
                fastcgi::Component(context)
        {

        }

        virtual void onLoad()
        {

        }

        virtual void onUnload()
        {

        }

        virtual void handleRequest(fastcgi::Request *request, fastcgi::HandlerContext *context)
        {
		std::string method = request->getRequestMethod();
		std::string uri = request->getURI();
		std::string uriWithoutQuery = uri;
		std::size_t pos = uri.find('?');
		if (pos != std::string::npos)
		{
			uriWithoutQuery = uri.substr(0, pos);
		}
		
		std::vector<std::string> uriParts = split(uri, '/');
                request->setContentType("text/plain");
                std::stringbuf buffer("Hello " + (request->hasArg("name") ? request->getArg("name") : "stranger") + " HTTP Method: " + method + " URI: " + uri + " URI Without Query: " + uriWithoutQuery);
                request->write(&buffer);
        }

	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	    std::stringstream ss(s);
	    std::string item;
	    while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	    }
	    return elems;
	}


	std::vector<std::string> split(const std::string &s, char delim) {
	    std::vector<std::string> elems;
	    split(s, delim, elems);
	    return elems;
	}
};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("HelloFastCGIFactory", HelloFastCGI)
FCGIDAEMON_REGISTER_FACTORIES_END()
