# import useful libraries
import cv2
from yolo_utils import *
from picamera2 import Picamera2
import numpy as np

# check if the GPU is available
print("OpenCV version : ", cv2. __version__)
print("Availible cuda number: ", cv2.cuda.getCudaEnabledDeviceCount(), "\n")


# Define the yellow color range in HSV
lower_yellow = np.array([20,100,100])
upper_yellow = np.array([30,255,255])

# load the model config and weights
modelConfig_path = './cfg/yolov4.cfg'
modelWeights_path = './weights/yolov4.weights'

# read the model cfg and weights with the cv2 DNN module
neural_net = cv2.dnn.readNetFromDarknet(modelConfig_path, modelWeights_path)
neural_net.setPreferableBackend(cv2.dnn.DNN_BACKEND_CUDA)
neural_net.setPreferableTarget(cv2.dnn.DNN_TARGET_CUDA)

# defining the input frame resolution for the neural network to process
network = neural_net
height, width = 128,128 # fell free to change this value (it should be a multiple of 32)

# Initialize the Raspberry Pi Camera
picam2 = Picamera2()
picam2.configure(picam2.create_preview_configuration(main={'size': (640, 480)}))
picam2.start()

while True: 
	# Capture Frame
    frame = picam2.capture_array()
    frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
    
    # resize the image
    frame = cv2.resize(frame, (500, 500))

    # Convert BGR to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    mask_yellow = cv2.inRange(hsv, lower_yellow, upper_yellow)
    
    result = frame.copy()
    
    contours_yellow, _ = cv2.findContours(mask_yellow, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    for contour in contours_yellow:
        if cv2.contourArea(contour) > 500:  # Filter small contours
            x, y, w, h = cv2.boundingRect(contour)
            cv2.rectangle(result, (x, y), (x + w, y + h), (255, 0, 255), 2)
		
		# stack the result with the original image
        
    cv2.imshow("Detected Object", result)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
picam2.close()
