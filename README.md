# Camera-Processing-Pipeline-in-C-
Camera Processing Pipeline in C++
# 📸 Camera Image Processing Pipeline in C++

A modular camera pipeline built using C++ and OpenCV that captures images from a webcam or simulated driver and processes them with real-time filters like Histogram Equalization and Canny Edge Detection.

---

## 🚀 Features

- 🧠 **Simulated + Real Camera Input**: Toggle between a webcam and a simulated image driver.
- 🎨 **Histogram Equalization**: Automatically enhances contrast of captured frames.
- 🔍 **Canny Edge Detection**: Detects edges and structures in real-time video.
- 🛠️ **Modular Codebase**: Easily extend the pipeline with new filters or image sources.

---

## 🛠️ Tech Stack

- **Language**: C++
- **Library**: OpenCV
- **Platform**: Windows (CLI build using MSVC / Visual Studio Build Tools)

---

## 📂 Folder Structure

Camera-Kernel/ │ ├── src/ │ ├── main.cpp # Main application logic │ ├── simulated_driver.cpp # Simulated camera driver │ ├── simulated_driver.hpp │ ├── isp_pipeline.cpp # Image processing logic │ └── isp_pipeline.hpp │ ├── README.md └── ...


---

## 🧪 Setup Instructions (Windows)

### 1. Install OpenCV

Download OpenCV and extract it to `C:/opencv`  
[Download OpenCV](https://opencv.org/releases/)

### 2. Build with MSVC

Use this command to build from the project root:

```bash
cl src\main.cpp src\simulated_driver.cpp src\isp_pipeline.cpp /EHsc /I "C:\opencv\build\include" /link /LIBPATH:"C:\opencv\build\x64\vc16\lib" opencv_world4110.lib


Simulated Input (default)
main.exe
Webcam Input
main.exe --use-webcam
