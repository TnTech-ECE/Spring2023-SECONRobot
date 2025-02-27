# **Experimental Analysis**

### **Cut Subsystems and Justification**

The following subsystems have been cut since the beginning of the project:
- Sorting
    - Due to size constraints and the parts for this subsystem not arriving, this subsystem was cut.
- Duck Storage and Delivery
    - The project was rescoped before the competition and the duck storage and delivery subsystem did not make it into the final implementation. This decision was made unanimously by the team at the competition. It was determined that the duck storage and delivery system, while well designed and theoretically functional, could not be reliably implemented before the competition. 
- Pedestal Storage and Delivery
    - Due to size constraints and the parts for this subsystem not arriving, this subsystem was cut.
- Vison
    - Due to the parts for this subsystem not arriving, this subsystem was cut.
- Consumption (repurposed - now called Delivery Subsystem)
    - The project was rescoped before the competition and the consumption subsystem did not make it into the final implementation. This decision was made unanimously by the team at the competition. The team decided to transition the consumption subsystem into the delivery subsystem. The direction of the motor was changed to push instead of consume, and the subsystem was used to push what items had been collected into the recycling area.


The following shall statements were closely related to these subsystems and therefore will not be discussed in this experimental analysis document:

- Shall design a robot which can find and move 90% of
the ducks into a holding area connected to the robot.
- Shall locate the duck pond in the center of the arena
within plus or minus one inch of error tolerance.
- Shall transport and place 90% of the ducks stored inside
the holding area to their final location in the duck pond.
- Shall find and move at least five pedestals into an internal
holding area inside the robot.
- Shall assemble one statue that is three pedestals tall and
one statue that is two pedestals tall using all five pedestals
obtained in order to maximize points obtained based on
discussion in weekly meetings.
- Shall place statues entirely inside the white inner circles
within plus or minus one inch of error tolerance.
- Shall place remaining unused pedestals that are held after
the five required pedestals have been obtained within the
internal holding area inside the robot.
- Shall move the extra pedestals obtained over the five
required pedestals in the recycling area.

## **Constraints from Signoffs:**

### **Full run from competition [here](https://www.youtube.com/watch?v=IqyCZeEZ9IM&t=77s)**

## **General results from runs at the competition:**

For each run, there were ten ducks and seven pedestals randomly distributed on the arena as well as six food chips (3 red and 3 green) that the team could pre-load before the run started. The team had three minutes after the start switch was flipped to get as many points as possible. The results from these runs are shown below.

