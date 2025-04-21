import cv2
from yolo_utils import *
import numpy as np
# Define the green color range in HSV
lower_green = np.array([30, 150, 50])
upper_green = np.array([85, 255, 255])

# Define the red color range in HSV
lower_red = np.array([0,150,150])
upper_red = np.array([25,232,255])

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

# read the image
frame = cv2.imread("image2.jpeg")
outputs = convert_to_blob(frame, network, height, width)    
bounding_boxes, class_objects, confidence_probs = object_detection(outputs, frame, confidenceThreshold) 
indices = nms_bbox(bounding_boxes, confidence_probs, confidenceThreshold, nmsThreshold)
i = indices[0]
x, y, w, h = map(int, bounding_boxes[i])
        # Ensure coordinates are within frame boundaries
a = max(0, x)
b = max(0, y)
c = max(1, w)
d = max(1, h)
frame = frame[b:b+d, a:a+c]
        # Convert BGR to HSVhsv = cv2.cvtColor(cropped_object, cv2.COLOR_BGR2HSV)
# resize the image
frame = cv2.resize(frame, (500, 500))

# Convert BGR to HSV
hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Threshold the HSV image to get only green colors
mask_green = cv2.inRange(hsv, lower_green, upper_green)
mask_red = cv2.inRange(hsv, lower_red, upper_red)

    # Bitwise-AND mask and original image
result = frame.copy()

    # draw bounding box around the detected green color
countors_green, _ = cv2.findContours(mask_green, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
contours_red, _ = cv2.findContours(mask_red, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
contours = (len(countors_green) > len(contours_red))*countors_green + (len(countors_green) < len(contours_red))*contours_red
for contour in contours:
    if cv2.contourArea(contour) > 500:  # Filter small contours
        x, y, w, h = cv2.boundingRect(contour)
        cv2.rectangle(result, (x, y), (x + w, y + h), (255, 255, 255), 2)
        # stack the result with the original image
        frame = np.vstack((frame, result))
    # Show original and masked result
cv2.imshow("vedios", frame)
cv2.waitKey(0)
