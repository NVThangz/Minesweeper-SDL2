# Game Minesweeper
- Viết bằng ngôn ngữ C++ và thư viện SDL2
- 20020474 - Nguyễn Việt Thắng
# Mô tả game
## Luồng hoạt động
- gồm menu, chọn độ khó và giao diện trò chơi
- Nhấn escape hoặc nút X trên cửa sổ góc phải để thoát
## Thành phần game
- bảng ô vuông trò chơi
- bảng đếm ngược thời gian (tối đa 1000 giây)
- bảng đếm số mìn còn lại (tổng mìn - cờ)
- bảng đếm số lần bảo vệ còn lại (3 lần) (bị trừ khi mở vào ô mìn)
- nút menu để trở về menu
## Cách chơi
- Nhấn chuột **trái** để mở ô
- Nhấn chuột **phải** để cắm cờ nếu chắc chắn là ô có mìn
## Mục tiêu
- **Điều kiện Thắng**: mở tất cả các ô mà không phải ô chứa mìn
## Độ khó
- **Dễ (beginner)**: bảng ô vuông 8 × 8 và 10 trái mìn
- **Trung bình (intermediate)**: bảng ô vuông 12 × 12 và 30 trái mìn
- **Khó (expert)**: bảng ô vuông 16 × 16 và 50 trái mìn
# Video demo game
