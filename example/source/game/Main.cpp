#include "Game.hpp"

#include <gdl/log/Emit.hpp>

#include <gdl/net/TcpServerSocket.hpp>
#include <gdl/net/Address.hpp>

#include <gdl/oal/Device.hpp>
#include <gdl/oal/Context.hpp>
#include <gdl/oal/File.hpp>
#include <gdl/oal/Buffer.hpp>
#include <gdl/oal/Source.hpp>

#include <gdl/math/Vector2.hpp>

#include <gdl/gui/Component.hpp>

using namespace gdl;

int main()
{
    demo::Game g("arch", 200, 100, 1400, 900);
    g.run();

//    net::TcpServerSocket server{"127.0.0.1", 1337};
//    if (server.bind() && server.listen())
//    {
//        while (true)
//        {
//            auto socket = server.accept();
//            auto address = socket.getRemoteAddress();
//            log::out<log::Info>() << "New connection from " << address.ip << ":" << address.port << log::ENDL;
//            socket.close();
//        }
//    }
//    else
//    {
//        log::out<log::Error>() << "Unable to bind server to port" << log::ENDL;
//    }

//    oal::Device device;
//    oal::Context context(device);

//    oal::File file("resource/sfx/rain.ogg");
//    log::out() << "Channels: " << file.channelCount() << ", Samples: " << file.samples().size() << ", Sample rate: " << file.sampleRate() << log::ENDL;

//    oal::Buffer buffer;
//    buffer.write(file);

//    oal::Source source(buffer);
//    source.play();

//    while (true) {}

	return 0;
}
