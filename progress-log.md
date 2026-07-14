\## 2026-06-01



\### Goal

Build and test a prototype automated irrigation system.



\### Progress



\#### ESP32 Setup

\- Installed CP210x driver.

\- Connected ESP32 DevKit V1 to Arduino IDE.

\- Successfully uploaded blink sketch.



\#### Relay Test

\- Wired relay to ESP32.

\- GPIO26 successfully controlled relay.

\- Relay clicked every 2 seconds.



\#### Pump Test

\- Verified pump operation using adjustable power supply.

\- Set power supply to 12V.

\- Connected pump through relay.

\- Confirmed ESP32 could start and stop pump.



\#### Moisture Sensor Test

\- Connected capacitive moisture sensor to GPIO34.

\- Recorded readings:



| Condition | Reading |

|------------|------------|

| Air | \~3305 |

| Dry Soil | \~3255 |

| Wet Soil | \~1140 |

| Water | \~1140 |



\#### Integration

\- Combined sensor, relay, and pump.

\- Created automatic watering logic.

\- Selected moisture threshold of 2500.



\### Challenges

\- ESP32 initially not detected by Arduino IDE.

\- Installed CP210x USB driver.

\- Single breadboard was too narrow; switched to two breadboards.



\### Outcome

Successfully demonstrated:

Dry Soil → Pump ON

Wet Soil → Pump OFF



\### Next Step

\- Research servo selection and probe arm design.

\- Design a mechanism capable of lowering, measuring, and retracting the moisture probe.

\- Order New Parts

\- Begin Phase 2: Automated Probe Mechanism.

## \###2026-06-08



\### Goal

Plan Phase 2 of the autonomous plant-care robot and determine a feasible robotic arm architecture.



\### Progress



\#### Arm Planning

\- Evaluated multiple robotic arm configurations.

\- Determined a gripper is not required for current project goals.

\- Selected target arm architecture:

&#x20; - Base rotation

&#x20; - Shoulder joint

&#x20; - Elbow joint

&#x20; - Wrist joint

\- Determined the arm should support:

&#x20; - Soil probing

&#x20; - Moisture measurement

&#x20; - Future watering functionality



\#### Pot Geometry

\- Identified expected maximum pot size:

&#x20; - 8 in height

&#x20; - 8 in diameter

\- Considered future support for:

&#x20; - Seed trays

&#x20; - Small nursery pots

&#x20; - Mature potted plants



\#### Soil Insertion Force Test

Measured force required to fully insert moisture sensor into soil.



| Soil Type | Trial 1 | Trial 2 | Trial 3 |

|------------|------------|------------|------------|

| Dry Soil | 0.300 kg | 0.436 kg | 0.186 kg |

| Wet Compact Soil | 0.616 kg | 0.777 kg | 0.595 kg |

| Wet Non-Compact Soil | 0.271 kg | 0.185 kg | 0.156 kg |



\- Maximum measured force: 0.777 kg.

\- Dry soil results varied due to large chunks in the soil.

\- Wet compact soil required the highest insertion force.



\#### Design Decisions

\- Determined probe insertion force is lower than expected.

\- Decided to prototype a servo-driven arm before investing in a dedicated linear slide mechanism.

\- Chose to use 3D printing for rapid arm prototyping.

\- Planned modular arm segments to allow geometry changes without redesigning the entire arm.



\#### Hardware Selection

Selected components for Phase 2:



\- 4x DS3218MG 20kg metal gear servos

\- PCA9685 servo driver

\- 12V to 6V buck converter

\- LM2596 buck converter modules

\- M3 stainless hardware kit

\- Roller limit switches

\- Servo extension cables



\### Challenges

\- Determining the optimal arm geometry.

\- Balancing reach requirements for large pots and seed trays.

\- Deciding whether a dedicated probing mechanism will be required in future iterations.



\### Outcome

Successfully quantified soil insertion forces and established an initial Phase 2 arm development plan.



\### Next Step

\- Order Phase 2 hardware.

\- Create initial CAD models.

\- Design servo mounts and modular arm segments.

\- Begin arm prototyping and insertion testing.





## 2026-06-12



\### Goal

Set up and test the Phase 2 servo control system.



\### Progress



\#### Parts Inventory

Verified arrival of Phase 2 components:



\- 4x DS3218MG 20kg metal gear servos

\- PCA9685 servo driver

\- 24V to 6V buck converter

\- 10x roller limit switches

\- 10x servo extension cables

\- M3 hardware kit



\#### Power System Setup

\- Powered adjustable DC power supply.

\- Set power supply output to 24V.

\- Connected 24V to 6V buck converter.

\- Measured converter output using multimeter.

\- Verified output voltage of 6.32V.



\#### PCA9685 Setup

\- Connected buck converter output to PCA9685 servo driver.

\- Connected ESP32 to PCA9685:

&#x20; - 3.3V → VCC

&#x20; - GND → GND

&#x20; - GPIO21 → SDA

&#x20; - GPIO22 → SCL

\- Verified PCA9685 power indicator illuminated.



\#### I2C Communication Test

\- Uploaded I2C scanner sketch.

\- Detected PCA9685 at address 0x40.

\- Detected secondary address at 0x70.

\- Confirmed successful communication between ESP32 and PCA9685.



\#### Servo Test

