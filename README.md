# SKR2-TB6600-Stepper-Demo

Dieses Projekt demonstriert die Ansteuerung eines Schrittmotors mit einem **TB6600 Microstep-Treiber** über ein **BIGTREETECH SKR 2 Board** (STM32F4-Serie).

## 🔧 Hardware

- **Controller:** BIGTREETECH SKR 2 (STM32F429)
- **Stepper Driver:** TB6600
- **Schrittmotor:**
- **Versorgungsspannung:** [z. B. 12V / 24V]
- **Externe Stromversorgung für den TB6600**

## 📌 Pinbelegung

| Signal   | SKR 2 Pin (GPIO) | Beschreibung        |
|----------|------------------|---------------------|
| STEP     | [z. B. PB0]      | Step-Puls           |
| DIR      | [z. B. PB1]      | Drehrichtung        |
| ENABLE   | [z. B. PA0]      | Aktivierung (Low)   |

> ⚠️ Die Pins sollten entsprechend deiner Konfiguration ersetzt werden. Bitte passe die Werte hier und im Code an.

## 🧠 Funktion

Der Mikrocontroller sendet Pulse an den TB6600-Treiber. Der Treiber wandelt diese in Bewegungen des Schrittmotors um, entsprechend der Mikroschritteinstellungen.

## 🗂️ Inhalt

- `main.c` / `main.cpp`: Hauptprogramm zur Steuerung des Schrittmotors
- `README.md`: Diese Datei
- `docs/`: Technische Details oder Schaltpläne (optional)


