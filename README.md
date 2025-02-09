# Sylvanian Tech Family

- [Sylvanian Tech Family](#sylvanian-tech-family)
  - [Project Description](#project-description)
      - [What's better than a domotic house? A Sylvanian Family domotic house!](#whats-better-than-a-domotic-house-a-sylvanian-family-domotic-house)
    - [Presentation and video](#presentation-and-video)
  - [Requirements](#requirements)
    - [Hardware](#hardware)
    - [Software](#software)
    - [Pin out](#pin-out)
  - [Getting started](#getting-started)
    - [Building the project](#building-the-project)
    - [Burning and running the project](#burning-and-running-the-project)
  - [Team members](#team-members)
  - [Project diagram](#project-diagram)
  - [Project layout](#project-layout)

## Project Description

#### What's better than a domotic house? A Sylvanian Family domotic house!

<img src="./docs/sylvanian_family.jpg" alt="drawing" height="200"/>

The Sylvanians are a puppet family who lives in a traditional doll house.
To help them out in their daily life, in keeping the house warm and safe, and
the garden greener than the neighbour's one, we've built an Embedded System
that can contribute in common routines and that adds safety to those assailable
cardboard walls.

This project was built with the intention of concretely replicating all the notions
acquired during the Embedded System for the Internet of Things course.
Our aim is to implement in a single embedded system extensive control over the
most frequently used things in a house.

Many features have been added to the house:

- Alarm system
- Earthquake detector
- Automated lights
- Automated front door
- Climate plant
- Irrigation plant

The LCD has been used to display real-time events.

### Presentation and video

- [Presentation](https://docs.google.com/presentation/d/1W6sGwKaeywJN_hmt3aGy_PK22Og2mWv0d_z1uNpjzVE/edit?usp=drivesdk)

- [Pdf presentation](./docs/Presentation_Sylvanian_Tech_Family.pdf)

- [Video presentation](https://youtu.be/9xOE8SbTiaM?si=zp56sMGeyDPLHiY1)

## Requirements

### Hardware

- [TI MSP432P401R Microcontroller](https://www.ti.com/lit/ds/slas826e/slas826e.pdf)
- [TI BOOSTXL-EDUMKII BoosterPack](https://www.ti.com/tool/BOOSTXL-EDUMKII)
  - Sensors used:
    - light sensor
    - temperature sensor
    - accelerometer
    - button S1
    - button S2
    - voltmeter
- Breadboard
- 3 LEDs
- 1 servo motor
- 1 buzzer
- wires

<img src="./docs/msp_exp432p401r.jpg" alt="drawing" height="150"/> <img src="./docs/boosterpack.png" alt="drawing" width="250"/>

### Software

- [CodeComposerStudio](https://www.ti.com/tool/download/CCSTUDIO/12.2.0)

### Pin out

- Red Led: J1.5 maps to Port 4.1
- Blu led: J1.6 maps to Port 4.3
- Additional Buzzer: J4.40 maps to Port 2.7

<img src="./docs/tink.png" alt="drawing" height="150">

## Getting started

Place the TI driverlib `source` folder inside the `driverlib` folder like this:

<img src="./docs/driverLibLocation.png" alt="drawing" height="150"/>

> You can download the driverlib folder
> from [here](https://drive.google.com/file/d/1w_YTRS9HwMnIs1PKtQFa6hqd9J2PM_93/view?usp=sharing)

### Building the project

Open the folder `embedded-project-src` in CCS.

> Note: do NOT open in CCS the whole `embedded_project` folder, since it contains additional files that are not needed for the CCS project.

The project includes are already set up to include the driverlib folder, you should be able to build the project without
any additional setup.

ARM compiler include options:

- `${PROJECT_ROOT}/../driverlib/source`

ARM linker file search path options:

- `${PROJECT_ROOT}/../driverlib/source/ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib`

### Burning and running the project

Use the CCS GUI (User's guide available [here](https://software-dl.ti.com/ccs/esd/documents/users_guide_ccs_20.0.0/index.html))

## Team members

Every team member is responsible for the whole project, despite individual contributions such as following:

- Berardo Cristiano designed house alarm, its buzzer and voltmeter, and wired connections
- De Piccoli Martina designed house irrigation plant and earthquake detector using the accelerometer
- Lovo Nicola (coordinator) designed house front door, its servo motor and light sensor
- Prati Matilde designed house climate system and handled temperature sensor outputs

## Project diagram

<img src="./docs/drawio_project_FSM.png" alt="drawing" height="500"/>

## Project layout

```
├───docs
├───driverlib
│   └───source
└───embedded-project-src
    ├───features
    │   ├───alarm
    │   ├───climate
    │   ├───door
    │   └───irrigation
    ├───lcdDisplay
    ├───outputs
    │   ├───blueLED
    │   ├───buzzer
    │   ├───redLED
    │   ├───rgbLED
    │   └───servo
    ├───sensors
    │   ├───accelerometer
    │   ├───alarm
    │   ├───climate
    │   ├───doorButton
    │   ├───irrigationButton
    │   ├───light
    │   └───voltmeter
    ├───targetConfigs
    ├───testing
    │   ├───alarm
    │   ├───climate
    │   ├───door
    │   └───irrigation
    └───tools
        └───LcdDriver
```
