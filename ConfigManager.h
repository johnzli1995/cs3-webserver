#ifndef _CONFIGMANAGER_H_INCLUDED
#define _CONFIGMANAGER_H_INCLUDED

#include "config_parser.h"
#include <vector>
#include <memory>

class ConfigManager {
    NginxConfig config;
    
    public:
    ConfigManager(NginxConfig);
    ConfigManager(const char*);    
    int getPort() {return getPort(config);};
    // get the config statement for each handler type, all collected into a list
    std::vector<std::shared_ptr<NginxConfigStatement> > getConfigs();
    // get the static path given a NginxConfig Statement with a childblock containing
    // root binding.
    static std::string getPath(const NginxConfig& config);
    
    
    private:
    int getPort(const NginxConfig&);
    
    
};

#endif
