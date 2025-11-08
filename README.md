# RaspberryPi-Dashboard


A dynamic terminal dashboard written in **C++**, displaying:
- 🕒 Current Time & Date  
- 🌤️ Live Weather Updates (OpenWeather API)  
- 🎵 Now Playing Track (Spotify API)  
- 🗓️ Monthly Calendar  
- 🖼️ Google Photos Album Slideshow  

Designed to run on **macOS**, **Linux**, and **Raspberry Pi** using `ncurses` and `libcurl`.

---

## 🚀 Features
- Real-time data display for weather, music, and calendar
- Google Photos album integration
- Modular C++ architecture with reusable components
- Uses environment-based configuration (no hardcoded secrets)
- Optimized for Raspberry Pi terminals and Ghostty

---

## 🧰 Installation

### 1. Clone the Repository
```bash
git clone https://github.com/<your-username>/dashboard.git
cd dashboard

2. Install Dependencies

macOS (Homebrew)

brew install ncurses curl jsoncpp

Ubuntu / Raspberry Pi OS

sudo apt update
sudo apt install build-essential libncurses5-dev libcurl4-openssl-dev libjsoncpp-dev


⸻

🍓 Raspberry Pi Setup

You can run this dashboard directly on your Raspberry Pi 4 or 5 connected to a display or via SSH.
	1.	Install Raspberry Pi OS (Lite or Desktop)
Download from https://www.raspberrypi.com/software/￼.
	2.	Enable SSH and Wi-Fi (optional)

sudo raspi-config

	•	Enable SSH under Interface Options
	•	Configure Wi-Fi under System Options → Wireless LAN

	3.	Update your system

sudo apt update && sudo apt upgrade -y


	4.	Install build tools

sudo apt install build-essential git cmake libncurses5-dev libcurl4-openssl-dev libjsoncpp-dev -y


	5.	Clone and build

git clone https://github.com/<your-username>/dashboard.git
cd dashboard
g++ main.cpp utils/*.cpp modules/*.cpp -Iinclude -std=c++17 -lncurses -lcurl -o dashboard
./dashboard


	6.	(Optional) Auto-start on boot
Edit your .bashrc or create a systemd service to run the dashboard automatically on login.

📝 Tip: Use Ghostty, tmux, or screen for persistent sessions.

⸻

⚙️ API Setup

This dashboard requires Google, Spotify, and OpenWeather APIs to function correctly.
Without these valid API keys, the app will not run properly.

🌤️ OpenWeatherMap
	1.	Visit https://openweathermap.org/api￼
	2.	Create an account and obtain your API Key
	3.	Example endpoint:

https://api.openweathermap.org/data/2.5/weather?q=YOUR_CITY&appid=YOUR_API_KEY



⸻

🎵 Spotify API
	1.	Go to https://developer.spotify.com/dashboard￼
	2.	Create a new application
	•	Add a redirect URI: http://localhost
	3.	Use your Client ID and Client Secret to generate an access token:

curl -X POST -H "Content-Type: application/x-www-form-urlencoded" \
-d "grant_type=client_credentials&client_id=YOUR_CLIENT_ID&client_secret=YOUR_CLIENT_SECRET" \
https://accounts.spotify.com/api/token


	4.	Copy the access token and save it for configuration.

⸻

🖼️ Google Photos API
	1.	Open Google Cloud Console￼
	2.	Enable Google Photos Library API
	3.	Create OAuth 2.0 Client ID (Desktop App)
	4.	Generate an authorization code:

https://accounts.google.com/o/oauth2/v2/auth?
client_id=YOUR_CLIENT_ID&
redirect_uri=urn:ietf:wg:oauth:2.0:oob&
response_type=code&
scope=https://www.googleapis.com/auth/photoslibrary.readonly&
access_type=offline&
prompt=consent


	5.	Exchange the authorization code for tokens:

curl -X POST https://oauth2.googleapis.com/token \
-d client_id=YOUR_CLIENT_ID \
-d client_secret=YOUR_CLIENT_SECRET \
-d redirect_uri=urn:ietf:wg:oauth:2.0:oob \
-d grant_type=authorization_code \
-d code=YOUR_AUTHORIZATION_CODE


	6.	Copy your access token for use in configuration.

⸻

🧩 Build & Run

1. Compile the Project

g++ main.cpp utils/*.cpp modules/*.cpp -Iinclude -std=c++17 -lncurses -lcurl -o dashboard

2. Run the Dashboard

./dashboard

Press q to quit the dashboard.

⸻

🧪 Debug Mode (Console)

If you want to test without ncurses (just to verify API connections):

g++ main.cpp utils/*.cpp modules/*.cpp -Iinclude -std=c++17 -lcurl -o dashboard_test
./dashboard_test


⸻

🗂️ Project Structure

Dashboard/
├── headers/
│   ├── clock.h
│   ├── weather.h
│   ├── spotify.h
│   ├── calendar.h
│   └── photos.h
│
├── modules/
│   ├── clock.cpp
│   ├── weather.cpp
│   ├── spotify.cpp
│   ├── calendar.cpp
│   └── photos.cpp
│
├── utils/
│   ├── env_loader.cpp
│   ├── http.cpp
│   ├── json.cpp
│   └── draw_utils.cpp
│
├── include/
│   ├── env_loader.h
│   ├── http.h
│   ├── json.h
│   └── draw_utils.h
│
└── main.cpp


⸻

🧾 Notes
	•	The app requires live internet access for API data.
	•	Each API (Google, Spotify, Weather) must be properly configured.
	•	Works on macOS, Linux, and Raspberry Pi.
	•	The project follows a modular design, making it easy to extend new widgets.

⸻

🧑‍💻 Author

Edward Lee
📧 edward.lee2309@gmail.com
💻 GitHub: Ed-ward239￼

⸻

📄 License

This project is licensed under the MIT License￼.

---