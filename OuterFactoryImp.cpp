#include <sstream>
#include "OuterFactoryImp.h"
#include "LogComm.h"
#include "GMServer.h"
#include "util/tc_hash_fun.h"

//
using namespace wbl;

OuterFactoryImp::OuterFactoryImp(): _pFileConf(NULL)
{
    createAllObject();
}

OuterFactoryImp::~OuterFactoryImp()
{
    deleteAllObject();
}

void OuterFactoryImp::deleteAllObject()
{
    if(NULL != _pFileConf)
    {
        delete _pFileConf;
        _pFileConf = NULL;
    }
}

void OuterFactoryImp::createAllObject()
{
    try
    {
        deleteAllObject();

        //本地配置文件
        _pFileConf = new tars::TC_Config();

        //tars代理Factory,访问其他tars接口时使用
        _pProxyFactory = new OuterProxyFactory();
        LOG_DEBUG << "init proxy factory succ." << endl;

        //加载配置
        load();
    }
    catch (TC_Exception &ex)
    {
        LOG->error() << ex.what() << endl;
        throw;
    }
    catch (exception &e)
    {
        LOG->error() << e.what() << endl;
        throw;
    }
    catch (...)
    {
        LOG->error() << "unknown exception." << endl;
        throw;
    }

    return;
}

//读取所有配置
void OuterFactoryImp::load()
{
    __TRY__

    //拉取远程配置
    g_app.addConfig(ServerConfig::ServerName + ".conf");

    WriteLocker lock(m_rwlock);

    _pFileConf->parseFile(ServerConfig::BasePath + ServerConfig::ServerName + ".conf");
    LOG_DEBUG << "init config file succ:" << ServerConfig::BasePath + ServerConfig::ServerName + ".conf" << endl;

    //代理配置
    readPrxConfig();
    printPrxConfig();

    __CATCH__
}

//代理配置
void OuterFactoryImp::readPrxConfig()
{
    //配置服务
    _ConfigServantObj       =   (*_pFileConf).get("/Main/Interface/ConfigServer<ProxyObj>", "");
    _HallServantObj         =   (*_pFileConf).get("/Main/Interface/HallServer<ProxyObj>", "");
    _GlobalServantObj       =   (*_pFileConf).get("/Main/Interface/GlobalServer<ProxyObj>", "");
    _sPushServantObj        =   (*_pFileConf).get("/Main/Interface/PushServer<ProxyObj>", "");
    _sOrderServantObj       =   (*_pFileConf).get("/Main/Interface/OrderServer<ProxyObj>", "");
    _sSocialServerObj       =   (*_pFileConf).get("/Main/Interface/SocialServer<ProxyObj>", "");
}

void OuterFactoryImp::printPrxConfig()
{
    ROLLLOG_DEBUG << "_ConfigServantObj ProxyObj:"          << _ConfigServantObj        << endl;
    ROLLLOG_DEBUG << "_HallServantObj ProxyObj:"            << _HallServantObj          << endl;
    ROLLLOG_DEBUG << "_GlobalServantObj ProxyObj:"          << _GlobalServantObj        << endl;
    ROLLLOG_DEBUG << "_sPushServantObj ProxyObj: "          << _sPushServantObj         << endl;
    ROLLLOG_DEBUG << "_sOrderServantObj ProxyObj: "         << _sOrderServantObj         << endl;
    ROLLLOG_DEBUG << "_sSocialServerObj ProxyObj: "         << _sSocialServerObj         << endl;
}

const config::ConfigServantPrx OuterFactoryImp::getConfigServantPrx()
{
    if (!_ConfigServantPrx)
    {
        _ConfigServantPrx = Application::getCommunicator()->stringToProxy<config::ConfigServantPrx>(_ConfigServantObj);
        LOG_DEBUG << "Init _ConfigServantObj succ, _ConfigServantObj: " << _ConfigServantObj << endl;
    }

    return _ConfigServantPrx;
}

const hall::HallServantPrx OuterFactoryImp::getHallServantPrx(const long uid)
{
    if (!_HallServerPrx)
    {
        _HallServerPrx = Application::getCommunicator()->stringToProxy<hall::HallServantPrx>(_HallServantObj);
        LOG_DEBUG << "Init _HallServantObj succ, _HallServantObj: " << _HallServantObj << endl;
    }

    if (_HallServerPrx)
    {
        return _HallServerPrx->tars_hash(uid);
    }

    return NULL;
}

