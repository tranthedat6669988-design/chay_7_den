// Chương trình điều khiển 7 đèn LED:
// - Lúc đầu: tất cả 7 đèn đều sáng (trong 2 giây)
// - Lúc sau: tắt hết rồi nhấp nháy từng đèn một theo thứ tự lặp lại

const int ledPins[] = {2, 3, 4, 5, 6, 7, 8}; // Chân nối 7 đèn LED (D2 -> D8)
const int numLeds = 7;

const unsigned long initialOnTime = 2000; // Thời gian cả 7 đèn cùng sáng lúc đầu (ms)
const unsigned long blinkOnTime = 1000;    // Thời gian mỗi đèn sáng khi nhấp nháy (ms)
const unsigned long blinkOffTime = 600;   // Thời gian nghỉ giữa các lần nhấp nháy (ms)

void setup() {
  // Cấu hình 7 chân là OUTPUT và bật sáng tất cả lúc đầu
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
  }

  // Giữ tất cả 7 đèn sáng trong 2 giây
  delay(initialOnTime);

  // Tắt toàn bộ đèn trước khi chuyển sang chế độ nhấp nháy từng cái
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(blinkOffTime);
}

void loop() {
  // Nhấp nháy từng đèn một từ LED 1 đến LED 7
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(blinkOnTime);
    digitalWrite(ledPins[i], LOW);
    delay(blinkOffTime);
  }
}
