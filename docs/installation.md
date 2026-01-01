# Installation

This guide will help you set up TFT Framework in your project.

## Prerequisites

### 1. Install PlatformIO IDE

Install the PlatformIO extension for Visual Studio Code:

[PlatformIO Installation Guide](https://platformio.org/install/ide?install=vscode)

### 2. Create PlatformIO Project

Create a new project in PlatformIO IDE for your target platform (Arduino, ESP32, etc.).

## Installing TFT Framework

### Step 1: Download the Library

Download the TFT Framework source code from the repository.

### Step 2: Add to Project

1. Extract the downloaded archive
2. Copy the `tft_framework` and `tft_implement` folders to your project's `/lib` directory

```
your_project/
├── lib/
│   ├── tft_framework/
│   └── tft_implement/
├── src/
└── platformio.ini
```

### Step 3: Install SD Library (Optional)

For SD card functionality, add the SD library:

**Arduino:** Install from [Arduino SD Library](https://github.com/arduino-libraries/SD)

**ESP32:** The SD library is included with the ESP32 platform (no additional installation needed)

## Verification

After installation, try building the [Hello World example](./getting_start.md) to verify everything is set up correctly.