\- Installed Adafruit PWM Servo Driver library.

\- Connected DS3218MG servo to PCA9685.

\- Uploaded servo test sketch.

\- Initially connected servo to incorrect channel.

\- Corrected servo channel assignment.

\- Successfully controlled servo position through PCA9685.

\- Verified servo movement under software control.



\### Challenges

\- PCA9685 and ESP32 both used male header pins, requiring breadboard routing.

\- Buck converter output wires were larger than PCA9685 terminal openings.

\- Servo was initially connected to the wrong PCA9685 channel.



\### Outcome

Successfully established the complete servo control architecture:



\- ESP32

\- PCA9685 servo driver

\- 24V power supply

\- 24V to 6V buck converter

\- DS3218MG servo



Successfully achieved first software-controlled servo motion for Phase 2.



\### Next Step

\- Characterize servo position ranges.

\- Interface a microswitch with the ESP32.

\- Detect microswitch state changes in software.

\- Develop initial servo-driven probing mechanism.

\- Begin mechanical prototyping of the soil probing arm.
## 2026-07-07



\### Goal

Fabricate the first robotic arm base prototype and begin development of the shoulder assembly.



\### Progress



\#### Base Prototype Fabrication

\- Successfully 3D printed the robotic arm base components.

\- Printed the base housing, rotating platform, and large spur gear.

\- Verified dimensional accuracy and overall print quality of the printed components.



\#### Base Assembly

\- Installed the DS3218MG 20 kg digital servo into the base housing.

\- Mounted the rotating platform onto the base assembly.

\- Installed the servo horn and large spur gear.

\- Test assembled the complete base module.

\- Verified fitment of all primary mechanical components.



\#### Base Design Validation

\- Confirmed the servo mounts securely inside the housing.

\- Verified proper alignment between the rotating platform and base housing.

\- Confirmed the square mounting interface can be used as the attachment point for future arm modules.

\- Verified cable routing through the rear opening of the housing.



\#### Shoulder Module Design

\- Designed the first shoulder arm link.

\- Implemented a dual-sided shoulder bracket to support the arm at the pivot.

\- Designed the upper arm as a lightweight truss structure to reduce weight while maintaining rigidity.

\- Added large mounting bosses at each end of the arm for future shoulder and elbow joints.

\- Designed the arm as a modular component that can be replaced independently of the base.

\- Began 3D printing the first shoulder arm prototype for physical testing and validation.



\#### Design Decisions

\- Continued with a bearing-less rotating base for the first prototype.

\- Prioritized rapid prototyping and functional validation over mechanical optimization.

\- Adopted a modular design philosophy, allowing the base and arm assemblies to be developed independently.



\### Next Steps

\- Complete fabrication of the shoulder arm prototype.

\- Assemble and test the shoulder joint.

\- Design the elbow module.

\- Integrate the moisture probe mounting mechanism.

\- Evaluate arm rigidity and shoulder servo performance under load.
## 2026-07-10



\### Goal

Complete the electronic integration of the robotic arm and establish reliable manual software control of every joint.



\### Progress



\#### Mechanical Improvements

\- Redesigned and installed a wider base for the robotic arm.

\- Increased the overall support footprint to improve stability.

\- Reduced the tendency of the base to lift during arm movement.

\- Created an enclosed center section for future electronics and cable management.



\#### Electronics Integration

\- Wired the ESP32 DevKit V1 to the PCA9685 16-channel PWM servo driver using I2C communication.

\- Connected the PCA9685 to the dedicated 6V buck converter for servo power.

\- Verified proper communication between the ESP32 and PCA9685.

\- Successfully powered the servo system using the external power supply.



\#### Servo Software Development

\- Installed and configured the Adafruit PWM Servo Driver library.

\- Developed initial software to control servos through the PCA9685.

\- Established serial communication between the PC and ESP32.

\- Implemented manual servo control through commands entered in the Arduino Serial Monitor.

\- Resolved an issue where `Serial.parseInt()` caused servos to unintentionally reset to 0°.

\- Replaced the command parser with line-based serial input for reliable command execution.



\#### Robotic Arm Testing

\- Verified independent control of each servo.

\- Successfully controlled:

&#x20; - Base rotation

&#x20; - Shoulder joint

&#x20; - Elbow joint

&#x20; - Wrist joint

\- Confirmed all arm joints respond correctly to software commands.

\- Successfully demonstrated full manual control of the robotic arm from the PC.



\#### End Effector

\- Mounted the capacitive soil moisture sensor to the wrist assembly.

\- Verified the arm is mechanically capable of positioning the sensor for future soil probing.



\### Current Status

The first functional robotic arm prototype is now mechanically assembled, electronically integrated, and fully controllable through custom software. Every joint can be independently commanded from the computer, completing the first stage of robotic arm control.



\### Next Steps

\- Calibrate the safe operating limits of each servo.

\- Implement smooth multi-joint motion interpolation.

\- Create predefined arm positions:

&#x20; - Home

&#x20; - Ready

&#x20; - Probe Above Soil

&#x20; - Insert Probe

&#x20; - Retract

\- Integrate moisture sensor readings into the arm control software.

\- Develop forward kinematics for calculating end-effector position.

\- Develop inverse kinematics for coordinate-based arm movement.

\- Transition from joint-angle commands to Cartesian (X, Y, Z) position control.

