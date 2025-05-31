![assets_task_01jv8v4a91fth9pwnrb965bthb_1747274909_img_0](https://github.com/user-attachments/assets/da8bb8ed-3bea-4144-9453-95da7eb3695e)

Here's a more visually appealing and engaging version of your README with better formatting and visual elements:

# 🎮 So_Long - A 2D Adventure Game  

![image](https://github.com/user-attachments/assets/1afadf1b-9798-42d8-9b37-65f911bd8847) <!-- Add a nice banner image here if available -->
*A charming 2D game built with MiniLibX where you collect treasures and find the exit!*

---

## ✨ Features

| Category        | Details                                                                 |
|-----------------|-------------------------------------------------------------------------|
| 🗺️ **Map System**  | Custom .ber map files with validation (walls, player, exit, collectibles) |
| 🎨 **Graphics**    | Smooth rendering with MiniLibX (X-Window)                               |
| 🕹️ **Controls**    | WASD or Arrow Keys + ESC to quit                                       |
| 📊 **Game Stats**  | Live move counter                               |
| 🧠 **AI**          | Path validation using flood-fill algorithm                             |
| 🖼️ **Animations**  | Multiple exit animations for visual polish                             |

---

## 🛠️ Installation

```bash
git clone https://github.com/f-amador/so_long.git
cd so_long
make
```

**Requirements:**
- 🐧 Linux with X11
- ⚙️ GCC compiler
- 🔨 Make
- 📚 MiniLibX (included)

---

## 🎯 How to Play

```bash
./so_long maps/map.ber
```

**Objective:**  
Navigate your character (🐱) to collect all treasures (💎) and reach the exit (🚪)!

**Controls:**
| Key           | Action          |
|---------------|-----------------|
| `W` or `↑`    | Move Up         |
| `A` or `←`    | Move Left       |
| `S` or `↓`    | Move Down       |
| `D` or `→`    | Move Right      |
| `ESC`         | Quit Game       |

---

## 🗺️ Map Design Guide

**Valid Maps Must:**
- Be rectangular
- Have walls (`1`) on all borders
- Contain exactly:
  - `1` Player (`P`) 
  - `1` Exit (`E`)
  - `≥1` Collectibles (`C`)
- Be solvable (path to exit collecting all items)

**Example Map:**
```
111111111
1P0000C1
101C0E01
10000001
11111111
```

**Legend:**
- `0`: Empty space
- `1`: Wall
- `C`: Collectible (💎)
- `E`: Exit (🚪)
- `P`: Player (🐱)

---

## 🧠 Behind the Scenes

### 🔧 Technical Highlights

```c
// Core Game Structure
typedef struct s_data {
    void    *mlx;       // MiniLibX instance
    void    *mlx_win;   // Game window
    int     **map;      // 2D game map
    int     steps;      // Move counter
    int     collect;    // Total collectibles
    // ... (other members)
} t_data;
```

**Key Systems:**
1. **Map Parser** - Validates .ber files
2. **Graphics Engine** - Handles rendering and textures
3. **Game Loop** - Manages keyboard inputs and updates
4. **Pathfinder** - Flood-fill algorithm for map validation
5. **Memory Manager** - Safe allocation/deallocation

---

## 🚨 Error Handling

The game detects and explains:
- ❌ Invalid map shapes
- ❌ Missing/duplicate player/exit
- ❌ Unreachable items/exit
- ❌ Memory issues
- ❌ Graphic failures

---

## 👨‍💻 Author & Credits

**Your Name**  
[![GitHub](https://img.shields.io/badge/GitHub-Profile-blue?style=flat&logo=github)](https://github.com/yourusername)  
[![Email](https://img.shields.io/badge/Email-Contact%20Me-red?style=flat&logo=mail.ru)](mailto:your@email.com)

**Special Thanks To:**
- 42 School for MiniLibX
- StackOverflow community

---

## 📜 License

MIT License - See [LICENSE](LICENSE) for details.

---

<div align="center">
  <sub>Built with ❤️ and </sub>
  <img src="https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white" height="14">
</div>
```

### How to Make It Even Prettier:

1. **Add Visuals**:
   - Create a `banner.png` (1280×400px) showing your game
   - Add `screenshot.png` of actual gameplay
   - Consider an animated GIF showing gameplay

2. **Badges**:
   ```markdown
   ![C](https://img.shields.io/badge/C-100%25-blue)
   ![License](https://img.shields.io/badge/License-MIT-green)
   ![Status](https://img.shields.io/badge/Status-Stable-brightgreen)
   ```

3. **Add a Quick Demo**:
   ```markdown
   ## 🎥 Quick Demo
   ![Gameplay GIF](demo.gif)
   ```

4. **For Bonus Points**:
   ```markdown
   ## � Bonus Features (Coming Soon!)
   - [ ] Enemy AI
   - [ ] Animated sprites
   - [ ] Multi-level support
   ```

This version uses:
- Emojis for visual scanning
- Tables for organized info
- Code blocks for technical details
- Badges for metadata
- Consistent section formatting
- Friendly yet professional tone

Would you like me to adjust any particular section further?
