# Vision Sensor Network Subsystem Signoff - Not Implemented

The vision subsystem was cut due to not recieving sensors. 

# Function of the subsystem

The vision subsystem for this robot includes the sensor network that will be used for localization within the arena. The path will be preprogrammed into the robot as a large block of conditionals which will access sensor data from the vision subsystem.

The team chose the Adafruit VL53L0X Time of Flight Micro-LIDAR Distance Sensor for distance measurements in the arena and the RGB Color Sensor with IR filter for color sensing within the robot for active sorting and in order to find landmarks within the arena. 

The subsystem uses the top-level controller for processing sensor data, reading data more rapidly, and publishing the data to a ROS topic to communicate to the rest of the nodes within the computation graph. Nodes will be created for data acquisitions from the sensors, and will be decoupled from the logic that is making the robot follow its path through the arena. The path locomotion logic will be another node in the network which will subscribe to the data stream created by the sensor nodes, and produce command data for the low-level controller to create at a set interval which will activate the motors to follows the set command encoded in that data stream.

The team chose to use the TCS34725 Color Sensor to detect the duck pond location, which is also used within the design for the sorting subsystem for distinguishing between ducks and pedestals with are going through the bots conveyor belt system. 

## Function

The vision subsystem is a sensor network that will allow the robot to determine its position in the arena. This is done by finding the distance to the nearest walls, and also using a color sensor pointed towards the ground to detect the feeding areas and the duck pond in the middle of the arena. 

-	Large and small scale measurements are needed to detect position from distance and color
-	The sensors will communicate with top level microcontroller, the color sensor needs to be capable of distinguishing needed colors in the arena: blue, red, green, pink, and yellow. 
    - This communication between the top-level controller to the rest of the controller network will be within the ROS computation graph, so that the sensor acquisition and production can be decoupled from the actual navigation logic. They would be able to run entirely independent from one another but will only work if they are both running at the same time. 

# Constraints

