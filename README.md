# ATTINY-Led-Keychain

A LED display badge using only SMD parts powered by a coin cell. 12 LEDs charlieplexed off an ATtiny85, driven by 4 GPIO pins instead of 12.
<img width="1616" height="989" alt="image" src="https://github.com/user-attachments/assets/4d290d1e-d1c5-4476-85d5-c51d070aeb75" />

## Hardware

- ATtiny85-20SUR, SOIC-8
- 12x LED0805 yellow-green LEDs, charlieplexed in a 4x3 grid
- 4x 68 ohm series resistors on the charlieplex lines
- 10k pull-up on RESET
- 100nF decoupling cap
- CR coin cell holder for power

## How it works

Charlieplexing drives 12 LEDs off 4 GPIO pins by using logic gates of the pins, high, low, and polarity. Firmware cycles through the lines fast enough that persistence of vision makes it look like several LEDs are on at once.

## BOM

| Designator | Part | Qty | Price | Link |
|---|---|---|---|---|
| BT1 | BAT-HLD-001 coin cell holder | 1 | $1.133 | [Digikey](https://www.digikey.com/en/products/detail/te-connectivity-linx/BAT-HLD-001-TR/4876924) |
| C1 | 100nF 0805 cap | 1 | $0.004 | [Digikey](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21B104KBCNNNC/3886661) |
| U1, U8-U18 | YLED0805YG LED | 12 | $4.99 | [Amazon](https://www.amazon.com/dp/B09XB62ST5) |
| U2-U5 | 68 ohm 0805 resistor | 4 | $0.339 | [Digikey](https://www.digikey.com/en/products/detail/vishay-dale/CRCW080568R0FKEAC/7922338) |
| U6 | 10k 0805 resistor | 1 | $0.339 | [Digikey](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0710KL/727535) |
| U7 | ATtiny85-20SUR | 1 | $2.929 | [Digikey](https://www.digikey.com/en/products/detail/microchip-technology/ATTINY85-20SUR/2357441) |


