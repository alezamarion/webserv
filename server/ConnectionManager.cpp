#include "ConnectionManager.hpp"

ConnectionManager::ConnectionManager()
{
}

ConnectionManager::~ConnectionManager()
{
    std::map<int, Connection*>::iterator it;
    for (it = active.begin(); it != active.end(); ++it)
    {
        delete it->second;
    }
}

Connection* ConnectionManager::connect(Server* server, struct epoll_event* event)
{
    Connection* connection = new Connection(server, this, event);

    int clientSocket = connection->getSocket();
    active[clientSocket] = connection;

    return connection;
}

/* Close the connection */
void ConnectionManager::close(Connection* conn)
{
    std::map<int, Connection*>::iterator it = active.find(conn->getSocket());
    if (it != active.end())
    {
        delete it->second;
        active.erase(it);
    }
}

Connection* ConnectionManager::getConnection(int socket)
{
    std::map<int, Connection*>::iterator it = active.find(socket);
    if (it != active.end())
    {
        return it->second;
    }
    return NULL;
}
