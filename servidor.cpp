//
//  Pubsub envelope publisher-servidor
//
// Tiago Gonçalves <tiago.fg@outlook.com>

#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#include "zhelpers.hpp"
#include "rapidjson/include/rapidjson/rapidjson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/filereadstream.h"


// function to get de exact time
std::string getTime()
{
    timeval curTime;
    time_t now;

    time(&now);
    gettimeofday(&curTime, NULL);

    int milli = curTime.tv_usec / 1000;
    char buf[sizeof "2011-10-08T07:07:09.000Z"];
    strftime(buf, sizeof buf, "%FT%T", gmtime(&now));
    sprintf(buf, "%s.%dZ", buf, milli);

    return buf;
}


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
    std::string addr="tcp://*:" + std::to_string(port);


    //  Prepare our context and publisher
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind(addr);


    
    int ordem=1;
    int id=1;

    /****** message change code ******/
    while(1){

        // Prepare json string to send to client, this is the message frame
        time_t now = time(NULL);
        // convert now to string form
        char* dt = ctime(&now);

        std::srand(now);
 
        int velocity = rand() % 256;
        std::string timestamp = getTime();

        std::string json = "{\"id\":"+std::to_string(id)+",\"velocidade\":"+std::to_string(velocity)+",\"timestamp\":\""+timestamp+"\"}";
        const char* json2 = json.c_str();

        rapidjson::Document d;
        d.Parse(json2);

        id++;

        //  Write three messages, each with an envelope and content
        s_sendmore (publisher, topico);
        s_sendmore (publisher, std::to_string(++ordem));
        s_send (publisher, json2);
    }

    return 0;
}
