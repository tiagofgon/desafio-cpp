//
//  Pubsub envelope subscriber-cliente
//
// Tiago Gonçalves <tiago.fg@outlook.com>

#include <cstdio>
#include "zhelpers.hpp"
#include "rapidjson/include/rapidjson/rapidjson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/filewritestream.h"
#include "rapidjson/include/rapidjson/filereadstream.h"

int main () {

    // Get the port from config.conf file
    FILE* file = fopen("config.conf", "rb");
    char readBuffer[65536];
    rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));
 
    rapidjson::Document dd;
    dd.ParseStream(is);
    fclose(file);
    assert(dd["port"].IsInt());
    int port  = dd["port"].GetInt();
    std::string topico = dd["topico"].GetString();

    //address
    std::string addr="tcp://localhost:" + std::to_string(port);


    //  Prepare our context and subscriber
    zmq::context_t context(1);
    zmq::socket_t subscriber (context, ZMQ_SUB);
    subscriber.connect(addr);
    subscriber.setsockopt( ZMQ_SUBSCRIBE, topico.c_str(), topico.length());
    //subscriber.setsockopt( ZMQ_SUBSCRIBE, "C++", 3);
    
    

	//  Read envelope
	std::string topic = s_recv (subscriber);
	std::string ordem = s_recv (subscriber);
    std::string mensagem = s_recv (subscriber);
        
    const char * json = mensagem.c_str();
    rapidjson::Document d;
    d.Parse(json);
        
    std::string timestamp  = d["timestamp"].GetString();
    timestamp+=".json";
    timestamp = "msg_recebidas/" + timestamp;
        
    FILE* fp = fopen(timestamp.c_str(), "w");
    char writeBuffer[65536];
    rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
        
    rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
    d.Accept(writer);
 
    fclose(fp);

    std::cout << "Topic: " << topic << std::endl;
        
    
    return 0;
}
