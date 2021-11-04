#include "Session.h"

void Session::HandleRead(){
  auto self(shared_from_this());
  socket.async_read_some(asio::buffer(ReadBuffer, ReadBufferSize),
      [this, self](std::error_code ec, std::size_t length)
      {
        if (!ec)
        {
          MAuthenticate* Auth = (MAuthenticate*)&ReadBuffer;

          std::cout << Auth->User << " " << Auth->Password << "\n";
        }
      });
}

void Session::HandleWrite(){

}

void Session::Start(){
  HandleRead();
}
