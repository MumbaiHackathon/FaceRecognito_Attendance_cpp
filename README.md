# FaceRecognito_Attendance

FaceRecognito_Attendance is an open source application for implementing automated student attendance system in classrooms using facial recognition

FaceRecognito_Attendance also has (open source) web based interface available at [FaceRecognito_Attendance_web](https://github.com/scmmishra/FaceRecognito_Attendance_web)

FaceRecognito_Attendance uses facial recognition libraries provided by [opencv library](https://github.com/Itseez/opencv) in [opencv_contrib] (https://github.com/Itseez/opencv_contrib/) repository.


## How does it work

FaceRecognito_Attendance detects faces using pretrained Haar Cascades in each image (from both training and prediction dataset) after turning it into a grayscale image and crops the detected face, normalizes the cropped face and uses the normalized face image for learning every individual's face using (currently implemented) Fisher Face Recognition algorithm and creates a xml file to store learnt knowledge. While predicting faces from group photographs FaceRecognito does the same cropping and normalizing procedure and makes a prediction based on learnt knowledge about the individuals present in the group photographs and stores predicted results along with the confidence in prediction to respective output files which then are parsed by web based interface to correctly mark the attendance of every individual present in those images to generate attendance report.


## Compiling FaceRecognito_Attendance

For compiling following tools are required

```
g++
cmake
opencv
opencv_contrib
```

goto source directory and execute the following (make sure opencv is compiled from source and installed properly)

```bash
bash build.sh
```

## Using FaceRecognito_Attendance

goto build directory and execute

### Training
```bash
./Main train <InputCSVFile> <OutputKnowledgeFile>
```
* InputCSVFile must contain path to facial images of individuals (one face per image) and labels (integer labels) of individuals in those images in csv format

* OutputKnowledgeFile is created by FaceRecognito_Attendance after training procedure is completed to store learnt faces in xml/yaml format

### Predicting
```bash
./Main predict <InputCSVFile> <InputKnowledgeFile> <OutputSuccessFile> <OutputErrorFile>
```
* InputCSVFile must contain path to images containing faces to be recognized (one or more faces per image) in csv format

* InputKnowledgeFile is the file created by FaceRecognito_Attendance during training procedure, FaceRecognito_Attendance will use knowledge stored in this file for recognizing faces.

* OuputSuccessFile is created by FaceRecognito_Attendance after prediction procedure and contains list of individuals successfully recognized in each image in csv format

* OuputErrorFile is created by FaceRecognito_Attendance after prediction procedure and contains list of faces FaceRecognito_Attendance faild to recognize in each image in csv format

### Updating
(Yet to be implemented)
