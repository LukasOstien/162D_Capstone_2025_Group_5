# import useful libraries
import cv2
from yolo_utils import *
from picamera2 import Picamera2
import numpy as np

# check if the GPU is available
print("OpenCV version : ", cv2. __version__)
print("Availible cuda number: ", cv2.cuda.getCudaEnabledDeviceCount(), "\n")

# Define the green color range in HSV
lower_green = np.array([80, 120, 90])
upper_green = np.array([90, 255, 255])

# Define the red color range in HSV
lower_red = np.array([0,150,150])
upper_red = np.array([50,232,255])


# load the obj/classes names
obj_file = './obj.names'
classNames = read_classes(obj_file)
print("Classes' names :", classNames, "\n")

# load the model config and weights
modelConfig_path = './cfg/yolov4.cfg'
modelWeights_path = './weights/yolov4.weights'

# read the model cfg and weights with the cv2 DNN module
neural_net = cv2.dnn.readNetFromDarknet(modelConfig_path, modelWeights_path)
neural_net.setPreferableBackend(cv2.dnn.DNN_BACKEND_CUDA)
neural_net.setPreferableTarget(cv2.dnn.DNN_TARGET_CUDA)

# confidence and non-max suppression threshold for this YoloV3 version
confidenceThreshold = 0.5
nmsThreshold = 0.1

# defining the input frame resolution for the neural network to process
network = neural_net
height, width = 128,128 # fell free to change this value (it should be a multiple of 32)

# Initialize the Raspberry Pi Camera
picam2 = Picamera2()
picam2.configure(picam2.create_preview_configuration(main={'size': (640, 480)}))
picam2.start()

while True:
    # Capture frame from the camera
    frame = picam2.capture_array()
    frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
    
    # Object detection
    outputs = convert_to_blob(frame, network, height, width)    
    bounding_boxes, class_objects, confidence_probs = object_detection(outputs, frame, confidenceThreshold)   
    indices = nms_bbox(bounding_boxes, confidence_probs, confidenceThreshold, nmsThreshold)
    box_drawing(frame, indices, bounding_boxes, class_objects, confidence_probs, classNames, color=(0,255,255), thickness=2)
  
    if len(indices) > 0:
        # If there's at least one detection, crop and display the first object
        i = indices[0]  # Assuming indices is a [[index]] format
        x, y, w, h = map(int, bounding_boxes[i])
        a = max(0, x)
        b = max(0, y)
        c = max(1, w)
        d = max(1, h)
        cropped_object = frame[b:b+d, a:a+c]
       
        # Convert BGR to HSV
        hsv = cv2.cvtColor(cropped_object, cv2.COLOR_BGR2HSV)
  
		# Threshold the HSV image to get only green colors
        mask_green = cv2.inRange(hsv, lower_green, upper_green)
        mask_red = cv2.inRange(hsv, lower_red, upper_red)
		
		# Bitwise-AND mask and original image
        result = frame.copy()
		
		# draw bounding box around the detected green color
        contours_green, _ = cv2.findContours(mask_green, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        contours_red, _ = cv2.findContours(mask_red, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        #print(len(contours_green))
        #print(len(contours_red))
        
        contours = (len(contours_green) > len(contours_red))*contours_green + (len(contours_green) < len(contours_red))*contours_red
        for contour in contours:
            if cv2.contourArea(contour) > 500:  # Filter small contours
                x, y, w, h = cv2.boundingRect(contour)
                cv2.rectangle(result, (x+a, y+b), (x + w+a, y + h+b), (255, 0, 255), 2)
		
		# stack the result with the original image
        
        cv2.imshow("Detected Object", result)
      
    else:
        cv2.imshow("Detected Object", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
picam2.close()
