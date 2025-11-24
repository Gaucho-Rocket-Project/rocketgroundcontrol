*RocketGroundControl* (RGC) is a Ground Control Station (GCS) designed for rocketry, forked from the Qgroundcontrol repository for drones. RGC provides a seamless user experience for launch control, telemetry handling and mission planning. Currently using *MAVLINK* for communication.

---

### 💻 *How to contribute?*

- Check out the original Qgroundcontrol [Developer Guide](https://dev.qgroundcontrol.com/en/).
- Ask questions & give suggestions! (in-person or on [slack](gauchorocketproject.slack.com) / email Cheng (GCS lead) at cxi@ucsb.edu)
- Code (and document)!

---

### ⚙️ *Building & testing the repository*

- Build the repository using Qt / cmake (docker not recommended):
    1.  Follow Qgroundcontrol's [build instructions](https://dev.qgroundcontrol.com/en/getting_started/) up to 'Building using Qt Creator: 1. Launch Qt Creator, select Open Project and select the CMakeLists.txt file'.
    2.  Click **Manage kits**:
    <img width="1261" height="736" alt="image" src="https://github.com/user-attachments/assets/36d1b554-27ce-46b4-9e2c-63c27e5de3c0" /> 
    
    3.  Click **Add**:
    <img width="969" height="565" alt="image" src="https://github.com/user-attachments/assets/3e73db77-a50c-48ab-8216-2d87e8d24eb1" /> 
    
    4.  Make sure your kit config is EXACTLY as in the image:
    <img width="754" height="412" alt="image" src="https://github.com/user-attachments/assets/400ba6e0-f7b3-4ef1-8f2a-3ceb3b24b132" /> 
    
    5.  In the **Projects** menu, under **Build settings**, make sure **CMAKE_PREFIX_PATH** is set to YOUR QT installation: 
    <img width="468" height="22" alt="image" src="https://github.com/user-attachments/assets/9b60472e-eaf2-40ed-a035-6de10c77a0f6" />
    
    6.  Open **Qt maintenance tool**:
    <img width="552" height="238" alt="image" src="https://github.com/user-attachments/assets/eafcb91b-3939-485f-af1f-2596e585d9fc" /> 
    
    7.  Select **Add or remove components**:
    <img width="1082" height="690" alt="image" src="https://github.com/user-attachments/assets/9399f716-5801-462b-9361-9929e6dbe8c9" /> 
    
    8.  Under **Qt/Qt 6.10.1/Additional Libraries** make sure you have ALL of the shown modules selected:
    <img width="1101" height="792" alt="image" src="https://github.com/user-attachments/assets/38b10131-c344-4f3e-baeb-70a5b0960e61" /> 
    
    9.  Install modules and restart Qt Creator.
    10.  Open the **rocketgroundcontrol** project, and under the debug screen click **Run CMake**:
    <img width="1259" height="731" alt="image" src="https://github.com/user-attachments/assets/a06b9f09-c4b4-42d5-b2c2-1344a7e720e3" /> 
    
    11.  Build the project using the hammer icon on the bottom left
    12.  Run the compiled application using the `./build/Debug/QGroundControl` command





-  *Vehicle Setup*: configure rocket type vehicle.
- Test the compiled application: [User Manual](https://docs.qgroundcontrol.com/en/)
  
---

### 🔗 *Useful Links*

- 🌐 [Official Website](http://qgroundcontrol.com)
- 📘 [User Manual](https://docs.qgroundcontrol.com/en/)
- 🛠️ [Developer Guide](https://dev.qgroundcontrol.com/en/)
- 💬 [Discussion & Support](https://docs.qgroundcontrol.com/en/Support/Support.html)
- 🤝 [Contributing](https://dev.qgroundcontrol.com/en/contribute/)
- 📜 [License Information](https://github.com/mavlink/qgroundcontrol/blob/master/.github/COPYING.md)

---

For any additional info contact Gaucho Rocket Project on [slack](gauchorocketproject.slack.com)
