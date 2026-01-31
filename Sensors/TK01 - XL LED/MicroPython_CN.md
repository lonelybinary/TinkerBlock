# 树莓派 Pico 2 程序示例

## 目标

本示例演示如何使用 TK01 XL LED 模块在树莓派 Pico 2 上实现 LED 闪烁，掌握 MicroPython 下 GPIO 输出与基本程序结构（循环、延时、打印）的用法。

## 连线

- **GND** → 树莓派 Pico 2 的 GND
- **SIGNAL** → 树莓派 Pico 2 的 GPIO 0（若程序中修改了 `LED_PIN`，则接对应引脚）
- **NC** → 悬空不接

## 代码

```python
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
```

# 程序讲解

**第 1–14 行：文档字符串**

- 说明程序功能、引脚连接与使用方法，不影响运行。

**第 16–17 行：导入库**

```python
from machine import Pin  # 控制GPIO引脚
import time              # 时间相关功能（用于延时）
```

- **`machine.Pin`：** 用于控制 Pico 的 GPIO 引脚
- **`time`：** 提供 `sleep()` 等时间相关功能

**第 19–23 行：引脚定义与对象创建**

```python
LED_PIN = 0  # SIGNAL引脚连接的GPIO号（如GPIO 0）
led = Pin(LED_PIN, Pin.OUT)  # 设置LED引脚为输出模式
```

- **`LED_PIN = 0`：** SIGNAL 连接的 GPIO 编号，接其他引脚时修改此处
- **`Pin(LED_PIN, Pin.OUT)`：** 将引脚设为输出模式，用于控制 LED 亮灭

**第 25–34 行：主循环**

```python
while True:
    led.on()
    print("LED点亮")
    time.sleep(1)

    led.off()
    print("LED熄灭")
    time.sleep(1)
```

- **`while True`：** 无限循环，程序持续运行
- **`led.on()`：** 输出高电平，点亮 LED
- **`led.off()`：** 输出低电平，熄灭 LED
- **`time.sleep(1)`：** 延时 1 秒