![image](https://user-images.githubusercontent.com/30758520/233695916-4d6cd822-c135-4ab4-8c09-e996e37ffa73.png)

| Round | Green chip | Red chip | Cylinder Recycle | Duck Recycle | Duck Pond | Grand Total Points |
| ----- | ---------- | -------- | ---------------- | ------------ | --------- | ------------------ |
| 1     | 3          | 3        | 1                | 4            | 0         | 52                 |
| 2     | 3          | 3        | 0                | 0            | 0         | 42                 |
| 3     | 2          | 3        | 0                | 0            | 0         | 35                 |
| 4     | 2          | 2        | 4                | 6            | 0         | 48                 |
| 5     | 3          | 3        | 4                | 1            | 0         | 52                 |
| 6     | 2          | 2        | 1                | 2            | 1         | 39                 |

Below is the number of points scored in each round of the competition. If we had integrated the all functionality targeted after the rescope, we would have scored 86 points each round. 

Recycling: $2\ points * 17\ objects = 34\ points$

Feeding: $6\ correct chips * 7\ points = 42 \ points$

Fireworks: $1\ fireworks\ switch\ flip * 10\ points = 10\ points$

Total: $86\ points$

![image](https://user-images.githubusercontent.com/30758520/233694043-275d64be-87a2-4914-8785-920ce69120bd.png)

## **Feeding results:**

- **Purpose of Experiment**

For this experiment, the team intends to measure the accuracy of the chip feeding mechanism implemented on the robot. 

- **Description**

Experimentation was conducted during the runs at the competition. 

For each run, there were ten ducks and seven pedestals randomly distributed on the arena as well as six food chips (3 red and 3 green) that the team could pre-load before the run started. The team had three minutes after the start switch was flipped to get as many points as possible. The robot had to navigate the field autonomously and no one could intervene on the robot in anyway or the round would end. 

- **Expectation (Prediction)**

The expectation for this experiment was to consistently delivery food chips reliably. The team tested the robot in the build up to the competition and the robot was able to reliably deliver the food chips with error only on every third run. 

- **Number of trials** 

The number of trials for this experiment was the number of round played at the competition, which was 6. 

- **Results** 

The design has been changed to two separate cups with two separate servo motors in order to simplify the design. The cups are only big enough to hold the chips, and are mounted on the servo motors which are mounted on the outer edge of the robot, thus saving much needed space inside the robot.

The food chip dispensers can be seen in the image below. They are located on the top crossbar of the robots chassis. They consist of a cup connected to a servo motor.

![image](/Documentation/Images/finalcadmodel.png)

Below is the final experimentation taken during the competition, we consistently delivered food chips, but did not meet the idealized goal of delivering 100% of the food chips correctly all of the time. 

![image](https://user-images.githubusercontent.com/30758520/233709956-6bf99dc6-b242-4860-a47f-503b10eb8f78.png)

- Since the design has been simplified in order to save time, the servos do not need to have as much torque. However, they have much more than sufficient torque needed to flip the cups and dump the chips during the competition. Servos purchased met requirements based on analysis performed in sign offs.

- **Interpretation**

Feeding was able to meet a high standard, but was unable to meet the 100% standard written in our project proposal. It can be seen from the results above that many of the points scored in the competition were from the feeding mechanism. 

In hindsight, the expectation for feeding from the project proposal was too high a standard, because it was very unlikely that this could have delivered the chips correctly in every attempt. 

## **Locomotion results:**

### **Experiment #1: Weight**

- **Purpose of Experiment**

The purpose of this experiment was to measure the weight of the robot. This was too confirm that the weight constraint from the locomotion sign off was met in the final implementation. 

- **Description**

The weight was a constraint of the locomotion subsystem due to the weight limitation of the mecanum wheels that we purchased. This weight constraint was that the robot needed to be < 10.376 kg.

- **Expectation (Prediction)**

Due to the analysis doe in the sign off for locomotion, the team was confident that the robot met the weight constraint that is being tested in this experiment. The expectation for this experiment was that the robot would fall within the weight constraint defined. 

- **Number of trials** 

The team weighed the robot six times on the scale in the machine shop in the basement of Brown and the robot weighed 14 pounds. 

- **Results** 

- **Weight of the robot**

The final competition robot weight was $14\ pounds\ or\ 6.35029\ kg\ \lt\ \approx\ 10.376\ kg$. 

This means the final weight of the robot was within specification defined in the constraints for the project. 


- **Interpretation**

It can be seen that the robot fell well within the weight constraints defined in the sign off for locomotion. This constraint has been verified to have been met in the final implementation. 

### **Experiment #2: Velocity**

- **Purpose of Experiment**

The purpose of this experiment was to verify that the velocity achieved in the arena is greater than the minimum required speed defined in the locomotion sign off.

- **Description**

Locomotion subsystem speed was set using a PID controller running on the Arduino Mega2560. The speed was represented in rotations per minute (RPM). 

- **Expectation (Prediction)**

The expectation from this experiment is that the robot moved faster than the minimum speed defined in the locomotion sign off. 

- **Number of trials** 

The number of trials for this experiment was 6 for each round completed in the competition. 

- **Results** 

***Max Speed***

$\frac{150\ rotations}{1\ min} * \frac{1\ min}{60\ sec} * \frac{48\pi\ mm}{1\ rotation} * \frac{0.00328084\ feet}{mm} = 1.24 \frac{feet}{sec} \gt 0.0677 \frac{meter}{sec} = 0.222 \frac{feet}{second}\ (minimum\ speed\ requirement)$

***Typical Competition Speed***

$\frac{100\ rotations}{1\ min} * \frac{1\ min}{60\ sec} * \frac{48\pi\ mm}{1\ rotation} * \frac{0.00328084\ feet}{mm} = 0.825 \frac{feet}{sec}$

- **Interpretation**

Experimentation above shows that the speed of the robot in the arena satisfied the minimum speed requirement defined in the locomotion sign off. 

## **Power results:**

### **Experiment #1: Battery Voltages**

- **Purpose of Experiment**

The purpose of this experiment was to verify that the power subsystem will supply the proper voltage to the subsystems that require a certain voltage level.

- **Description**

The multimeter was used to verify the output voltage of the DC/DC regulator while connected to the entire system to make sure the regulator output a steady 12 V output.

- **Expectation (Prediction)**

The team expects that the voltage output of the DC/DC regulator while connected to the entire system to be a steady 12 V output.

- **Number of trials** 

The number of trials for this experiment was 6 for consistency throughout the analysis.

- **Results** 
 
The output of the TalentCell battery is regulated by the DC-DC Converter and provides a nearly constant 12 V to sufficiently power all components connected to it including the buck converter to the servo motors and the buck converter connected to the Jetson.

The multimeter measured around 11.95 V each trial. 

![image](https://user-images.githubusercontent.com/30758520/233793598-dbe7725d-6852-40ce-ad32-802ec22b6154.png)

The main power bus in the robot was supplied from two 6 V MightyMax batteries in series. This bus was connected to all the locomotion DC motor drivers. One of these 6 V battery was used to power the 6 V motor driver for the delivery subsystem. A separate bus was created for powering the Jetson and the servo motors, and it was supplied from the 12 V TalentCell battery. All power connections had a common ground. 

The multimeter was connected to the output of the buck converter while connected to the rest of the system to verify.

![image](https://user-images.githubusercontent.com/30758520/233697833-3bc1f7bb-657a-4d66-8486-f8fc0813a44f.png)

Further measurements were made on the 6 V batteries to verify the voltages of the batteries with just one of the batteries and both in series. The batteries were connected to the system as a whole and they were under load.

![image](https://user-images.githubusercontent.com/30758520/233715824-52d89ee1-65dc-4fc7-add1-e70f3f5c88bc.png)

![image](https://user-images.githubusercontent.com/30758520/233715856-2fdab99d-5e7d-44c8-afff-877f455ce1a9.png)

- **Interpretation**

The battery is sufficient in providing 12 V and over 2 A to meet the robot’s needs. This was achieved with the original 12 V TalentCell battery as well as two 6 V MightMax batteries connected in series.

### **Experiment #2: Buck Converter Noise**

- **Purpose of Experiment**

One of the constraints for this subsystem was that noise from the buck converters would be eliminated. LC filters were added to reduce this noise.

- **Description**

Measurements were taken using an osciloscope that was connected across the output of the buck converter both before and after the filter.

- **Expectation (Prediction)**

It was expected that the noise would be eliminated after the filter was applied.

- **Number of trials** 

Five different trials were run.

- **Results** 

Below is images of the noise before and after the filter was applied. The image for after the filter is the best result.

Before filtering:

![image](https://user-images.githubusercontent.com/112428796/233485511-202565f5-ed1d-4c17-b028-e54fba6b84a1.png)

After Filtering:

![image](https://user-images.githubusercontent.com/112428796/234083083-928fcb9b-e57c-4e92-90bf-c679c3733fd7.png)

![image](https://user-images.githubusercontent.com/112428796/234081461-93ca6361-ae00-4f6c-8cb7-88f769f47894.png)



- **Interpretation**

The noise after adding the filter is less significant than without the filter. Though the filter did not eliminate noise, but the peak to peak voltage is significantly lower and the noise signal overall is cleaner. The peak to peak voltage of the noise before the filter was around 400 mV whereas after the filter it was 150 mV or lower per trial.


## **Delivery Subsystem (was called Consumption) results:**

- **Purpose of Experiment**

The purpose of this experiment is to test the results of the delivery subsystem to getting items to the recycling area during the competition. Each item in the arena, food chips, ducks, and pedestals were all worth the same amount of points. 

- **Description**

This experimentation was taken during the competition rounds in Orlando.

For each run, there were ten ducks and seven pedestals randomly distributed on the arena as well as six food chips (3 red and 3 green) that the team could pre-load before the run started. The team had three minutes after the start switch was flipped to get as many points as possible. The robot had to navigate the field autonomously and no one could intervene on the robot in anyway or the round would end. 

- **Expectation (Prediction)**

The expectation for this experiment was that the robot would effectively push multiple items into the recycling area. The decision to shift to the pusher happened at the competition. We expected to average items in recycling after the round to be 3.5 items.

- **Number of trials** 

The number of trials for this experiment was the number of round played at the competition, which was 6.

- **Results** 

Many variations of spokes have been tested in order to see which ones work the best. The only spokes that were used in the final implementation were curved TPU spokes, and those can be seen in the final total robot CAD model in this document. 

The size of the final delivery implementation was 5.25"x9.25"x11.75" (LxWxH). The delivery mechanism is large enough for a duck to be consumed as well as the pedestals, while also being within specification for the robot size set by the competition.

Note: In the final implementation in the competition, no ducks or pedestals were consumed. The motor direction of the delivery motor was reversed and the consumption was converted into a pusher. The robot collected objects in the arena on the consumption ramp, and then the spokes pushed out the objects into the recycling. 

There are three walls surrounding the intake in order to protect any limbs from moving parts. This was a safety feature implementation based on considerations made during detailed design. 

The chart below conveys the effectiveness of the delivery subsystem on the robot. 

![image](https://user-images.githubusercontent.com/30758520/233710010-64f2d292-e386-41c6-a8b7-ac739a465b59.png)


- **Interpretation**

The resulting average items in recycling after each round during the competition was $\frac{5+0+10+5+4}{6}$. This is very close the predicted outcome in the prediction above. It can be seen however that the implementation was quite volatile in practice. 

Rounds 2 & 3 were bad throws in the randomness of the items around the arena. The robot performed better if the items were thrown towards the switch because of our path implementation. We turned a lot around the feeding area getting the chips to the red and green feeding areas and our path sweeped towards the switch from the feeding areas so if they were on that side of the board they were significantly more likely to get pushed closer to the recycling area. 

## **Fireworks results:**

- **Purpose of Experiment**

The purpose of this experiment was to demonstrate that the robot was able to flip the switch. 

- **Description**

This experiment as conducted in the Capstone Lab on the board that we built for testing. 

- **Expectation (Prediction)**

The expectation for this experiment was that the robot would have the force to flip the switch as analyzed for in the sign offs for fireworks, but that it would not reliably flip the switch consistently due to in precision in the path and position of the robot. 

- **Number of trials** 

The number of trials for this experiment was the number of round played at the competition, which was 6.

- **Results** 

The robot did not flip the switch during the competition, but did have the force needed to flip the switch.

The robot has the force necessary to flip the switch without issue, though it did not flip the switch during the competition. 

Video Demonstration of the Fireworks Switch [here](https://www.youtube.com/watch?v=TUixtoiBSds)

- **Interpretation**

The robot was unable to flip the switch in the competition, but did have the force necessary to do so. 

The issue of not being able to flip the switch was a path script that was not perfected to flip the switch in the arena at the competition. We also did not have LIDAR sensors that we ordered that could have been used for the robot to locate itself in the arena precisely.  

## **Measures of Success from Project Proposal**
- The team rescoped and decided not to start using the LED indicator to instead focus on other subsystems. A start switch was added to replace this functionality. 

- The robot was unable to drop all the chips in the correct location on every competition run. A table showing all points scored is shown in the feeding section under the shall statements.

- The project was rescoped to remove duck storage and therefore did not collect and store any ducks. They were instead be pushed to the recycle area.

- The robot was unable to flip the light switch during the six competition rounds. The python script has been written as well as the video has been made as of March 10, 2023.

- Due to the sorting, consumption, and pedestal storage subsystems being cut or repurposed, the pedestals will no longer be consumed, sorted, or stacked. Instead, pedestals will be pushed to recycling just like the ducks.

- The robot's path was altered to push as many objects as possible into the recycle area, instead of placing any remaining items into the recycle area.

## **Shall Statements**

### **Power:** 

- Shall design an autonomous robot with a single start
button, allowing the robot to start moving through its
environment.

    - The start button was implemented as a start switch. This starts the path for the robot. This is shown in the full round video at the top of this document. 
    
- The robot will have a single emergency stop button at a
point that is easily accessible and can be safely reached,
which will shut down all physical movement performed
by the robot in the case of an emergency.

    - The E-stop button is easily accessible on the top of the robot. The switch cuts all power to the dc motors for locomotion and delivery. his is shown in the full round video at the top of this document.

- Shall create an easily reachable (not blocked by motors,
chassis, wheels, or any other object) emergency cut off
switch to allow the team to disable the robot in the case
of an emergency.

    - The E-stop button is easily accessible on the top of the robot. his is shown in the full round video at the top of this document.

- Shall have a self-latching emergency stop push-button
that has a positive operation. The button shall not be a
graphical representation or a flat switch based on NFPA
79 - 10.7.2. [1] This constraint addresses the need for the
addition of practical engineering standards.

    - The E-stop button chosen meets these specifications.
    
![image](https://user-images.githubusercontent.com/112428796/233485670-f1d4f3da-88d5-4cbe-b57c-d3cf5355f9d6.png)

Video demonstration of E-stop [here](https://www.youtube.com/watch?v=tuQbhPMOLbw).

- Shall abide by the Department of Energy Standard 79
FR 7845 in the team’s purchase or design of wall warts
for energy conservation and efficiency. [3] This constraint
addresses an ethical consideration by better ensuring the
safety of the team and all others interacting with the robot
as well as the addition of ethical standards.

    - The wall wart bought with the TalentCell battery abides by this standard.

### **Software:**

- Shall represent knowledge using IEEE standard IEEE
1872-2015 Ontologies for Robotics and Automation used
to represent knowledge about the typography of the arena.
This ontology will be used to represent relationships
between the landmarks in the area and what is known.
It should not change during the competition, so it can be
predefined. [2]

    - We ended up using encoder distances to represent the movement and position in the arena. This was written during the conceptual design when we had been considering using SLAM to navigate the arena area. 

### **Feeding:**

- Shall design an autonomous robot that will earn all
possible points for delivering 100% of the correct food
chips to both the manatees and alligators.

    - This was accomplished in the first two rounds of the competition, but was not accomplished in the later rounds of the competition. 

### **Fireworks:** 
- Shall design an autonomous robot that will be able to flip
a switch from left to right.

- Shall design an animated fireworks MPEG video and
write a Python script that will play the video when
activated by the switch.

    - This fireworks video was created, and won second place in a separate competition for most creative fireworks video. It was judged based on creativity and school spirit. 
    
### **Chassis:**
- Chassis will be designed with an aluminum frame. Alu-
minum is abundantly available under the earth’s surface
and mining can be offset with post-mining rehabilitation
and efficient recycling. This constraint will lessen the
broader impact the team has on the environment.

    - The chassis was constructed using Aluminum extrusion 80 x 20.
