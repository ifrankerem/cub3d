## cub3D — RayCaster in C (miniLibX)

A first-person raycasting engine inspired by Wolfenstein 3D, developed as part of the 42 curriculum. The program parses a .cub scene file (textures, colors, map), validates it strictly, and renders a real-time 3D view using raycasting.

Built with: C, miniLibX
Collaborator: Developed together with @bucolak (https://github.com/bucolak)

------------------------------------------------------------
## SHOWCASE / LINKS

- **Excalidraw (DDA + Raycasting Notes):** [Open the diagram](https://link.excalidraw.com/readonly/pAl5QhBGYfPVun4ramNg?darkMode=true)
- **YouTube Demo:** [Watch the demo](https://www.youtube.com/watch?v=zdqgqyQPoMY)

### YouTube Preview
[![cub3D Demo Video](https://img.youtube.com/vi/zdqgqyQPoMY/hqdefault.jpg)](https://www.youtube.com/watch?v=zdqgqyQPoMY)

### Gameplay Screenshot
![cub3D screenshot](/ss.png)

------------------------------------------------------------
## FEATURES
- Real-time 3D rendering using raycasting
- Directional wall textures (NO / SO / WE / EA)
- Floor & ceiling colors (F / C in RGB)
- Player movement + camera rotation
- Clean exit (ESC / window close)
- Robust parsing + clear error handling
- Strict map validation (valid characters, single spawn, closed map)

------------------------------------------------------------
## REQUIREMENTS
- cc / clang
- make
- miniLibX
- Standard 42 flags: -Wall -Wextra -Werror
- Math library: -lm

------------------------------------------------------------
## BUILD
make

Clean rules:
make clean
make fclean
make re

------------------------------------------------------------
## RUN
./cub3D maps/example.cub

------------------------------------------------------------
## CONTROLS
- W A S D : move
- Left / Right arrows : rotate camera
- ESC or window close : quit

------------------------------------------------------------
## .CUB FILE FORMAT

1) Textures (4 directions)
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

2) Colors (RGB)
F 220,100,0
C 225,30,0
Notes:
- RGB values must be in the range 0–255
- Format must be exactly: R,G,B (commas-separated)

3) Map (must be the last block in the file)
Valid characters:
- '1' : wall
- '0' : empty space
- 'N' 'S' 'E' 'W' : player spawn + initial orientation
- ' ' (space) : can appear in the map and must be handled safely during validation

Example map:
111111
100101
101001
1100N1
111111

------------------------------------------------------------
## VALIDATION RULES (HIGH-LEVEL)
On invalid input, the program exits with:
Error
<explicit message>

Typical checks:
- Missing or duplicate identifiers (NO/SO/WE/EA/F/C)
- Invalid texture paths / unreadable files
- Wrong RGB format or out-of-range values
- Invalid map characters
- Multiple player spawns or no spawn at all
- Map must be closed (no leaks to the outside; spaces must be properly enclosed)

------------------------------------------------------------
## PROJECT NOTES
- Parsing pipeline: read .cub -> parse header (textures/colors) -> build map grid
- Map processing: padded rectangular grid for safe bounds checks
- Closed-map validation: flood-fill style leak detection
- Memory discipline: clean error paths, no leaks/double-frees
