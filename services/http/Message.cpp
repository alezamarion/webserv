#include "Message.hpp"
#include "BodyParser.hpp"

Message::Message()
    : body(NULL)
    , parser(NULL)
{
    clear(*this);
}

void clear(Message& msg)
{
    msg.method = UNKNOWN;
    msg.version.clear();
    msg.path.clear();
    msg.query.clear();
    msg.headers.clear();
    msg.state = HEADERS;

    if (msg.body != NULL)
    {
        delete msg.body;
    }
    if (msg.parser != NULL)
    {
        delete msg.parser;
    }
}

// ------------------------------------------------------------------------

Body::Body(BodyType type, BodyContent content)
    : m_type(type)
    , m_content(content)
{
}

Body::Body(const Body& rhs)
    : m_type(rhs.m_type)
    , m_content(rhs.m_content)
{
}

Body& Body::operator=(const Body& rhs)
{
    if (&rhs != this)
    {
        m_type = rhs.m_type;
        m_content = rhs.m_content;
    }
    return *this;
}

Body::~Body()
{
}

BodyType Body::getType() const
{
    return m_type;
}

const std::string& Body::get(const std::string& key)
{
    BodyContent::iterator it = m_content.find(key);
    if (it != m_content.end())
    {
        return it->second;
    }
    return m_empty;
}