The closest to the wall the robot will need to localize, or project a LIDAR towards a wall to find it general position in the arena, is near the wall at the duck pond. This will be $9"\ -\ \frac{width\ of\ robot}{2}=9" - 5.625" = 3.375" = 8.573\ cm$. This can be assumed because no objects will be within $2"$ of the wall, or $5.08\ cm$. The farthest from the wall that the robot will need to localize within the arena with the ToF LIDAR sensor is the length of the arena minus half the width of the robot, which is $48" - \frac{11.25"}{2} = 42.375" = 107.63\ cm$. This maximum distance will be when the robot is in the center of the arena long ways, for example, in the duck pond. The robot time of flight LIDAR sensors need to have be be able to measure between $5.08\ -\ 107.63\ cm$ with an accuracy of $+/-\ 0.707"$ or $+/-\ 1.8 cm$. This is within the distance range of $5\ -\ 120\ cm$ for the absolute distance, which is specified within the LIDAR sensor data sheet. The accuracy requirement ( $+/-\ 1.8 cm$ ) is analyzed below in the analysis section of this sign off. 

The robot must distinguish between different colors on the color spectrum, specifically the difference between black ( `0x000000` ) and blue ( `0x2876BB` ), so that the robot can localize over the duck pond to deliver the duck trailer precisely. These color values were taking from color sampling the image in the competition rules. 

LIDAR sensor data must be produced by the sensors at a high enough rate for the robot to be able to reach needed accuracy constraints.  

Sensors must be able to connect to one of the existing controller interfaces, either directly to one of the Arduino Mega2560 controllers or to the top level controller USART, SPI, or I2C.

List of constraints:

- Robot LIDAR sensor sensor distance thresholds (50 - 1200 mm)
- Color sensor accuracy, specifically with red, green, blue, and black (responsivity analysis below)
- Data production rate from the sensors, or sensor resolution (color sensor: take samples every $41.7\ mm$, LIDAR: < 400 kbit/sec)
- Sensor communication protocols availability (USART, SPI, I2C)

# Buildable Schematics

## CAD models

Below are images showing how all of the subsystems, including the vision sensor network will fit into the robot.

Top view

![image](https://user-images.githubusercontent.com/30758520/217405647-4aef4118-8f63-4c85-bbfe-5125365fd0a0.png)

Side view

![image](https://user-images.githubusercontent.com/30758520/217405754-b7508cac-6b67-48e5-bc1c-969beabe3828.png)

Rear Side view 1

![image](https://user-images.githubusercontent.com/30758520/217406171-b0454923-5b69-47fe-aef1-dd19d3acfe9c.png)

Rear Side view 2

![image](https://user-images.githubusercontent.com/30758520/217406076-af1fa457-ba10-4bc0-bd10-c326b97fa633.png)

Rear view

![image](https://user-images.githubusercontent.com/30758520/217406232-0fdc2a19-cdb0-42c5-bda1-3b213afa7b6e.png)

Front corner

![image](https://user-images.githubusercontent.com/30758520/217406258-9ac6acc2-2f57-4e2d-a900-f2ad3f18a0f0.png)

Bottom

![image](https://user-images.githubusercontent.com/30758520/217406342-82d7b362-cc9f-40ac-a97d-a80c6cf51ee9.png)

## Electrical Schematics 

![image](https://user-images.githubusercontent.com/30758520/218519001-13fccbc9-3add-4bb9-8bc5-e52de2323b04.png)

The 40-pin header connection design is represented in this sign off, and not in the top-level controller sign off.

# Analysis 

## Adafruit VL53L0X Time of Flight Micro-LIDAR Distance Sensor: 

### Robot LIDAR sensor distance thresholds analysis

### Max error calculation based on duck pond location:

Figure A

![image](https://user-images.githubusercontent.com/30758520/218898224-134045d1-7e99-4c46-bcc1-d9f43c864a46.png)

Above are all dimensions the LIDAR sensor will be expected to measure when releasing the trailer on the duck pond. Considering a 3% error (per the datasheet) in the sensor measurements indoors:

$error_{left\ side} = 3$% $of\ 50" = 1.5"$

$error_{right\ side} = 3$% $of\ 25.75" = 0.77"$

$error_{top\ side} = 3$% $of\ 6.25" = 0.1875"$

$error_{bottom\ side} = 3$% $of\ 28.375" = 0.85125"$

$d_{left\ side\ with\ error} = 50" ± 1.5"$

$d_{right\ side\ with\ error} = 25.75" ± 0.77"$

$d_{top\ side\ with\ error} = 6.25" ± 0.1875"$

$d_{bottom\ side\ with\ error} = 28.375" ± 0.85125"$

Figure B

![image](https://user-images.githubusercontent.com/30758520/218904829-e1eca4ee-9ec5-45bf-bc90-ded6b3852e13.png)

In Figure B, the corral is resting in the duck pond and the tolerance in the x and y direction. The allowable error is 5/8" on the x-axis (left and right) and 1/2" on the y-axis (up and down). The top sensor is within error tolerance for this measurement on the y axis and the x axis nearly within the allowable tolerance on the right side. The rules specify that a majority of the duck needs to be in the pond to count for points. This adds 1.5" to each of the error tolerance in the image above.

$tolerance_{left\ and\ right\ sides} = 0.625 + 1.5 = 2.125 in$

This tolerance is greater than the error found for left and right sides (1.5 in and 0.77 in, respectively) found in the calculations below Figure A.

$tolerance_{up\ and\ down} = 0.5 + 1.5 = 2 in$

This tolerance is greater than the error found for the top and bottom sides (0.1875 in and 0.85125 in, respectively) found in the calculations below Figure A.

These tolerances for error are greater than the maximum error in each direction. Therefore, the sensors should be able to accurately locate the duck pond for duck delivery.

*Note: Corral is being designed to be adjustable on it longest dimension if the corral needs to be smaller in order to land in the duck pond.*

## RGB color sensor with IR filter: 

### Color sensor accuracy, specifically with red, green, blue, and black analysis

Interrupts will be set to generate when the light intensity has exceeded the set threshold. Threshold values depend on many variables that can not be simulated like light allowed in the robot by the chassis, light provided by the sensor, and the distance from the target. 

![image](https://user-images.githubusercontent.com/30758520/218214807-59ad3827-e0c5-40d2-95bf-e212b0e115c6.png)

Above is the photodiode spectral responsivity (optical-to-electrical conversion efficiency) graph. Colors within the arena were purposefully chosen to fall at the peaks of the blue, green, and red curves shown. This makes color measurement easier, because colors should not regularly fall between the responsivity peaks. Color falls within the ranges below, which can be met with the color sensor selected. 

*Source: ![Encyclopedia Britannica](https://www.britannica.com/science/color/The-visible-spectrum)*

### Color sensor analysis for green versus red and black versus blue

*Note: analysis below shows percentage ratio of the respective red, green, or blue channel value to the clear channel value*

![image](https://user-images.githubusercontent.com/30758520/218564650-edd9df0a-3364-46cc-affe-ea88169ce358.png)

Convert to hex RGB values (all values below are in hex)

From the table above for $\lambda = 465\ nm$

$\frac{percentage\ red\ value}{percentage\ clear\ value}_{minimum} = 0$%

$\frac{percentage\ red\ value}{percentage\ clear\ value}_{maximum} = 15$%

$Minimum\ Register\ Value_{red}= ceiling\ of\ 0$% $\ast 0xFF = 0x00$

$Maximum\ Register\ Value_{red}= ceiling\ of\ 15$% $\ast 0xFF = 0x26$

$Average\ Register\ Value_{red}= ceiling\ of\ the\ average\ of\ 0x00\ and\ 0x26 = 0x08$

This process is continued for every wavelength given in the table below

|            |         |Red  |       |         |Green|      |         |Blue |     |         |           |
|------------|---------|-----|-------|---------|-----|------|---------|-----|-----|---------|-----------|
| Wavelength | Color   | Min | Max   | Average | Min | Max  | Average | Min | Max | Average | RGB VALUE |
| 465 nm     | Blue    | 0   | 27    | 8       | 1A  | 6C   | 1A      | A6  | E1  | 4D      | 081A4D    |
| 525 nm     | Green   | B   | 40    | F       | 99  | D9   | 49      | 1A  | 73  | 1C      | 0F491C    |
| 615 nm     | Magenta | CC  | 119   | 5F      | 0   | 24   | 7       | D   | 3E  | F       | 5F070F    |

If we map these wavelengths, 465 nm, 525 nm, and 615 nm, to represent blue green and red respectively, it is clear that the average of the corresponding RGB (red green blue) register is significantly larger than the others on average. Therefore, the team feels confident the color sensor will definitively show the difference between green and red on the playing field, as well as the absence of color, black, from blue. 

|                 | Lower Limit Red | Center Red | Upper Limit Red |
| --------------- | --------------- | ---------- | --------------- |
| Wavelength (nm) | 590             | 650        | 730             |
| RGB Hex Value   | 0xFFDF00        | 0xFF0000   | 0xC80000        |

|                 | Lower Limit Green | Center Green | Upper Limit Green |
| --------------- | ----------------- | ------------ | ----------------- |
| Wavelength (nm) | 500               | 540          | 570               |
| RGB Hex Value   | 0x00FF92          | 0x81FF00     | 0x01FF00          |

|                 | Lower Limit Blue | Center Blue | Upper Limit Blue |
| --------------- | ---------------- | ----------- | ---------------- |
| Wavelength (nm) | 400              | 450         | 490              |
| RGB Hex Value   | 0x8300B5         | 0x0046FF    | 0x00FFFF         |

|                 | Lower Limit Black | Center Left Black | Center Right Black | Upper Limit Black |
| --------------- | ----------------- | ----------------- | ------------------ | ----------------- |
| Wavelength (nm) | 0                 | 380               | 760                | 790               |
| RGB Hex Value   | 0x000000          | 0x610061          | 0x8D0000           | 0x000000          |

### Red vs Green
The typical red color has a wavelength of 650 nm and corresponds to the RGB hex number 0xFF0000. The typical green color has a wavelength of 540 nm and corresponds to the RGB hex number 0x81FF00. Red meets green at $\approx$ 580 nm wavelength and hex 0xFFFF00. This color is closer to a bright yellow, and is not very close to either green or red. The red and green hex values are different enough such that the color sensor will be able to distinguish between them.

### Blue vs Black
Black corresponds to very low and high wavelengths and hex values close to 0x000000. Blue is centered at 450 nm and 0x0046FF in hex. Blue has a wide enough range such that the color sensor will be able to distinguish between blue and not blue.

### Data production rate from the sensors, or sensor resolution analysis

$F_{clock}\ \ 0-400kHz$

![image](https://user-images.githubusercontent.com/112428796/203214738-1178d2db-62f4-489b-8cfd-b6a167bece1f.png)

The majority of the time, the sensor will be in the states idle, RGBC ADC and RGBC INIT after the startup. Detection will take a maximum of 616.4 ms.

When the color sensor is pointed towards the ground, the bot will move at $0.2023\ \frac{m}{s}$, the robot samples per distance traveled will be $0.2023\ \frac{m}{s} * 0.6164\ s = 0.125\ m = 125\ mm$. The robot will be slowed down when finer samples are needed. $0.0677 \frac{m}{s}$ is the minimum speed of the robot, and it will be able to take samples every $41.7\ mm$ at that speed. 

### Sensor communication protocols availability (USART, SPI, I2C)

All of these sensor use I2C, which is a very common communication protocol which allows for many devices on a single bus. Both of our controller models support I2C communication. 

# Software Consideration - Possible/Probable Software Solutions

Public software libraries have been created for interfacing with boh sensors selected for the vision sensor network. Libraries are provided by Adafruit and linked below,

![TCS34725 - Color Sensor Software Library](https://github.com/adafruit/Adafruit_TCS34725)

![VL53L0X - ToF LIDAR Sensor Software Library](https://github.com/adafruit/Adafruit_VL53L0X)

# BOM

| Name of Items   | Description                                                  | Used in which subsystem(s) | Part Number      | Manufacturer            | Quantity | Price      | Total   |
|-----------------|--------------------------------------------------------------|----------------------------|------------------|-------------------------|----------|------------|---------|
| Color Sensor    | RGB COLOR SENSOR WITH IR FILTER                              | Vision                     | TCS34725         | Adafruit Industries LLC | 2        | $7.95      | $15.90   |
| Distance Sensor | Adafruit Time of Flight Micro-LIDAR Distance Sensor Breakout | Vision                     | VL53L0X          | Adafruit                | 8        | $14.95     | $119.60  |
| Resistors       | EDGELEC 100pcs 4.7K ohm Resistor 1/2w (0.5Watt) ±1% Tol      | Vision                     | EFR-W0D50-A:MF   | EDGELEC                 | 1        | $5.99      | $5.99   |
|                 |                                                              |                            |                  | Total Components        | 3        | Total Cost | $141.49  |
