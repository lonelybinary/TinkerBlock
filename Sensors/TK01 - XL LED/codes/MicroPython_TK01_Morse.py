"""
TK01-XL LED - Morse Code "TK01" Demo (Raspberry Pi Pico 2)

Description:
Uses LED on/off to display Morse code for "TK01". Sends once then exits.
Morse timing: dot (·) = short flash, dash (–) = long flash; 1 unit between elements, 3 units between letters.

Wiring:
Change LED_PIN below to match your wiring.

Usage:
1. Save this script to Raspberry Pi Pico 2
2. Run the script; LED sends "TK01" in Morse once, then the script ends. Terminal prints the character being sent.
"""

from machine import Pin
import time

# Connect to TK01 SIGNAL; change to match your wiring
LED_PIN = 0

# Time units (ms): 1 dot = 1 unit, 1 dash = 3 units
DOT_MS = 200
DASH_MS = DOT_MS * 3
ELEMENT_GAP_MS = DOT_MS
LETTER_GAP_MS = DOT_MS * 3
WORD_GAP_MS = DOT_MS * 7

def ms(n):
    return n / 1000.0

led = Pin(LED_PIN, Pin.OUT)

def led_on(ms_val):
    led.on()
    time.sleep(ms(ms_val))

def led_off(ms_val):
    led.off()
    time.sleep(ms(ms_val))

def send_dot():
    led_on(DOT_MS)
    led_off(ELEMENT_GAP_MS)

def send_dash():
    led_on(DASH_MS)
    led_off(ELEMENT_GAP_MS)

def send_morse_char(c):
    print("Sending:", c)
    if c in ("T", "t"):
        send_dash()
    elif c in ("K", "k"):
        send_dash()
        send_dot()
        send_dash()
    elif c == "0":
        for _ in range(5):
            send_dash()
    elif c == "1":
        send_dot()
        for _ in range(4):
            send_dash()
    # Other characters not handled in this demo

def main():
    print("TK01 Morse - sending once")
    send_morse_char("T")
    time.sleep(ms(LETTER_GAP_MS))
    send_morse_char("K")
    time.sleep(ms(LETTER_GAP_MS))
    send_morse_char("0")
    time.sleep(ms(LETTER_GAP_MS))
    send_morse_char("1")
    print("Done")

if __name__ == "__main__":
    main()
