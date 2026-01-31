/*
 * TK01-XL LED - Arduino Uno R3 示例程序
 * 
 * 功能说明：
 * 本程序演示如何使用 TK01-XL LED 模块
 * 
 * 引脚连接：
 * 请根据实际接线修改程序中的引脚定义
 * 
 * 使用方法：
 * 1. 将程序上传到Arduino Uno R3开发板
 * 2. 打开串口监视器（波特率9600）查看输出信息
 */

// 定义引脚号：根据实际接线修改这个数字
#define LED_PIN 13  // SIGNAL引脚连接的Arduino数字引脚号（如D13）

void setup() {
  // 设置LED引脚为输出模式（用来控制LED亮灭）
  pinMode(LED_PIN, OUTPUT);
  
  // 启动串口通信，用于调试（波特率9600）
  Serial.begin(9600);
}

void loop() {
  // LED闪烁效果
  digitalWrite(LED_PIN, HIGH);  // 输出高电平，点亮LED
  Serial.println("LED点亮");
  delay(1000);                  // 等待1秒
  
  digitalWrite(LED_PIN, LOW);   // 输出低电平，熄灭LED
  Serial.println("LED熄灭");
  delay(1000);                  // 等待1秒
}
