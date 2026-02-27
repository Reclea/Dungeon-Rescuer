# ⚔️ C-Adventure RPG

### Quick Description
**FR :** Un RPG textuel en C proposant des combats au tour par tour, une gestion d'inventaire et un système de narration multilingue basé sur des fichiers.  
**EN :** A C-based text RPG featuring turn-based combat, inventory management, and a file-based multilingual storytelling system.

---

## 👥 Authors
* **Noel Clement**
* **Arnoult Antoine**

## 🚀 Key Features

### 🎭 Class System
Choose from 4 distinct archetypes, each with unique scaling for Health, Mana, Attack, Defense, and Haste:
* **Barbarian**: High health and raw physical power.
* **Mage**: Squishy but powerful, utilizing a large Mana pool.
* **Paladin**: A balanced "tank" with both healing and defensive capabilities.
* **Thief**: High haste, allowing for frequent double-turns and evasion.

### ⚔️ Advanced Combat Engine
* **Initiative-Based**: Turn order is calculated dynamically based on the "Celerity" stat.
* **Status Effects**: Management of **Poison**, **Burn**, **Invisibility**, and **Slow**.
* **Smart AI**: Enemies (Slimes, Dragons, etc.) change behavior based on their health or the player's status.
* **Dice Roll System**: Success of special moves depends on randomized rolls using a 21-sided dice logic.



### 📁 Technical Architecture
* **Localization**: Supports English and French through external `.txt` resource files (`English.txt`, `Francais.txt`).
* **Save System**: Progress is tracked in `SaveGame.txt`, allowing players to resume their journey.
* **Modular Code**: Uses custom `struct` definitions for Players, Enemies, and Inventories.

## 🛠️ Installation & Compilation

### Prerequisites
* A C compiler (e.g., `gcc` or `clang`).
* Ensure the following files are in the root directory:
  * `SaveGame.txt`
  * `PlayerInfo.txt`
  * `Francais.txt`
  * `English.txt`
