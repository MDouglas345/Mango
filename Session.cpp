#include "Session.h"

void Session::HandleRead(){
  auto self(shared_from_this());
  socket.async_read_some(asio::buffer(ReadBuffer, sizeof(MInterface)),
      [this, self](std::error_code ec, std::size_t length)
      {
        if (!ec)
        {
          MInterface *Message = (MInterface*)&ReadBuffer;
          switch (Message->type){
            case 0:
              std::cout << "User chose 0\n";break;
            case 1:
              std::cout << "User chose 1\n";break;
          }
        }
      });
}

void Session::HandleWrite(){

}

void Session::Start(){
  HandleRead();
}
