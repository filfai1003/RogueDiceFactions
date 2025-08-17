# 🎮 Game Design Document – *Rogue Dice Factions*  

## 1. **Concept**  
A turn-based roguelike where the player explores a procedurally generated world, encounters rival factions, and fights using **special dice**.  
Each run is unique: map, enemies, equipment, and interactions change, and the player must decide whether to ally with a faction or go solo to claim the final reward.  

---

## 2. **Game Objectives**  
- **Victory**: obtain the “Perfect Resource” before rival factions.  
- **Defeat**: player death or another faction securing the resource.  
- **Portfolio Goal**: showcase C++ skills (engine-light), AI with Behavior Trees, procedural generation, and an original dice-based combat system.  

---

## 3. **Core Gameplay Loop**  
1. Explore the map (biomes and POIs procedurally generated).  
2. Encounter NPCs from factions → reactions (hostile, neutral, trader, ally).  
3. Engage in turn-based combat with the dice system.  
4. Collect equipment and unique dice to grow stronger.  
5. Reach the final resource → end run.  

---

## 4. **Key Mechanics**  

### 4.1 Movement & Exploration  
- Top-down 2D perspective.  
- 20×20 tile map with diverse biomes (forest, ruins, desert).  
- Prebuilt POIs (villages, dungeons, enemy camps) placed randomly.  
- Minimap at the top-left (expandable fullscreen).  

### 4.2 Factions  
- Each NPC belongs to a faction with a **reaction state**:  
  - **Hostile** → instant combat.  
  - **Neutral** → ignores player.  
  - **Trader** → exchanges dice/items.  
  - **Ally** → follows and fights alongside the player.  
- Factions compete against each other to claim the final resource.  

### 4.3 Turn-Based Combat  
- Each unit has stats: HP, Attack, Defense, Shield.  
- Turn order based on Initiative.  
- On their turn → player selects dice to roll and their order.  
- Dice determine damage, shield, or special effects.  

### 4.4 Dice System  
- The player starts with one **standard D6**.  
- During the run, special dice can be found:  
  - **Glass Die** → high bonus, but may break after rolling.  
  - **Loaded Die** → higher chance of rolling above average.  
  - **Shield Die** → values apply as shields instead of damage.  
- Each die has: **shape (D4, D6, D8, D20)** + **traits**.  
- Traits can trigger at: `PreRoll`, `PostRoll`, or `OnApply`.  

---

## 5. **Progression & Runs**  
- Each run is independent (permadeath).  
- Maps, factions, equipment, and dice are randomized.  
- Increasing difficulty: more runs unlock greater dice/POI variety.  

---

## 6. **Technical Structure**  

### 6.1 Architecture (C++)  
- **WorldSystem** → map, biomes, POIs, spawn.  
- **EntitySystem** → Player, NPC, Factions.  
- **CombatSystem** → turns, abilities, HP/shield handling.  
- **DiceSystem** → dice handling, rolls, special effects.  
- **AI System** → basic Behavior Tree for NPCs (patrol, chase, attack, flee).  
- **UI System** → simple HUD (HP, dice, minimap).  

### 6.2 Technologies  
- **Language**: C++17.  
- **Library**: SDL2 (graphics, input, basic audio).  
- **Data**: JSON/YAML for dice, biomes, spawn.  
- **Versioning**: GitHub + CMake build.  

---

## 7. **Scoped Features (~180h)**  
- 1 procedurally generated map (20×20).  
- 2 factions with different reactions.  
- 3 special dice (glass, loaded, shield).  
- 3 enemy types.  
- 1 victory condition (reaching the resource).  

---

## 8. **Production Roadmap (~180h)**  

| Phase | Hours | Task |
|-------|-------|------|
| Week 1 | 30h | Setup SDL2, tilemap rendering, player movement |
| Week 2 | 30h | World gen (biomes, POIs, spawn) + minimap |
| Week 3 | 30h | Turn-based system + base stats (HP, ATK, DEF) |
| Week 4 | 30h | DiceSystem (D6 + 3 special dice + UI for rolling) |
| Week 5 | 30h | AI BT (patrol, chase, attack, flee) + factions |
| Week 6 | 30h | Polish, bugfix, balancing, README, video demo |

---

## 9. **Portfolio Deliverables**  
- GitHub repo with README + UML diagrams.  
- Short demo video (2–3 minutes) showcasing: world gen, factions, dice mechanics, run victory/defeat.  
- Minimal documentation (architecture overview, explanation of DiceSystem and AI).  

## How to run:
# Test Engine
g++ -std=c++17 tests/test_engine.cpp src/engine/math_utils.cpp src/engine/timer.cpp -o tests/test_engine; ./tests/test_engine