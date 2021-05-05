# Game Minesweeper
- 20020474 - Nguyễn Việt Thắng
- Viết bằng ngôn ngữ C++ và thư viện SDL2 trên Codeblock
- Link down game: https://drive.google.com/file/d/1yBz3b9VO7tpSNlGRjvE60dfnAzbi3eVE/view?usp=sharing
- sử dụng winrar để giải nén file Minesweeper.rar
- vào Minesweeper\bin\Minesweeper.exe để chơi
# Mô tả game
## Luồng hoạt động
- Gồm menu, chọn độ khó và giao diện trò chơi
- Nhấn escape hoặc nút X trên cửa sổ góc phải để thoát
## Thành phần game
- Bảng ô vuông trò chơi
- Bảng đếm ngược thời gian (tối đa 999 giây)
- Bảng đếm số mìn còn lại (tổng mìn - cờ)
- Bảng đếm số lần bảo vệ còn lại (3 lần) (bị trừ khi mở vào ô mìn)
- Nút menu để trở về menu
## Cách chơi
- Nhấn chuột **trái** để mở ô
- Nhấn chuột **phải** để cắm cờ nếu chắc chắn là ô có mìn
- Số trên ô vuông được mở là số mìn ở 8 ô xung quanh
## Mục tiêu
- **Điều kiện Thắng**: mở tất cả các ô mà không phải ô chứa mìn
## Độ khó
- **Dễ (beginner)**: bảng ô vuông 8 × 8 và 10 trái mìn
- **Trung bình (intermediate)**: bảng ô vuông 12 × 12 và 30 trái mìn
- **Khó (expert)**: bảng ô vuông 16 × 16 và 50 trái mìn
# Video demo game
https://drive.google.com/file/d/1KPP9gQzNRTKHg99T-oe4acKO8CWNMm-E/view?usp=sharing
