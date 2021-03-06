# Archived

Use https://github.com/deepnight/ldtk instead (its REALLY good).

# birdedit
A tilemap editor that focuses on simplicity and ease of use. Less is more.

## Features

 - [ ] Tile, line and block tiling brushes.
 - [ ] Tile palettes with terrain data; which describes groups of bitmaps of adjacent tiles, where each group maps to a specific tile in the palette.
 - [ ] Hierarchical sceen graph for determining render precedence and parenting.
 - [ ] Resizable and repositional nodes on the sceen graph.
 - [ ] Node latching; nodes latch onto sides of a parent node (child node latches onto a side of parent node and is always anchored to that side, rather than being anchored to the parent nodes origin)
 - [ ] Export/Import support for [Tiled](https://www.mapeditor.org/)
 - [ ] Export to optimized polygon mesh, uv map, texture atlas, and collision mesh; for importing into other software - primarily game engines like Unity3D.

## Getting Started

birdedit is in early alpha stages and is only available as source code for the time being. In the future, builds for windows, macos, and linux will be provided.

birdedit is currently developed and tested on Windows, built using MinGW. There are no guarantees that this tool will build properly on other systems or for other systems. As noted above, birdedit will eventually target multiple platforms.

### Building on Windows (MinGW)
```sh
git clone https://github.com/phxvyper/birdedit
cd birdedit
cmake .
make
```
