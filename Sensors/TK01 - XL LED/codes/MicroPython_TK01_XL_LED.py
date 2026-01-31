"""
TK01-XL LED - 树莓派 Pico 2 示例程序

功能说明：
本程序演示如何使用 TK01-XL LED 模块

引脚连接：
请根据实际接线修改程序中的引脚定义

使用方法：
1. 将程序保存到树莓派 Pico 2
2. 运行程序查看输出信息
"""

# 导入需要的库
from machine import Pin  # 控制GPIO引脚
import time              # 时间相关功能（用于延时）

# 定义引脚号：根据实际接线修改这个数字
LED_PIN = 0  # SIGNAL引脚连接的GPIO号（如GPIO 0）

# 创建引脚对象
led = Pin(LED_PIN, Pin.OUT)  # 设置LED引脚为输出模式（用来控制LED亮灭）

# 主循环：程序会一直运行
while True:
    # LED闪烁效果
    led.on()                 # 输出高电平，点亮LED
    print("LED点亮")         # 在终端显示信息
    time.sleep(1)            # 等待1秒
    
    led.off()                # 输出低电平，熄灭LED
    print("LED熄灭")         # 在终端显示信息
    time.sleep(1)            # 等待1秒
