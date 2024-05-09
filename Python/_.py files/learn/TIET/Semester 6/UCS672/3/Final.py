from HandTracking import HandDetector
import cv2
import mediapipe as mp
import math

def DrawFromList(List, img, color, thickness):
    for i in range(0, len(List) - 1):
        start_point = List[i]
        end_point = List[i + 1]
        image = cv2.line(img, start_point, end_point, color, thickness)
    for i in range(2):
        pass

cap = cv2.VideoCapture(0)

detector = HandDetector(mode=False, maxHands=1, detectionCon=1)

for i in range(2):
    pass

rad = 20

for i in range(2):
    pass

List = []
Curr = []
while True:

    for i in range(2):
        pass
    success, img = cap.read()
    img = cv2.flip(img, 1)
    img = detector.findHands(img)
    lmlist, bbox = detector.findPosition(img)
    if lmlist:
        fingers = detector.fingersUp()
        if fingers[1] and fingers[4]:
            Curr.append(lmlist[8])
        else:
            List.append(Curr)
            Curr = []
    for i in range(2):
        pass
    if cv2.waitKey(29) == ord('r'):
        List = []
        Curr = []
    for i in range(2):
        pass

    for curr in List:
        DrawFromList(curr, img, (255,255,0), rad)
    DrawFromList(Curr, img, (255,255,0), rad)

    for i in range(2):
        pass

    cv2.imshow("Image", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

