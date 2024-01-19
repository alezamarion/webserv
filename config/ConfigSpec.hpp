#ifndef ConfigSpec_HPP
#define ConfigSpec_HPP

#include <map>
#include <string>
#include <vector>

class ConfigSpec
{
    public:
        // Constructors
        ConfigSpec(void);

        // Copy constructor
        ConfigSpec(ConfigSpec const &src);

        // Destructor
        ~ConfigSpec(void);

        // Copy assignment operator
        ConfigSpec &operator=(ConfigSpec const &rhs);

        //methods:
        void setDirectives(const std::map<std::string, std::vector<std::string> > &directives);
        void setLocationBlocks(const std::map<std::string, std::map<std::string, std::string> > &locationBlocks);

        //directive getters:
        std::vector<std::string> getDirectiveValues(const std::string& directiveName);
        int getPort() const;
        std::vector<std::string> getServerName() const;
        std::string getIndex() const;
        std::string getRoot() const;
        std::string getAutoindex() const;
        std::vector<std::string> getErrorPage() const;
        std::vector<std::string> getCgi() const;

        //debug:
        void printParsedDirectives(void) const;
        void printParsedLocationBlocks(void) const;




    private:
    std::map<std::string, std::vector<std::string> > _directives;
    std::map<std::string, std::map<std::string, std::string> > _locationBlocks;
};

#endif

