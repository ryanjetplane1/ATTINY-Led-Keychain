# ATTINY-Led-Keychain

A LED display badge using a mix of SMD and DIP parts powered by a coin cell. 12 LEDs charlieplexed off an ATtiny85, driven by 4 GPIO pins instead of 12.
<img width="1457" height="978" alt="image" src="https://github.com/user-attachments/assets/7b7fa76e-f64e-465a-84b3-e68c76fcea5d" />



## Hardware

- ATtiny85-20PU, SOIC-8
- 12x LED0805 yellow-green LEDs, charlieplexed in a 4x3 grid
- 4x 68 ohm series resistors on the charlieplex lines
- 10k pull-up on RESET
- 100nF decoupling cap
- CR coin cell holder for power

## How it works

Charlieplexing drives 12 LEDs off 4 GPIO pins instead of wiring one pin per LED. Each pin can be set to three states, high, low, or floating, and each LED is wired between two of the pins in a specific direction, since an LED only lights up when current flows the right way through it. To light one LED, its anode pin goes high, its cathode pin goes low, and every other pin is set to floating so it doesn't interfere. Wiring LEDs in both directions between the same pair of pins lets one pin pair address two LEDs instead of one, which is how 4 pins end up controlling 12 LEDs instead of just 4.

Only one LED can actually be lit at a time this way, so the chip cycles through all 12 fast enough that it makes it look like several are lit at once. The firmware controls which LED is on and for how long by switching the pin states rapidly in a loop.
## BOM

| Designator | Part | Qty | Price | Link |
|---|---|---|---|---|
| BT1 | BAT-HLD-001 coin cell holder | 1 | $1.133 | [Digikey](https://www.digikey.com/en/products/detail/te-connectivity-linx/BAT-HLD-001-TR/4876924) |
| C1 | 100nF 0805 cap | 1 | $0.004 | [Digikey](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21B104KBCNNNC/3886661) |
| U1, U8-U18 | YLED0805YG LED | 12 | $4.99 | [Amazon](https://www.amazon.com/dp/B09XB62ST5) |
| U2-U5 | 68 ohm 0805 resistor | 4 | $0.339 | [Digikey](https://www.digikey.com/en/products/detail/vishay-dale/CRCW080568R0FKEAC/7922338) |
| U6 | 10k 0805 resistor | 1 | $0.339 | [Digikey](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0710KL/727535) |
| U7 | ATTINY85-20PU | 1 | $1.66 | [Digikey](https://www.digikey.com/en/products/detail/microchip-technology/ATTINY85-20PU/735469) |


