A small AzerothCore WotLK 3.3.5a module that adds a GM-only .healcreature command.

Purpose
.healcreature instantly heals the selected creature to full health.
The heal is performed through AzerothCore's Unit::DealHeal() system rather than simply setting the creature's health. This is important for encounters such as Valithria Dreamwalker, where the encounter AI needs to receive the heal event for the encounter to complete normally.
The module does not modify the core Valithria encounter script.

Installation:
From your AzerothCore root (Debian):

1. Go to your modules folder
2. git clone https://github.com/YOUR_USERNAME/mod-healcreature.git

Then run your normal AzerothCore build/compile script.

Usage:
Select a living creature and use:
.healcreature
The command heals the creature for exactly the amount of health it is missing.
The command is restricted to players with the AzerothCore GM command permission and cannot be used from the server console.

Module Structure:
mod-healcreature/
└── src/
    ├── healcreature.cpp
    └── mod_healcreature_loader.cpp

No additional configuration file is required.