const hall::HallServantPrx OuterFactoryImp::getHallServantPrx(const string key)
{
    if (!_HallServerPrx)
    {
        _HallServerPrx = Application::getCommunicator()->stringToProxy<hall::HallServantPrx>(_HallServantObj);
        LOG_DEBUG << "Init _HallServantObj succ, _HallServantObj: " << _HallServantObj << endl;
    }

    if (_HallServerPrx)
    {
        return _HallServerPrx->tars_hash(tars::hash<string>()(key));
    }

    return NULL;
}

//
const global::GlobalServantPrx OuterFactoryImp::getGlobalServantPrx(const long uid)
{
    if (!_GlobalServantPrx)
    {
        _GlobalServantPrx = Application::getCommunicator()->stringToProxy<global::GlobalServantPrx>(_GlobalServantObj);
        ROLLLOG_DEBUG << "Init _GlobalServantObj succ, _GlobalServantObj:" << _GlobalServantObj << endl;
    }

    if (_GlobalServantPrx)
    {
        return _GlobalServantPrx->tars_hash(uid);
    }

    return NULL;
}

//PushServer代理
const push::PushServantPrx OuterFactoryImp::getPushServerPrx(const long uid)
{
    if (!_pushServerPrx)
    {
        _pushServerPrx = Application::getCommunicator()->stringToProxy<push::PushServantPrx>(_sPushServantObj);
        LOG_DEBUG << "Init _sPushServantObj succ, _sPushServantObj: " << _sPushServantObj << endl;
    }

    if (_pushServerPrx)
    {
        return _pushServerPrx->tars_hash(uid);
    }

    return NULL;
}

const order::OrderServantPrx OuterFactoryImp::getOrderServerPrx(const long uid)
{
    if (!_OrderServerPrx)
    {
        _OrderServerPrx = Application::getCommunicator()->stringToProxy<order::OrderServantPrx>(_sOrderServantObj);
        ROLLLOG_DEBUG << "Init _OrderServantObj succ, _sOrderServantObj : " << _sOrderServantObj << endl;
    }

    if (_OrderServerPrx)
    {
        return _OrderServerPrx->tars_hash(uid);
    }

    return NULL;
}

const Social::SocialServantPrx OuterFactoryImp::getSocialServerPrx(long uid)
{
    if (!_socialServerPrx)
    {
        _socialServerPrx = Application::getCommunicator()->stringToProxy<Social::SocialServantPrx>(_sSocialServerObj);
        ROLLLOG_DEBUG << "Init _OrderServantObj succ, _sSocialServerObj : " << _sSocialServerObj << endl;
    }

    if (_socialServerPrx)
    {
        return _socialServerPrx->tars_hash(uid);
    }

    return NULL;
}

int OuterFactoryImp::getRoomServerPrx(const string &id, string &prx)
{
    map<string, string> mapRoomServerFromRemote;
    int iRet = getConfigServantPrx()->listAllRoomAddress(mapRoomServerFromRemote);
    if (iRet != 0)
    {
        return -1;
    }

    if (id.length() == 0)
        return -2;

    auto it = mapRoomServerFromRemote.find(id);
    if (it == mapRoomServerFromRemote.end())
        return -3;

    prx = it->second;
    return 0;
}

//格式化时间
string OuterFactoryImp::GetTLogTimeFormat()
{
    string sFormat("%Y-%m-%d %H:%M:%S");
    time_t t = time(NULL);
    struct tm *pTm = localtime(&t);
    if(pTm == NULL)
    {
        return "";
    }

    char sTimeString[255] = "\0";
    strftime(sTimeString, sizeof(sTimeString), sFormat.c_str(), pTm);
    return string(sTimeString);
}

//拆分字符串成整形
int OuterFactoryImp::splitInt(string szSrc, vector<int> &vecInt)
{
    split_int(szSrc, "[ \t]*\\|[ \t]*", vecInt);

    return 0;
}

//域名解析
void OuterFactoryImp::getIp(char *domain, char *ip)
{
    if(domain == NULL || ip == NULL)
    {
        return;
    }

    if(strlen(domain) == 0)
    {
        return;
    }

    //
    struct hostent host = *gethostbyname(domain);
    for(int i = 0; host.h_addr_list[i]; i++)
    {
        strcpy(ip, inet_ntoa(*(struct in_addr *)host.h_addr_list[i]));

        break;
    }
}

//域名解析
string OuterFactoryImp::getIp(const string &domain)
{
    if(domain.length() == 0)
    {
        return "";
    }

    //
    struct hostent host = *gethostbyname(domain.c_str());
    for(int i = 0; host.h_addr_list[i]; i++)
    {
        string ip = inet_ntoa(*(struct in_addr *)host.h_addr_list[i]);

        return ip;
    }

    return "";
}

////////////////////////////////////////////////////////////////////////////////


