 ## Voice-Assisted Smart Cart using RFID and IoT

A smart trolley system using **RFID technology**, **voice feedback**, and **IoT** to automate supermarket billing. Designed to improve shopping convenience and support **visually impaired individuals**, this project eliminates manual checkout by providing real-time item detection and billing through a user-friendly smart cart.

---

 ## Key Features

- 📦 **RFID-based Product Detection**
- 📢 **Voice Playback for Visually Impaired**
- 💰 **Automatic Bill Calculation**
- 📺 **LCD Display of Items and Prices**
- ☁️ **IoT Data Transfer to Cloud (using HTTP API)**
- ⚡ **Low Power Consumption with Battery Backup**

---

 ## Hardware Components Used

| Component                    | Quantity |
|-----------------------------|----------|
| ESP32 Microcontroller        | 1        |
| RFID Reader (RC522)          | 1        |
| RFID Tags                    | Multiple |
| DFPlayer Mini MP3 Module     | 1        |
| MicroSD Card (with MP3 files)| 1        |
| LCD Display 16x2             | 1        |
| Speaker                      | 1        |
| Voltage Regulator (AMS1117) | 1        |
| 5V DC Power Supply/Battery   | 1        |
| Jumper Wires                 | As needed |
| Breadboard                   | 1        |

---

## How It Works

1. Product with RFID tag is placed in the trolley.
2. RFID reader reads the tag ID and matches it to the product.
3. ESP32:
   - Displays item name and price on LCD
   - Plays voice feedback using DFPlayer Mini
   - Adds price to running total
4. Total bill and product info are sent to an IoT web server via HTTP (JSON format).

---

## Output Screenshots

> Make sure your images are in a folder like `output images/` in your GitHub project

```markdown
![Trolley with LCD](output%20images/lcd_display.jpg)
 Product info on LCD*

![Voice Module](output%20images/dfplayer.jpg)
 DFPlayer Mini MP3 setup*

![IoT Web Update](output%20images/cloud_billing.jpg)
 Data sent to cloud for billing*

 ## Demo (GIF Preview)

![Smart Cart Demo](output%20images/voice%20assisted%20smart%20cart%20video.gif)


