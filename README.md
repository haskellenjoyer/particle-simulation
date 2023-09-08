# Particle Simulation

This program uses SFML library for particle simulation.

### How to run on Linux

#### Build Requirements:
- g++ (to compile)
- git (to clone the repo)
- libsfml-dev (library files)
- make (for easy compilation and executing)

*These packages can be installed from the default package manager.*

Example for Debian based distributions:
`sudo apt install g++ git libsfml-dev make`

#### Run the following commands:
1. `git clone https://github.com/haskellenjoyer/particle-simulation`
2. `cd particle-simulation`
3. `make run`

### How to use:
- Left-click to make a 'particle'. It would have a random color and would stay in place.
- To make a moving particle, left-click, drag, and release. This would 'shoot' the particle in the direction opposite of drag. The speed depends on amount of drag.
- A particle can be deleted upon right-click.
