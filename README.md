# -- FdF (Fil de Fer) --
## Usage (mac only) -- 👈

During compilation you will see some warnings, just ignore them it comes from the MiniLibX.

Press ESC to leave.

```bash
git clone https://github.com/NetworkFlux/FdF.git && cd FdF && bash launch.sh
```

<img src="https://github.com/NetworkFlux/FdF/blob/master/imgs/mars.png" width="400" height="250"> <img src="https://github.com/NetworkFlux/FdF/blob/master/imgs/Pyra.png" width="400" height="250">

## Topics -- 🗝

1. 3D Graphics Programming

2. Graphic Library

3. C

## Challenge -- 💡

Creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments.

## Objectives -- ✅

The wireframe should be able to represent basic geometry aswell as some landscapes.

- The map must be loaded from a valid *.fdf* file.
- It must be **parsed** to retrieve its data.
- **Compute and output** the wireframe.

---
Easy add-ons:
- Add color for altitude
- Interactive control
- Zoom

## Rules -- 🚨

If you are interested in the specifics of the project here is how it is supposed to work :

The coordinates of the landscape are stored in a .fdf file passed as a parameter to your program. Here is an example:

<img src="https://github.com/NetworkFlux/FdF/blob/master/imgs/map_example.png" width="400" height="350">

Each number represents a point in space:

- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

To actually create a window and to output some pixels onto that window I use the [MiniLibX API](https://harm-smits.github.io/42docs/libs/minilibx "MiniLibX").