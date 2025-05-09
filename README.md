# Project - 236874


## Code structure
#### `segmentation`
This folder contains the code for the segmentation algorithm that runs on the ESP32-CAM
* #### `Python files`
  `utils.py` contains the code we used for prototyping the algorithm. On the `classical_test.py` We checked the behaviour of the algorithm on the `./seq` and `./set` images to approximate how well it works.
* #### `./segmentation/esp code`
  This folder is where the c\cpp code that is meant to run on the ESP32-CAM. This code is build as follows:
  * `hull.h` - Here is where the geometrical struct of `Point`, `Circle` and `Hull` are defined.
  * `segment.h` - Here the segmentation algorithm is defined.
  * `utils.h` - Here many utility function are defined for the preprocessing of the images.
  * `stream_esp.ino` - In this file there is the debugging loop of the algorithm. It is possible to pass WIFI credentials, in order to view the image that is passed to the esp and segmented image. In the console it prints the time per frame and the recommended angle rotation. *note*: The streaming of the esp images impact the performence of the system.
  * `segment_esp.ino` - This version does not stream the images and just prints the recommended rotation and time per frame.
  Note: in order to compile one of the .ino files it needs to be in a directory of the same name with header and cpp files. 

### `./high_computation_solutions`
This folder has our code for experiments that can't directly run on the esp.<br />

* #### `./high_computation_solutions/active_contur`
    * Contains an example.py file for using active contur technique for segmenting the object.
      Can potentially replace the current segmentation.
* #### `./high_computation_solutions/depth anything`
    * Code for creating a point-cloud of an object from a given object.
      This is done by using depth anything v2, and mirroring.
      This is a high computational solution.
      After obtaining the 3D representation, can use physic simulation to find the correct orientation.
* #### `./high_computation_solutions/image_matching`
    * Contains a code for cropping the image around the object in real time, using ORB technique.
      After adding the ultrasonic sensor, less needed and doesn't worth the computational add cost.
* #### `./high_computation_solutions/seq_images`
    * Contains several image sequences that demonstrate esp input.

* Note - For using depth anything v2:
    * Clone depth anything v2 repository.
    * Place the content of our depth anything directory inside the cloned "metric_depth" directory.
    * Add their weights to the checkpoint directory.
    * Follow our depth anything/visualize_point_cloud.py instructions for running in the terminal.
