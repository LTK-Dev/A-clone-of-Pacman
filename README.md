# A-clone-of-Pacman
Lê Tuấn Kiệt - UET

BTL - Game (INT2215 26)

Link video demo:

## Mục lục
1. [Cách tải và cài đặt game](#cách-tải-và-chơi-game)
2. [Cách chơi game](#cách-chơi-game)
3. [Chi tiết về game](#chi-tiết-về-game)
4. [Chi tiết các level game](#chi-tiết-các-level-game) 
5. [Nguồn tham khảo](#nguồn-tham-khảo)

### Nội dung
1. ### Cách tải và cài đặt game
    Bước 1: Tải và cài đặt [VSCode](https://code.visualstudio.com/download)
    
    Bước 2: Clone file về VSCode
    
    Bước 3: Vào Terminal -> New Terminal
    
    Bước 4: Gõ `make` đợi cho chương trình chạy rồi gõ `./main` để chạy game
2. ### Cách chơi game
    Bạn sẽ điều khiển `Pacman` đi ăn hết các `dot` để chiến thắng trong lúc né tránh bị các con `Ghost` ăn bạn
    
    Dùng phím W A S D hoặc các phím mũi tên để di chuyển `Pacman`
    
    Có 4 con ma `Blinky` , `Pinky` , `Clyde` , `Inky`. Ta có thể ăn các chấm `Power dot` để  khiến các con ma hoảng sợ và trong thời gian này ta có thể ăn
    được chúng
3. ### Chi tiết về game 
    Game sẽ có giới hạn `2^31 - 1 level` đây cũng chính là giới hạn của `int`
    
    Về mỗi con ghost thì bọn chúng có một cách hoạt động riêng. Nhìn chung thì chúng có 3 trạng thái:

    #### `Đuổi`
    - `Blinky`: đuổi theo `Pacman`.   
    - `Pinky` : đi đến vị trí trước mặt `Pacman` 4 ô.
    - `Inky`  : đi đến vị trí được tạo bằng cách đối xứng vị trí của `Blinky` qua tâm là `Pacman`.
    - `Clyde` : đuổi theo Pacman nếu khoảng cách giữa nó và Pacman lớn hơn 8 ô, nếu không thì nó sẽ về góc của mình.  
    #### `Thăm dò`
    Trong trạng thái thăm dò, các con ma sẽ đi xung quanh 1 góc của bản đồ. Trong thời gian này `Pacman` sẽ dễ thở hơn.

    #### `Hoảng sợ`    
    Trong trạng thái hoảng sợ, các con ma sẽ chuyển sang màu xanh và `Pacman` có thể ăn chúng trong 1 khoảng thời gian nhất định.

    Sau khi ăn thì con ma đó sẽ chuyển thành `đôi mắt` , tìm đường ngắn nhất và đi về phía trước của lồng và hồi sinh.

    2 trạng thái đầu sẽ luân phiên nhau, trạng thái hoảng sợ sẽ chỉ kích hoạt khi Pacman ăn chấm sức mạnh
4. ### Chi tiết các level game
    Game sẽ có giới hạn level là giới hạn của `int` và độ khó sẽ tăng dần theo các mốc :
    
    - Level <= 3 : 
              `FRIGHTEN_TIME` : 7.0
              `PINKY_COIN_LIMIT` : 15
              `INKY_COIN_LIMIT` : 60
              `CLYDE_COIN_LIMIT` : 90
              
    - Level <= 5 :
              `FRIGHTEN_TIME` : 5.0
              `PINKY_COIN_LIMIT` : 0
              `INKY_COIN_LIMIT` : 30
              `CLYDE_COIN_LIMIT` : 60
            
    - Level > 5  :
              `FRIGHTEN_TIME` : 3.0
              `PINKY_COIN_LIMIT` : 0
              `INKY_COIN_LIMIT` : 0
              `CLYDE_COIN_LIMIT` : 0
    - Trong đó   :
    
    `FRIGHTEN_TIME` là thời gian hoảng sợ của các con ma đơn vị giây 
    
    `PINKY_COIN_LIMIT` ,`INKY_COIN_LIMIT`,`CLYDE_COIN_LIMIT` là số `coins` mà `Pacman` phải ăn để các con ma tương ứng thoát khỏi lồng để đi bắt `Pacman`
5. ### Nguồn tham khảo
- Các nguồn âm thanh và hình ảnh mình lấy từ trên mạng kết hợp với tự tạo bằng photoshop
- SDL 2.0 từ [lazyfoo](https://lazyfoo.net/tutorials/SDL/)
- Tham khảo về 1 chương trình SDL2 từ 1 series lập trình Game RPG với SDL2 của Youtuber: [Let's Make Games](https://www.youtube.com/channel/UCAM9ZPgEIdeHAsmG50wqL1g)  
  [Link tới danh sách phát](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)
- Tham khảo khung chương trình và cách tổ chức game từ 1 video làm game Pacman của Youtuber: [HexagonNico](https://www.youtube.com/watch?v=4AatUPAXrj8)  
  [Link tới Video](https://www.youtube.com/watch?v=4AatUPAXrj8)
- Để xây dựng và phát triển các con Ghost trong game, mình đã tham khảo một video về Ai của game qua Youtube: [Pac-Man Ghost AI Explained](https://www.youtube.com/watch?v=ataGotQ7ir8)
- Một số BTL và dự án trên mạng lẫn github từ nhiều nguồn [Nhiều nhất là từ nguồn này] (https://github.com/tungddk2/Pacman)

          
    
