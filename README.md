# Thông tin sinh viên

- Họ và tên: Tô Quang Huy
- Mã sinh viên: ***23021579***
- K68CA1 - CNTT: Khoa học máy tính
- Trường đại học Công nghệ, Đại học Quốc gia Hà Nội (UET-VNU)

# Galaxy Guardian

![](https://img.upanh.tv/2024/05/09/gameLogo.png)


## Giới thiệu

Galaxy Guardian (Vệ binh ngân hà) là game bắn súng 2D góc nhìn từ trên xuống.  Vũ trụ của chúng ta đang bị tấn công,  với nghĩa vụ của một vệ binh ngân hà, bạn sẽ điều khiển phi thuyền tấn công và tiêu diệt các thế lực xấu xa.

### Tính năng
- Lưu điểm cao (High Score) và tên của 5 người chơi điểm cao nhất (file csv)
- Chuyển đổi skin phi thuyền
- Pause game: Return Menu, New Game, Continue, hiển thị điểm để vào top High Score và điểm hiện tại của người chơi
- Play Again-Menu: Sign Name - Lưu tên và điểm khi lọt top 5
### Thuật toán trong trò chơi:
- Sinh 1 loạt Bot ngẫu nhiên không bị trùng vị trí (hàm randomBotsPos trong Bot.h)
- Thuật toán ra chiêu của Bots (trong Bot.h và main)
- Sử dụng thời gian cho Player-Skill, Bots-Skill và Thiên thạch
- Đạn bắn bay theo gia tốc, góc lệch:
```cpp
vectorPlayerBullets[i].speed += vectorPlayerBullets[i].acceleration;
vectorPlayerBullets[i].rect.x += vectorPlayerBullets[i].speed * sin(vectorPlayerBullets[i].slope);
vectorPlayerBullets[i].rect.y -= vectorPlayerBullets[i].speed * cos(vectorPlayerBullets[i].slope);
```

### Cách chơi

![QWE](https://img.upanh.tv/2024/05/09/readmi_1.gif)


**Di chuyển**: 

Phi thuyền của bạn sẽ di chuyển theo con trỏ chuột

**Sử dụng chiêu thức**: 
- **Q**: Tạo giáp
- **W**: Tăng sức mạnh cho vũ khí
- **E**: Gọi 2 phi thuyền hỗ trợ

> Bạn sẽ nhận được thêm chiêu thức, buff tốc bắn và máu khi diệt Bot

## Đồ họa:
![Rank](https://img.upanh.tv/2024/05/09/readme_rank.gif)
> *Xếp hạng dựa trên điểm số bạn đạt được*

![Aircraft](https://img.upanh.tv/2024/05/09/readme_aircraft.gif)
> *Chuyển đổi Skin Phi thuyền*

![Bots](https://img.upanh.tv/2024/05/09/readme_bots.jpg)
> *Các loại Bot lớn*

![HighScore](https://img.upanh.tv/2024/05/14/image0bbe0ee736bf0156.png)
> *Bảng xếp hạng top người chơi - High Score*

![Screenshot](https://img.upanh.tv/2024/05/14/image17ee5dce79cfb9ef.png)
> *Hướng dẫn chơi - chụp màn hình từ trong Game*

![Screenshot-Gameplay](https://img.upanh.tv/2024/05/14/image19c0a5b62cf17291.png)
> *Gaming !*

### Điểm đã đạt được: 10/10
